#!/usr/bin/env python3
"""
Converts a YAML file back to a C struct initializer, driven by a C header.

The output is the inner initializer content only — no variable declaration,
no outer braces — intended to be included at the point of use:

    static vs_battle_charInitData myChar = {
        #include "myChar.h"
    };

Usage:
    python yamlToInitializer.py <input.yaml> <output.h>
                                [--header path/to/structs.h]
                                [--compiler mipsel-linux-gnu-gcc]
                                [--include /path/to/sdk/include]
                                [--struct vs_battle_charInitData]

char[] fields annotated with /* vs_string */ will be encoded via
tools.etc.vsString.encode.
"""

import sys
import re
import subprocess
import argparse
from pathlib import Path

import cffi
import yaml
from tools.etc.vsString import encode as _vs_encode

def vs_encode(s):
    return _vs_encode(s, padding=None)


# ---------------------------------------------------------------------------
# Preprocessing  (shared logic with dumpStruct.py)
# ---------------------------------------------------------------------------

def preprocess(header_path: Path, compiler: str, include_dirs: list) -> str:
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
# Annotation extraction  (shared logic with dumpStruct.py)
# ---------------------------------------------------------------------------

_VS_STRING_RE = re.compile(
    r'\bchar\s+(\w+)\s*\[\d+\]\s*;[^\S\n]*/\*\s*vs_string\s*\*/'
)

def extract_vs_string_fields(source: str) -> set:
    vs_fields = set()
    text = source
    n = len(text)
    i = 0

    while i < n:
        m = re.search(r'\btypedef\s+struct\s*\{', text[i:])
        if not m:
            break

        brace_pos = i + m.end() - 1
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

        name_m = re.match(r'\s*(\w+)\s*;', text[i:])
        if not name_m:
            continue
        struct_name = name_m.group(1)

        for field_m in _VS_STRING_RE.finditer(body):
            vs_fields.add(f'{struct_name}.{field_m.group(1)}')

    return vs_fields


# ---------------------------------------------------------------------------
# cffi setup  (shared logic with dumpStruct.py)
# ---------------------------------------------------------------------------

def build_ffi(source: str, root_struct: str):
    cleaned = re.sub(r'^#[^\n]*\n', '', source, flags=re.MULTILINE)
    cleaned = re.sub(r'/\*.*?\*/', '', cleaned, flags=re.DOTALL)
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
# YAML -> C initializer
# ---------------------------------------------------------------------------

def is_primitive_type(ffi, ctype) -> bool:
    return ctype.kind == 'primitive'

def is_bitfield(ffi, ctype, field_info) -> bool:
    return field_info is not None and field_info.bitshift >= 0 and field_info.bitsize > 0

def format_int(value: int) -> str:
    return str(value)

def format_bytes_array(data: bytes, length: int) -> str:
    # Pad or truncate to the declared length
    padded = data[:length].ljust(length, b'\x00')
    return '{' + ', '.join(f'0x{b:02X}' for b in padded) + '}'

def format_int_array(values: list, signed: bool) -> str:
    return '{' + ', '.join(str(v) for v in values) + '}'


def yaml_to_initializer(ffi, ctype, data, vs_fields: set,
                         indent: int = 0, path: str = '') -> str:
    """
    Recursively convert a plain Python object (from yaml.safe_load) to a C
    initializer string, guided by the cffi type info.
    """
    pad = '    ' * indent
    field_pad = '    ' * (indent + 1)
    kind = ctype.kind

    if kind == 'struct':
        struct_name = ctype.cname
        lines = []
        for field_name, field_info in ctype.fields:
            child_path = f'{struct_name}.{field_name}'

            if field_info is not None and field_info.bitsize > 0:
                # Bitfield — emit as plain integer
                value = data.get(field_name, 0)
                lines.append(f'{field_pad}/* {field_name} */ {format_int(value)},')
                continue

            field_ctype = field_info.type if field_info is not None else None
            if field_ctype is None:
                continue

            child_data = data.get(field_name, None)
            child_str = yaml_to_initializer(
                ffi, field_ctype, child_data, vs_fields,
                indent + 1, child_path
            )
            lines.append(f'{field_pad}/* {field_name} */ {child_str},')

        return '{\n' + '\n'.join(lines) + '\n' + pad + '}'

    elif kind == 'array':
        item_type = ctype.item
        length = ctype.length
        char_types = ('char', 'signed char', 'unsigned char')

        if item_type.kind == 'primitive' and item_type.cname in char_types:
            if path in vs_fields:
                # Encode the string and emit as byte array
                raw = vs_encode(data if data is not None else '')
                return format_bytes_array(raw, length)
            else:
                # Plain char array — data is a list of ints or a single int
                if isinstance(data, int):
                    data = [data]
                values = (data or [])[:length]
                values += [0] * (length - len(values))
                return '{' + ', '.join(str(v) for v in values) + '}'

        elif item_type.kind == 'primitive':
            if isinstance(data, int):
                data = [data]
            values = (data or [])[:length]
            values += [0] * (length - len(values))
            return '{' + ', '.join(str(v) for v in values) + '}'

        else:
            # Array of structs
            if data is None:
                data = []
            lines = []
            for i in range(length):
                elem = data[i] if i < len(data) else None
                elem_str = yaml_to_initializer(
                    ffi, item_type, elem, vs_fields,
                    indent + 1, path
                )
                lines.append(f'{field_pad}{elem_str},')
            return '{\n' + '\n'.join(lines) + '\n' + pad + '}'

    elif kind == 'primitive':
        return format_int(data if data is not None else 0)

    else:
        return '0'


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

def main():
    parser = argparse.ArgumentParser(
        description='Convert a YAML struct dump back to a C initializer.'
    )
    parser.add_argument('input',  help='Path to the input YAML file')
    parser.add_argument('output', help='Path to the output .h file')
    parser.add_argument('--header',   default='structs.h',
                        help='C header file to parse (default: structs.h)')
    parser.add_argument('--compiler', default='mipsel-linux-gnu-gcc',
                        help='GCC cross-compiler binary '
                             '(default: mipsel-linux-gnu-gcc)')
    parser.add_argument('--include',  action='append', default=[], metavar='DIR',
                        help='Extra -I include path (repeatable)')
    parser.add_argument('--struct',   default='vs_battle_charInitData',
                        help='Root struct typedef name '
                             '(default: vs_battle_charInitData)')
    args = parser.parse_args()

    header_path  = Path(args.header)
    include_dirs = [Path(p) for p in args.include]

    source = preprocess(header_path, args.compiler, include_dirs)

    vs_fields = extract_vs_string_fields(source)

    ffi, ctype = build_ffi(source, args.struct)

    with open(args.input, 'r', encoding='utf-8') as f:
        data = yaml.safe_load(f)

    # We want the inner content without the outermost braces
    inner = yaml_to_initializer(ffi, ctype, data, vs_fields, indent=0)
    # Strip the outer { ... } — the caller provides those
    inner = inner.strip()
    assert inner.startswith('{') and inner.endswith('}')
    inner = inner[1:-1].strip()

    with open(args.output, 'w', encoding='utf-8') as f:
        f.write(inner)
        f.write('\n')


if __name__ == '__main__':
    main()