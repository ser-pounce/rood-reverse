import sys
import re
from ast import literal_eval
from tools.etc.vsString import encode_raw

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

def encode_c_string_literal(s):
    # C concatenates adjacent literals before interpreting the game encoding.
    # In particular, "L" "v." must produce the single-byte Lv. glyph.
    text = ''.join(
        literal_eval(match.group('literal'))
        for match in STRING_TOKEN_RE.finditer(s)
        if match.group('literal') is not None
    )
    encoded = encode_raw(text)
    byte_array = ', '.join(str(b) for b in encoded)
    return '{' + byte_array + '}'

def encode_c_char_literal(s):
    # s includes the surrounding single quotes
    # evaluate to a Python string of length 1 and encode it
    encoded = encode_raw(literal_eval(s))
    if len(encoded) != 1:
        # unexpected; fall back to full list
        return '{' + ', '.join(str(b) for b in encoded) + '}'
    return str(encoded[0])

def process_vsstring_block(block):
    def replacer(match):
        if match.group('comment') is not None:
            return match.group(0)
        if match.group('string') is not None:
            return encode_c_string_literal(match.group(0))
        return encode_c_char_literal(match.group(0))

    return TOKEN_RE.sub(replacer, block)

if __name__ == "__main__":
    lines = sys.stdin.readlines()
    output = []
    in_vsstring = False
    vsstring_block = []

    for line in lines:
        stripped = line.strip()
        if not in_vsstring and stripped == "#pragma vsstring(start)":
            in_vsstring = True
            vsstring_block = []
            continue
        elif in_vsstring and stripped == "#pragma vsstring(end)":
            in_vsstring = False
            output.append(process_vsstring_block(''.join(vsstring_block)))
            continue

        if in_vsstring:
            vsstring_block.append(line)
        else:
            output.append(line)

    if in_vsstring and vsstring_block:
        output.append(process_vsstring_block(''.join(vsstring_block)))

    sys.stdout.writelines(output)
