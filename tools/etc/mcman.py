import sys
import yaml
from tools.etc.vsString import encode

if len(sys.argv) < 4:
    print("Usage: python mcman.py <path_to_yaml> <output_bin> <output_header>")
    sys.exit(1)

with open(sys.argv[1], "r", encoding="utf-8") as f:
    data = yaml.safe_load(f)

strings = []
offsets = []
enums = {}
offset = 0

for key, value in data.items():
    enums[key] = offset
    if isinstance(value, list):
        for item in value:
            encoded = encode(item)
            strings.append(encoded)
            offsets.append(offset)
            offset += len(encoded) // 2
    else:
        encoded = encode(value)
        strings.append(encoded)
        offsets.append(offset)
        offset += len(encoded) // 2

count = len(strings)
for i in range(len(offsets)):
    offsets[i] += count
for key in enums:
    enums[key] += count

with open(sys.argv[2], "wb") as out:
    for offset in offsets:
        out.write(offset.to_bytes(2, "little"))
    for s in strings:
        out.write(s)

with open(sys.argv[3], "w", encoding="utf-8") as h:
    h.write("#pragma once\n\nenum {\n")
    for k, v in enums.items():
        h.write(f"    VS_MCMAN_{k} = {v},\n")
    h.write("};\n")