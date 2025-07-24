import sys
import yaml
import os
from pathlib import Path
from tools.etc.vsString import encode


def process_yaml_strings(data):
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

    return strings, offsets, enums

if len(sys.argv) < 4:
    print("Usage: python mcman.py <path_to_yaml> <output_filename> <output_header>")
    sys.exit(1)

stem = Path(sys.argv[1]).stem

with open(sys.argv[1], "r", encoding="utf-8") as f:
    data = yaml.safe_load(f)

strings, offsets, enums = process_yaml_strings(data)

# Prepare binary content
bin_content = bytearray()
for offset in offsets:
    bin_content += offset.to_bytes(2, "little")
for s in strings:
    bin_content += s

os.makedirs(os.path.dirname(sys.argv[2]), exist_ok=True)

with open(sys.argv[2], "wb") as out:
    out.write(bin_content)
    

os.makedirs(os.path.dirname(sys.argv[3]), exist_ok=True)
array_name = f"{stem}_strings_bin"
with open(sys.argv[3], "w", encoding="utf-8") as out:
    out.write(f"// Auto-generated from {sys.argv[1]}\n")
    out.write(f"unsigned char {array_name}[] = {{\n")
    for i, b in enumerate(bin_content):
        if i % 16 == 0:
            out.write("    ")
        out.write(f"0x{b:02X}, ")
        if (i + 1) % 16 == 0:
            out.write("\n")
    if len(bin_content) % 16 != 0:
        out.write("\n")
    out.write("};\n")


os.makedirs(os.path.dirname(sys.argv[4]), exist_ok=True)

with open(sys.argv[4], "w", encoding="utf-8") as h:
    h.write(f"#pragma once\n\nenum {stem}_offsets_e {{\n")
    for k, v in enums.items():
        h.write(f"    VS_{stem}_OFFSET_{k} = {v},\n")
    h.write("};\n\n")
    h.write(f"enum {stem}_indices_e {{\n")
    for i, (k, v) in enumerate(enums.items()):
        h.write(f"    VS_{stem}_INDEX_{k} = {i},\n")
    h.write("};\n")