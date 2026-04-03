#!/usr/bin/env python3
"""
Dumps vs_battle_charInitData from a binary file to YAML.
Struct layout is derived directly from a C header file via cffi + GCC preprocessing.

Usage:
    python dump_charInitData.py <input> <offset> <output>
                                [--header path/to/structs.h]
                                [--compiler mipsel-linux-gnu-gcc]
                                [--include /path/to/sdk/include]
                                [--struct vs_battle_charInitData]

    offset can be decimal (e.g. 1234) or hex (e.g. 0x4D2)

char[] fields annotated with /* vs_string */ in the header will be decoded
using tools.etc.vsString.decode. All other char arrays are emitted as lists
of integers.
"""

import sys
import re
import subprocess
import argparse
from pathlib import Path

import cffi
import yaml
from tools.etc.vsString import decode as vs_decode


# ---------------------------------------------------------------------------
# Preprocessing
# ---------------------------------------------------------------------------

def preprocess(header_path: Path, compiler: str, include_dirs: list) -> str:
    """
    Run the header through GCC's preprocessor (-E -C to preserve comments)
    and return the expanded source as a string.
    """
    cmd = [compiler, '-E', '-C', '-x', 'c']
    for inc in include_dirs:
        cmd += ['-I', str(inc)]
    cmd.append(str(header_path))

    result = subprocess.run(cmd, capture_output=True, text=True)
    if result.returncode != 0:
        print("Preprocessor error:", file=sys.stderr)
        print(result.stderr, file=sys.stderr)
        sys.exit(1)

    return result.stdout


# ---------------------------------------------------------------------------
# Annotation extraction
# ---------------------------------------------------------------------------

# Matches a char array field followed by /* vs_string */ on the same line.
# e.g.   char name[24]; /* vs_string */
_VS_STRING_RE = re.compile(
    r'\bchar\s+(\w+)\s*\[\d+\]\s*;[^\S\n]*/\*\s*vs_string\s*\*/'
)


def extract_vs_string_fields(source: str) -> set:
    """
    Parse the preprocessed source (with comments intact) and return a set of
    'TypedefName.fieldName' strings for every char[] annotated /* vs_string */.
    """
    vs_fields = set()
    text = source
    n = len(text)
    i = 0

    while i < n:
        # Find the next typedef struct { ... } Name;
        m = re.search(r'\btypedef\s+struct\s*\{', text[i:])
        if not m:
            break

        brace_pos = i + m.end() - 1   # index of the opening '{'
        i = brace_pos + 1
        depth = 1
        body_start = i

        while i < n and depth > 0:
            if text[i] == '{':
                depth += 1
            elif text[i] == '}':
                depth -= 1
            i += 1

        body = text[body_start:i - 1]

        # The typedef name follows the closing '}'
        name_m = re.match(r'\s*(\w+)\s*;', text[i:])
        if not name_m:
            continue
        struct_name = name_m.group(1)

        for field_m in _VS_STRING_RE.finditer(body):
            vs_fields.add(f'{struct_name}.{field_m.group(1)}')

    return vs_fields


# ---------------------------------------------------------------------------
# cffi setup
# ---------------------------------------------------------------------------

def build_ffi(source: str, root_struct: str):
    """
    Strip preprocessor line markers and comments, feed to cffi, and return
    (ffi, ctype) for the named root struct.
    """
    # Remove # line directives emitted by -E
    cleaned = re.sub(r'^#[^\n]*\n', '', source, flags=re.MULTILINE)
    # Strip block comments (annotations already captured above)
    cleaned = re.sub(r'/\*.*?\*/', '', cleaned, flags=re.DOTALL)
    # Strip line comments
    cleaned = re.sub(r'//[^\n]*', '', cleaned)

    ffi = cffi.FFI()
    try:
        ffi.cdef(cleaned)
    except cffi.CDefError as e:
        print(f"cffi cdef error: {e}", file=sys.stderr)
        sys.exit(1)

    try:
        ctype = ffi.typeof(root_struct)
    except cffi.CDefError as e:
        print(f"cffi cannot find type '{root_struct}': {e}", file=sys.stderr)
        sys.exit(1)

    return ffi, ctype


# ---------------------------------------------------------------------------
# Binary reading
# ---------------------------------------------------------------------------

