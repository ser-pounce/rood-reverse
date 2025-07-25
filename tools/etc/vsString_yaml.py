import yaml
from tools.etc.vsString import encode

def read_yaml(path):
    with open(path, "r", encoding="utf-8") as f:
        data = yaml.safe_load(f)

    strings = []
    offsets = []
    enums = {}
    offset = 0

    def add_string(s):
        encoded = encode(s)
        strings.append(encoded)
        offsets.append(offset)
        return len(encoded) // 2

    def process_value(value):
        nonlocal offset
        if isinstance(value, list):
            for item in value:
                process_value(item)
        else:
            offset += add_string(value)

    for key, value in data.items():
        enums[key] = offset
        process_value(value)

    count = len(strings)
    offsets = [o + count for o in offsets]
    enums = {k: v + count for k, v in enums.items()}

    return strings, offsets, enums

def write_binary(path, offsets, strings):
    bin_content = bytearray()
    for offset in offsets:
        bin_content += offset.to_bytes(2, "little")
    for s in strings:
        bin_content += s
    path.parent.mkdir(parents=True, exist_ok=True)
    with open(path, "wb") as out:
        out.write(bin_content)
    return bin_content

def write_data(path, offsets, strings):
    bin_content = write_binary(path, offsets, strings)
    path.parent.mkdir(parents=True, exist_ok=True)
    with open(path, "w", encoding="utf-8") as out:
        for i in range(0, len(bin_content), 2):
            val = (bin_content[i+1] << 8) | bin_content[i]
            out.write(f"0x{val:04X}, ")

def write_header(path, stem, enums):
    path.parent.mkdir(parents=True, exist_ok=True)
    with open(path, "w", encoding="utf-8") as h:
        h.write(f"#pragma once\n\nenum {stem}_offsets_e {{\n")
        for k, v in enums.items():
            h.write(f"    VS_{stem}_OFFSET_{k} = {v},\n")
        h.write("};\n\n")
        h.write(f"enum {stem}_indices_e {{\n")
        for i, (k, v) in enumerate(enums.items()):
            h.write(f"    VS_{stem}_INDEX_{k} = {i},\n")
        h.write("};\n")
