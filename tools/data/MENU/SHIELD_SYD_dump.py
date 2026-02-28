#!/usr/bin/env python3
"""
Script to dump a binary .SYD file to YAML format.

The file structure consists of:
- 3 x 4-byte little-endian offsets (pointing to 3 data sections)
- 3 data sections indexed by the offsets

Handles:
- First section: 17x17 array of bytes (output 16x16 without first row/col as "combinations")
- Second section: 8x8 array of bytes (output 7x7 without first row/first element as "materials")
- Third section: 17x8 byte structs (output 16, skipping first null element)
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


MATERIAL_NAMES = ['', 'wood', 'leather', 'bronze', 'iron', 'hagane', 'silver', 'damascus']


def byte_to_material(value: int) -> str:
    if 1 <= value <= 7:
        return MATERIAL_NAMES[value]
    return str(value)


def parse_syd(binary_file_path: str, output_yaml_path: str) -> None:
    """
    Parse a binary .SYD file and dump to YAML format.

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

    # --- Section 1: 17x17 array of bytes ---
    # Skip first row and first column, output 16x16 as "combinations"
    combinations = {}
    for row in range(1, 17):
        row_offset = offset1 + (row * 17)
        row_data = [str(data[row_offset + col]) for col in range(1, 17)]
        combinations[f'shield_{row-1:02d}'] = row_data

    # --- Section 2: 8x8 array of bytes ---
    # Skip first block (d0=0) and first element of each block (d1=0)
    # Output as material -> [7 result material values]
    materials = {}
    for d0 in range(1, 8):
        material_name = MATERIAL_NAMES[d0]
        row_data = [byte_to_material(data[offset2 + d0 * 8 + d1]) for d1 in range(1, 8)]
        materials[material_name] = row_data

    # --- Section 3: 17x8 byte structs ---
    # Skip first element (index 0), which is always filled with zeros
    armor_info_list = []
    for i in range(1, 17):
        info_offset = offset3 + (i * 8)
        subId        = struct.unpack('b', data[info_offset:info_offset+1])[0]
        wepId        = struct.unpack('b', data[info_offset+1:info_offset+2])[0]
        category     = struct.unpack('b', data[info_offset+2:info_offset+3])[0]
        gemSlots     = struct.unpack('b', data[info_offset+3:info_offset+4])[0]
        strength     = struct.unpack('b', data[info_offset+4:info_offset+5])[0]
        intelligence = struct.unpack('b', data[info_offset+5:info_offset+6])[0]
        agility      = struct.unpack('b', data[info_offset+6:info_offset+7])[0]
        # unk7 is skipped

        armor_info_list.append(FlowDict({
            'subId': subId,
            'wepId': wepId,
            'category': category,
            'gemSlots': gemSlots,
            'strength': strength,
            'intelligence': intelligence,
            'agility': agility,
        }))

    output_data = {
        'combinations': combinations,
        'materials': materials,
        'armor_info': BlockList(armor_info_list),
    }

    with open(output_yaml_path, 'w') as f:
        yaml.dump(output_data, f, Dumper=FlowListDumper, default_flow_style=False, sort_keys=False, width=float('inf'))


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