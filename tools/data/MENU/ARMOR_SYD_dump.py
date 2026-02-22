#!/usr/bin/env python3
"""
Script to dump ARMOR.SYD binary file to YAML format.

The file structure consists of:
- 3 x 4-byte little-endian offsets (pointing to 3 data sections)
- 3 data sections indexed by the offsets

Currently handles:
- First section: 65x65 array of bytes (output 64x64 without first row/col as "combinations")
- Second section: 8x4x8x4 array of bytes (output as "materials")
- Third section: 81x8 armor info structures (output 80, skipping first zero element)
"""

import struct
import sys
from pathlib import Path
import yaml


class BlockList(list):
    """A list that should be formatted in block style in YAML."""
    pass


def parse_armor_syd(binary_file_path: str, output_yaml_path: str) -> None:
    """
    Parse a binary ARMOR.SYD file and dump to YAML format.
    
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
    
    # Parse the first section (65x65 array of bytes), skip first row and first column
    material_names = ['wood', 'leather', 'bronze', 'iron', 'hagane', 'silver', 'damascus']
    material_values = ['', 'wood', 'leather', 'bronze', 'iron', 'hagane', 'silver', 'damascus']
    
    combinations = {}
    for row in range(1, 65):  # Start from row 1, read 64 rows
        row_offset = offset1 + (row * 65)
        row_data = []
        for col in range(1, 65):  # Start from col 1, read 64 columns
            byte_value = data[row_offset + col]
            # Convert numeric material value to material name
            if 1 <= byte_value <= 7:
                row_data.append(material_values[byte_value])
            else:
                row_data.append(str(byte_value))
        combinations[f'armor_{row-1:02d}'] = row_data
    
    # Parse the second section (8x4x8x4 array of bytes)
    # Skip first d0 block and first d2 row
    material_names = ['wood', 'leather', 'bronze', 'iron', 'hagane', 'silver', 'damascus']
    armor_type_names = ['helm', 'body', 'leg', 'arm']
    
    materials = {}
    for d0 in range(1, 8):  # Start from d0=1, skip d0=0
        material_name = material_names[d0 - 1]
        d0_group = {}
        for d1 in range(4):
            armor_type_name = armor_type_names[d1]
            d1_group = {}
            for d2 in range(1, 8):  # Start from d2=1, skip d2=0
                material_name_inner = material_names[d2 - 1]
                d2_list = []
                for d3 in range(4):
                    linear_offset = offset2 + (d0 * 4 * 8 * 4) + (d1 * 8 * 4) + (d2 * 4) + d3
                    byte_value = data[linear_offset]
                    # Convert numeric material value to material name
                    if 1 <= byte_value <= 7:
                        d2_list.append(material_values[byte_value])
                    else:
                        d2_list.append(str(byte_value))
                d1_group[material_name_inner] = d2_list
            d0_group[armor_type_name] = d1_group
        materials[material_name] = d0_group
    
    # Parse the third section (81 armor info structures, 8 bytes each)
    # Skip first element (index 0), which is always filled with zeros
    armor_info_list = []
    for i in range(1, 81):
        info_offset = offset3 + (i * 8)
        subId = struct.unpack('b', data[info_offset:info_offset+1])[0]
        wepId = struct.unpack('b', data[info_offset+1:info_offset+2])[0]
        category = struct.unpack('b', data[info_offset+2:info_offset+3])[0]
        gemSlots = struct.unpack('b', data[info_offset+3:info_offset+4])[0]
        strength = struct.unpack('b', data[info_offset+4:info_offset+5])[0]
        intelligence = struct.unpack('b', data[info_offset+5:info_offset+6])[0]
        agility = struct.unpack('b', data[info_offset+6:info_offset+7])[0]
        # unk7 is skipped
        
        armor_info_list.append(FlowDict({
            'subId': subId,
            'wepId': wepId,
            'category': category,
            'gemSlots': gemSlots,
            'strength': strength,
            'intelligence': intelligence,
            'agility': agility
        }))
    
    armor_info = BlockList(armor_info_list)
    
    # Write to YAML format using yaml library with flow style for lists
    output_data = {
        'combinations': combinations,
        'materials': materials,
        'armor_info': armor_info
    }
    
    with open(output_yaml_path, 'w') as f:
        yaml.dump(output_data, f, Dumper=FlowListDumper, default_flow_style=False, sort_keys=False, width=float('inf'))


class FlowListDumper(yaml.Dumper):
    pass


class FlowDict(dict):
    """A dict that should be formatted in flow style in YAML."""
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
        parse_armor_syd(input_file, output_file)
        print(f"Successfully dumped {input_file} to {output_file}")
    except Exception as e:
        print(f"Error: {e}", file=sys.stderr)
        sys.exit(1)