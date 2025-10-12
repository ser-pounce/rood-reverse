import yaml
from tools.etc.vsString import encode

def read_yaml(path, padding=0xEB):
    with open(path, "r", encoding="utf-8") as f:
        data = yaml.safe_load(f)

    strings = []
    offsets = []
    enums = {}
    indices = {}  # Track the index in the offsets table for each key
    offset = 0
    current_index = 0

    def add_string(s, padding):
        encoded = encode(s, padding)
        strings.append(encoded)
        offsets.append(offset)
        return len(encoded) // 2

    def process_value(value, padding):
        nonlocal offset, current_index
        if isinstance(value, list):
            for item in value:
                process_value(item, padding)
        else:
            offset += add_string(value, padding)
            current_index += 1

    for key, value in data.items():
        enums[key] = offset
        indices[key] = current_index  # Store the index position for this key
        process_value(value, padding)

    count = len(strings)
    offsets = [o + count for o in offsets]
    enums = {k: v + count for k, v in enums.items()}

    return strings, offsets, enums, indices

def write_binary_header(offsets):
    header = bytearray()
    for offset in offsets:
        header += offset.to_bytes(2, "little")
    return header

def write_binary_data(path, bin_content, strings):
    for s in strings:
        bin_content += s
    path.parent.mkdir(parents=True, exist_ok=True)
    with open(path, "wb") as out:
        out.write(bin_content)
    return bin_content

def write_data(path, offsets, strings):
    header = write_binary_header(offsets)
    bin_content = write_binary_data(path, header, strings)
    path.parent.mkdir(parents=True, exist_ok=True)
    with open(path, "w", encoding="utf-8") as out:
        for i in range(0, len(bin_content), 2):
            val = (bin_content[i+1] << 8) | bin_content[i]
            out.write(f"0x{val:04X}, ")

def write_header(path, stem, enums, indices):
    path.parent.mkdir(parents=True, exist_ok=True)
    with open(path, "w", encoding="utf-8") as h:
        h.write(f"#pragma once\n\nenum {stem}_offsets_e {{\n")
        for k, v in enums.items():
            h.write(f"    VS_{stem}_OFFSET_{k} = {v},\n")
        h.write("};\n\n")
        h.write(f"enum {stem}_indices_e {{\n")
        for k, idx in indices.items():
            h.write(f"    VS_{stem}_INDEX_{k} = {idx},\n")
        h.write("};\n")
