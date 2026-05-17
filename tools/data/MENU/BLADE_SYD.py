#!/usr/bin/env python3
"""
Script to convert between BLADE.SYD binary format and YAML.

Usage:
    BLADE_SYD.py <input.SYD>  <output.yaml>   # decode binary → YAML
    BLADE_SYD.py <input.yaml> <output.SYD>    # encode YAML → binary

Binary file structure:
- 3 x 4-byte little-endian offsets (pointing to 3 data sections)
- Section 1: 96x96 array of bytes (95x95 combinations, skipping first row/col)
- Section 2: 5x10x5x10 array of bytes (materials, skipping material<3 and category=0)
- Section 3: 96x16 byte structs (95 entries, skipping first null element)
"""

import struct
import sys
from tools.data.MENU.syd_lib import (
    BLADE_MATERIAL_NAMES, BLADE_CATEGORY_NAMES,
    material_str_to_byte,
    BlockList, FlowDict,
    read_offsets, write_syd, dump_yaml, load_yaml,
)


def decode(binary_path: str, yaml_path: str) -> None:
    with open(binary_path, 'rb') as f:
        data = f.read()

    offset1, offset2, offset3 = read_offsets(data)

    # --- Section 1: 96x96 array of bytes ---
    # Skip first row and first column, output 95x95 as raw integers
    combinations = {}
    for row in range(1, 96):
        row_offset = offset1 + (row * 96)
        row_data = [str(data[row_offset + col]) for col in range(1, 96)]
        combinations[f'blade_{row-1:02d}'] = row_data

    # --- Section 2: 5x10x5x10 array of bytes ---
    # Materials 3-7 (bronze-damascus), categories 1-9 (skip category 0)
    # Index: (first_material*500) + (first_category*50) + (second_material*10) + second_category - 1530
    materials = {}
    for d0, mat1_name in enumerate(BLADE_MATERIAL_NAMES):
        first_material = d0 + 3
        d0_group = {}
        for d1, cat1_name in enumerate(BLADE_CATEGORY_NAMES):
            first_category = d1 + 1
            d1_group = {}
            for d2, mat2_name in enumerate(BLADE_MATERIAL_NAMES):
                second_material = d2 + 3
                d2_list = []
                for d3 in range(len(BLADE_CATEGORY_NAMES)):
                    second_category = d3 + 1
                    idx = (first_material * 500 + first_category * 50
                           + second_material * 10 + second_category - 1530)
                    byte_value = data[offset2 + idx]
                    if 3 <= byte_value <= 7:
                        d2_list.append(BLADE_MATERIAL_NAMES[byte_value - 3])
                    else:
                        d2_list.append(str(byte_value))
                d1_group[mat2_name] = d2_list
            d0_group[cat1_name] = d1_group
        materials[mat1_name] = d0_group

    # --- Section 3: 96x16 byte structs ---
    # Skip first element (index 0), which is always filled with zeros
    blade_info_list = []
    for i in range(1, 96):
        base   = offset3 + i * 16
        r_unk3 = data[base + 15]
        blade_info_list.append(FlowDict({
            'subId':        struct.unpack('b', data[base:base+1])[0],
            'wepId':        struct.unpack('b', data[base+1:base+2])[0],
            'category':     struct.unpack('b', data[base+2:base+3])[0],
            'damageType':   struct.unpack('b', data[base+3:base+4])[0],
            'costType':     struct.unpack('b', data[base+4:base+5])[0],
            'cost':         struct.unpack('b', data[base+5:base+6])[0],
            'unk6':         struct.unpack('b', data[base+6:base+7])[0],
            'unk7':         struct.unpack('b', data[base+7:base+8])[0],
            'strength':     struct.unpack('b', data[base+8:base+9])[0],
            'intelligence': struct.unpack('b', data[base+9:base+10])[0],
            'agility':      struct.unpack('b', data[base+10:base+11])[0],
            # base+11 is padding, skipped
            'range_unk0':   struct.unpack('b', data[base+12:base+13])[0],
            'range_unk1':   struct.unpack('b', data[base+13:base+14])[0],
            'range_unk2':   struct.unpack('b', data[base+14:base+15])[0],
            'range_unk3_0': r_unk3 & 0x07,         # lower 3 bits
            'range_unk3_3': (r_unk3 >> 3) & 0x1F,  # upper 5 bits
        }))

    dump_yaml(yaml_path, {
        'combinations': combinations,
        'materials':    materials,
        'blade_info':   BlockList(blade_info_list),
    })


def encode(yaml_path: str, binary_path: str) -> None:
    data = load_yaml(yaml_path)

    combinations = data['combinations']
    materials    = data['materials']
    blade_info   = data['blade_info']

    # --- Section 1: 96x96 bytes ---
    # Row 0 and col 0 are zeroed; data starts at row 1, col 1
    section1 = bytearray(96 * 96)
    for row in range(1, 96):
        key      = f'blade_{row-1:02d}'
        row_data = combinations[key]
        for col in range(1, 96):
            section1[row * 96 + col] = int(row_data[col - 1])

    # --- Section 2: 5x10x5x10 bytes (2500 total) ---
    # Index: (first_material*500) + (first_category*50) + (second_material*10) + second_category - 1530
    section2 = bytearray(2500)
    for d0, mat1_name in enumerate(BLADE_MATERIAL_NAMES):
        first_material = d0 + 3
        d0_group = materials[mat1_name]
        for d1, cat1_name in enumerate(BLADE_CATEGORY_NAMES):
            first_category = d1 + 1
            d1_group = d0_group[cat1_name]
            for d2, mat2_name in enumerate(BLADE_MATERIAL_NAMES):
                second_material = d2 + 3
                d2_list = d1_group[mat2_name]
                for d3, value in enumerate(d2_list):
                    second_category = d3 + 1
                    idx = (first_material * 500 + first_category * 50
                           + second_material * 10 + second_category - 1530)
                    section2[idx] = material_str_to_byte(str(value))

    # --- Section 3: 96 x 16 bytes ---
    # Insert a null element at index 0 to match the original format
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
        section3[base + 11] = 0  # padding
        section3[base + 12] = struct.pack('b', entry['range_unk0'])[0]
        section3[base + 13] = struct.pack('b', entry['range_unk1'])[0]
        section3[base + 14] = struct.pack('b', entry['range_unk2'])[0]
        # Reconstruct bitfield: unk3_0 in lower 3 bits, unk3_3 in upper 5 bits
        section3[base + 15] = (entry['range_unk3_0'] & 0x07) | ((entry['range_unk3_3'] & 0x1F) << 3)

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
