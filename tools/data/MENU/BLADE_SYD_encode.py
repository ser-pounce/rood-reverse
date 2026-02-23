#!/usr/bin/env python3
"""
Script to convert YAML format back to a blade .SYD binary file.

Inverse of dump_weapon_syd.py. Takes a YAML file produced by that script
and reconstructs the original binary format:
- 3 x 4-byte little-endian offsets
- Section 1: 96x96 array of bytes (combinations)
- Section 2: 5x10x5x10 array of bytes (materials)
- Section 3: 96 x 16-byte blade info structs
"""

import struct
import sys
from pathlib import Path
import yaml


MATERIAL_VALUES = {
    'bronze': 3,
    'iron': 4,
    'hagane': 5,
    'silver': 6,
    'damascus': 7,
}

MATERIAL_NAMES = ['bronze', 'iron', 'hagane', 'silver', 'damascus']  # indices 3-7
CATEGORY_NAMES = ['dagger', 'sword', 'greatSword', 'axeMace', 'greatAxe',
                  'staff', 'heavyMace', 'polearm', 'crossbow']  # indices 1-9


def material_str_to_byte(value: str) -> int:
    if value in MATERIAL_VALUES:
        return MATERIAL_VALUES[value]
    return int(value)


def pad_to_4(data: bytearray) -> bytearray:
    remainder = len(data) % 4
    if remainder:
        data += bytearray(4 - remainder)
    return data


def build_blade_syd(yaml_path: str, output_path: str) -> None:
    with open(yaml_path, 'r') as f:
        data = yaml.safe_load(f)

    combinations = data['combinations']
    materials = data['materials']
    blade_info = data['blade_info']

    # --- Section 1: 96x96 bytes ---
    # Row 0 and col 0 are zeroed; data starts at row 1, col 1
    section1 = bytearray(96 * 96)
    for row in range(1, 96):
        key = f'blade_{row-1:02d}'
        row_data = combinations[key]
        for col in range(1, 96):
            section1[row * 96 + col] = int(row_data[col - 1])

    # --- Section 2: 5x10x5x10 bytes ---
    # Full array is 2500 bytes; indexed via:
    # (first_material * 500) + (first_category * 50) + (second_material * 10) + second_category - 1530
    # Materials 3-7 (bronze-damascus), categories 1-9 (category 0 is skipped/zeroed)
    section2 = bytearray(2500)
    for d0, mat1_name in enumerate(MATERIAL_NAMES):
        first_material = d0 + 3
        d0_group = materials[mat1_name]
        for d1, cat1_name in enumerate(CATEGORY_NAMES):
            first_category = d1 + 1
            d1_group = d0_group[cat1_name]
            for d2, mat2_name in enumerate(MATERIAL_NAMES):
                second_material = d2 + 3
                d2_list = d1_group[mat2_name]
                for d3, value in enumerate(d2_list):
                    second_category = d3 + 1
                    idx = (first_material * 500 + first_category * 50
                           + second_material * 10 + second_category - 1530)
                    section2[idx] = material_str_to_byte(str(value))

    # --- Section 3: 96 x 16 bytes ---
    # Insert a null element at index 0 to match the original format
    # Layout: subId(1), wepId(1), category(1), damageType(1), costType(1), cost(1),
    #         unk6(1), unk7(1), strength(1), intelligence(1), agility(1), _(1, zero),
    #         vs_battle_range_t: unk0(1), unk1(1), unk2(1), unk3(1, bitfield)
    section3 = bytearray(96 * 16)
    for i, entry in enumerate(blade_info, start=1):
        base = i * 16
        section3[base + 0]  = struct.pack('b', entry['subId'])[0]
        section3[base + 1]  = struct.pack('b', entry['wepId'])[0]
        section3[base + 2]  = struct.pack('b', entry['category'])[0]
        section3[base + 3]  = struct.pack('b', entry['damageType'])[0]
        section3[base + 4]  = struct.pack('b', entry['costType'])[0]
        section3[base + 5]  = struct.pack('b', entry['cost'])[0]
        section3[base + 6]  = struct.pack('b', entry['unk6'])[0]
        section3[base + 7]  = struct.pack('b', entry['unk7'])[0]
        section3[base + 8]  = struct.pack('b', entry['strength'])[0]
        section3[base + 9]  = struct.pack('b', entry['intelligence'])[0]
        section3[base + 10] = struct.pack('b', entry['agility'])[0]
        section3[base + 11] = 0  # _ (padding)
        section3[base + 12] = struct.pack('b', entry['range_unk0'])[0]
        section3[base + 13] = struct.pack('b', entry['range_unk1'])[0]
        section3[base + 14] = struct.pack('b', entry['range_unk2'])[0]
        # Reconstruct bitfield byte: unk3_0 in lower 3 bits, unk3_3 in upper 5 bits
        unk3 = (entry['range_unk3_0'] & 0x07) | ((entry['range_unk3_3'] & 0x1F) << 3)
        section3[base + 15] = unk3

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

    print(f"Successfully wrote binary to {output_path}")


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
        build_blade_syd(yaml_file, output_file)
    except Exception as e:
        print(f"Error: {e}", file=sys.stderr)
        sys.exit(1)