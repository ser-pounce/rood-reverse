#!/usr/bin/env python3
"""
Script to dump a weapon .SYD binary file to YAML format.

The file structure consists of:
- 3 x 4-byte little-endian offsets (pointing to 3 data sections)
- 3 data sections indexed by the offsets

Handles:
- First section: 96x96 array of bytes (output 95x95 without first row/col as "combinations")
- Second section: 5x10x5x10 array of bytes (output skipping material<3 and category=0 as "materials")
- Third section: 96x16 byte structs (output 95, skipping first null element)
"""

import struct
import sys
from pathlib import Path
import yaml


class BlockList(list):
    """A list that should be formatted in block style in YAML."""
    pass


class FlowDict(dict):
    """A dict that should be formatted in flow style in YAML."""
    pass


class FlowListDumper(yaml.Dumper):
    pass


def _represent_list(dumper, data):
    return dumper.represent_sequence('tag:yaml.org,2002:seq', data, flow_style=True)


def _represent_block_list(dumper, data):
    return dumper.represent_sequence('tag:yaml.org,2002:seq', data, flow_style=False)


def _represent_flow_dict(dumper, data):
    return dumper.represent_mapping('tag:yaml.org,2002:map', data, flow_style=True)


FlowListDumper.add_representer(list, _represent_list)
FlowListDumper.add_representer(BlockList, _represent_block_list)
FlowListDumper.add_representer(FlowDict, _represent_flow_dict)


MATERIAL_NAMES = ['bronze', 'iron', 'hagane', 'silver', 'damascus']  # indices 3-7
CATEGORY_NAMES = ['dagger', 'sword', 'greatSword', 'axeMace', 'greatAxe',
                  'staff', 'heavyMace', 'polearm', 'crossbow']  # indices 1-9 (0 skipped)


def parse_syd(binary_file_path: str, output_yaml_path: str) -> None:
    """
    Parse a weapon binary .SYD file and dump to YAML format.

    Args:
        binary_file_path: Path to the input binary file
        output_yaml_path: Path to the output YAML file
    """
    with open(binary_file_path, 'rb') as f:
        data = f.read()

    # Read the three 4-byte little-endian offsets
    offset1 = struct.unpack('<I', data[0:4])[0]
    offset2 = struct.unpack('<I', data[4:8])[0]
    offset3 = struct.unpack('<I', data[8:12])[0]

    # --- Section 1: 96x96 array of bytes ---
    # Skip first row and first column, output 95x95 as raw integers
    combinations = {}
    for row in range(1, 96):
        row_offset = offset1 + (row * 96)
        row_data = [str(data[row_offset + col]) for col in range(1, 96)]
        combinations[f'blade_{row-1:02d}'] = row_data

    # --- Section 2: 5x10x5x10 array of bytes ---
    # Materials 3-7 (bronze-damascus), categories 1-9 (skip category 0)
    # Index formula: (first_material * 500) + (first_category * 50)
    #              + (second_material * 10) + second_category - 1530
    materials = {}
    for d0, mat1_name in enumerate(MATERIAL_NAMES):
        first_material = d0 + 3  # material index 3-7
        d0_group = {}
        for d1, cat1_name in enumerate(CATEGORY_NAMES):
            first_category = d1 + 1  # category index 1-9
            d1_group = {}
            for d2, mat2_name in enumerate(MATERIAL_NAMES):
                second_material = d2 + 3  # material index 3-7
                d2_list = []
                for d3, cat2_name in enumerate(CATEGORY_NAMES):
                    second_category = d3 + 1  # category index 1-9
                    idx = (first_material * 500 + first_category * 50
                           + second_material * 10 + second_category - 1530)
                    byte_value = data[offset2 + idx]
                    if 3 <= byte_value <= 7:
                        d2_list.append(MATERIAL_NAMES[byte_value - 3])
                    else:
                        d2_list.append(str(byte_value))
                d1_group[mat2_name] = d2_list
            d0_group[cat1_name] = d1_group
        materials[mat1_name] = d0_group

    # --- Section 3: 96 x 16 byte structs ---
    # Skip first element (index 0), which is always filled with zeros
    # Layout: subId(1), wepId(1), category(1), damageType(1), costType(1), cost(1),
    #         unk6(1), unk7(1), strength(1), intelligence(1), agility(1), _(1, skipped),
    #         vs_battle_range_t: unk0(1), unk1(1), unk2(1), unk3(1, bitfield)
    blade_info_list = []
    for i in range(1, 96):
        base = offset3 + i * 16
        subId        = struct.unpack("b", data[base:base+1])[0]
        wepId        = struct.unpack("b", data[base+1:base+2])[0]
        category     = struct.unpack("b", data[base+2:base+3])[0]
        damageType   = struct.unpack("b", data[base+3:base+4])[0]
        costType     = struct.unpack("b", data[base+4:base+5])[0]
        cost         = struct.unpack("b", data[base+5:base+6])[0]
        unk6         = struct.unpack("b", data[base+6:base+7])[0]
        unk7         = struct.unpack("b", data[base+7:base+8])[0]
        strength     = struct.unpack("b", data[base+8:base+9])[0]
        intelligence = struct.unpack("b", data[base+9:base+10])[0]
        agility      = struct.unpack("b", data[base+10:base+11])[0]
        # base+11 is _ (padding, skipped)
        r_unk0   = struct.unpack("b", data[base+12:base+13])[0]
        r_unk1   = struct.unpack("b", data[base+13:base+14])[0]
        r_unk2   = struct.unpack("b", data[base+14:base+15])[0]
        r_unk3   = data[base+15]  # raw byte for bitfield extraction
        r_unk3_0 = r_unk3 & 0x07          # lower 3 bits
        r_unk3_3 = (r_unk3 >> 3) & 0x1F   # upper 5 bits

        blade_info_list.append(FlowDict({
            'subId': subId,
            'wepId': wepId,
            'category': category,
            'damageType': damageType,
            'costType': costType,
            'cost': cost,
            'unk6': unk6,
            'unk7': unk7,
            'strength': strength,
            'intelligence': intelligence,
            'agility': agility,
            'range_unk0': r_unk0,
            'range_unk1': r_unk1,
            'range_unk2': r_unk2,
            'range_unk3_0': r_unk3_0,
            'range_unk3_3': r_unk3_3,
        }))

    output_data = {
        'combinations': combinations,
        'materials': materials,
        'blade_info': BlockList(blade_info_list),
    }

    with open(output_yaml_path, 'w') as f:
        yaml.dump(output_data, f, Dumper=FlowListDumper, default_flow_style=False,
                  sort_keys=False, width=float('inf'))


if __name__ == '__main__':
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} <input_binary_file> <output_yaml_file>")
        sys.exit(1)

    input_file = sys.argv[1]
    output_file = sys.argv[2]

    if not Path(input_file).exists():
        print(f"Error: Input file '{input_file}' not found", file=sys.stderr)
        sys.exit(1)

    try:
        parse_syd(input_file, output_file)
    except Exception as e:
        print(f"Error: {e}", file=sys.stderr)
        sys.exit(1)