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

def write_c_array(path, stem, bin_content):
    array_name = f"{stem}_strings_bin"
    path.parent.mkdir(parents=True, exist_ok=True)
    with open(path, "w", encoding="utf-8") as out:
        out.write(f"// Auto-generated from {stem}.yaml\n")
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