def read_struct(ffi, ctype, data: bytes, offset: int):
    sz = ffi.sizeof(ctype)
    if offset + sz > len(data):
        print(
            f"ERROR: struct extends to 0x{offset+sz:X} "
            f"but file is only 0x{len(data):X} bytes.",
            file=sys.stderr,
        )
        sys.exit(1)
    buf = ffi.new(f'{ctype.cname} *')
    ffi.memmove(buf, data[offset:offset + sz], sz)
    return buf[0]


# ---------------------------------------------------------------------------
# cffi cdata → plain Python (recursive)
# ---------------------------------------------------------------------------

def cdata_to_python(ffi, value, vs_fields: set, path: str = ''):
    """
    Recursively convert a cffi cdata value to a plain Python object
    (dict / list / int) suitable for yaml.dump.

    `path` is 'StructTypeName.fieldName', used to match vs_string annotations.
    """
    ctype = ffi.typeof(value)
    kind  = ctype.kind

    if kind == 'struct':
        result = {}
        struct_name = ctype.cname
        for field_name, field_info in ctype.fields:
            child = getattr(value, field_name)
            # cffi returns bitfields as int, and char[] fields as bytes directly
            if isinstance(child, int):
                result[field_name] = child
                continue
            if isinstance(child, bytes):
                child_path = f'{struct_name}.{field_name}'
                if len(child) == 1:
                    # Plain char — emit as scalar integer
                    b = child[0]
                    result[field_name] = b if b < 128 else b - 256
                elif child_path in vs_fields:
                    result[field_name] = vs_decode(child)
                else:
                    result[field_name] = [b if b < 128 else b - 256 for b in child]
                continue
            child_path = f'{struct_name}.{field_name}'
            result[field_name] = cdata_to_python(ffi, child, vs_fields, child_path)
        return result

    elif kind == 'array':
        item_type = ctype.item
        length    = ctype.length
        char_types = ('char', 'signed char', 'unsigned char')

        if item_type.kind == 'primitive' and item_type.cname in char_types:
            raw = bytes(ffi.buffer(ffi.addressof(value, 0), length))
            if path in vs_fields:
                return vs_decode(raw)
            # signed char → signed integers; char/unsigned char → unsigned
            if item_type.cname == 'signed char':
                return [b if b < 128 else b - 256 for b in raw]
            return list(raw)

        return [cdata_to_python(ffi, value[i], vs_fields, path) for i in range(length)]

    elif kind == 'primitive':
        return int(value)

    else:
        return repr(value)


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------
def main():
    parser = argparse.ArgumentParser(
        description='Dump a C struct from a binary file to YAML, '
                    'driven by a C header processed with GCC.'
    )
    parser.add_argument('input',  help='Path to the input binary file')
    parser.add_argument('offset', help='Byte offset (decimal or 0x hex)')
    parser.add_argument('output', help='Path to the output YAML file')
    parser.add_argument('--header',   default='structs.h',
                        help='C header file to parse (default: structs.h)')
    parser.add_argument('--compiler', default='mipsel-linux-gnu-gcc',
                        help='GCC cross-compiler binary '
                             '(default: mipsel-linux-gnu-gcc)')
    parser.add_argument('--include',  action='append', default=[], metavar='DIR',
                        help='Extra -I include path (repeatable)')
    parser.add_argument('--struct',   default='vs_battle_charInitData',
                        help='Root struct typedef name to dump '
                             '(default: vs_battle_charInitData)')
    args = parser.parse_args()

    offset       = int(args.offset, 0)
    header_path  = Path(args.header)
    include_dirs = [Path(p) for p in args.include]

    source = preprocess(header_path, args.compiler, include_dirs)

    vs_fields = extract_vs_string_fields(source)
    ffi, ctype = build_ffi(source, args.struct)
    sz = ffi.sizeof(ctype)

    with open(args.input, 'rb') as f:
        data = f.read()

    instance = read_struct(ffi, ctype, data, offset)

    result = cdata_to_python(ffi, instance, vs_fields)

    def represent_list_inline(dumper, data):
        flow = len(data) > 0 and isinstance(data[0], (int))
        return dumper.represent_sequence('tag:yaml.org,2002:seq', data, flow_style=flow)

    yaml.add_representer(list, represent_list_inline)

    with open(args.output, 'w', encoding='utf-8') as f:
        yaml.dump(result, f, allow_unicode=True, sort_keys=False)


if __name__ == '__main__':
    main()