import sys
import re
from vsString import encode_raw

def encode_c_string_literal(s):
    encoded = encode_raw(eval(s))
    byte_array = ', '.join(str(b) for b in encoded)
    return '{' + byte_array + '}'

def process_vsstring_block(block):
    string_literal_re = re.compile(r'"([^"\\]*(?:\\.[^"\\]*)*)"')
    def replacer(match):
        return encode_c_string_literal(match.group(0))
    return string_literal_re.sub(replacer, block)

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
