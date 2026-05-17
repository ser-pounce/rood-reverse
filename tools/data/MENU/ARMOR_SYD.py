#!/usr/bin/env python3
"""
Script to convert between ARMOR.SYD binary format and YAML.

Usage:
    ARMOR_SYD.py <input.SYD>  <output.yaml>   # decode binary → YAML
    ARMOR_SYD.py <input.yaml> <output.SYD>    # encode YAML → binary

Binary file structure:
- 3 x 4-byte little-endian offsets (pointing to 3 data sections)
- Section 1: 65x65 array of bytes (64x64 combinations, skipping first row/col)
- Section 2: 8x4x8x4 array of bytes (materials)
- Section 3: 81x8 armor info structs (80 entries, skipping first zero element)
"""

import struct
import sys
from tools.data.MENU.syd_lib import (
    ARMOR_MATERIAL_NAMES, ARMOR_TYPE_NAMES,
    byte_to_material, material_str_to_byte,
    BlockList, FlowDict,
    read_offsets, write_syd, dump_yaml, load_yaml,
)


def decode(binary_path: str, yaml_path: str) -> None:
    with open(binary_path, 'rb') as f:
        data = f.read()

    offset1, offset2, offset3 = read_offsets(data)

    # --- Section 1: 65x65 array of bytes ---
    # Skip first row and first column, output 64x64 as "combinations"
    combinations = {}
    for row in range(1, 65):
        row_offset = offset1 + (row * 65)
        row_data = [byte_to_material(data[row_offset + col]) for col in range(1, 65)]
        combinations[f'armor_{row-1:02d}'] = row_data

    # --- Section 2: 8x4x8x4 array of bytes ---
    # Skip d0=0 block and d2=0 rows
    materials = {}
    for d0 in range(1, 8):
        material_name = ARMOR_MATERIAL_NAMES[d0 - 1]
        d0_group = {}
        for d1 in range(4):
            armor_type_name = ARMOR_TYPE_NAMES[d1]
            d1_group = {}
            for d2 in range(1, 8):
                material_name_inner = ARMOR_MATERIAL_NAMES[d2 - 1]
                d2_list = []
                for d3 in range(4):
                    linear_offset = offset2 + (d0 * 4 * 8 * 4) + (d1 * 8 * 4) + (d2 * 4) + d3
                    d2_list.append(byte_to_material(data[linear_offset]))
                d1_group[material_name_inner] = d2_list
            d0_group[armor_type_name] = d1_group
        materials[material_name] = d0_group

    # --- Section 3: 81x8 armor info structs ---
    # Skip first element (index 0), which is always filled with zeros
    armor_info_list = []
    for i in range(1, 81):
        info_offset = offset3 + (i * 8)
        armor_info_list.append(FlowDict({
            'subId':        struct.unpack('b', data[info_offset:info_offset+1])[0],
            'wepId':        struct.unpack('b', data[info_offset+1:info_offset+2])[0],
            'category':     struct.unpack('b', data[info_offset+2:info_offset+3])[0],
            'gemSlots':     struct.unpack('b', data[info_offset+3:info_offset+4])[0],
            'strength':     struct.unpack('b', data[info_offset+4:info_offset+5])[0],
            'intelligence': struct.unpack('b', data[info_offset+5:info_offset+6])[0],
            'agility':      struct.unpack('b', data[info_offset+6:info_offset+7])[0],
            # unk7 is skipped
        }))

    dump_yaml(yaml_path, {
        'combinations': combinations,
        'materials':    materials,
        'armor_info':   BlockList(armor_info_list),
    })


def encode(yaml_path: str, binary_path: str) -> None:
    data = load_yaml(yaml_path)

    combinations = data['combinations']
    materials    = data['materials']
    armor_info   = data['armor_info']

    # --- Section 1: 65x65 bytes ---
    # Row 0 and col 0 are zeroed; data starts at row 1, col 1
    section1 = bytearray(65 * 65)
    for row in range(1, 65):
        key      = f'armor_{row-1:02d}'
        row_data = combinations[key]
        for col in range(1, 65):
            section1[row * 65 + col] = material_str_to_byte(str(row_data[col - 1]))

    # --- Section 2: 8x4x8x4 bytes ---
    # d0=0 block and d2=0 rows are zeroed
    section2 = bytearray(8 * 4 * 8 * 4)
    for d0, material_name in enumerate(ARMOR_MATERIAL_NAMES, start=1):
        d0_group = materials[material_name]
        for d1, armor_type in enumerate(ARMOR_TYPE_NAMES):
            d1_group = d0_group[armor_type]
            for d2, material_name_inner in enumerate(ARMOR_MATERIAL_NAMES, start=1):
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

    write_syd(binary_path, section1, section2, section3)


if __name__ == '__main__':
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} <input.SYD> <output.yaml>")
        print(f"       {sys.argv[0]} <input.yaml> <output.SYD>")
        sys.exit(1)

    input_file, output_file = sys.argv[1], sys.argv[2]

    try:
        if input_file.upper().endswith('.SYD'):
            decode(input_file, output_file)
        elif input_file.lower().endswith('.yaml'):
            encode(input_file, output_file)
        else:
            print(f"Error: cannot determine mode from input filename '{input_file}' (expected *.SYD or *.yaml)", file=sys.stderr)
            sys.exit(1)
    except Exception as e:
        print(f"Error: {e}", file=sys.stderr)
        sys.exit(1)
