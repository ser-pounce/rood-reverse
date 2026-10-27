"""Preprocessor filter that encodes string and character literals in marked blocks.

Source text between `#pragma <encoding>(start)` and `#pragma <encoding>(end)` lines has
its string and character literals replaced by byte values in that encoding. Text outside
the blocks, and unrecognised pragmas, pass through untouched.

Supported encodings:
    vsstring  The game's own font encoding (tools.etc.vsString).
    sjis      Shift-JIS, for text stored in the game's save data.
"""
import re
import sys
from ast import literal_eval
from functools import partial
from typing import Callable, Dict, List, Match

from tools.etc.vsString import encode_raw

Encoder = Callable[[str], List[int]]


def encode_sjis(text: str) -> List[int]:
    return list(text.encode('shift_jis'))


ENCODERS: Dict[str, Encoder] = {
    'vsstring': encode_raw,
    'sjis': encode_sjis,
}

# Match comments before literals so quotes in comments remain untouched.
COMMENT = r'//[^\n]*|/\*.*?\*/'
STRING_LITERAL = r'"([^"\\]*(?:\\.[^"\\]*)*)"'
CHAR_LITERAL = r"'([^'\\]*(?:\\.[^'\\]*)*)'"
STRING_TOKEN_RE = re.compile(
    rf'(?:{COMMENT})|(?P<literal>{STRING_LITERAL})', re.DOTALL
)
TOKEN_RE = re.compile(
    rf'(?P<comment>{COMMENT})'
    rf'|(?P<string>{STRING_LITERAL}(?:(?:\s|{COMMENT})*{STRING_LITERAL})*)'
    rf'|(?P<char>{CHAR_LITERAL})',
    re.DOTALL,
)
PRAGMA_RE = re.compile(r'\s*#\s*pragma\s+(\w+)\((start|end)\)\s*')


def encode_c_string_literal(s: str, encode: Encoder) -> str:
    # C concatenates adjacent literals before interpreting the game encoding.
    # In particular, "L" "v." must produce the single-byte Lv. glyph.
    text = ''.join(
        literal_eval(match.group('literal'))
        for match in STRING_TOKEN_RE.finditer(s)
        if match.group('literal') is not None
    )
    byte_array = ', '.join(str(b) for b in encode(text))
    return '{' + byte_array + '}'


def encode_c_char_literal(s: str, encode: Encoder) -> str:
    # s includes the surrounding single quotes
    # evaluate to a Python string of length 1 and encode it
    encoded = encode(literal_eval(s))
    if len(encoded) != 1:
        # unexpected; fall back to full list
        return '{' + ', '.join(str(b) for b in encoded) + '}'
    return str(encoded[0])


def process_block(block: str, encode: Encoder) -> str:
    def replacer(match: Match[str]) -> str:
        if match.group('comment') is not None:
            return match.group(0)
        if match.group('string') is not None:
            return encode_c_string_literal(match.group(0), encode)
        return encode_c_char_literal(match.group(0), encode)

    return TOKEN_RE.sub(replacer, block)


process_vsstring_block = partial(process_block, encode=ENCODERS['vsstring'])
process_sjis_block = partial(process_block, encode=ENCODERS['sjis'])


def process_lines(lines: List[str]) -> List[str]:
    output: List[str] = []
    active = None  # name of the encoding whose block is open
    block: List[str] = []

    for line in lines:
        pragma = PRAGMA_RE.fullmatch(line.rstrip('\n'))
        if pragma and pragma.group(1) in ENCODERS:
            name, edge = pragma.groups()
            if active is None and edge == 'start':
                active = name
                block = []
                continue
            if active == name and edge == 'end':
                output.append(process_block(''.join(block), ENCODERS[name]))
                active = None
                continue

        if active is not None:
            block.append(line)
        else:
            output.append(line)

    if active is not None and block:
        output.append(process_block(''.join(block), ENCODERS[active]))
    return output


if __name__ == "__main__":
    # Pass bytes through untouched; only literals inside pragma blocks are rewritten.
    sys.stdin.reconfigure(encoding='utf-8', errors='surrogateescape')
    sys.stdout.reconfigure(encoding='utf-8', errors='surrogateescape')
    sys.stdout.writelines(process_lines(sys.stdin.readlines()))
