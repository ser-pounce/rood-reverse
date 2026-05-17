#!/usr/bin/env python3
"""
Script to convert between SHIELD.SYD binary format and YAML.

Usage:
    SHIELD_SYD.py <input.SYD>  <output.yaml>   # decode binary → YAML
    SHIELD_SYD.py <input.yaml> <output.SYD>    # encode YAML → binary

Binary file structure:
- 3 x 4-byte little-endian offsets (pointing to 3 data sections)
- Section 1: 17x17 array of bytes (16x16 combinations, skipping first row/col)
- Section 2: 8x8 array of bytes (7x7 materials, skipping first row/first element)
- Section 3: 17x8 byte structs (16 entries, skipping first null element)
"""

import struct
import sys
from tools.data.MENU.syd_lib import (
    SHIELD_MATERIAL_NAMES,
    byte_to_material, material_str_to_byte,
    BlockList, FlowDict,
    read_offsets, write_syd, dump_yaml, load_yaml,
)


def decode(binary_path: str, yaml_path: str) -> None:
    with open(binary_path, 'rb') as f:
        data = f.read()

    offset1, offset2, offset3 = read_offsets(data)

    # --- Section 1: 17x17 array of bytes ---
    # Skip first row and first column, output 16x16 as "combinations"
    combinations = {}
    for row in range(1, 17):
        row_offset = offset1 + (row * 17)
        row_data = [str(data[row_offset + col]) for col in range(1, 17)]
        combinations[f'shield_{row-1:02d}'] = row_data

    # --- Section 2: 8x8 array of bytes ---
    # Skip first block (d0=0) and first element of each block (d1=0)
    materials = {}
    for d0 in range(1, 8):
        material_name = SHIELD_MATERIAL_NAMES[d0 - 1]
        row_data = [byte_to_material(data[offset2 + d0 * 8 + d1]) for d1 in range(1, 8)]
        materials[material_name] = row_data

    # --- Section 3: 17x8 byte structs ---
    # Skip first element (index 0), which is always filled with zeros
    armor_info_list = []
    for i in range(1, 17):
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

    # --- Section 1: 17x17 bytes ---
    # Row 0 and col 0 are zeroed; data starts at row 1, col 1
    section1 = bytearray(17 * 17)
    for row in range(1, 17):
        key      = f'shield_{row-1:02d}'
        row_data = combinations[key]
        for col in range(1, 17):
            section1[row * 17 + col] = int(row_data[col - 1])

    # --- Section 2: 8x8 bytes ---
    # d0=0 block and d1=0 element of each block are zeroed
    section2 = bytearray(8 * 8)
    for d0, material_name in enumerate(SHIELD_MATERIAL_NAMES, start=1):
        row_data = materials[material_name]
        for d1, value in enumerate(row_data, start=1):
            section2[d0 * 8 + d1] = material_str_to_byte(str(value))

    # --- Section 3: 17 x 8 bytes ---
    # Insert a null element at index 0 to match the original format
    section3 = bytearray(17 * 8)
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
