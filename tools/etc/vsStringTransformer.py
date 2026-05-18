import sys
import re
from vsString import encode_raw

def encode_c_string_literal(s):
    encoded = encode_raw(eval(s))
    byte_array = ', '.join(str(b) for b in encoded)
    return '{' + byte_array + '}'

def encode_c_char_literal(s):
    # s includes the surrounding single quotes
    # evaluate to a Python string of length 1 and encode it
    encoded = encode_raw(eval(s))
    if len(encoded) != 1:
        # unexpected; fall back to full list
        return '{' + ', '.join(str(b) for b in encoded) + '}'
    return str(encoded[0])

def process_vsstring_block(block):
    # match C string literals \"...\" and character literals '\''...\''
    string_literal_re = re.compile(r'"([^"\\]*(?:\\.[^"\\]*)*)"')
    char_literal_re = re.compile(r"'([^'\\]*(?:\\.[^'\\]*)*)'")

    def string_replacer(match):
        return encode_c_string_literal(match.group(0))

    def char_replacer(match):
        # encode character literal without braces
        return encode_c_char_literal(match.group(0))

    # replace string literals first, then character literals
    block = string_literal_re.sub(string_replacer, block)
    block = char_literal_re.sub(char_replacer, block)
    return block

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
