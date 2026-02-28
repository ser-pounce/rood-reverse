#!/usr/bin/env python3
"""
Script to convert YAML format back to ARMOR.SYD binary file.

Inverse of dump_armor_syd.py. Takes a YAML file produced by that script
and reconstructs the original binary format:
- 3 x 4-byte little-endian offsets
- Section 1: 65x65 array of bytes (combinations)
- Section 2: 8x4x8x4 array of bytes (materials)
- Section 3: 81 x 8-byte armor info structs
"""

import struct
import sys
from pathlib import Path
import yaml


MATERIAL_VALUES = {
    'wood': 1,
    'leather': 2,
    'bronze': 3,
    'iron': 4,
    'hagane': 5,
    'silver': 6,
    'damascus': 7,
}

MATERIAL_NAMES = ['wood', 'leather', 'bronze', 'iron', 'hagane', 'silver', 'damascus']
ARMOR_TYPE_NAMES = ['helm', 'body', 'leg', 'arm']


def material_str_to_byte(value: str) -> int:
    if value in MATERIAL_VALUES:
        return MATERIAL_VALUES[value]
    return int(value)


def build_armor_syd(yaml_path: str, output_path: str) -> None:
    with open(yaml_path, 'r') as f:
        data = yaml.safe_load(f)

    combinations = data['combinations']
    materials = data['materials']
    armor_info = data['armor_info']

    # --- Section 1: 65x65 bytes ---
    # Row 0 and col 0 are skipped (zeroed), data starts at row 1, col 1
    section1 = bytearray(65 * 65)
    for row in range(1, 65):
        key = f'armor_{row-1:02d}'
        row_data = combinations[key]
        for col in range(1, 65):
            section1[row * 65 + col] = material_str_to_byte(str(row_data[col - 1]))

    # --- Section 2: 8x4x8x4 bytes ---
    # d0=0 block and d2=0 rows are skipped (zeroed)
    section2 = bytearray(8 * 4 * 8 * 4)
    for d0, material_name in enumerate(MATERIAL_NAMES, start=1):
        d0_group = materials[material_name]
        for d1, armor_type in enumerate(ARMOR_TYPE_NAMES):
            d1_group = d0_group[armor_type]
            for d2, material_name_inner in enumerate(MATERIAL_NAMES, start=1):
                d2_list = d1_group[material_name_inner]
                for d3 in range(4):
                    linear_offset = (d0 * 4 * 8 * 4) + (d1 * 8 * 4) + (d2 * 4) + d3
                    section2[linear_offset] = material_str_to_byte(str(d2_list[d3]))

    # --- Section 3: 81 x 8 bytes ---
    # Insert a null element at index 0 to match the original format
    section3 = bytearray(81 * 8)
    for i, entry in enumerate(armor_info, start=1):
        base = i * 8
        section3[base + 0] = struct.pack('b', entry['subId'])[0]
        section3[base + 1] = struct.pack('b', entry['wepId'])[0]
        section3[base + 2] = struct.pack('b', entry['category'])[0]
        section3[base + 3] = struct.pack('b', entry['gemSlots'])[0]
        section3[base + 4] = struct.pack('b', entry['strength'])[0]
        section3[base + 5] = struct.pack('b', entry['intelligence'])[0]
        section3[base + 6] = struct.pack('b', entry['agility'])[0]
        section3[base + 7] = 0  # unk7

    def pad_to_4(data: bytearray) -> bytearray:
        remainder = len(data) % 4
        if remainder:
            data += bytearray(4 - remainder)
        return data

    section1 = pad_to_4(section1)
    section2 = pad_to_4(section2)
    section3 = pad_to_4(section3)

    # Offsets: header is 12 bytes (3 x 4-byte offsets)
    offset1 = 12
    offset2 = offset1 + len(section1)
    offset3 = offset2 + len(section2)

    with open(output_path, 'wb') as f:
        f.write(struct.pack('<I', offset1))
        f.write(struct.pack('<I', offset2))
        f.write(struct.pack('<I', offset3))
        f.write(section1)
        f.write(section2)
        f.write(section3)


if __name__ == '__main__':
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} <input_yaml_file> <output_binary_file>")
        sys.exit(1)

    yaml_file = sys.argv[1]
    output_file = sys.argv[2]

    if not Path(yaml_file).exists():
        print(f"Error: Input file '{yaml_file}' not found", file=sys.stderr)
        sys.exit(1)

    try:
        build_armor_syd(yaml_file, output_file)
    except Exception as e:
        print(f"Error: {e}", file=sys.stderr)
        sys.exit(1)