#!/usr/bin/env python3
"""
Shared utilities for dumping and encoding .SYD binary files.

Provides:
- YAML formatting helpers (BlockList, FlowDict, FlowListDumper)
- Material/category name constants and conversion functions
- Binary helpers (pad_to_4)
"""

import struct
from pathlib import Path
import yaml


# ---------------------------------------------------------------------------
# Material and category constants
# ---------------------------------------------------------------------------

# All materials in index order (index 1-7); index 0 is empty/unused
ALL_MATERIAL_NAMES = ['', 'wood', 'leather', 'bronze', 'iron', 'hagane', 'silver', 'damascus']

# Subsets used by different file types
ARMOR_MATERIAL_NAMES  = ['wood', 'leather', 'bronze', 'iron', 'hagane', 'silver', 'damascus']  # indices 1-7
BLADE_MATERIAL_NAMES  = ['bronze', 'iron', 'hagane', 'silver', 'damascus']                      # indices 3-7
SHIELD_MATERIAL_NAMES = ARMOR_MATERIAL_NAMES

ARMOR_TYPE_NAMES = ['helm', 'body', 'leg', 'arm']

BLADE_CATEGORY_NAMES = [
    'dagger', 'sword', 'greatSword', 'axeMace', 'greatAxe',
    'staff', 'heavyMace', 'polearm', 'crossbow',
]  # indices 1-9 (0 is skipped)

# Numeric values keyed by material name
MATERIAL_VALUES: dict[str, int] = {name: i for i, name in enumerate(ALL_MATERIAL_NAMES) if name}


# ---------------------------------------------------------------------------
# Conversion helpers
# ---------------------------------------------------------------------------

def byte_to_material(value: int) -> str:
    """Convert a material byte (1-7) to its name, or return the raw int string."""
    if 1 <= value <= 7:
        return ALL_MATERIAL_NAMES[value]
    return str(value)


def material_str_to_byte(value: str) -> int:
    """Convert a material name or numeric string to its byte value."""
    if value in MATERIAL_VALUES:
        return MATERIAL_VALUES[value]
    return int(value)


# ---------------------------------------------------------------------------
# Binary helpers
# ---------------------------------------------------------------------------

def pad_to_4(data: bytearray) -> bytearray:
    """Pad a bytearray to the next 4-byte boundary."""
    remainder = len(data) % 4
    if remainder:
        data += bytearray(4 - remainder)
    return data


def read_offsets(data: bytes) -> tuple[int, int, int]:
    """Read the three 4-byte little-endian section offsets from the file header."""
    offset1 = struct.unpack('<I', data[0:4])[0]
    offset2 = struct.unpack('<I', data[4:8])[0]
    offset3 = struct.unpack('<I', data[8:12])[0]
    return offset1, offset2, offset3


def write_syd(output_path: str, section1: bytearray, section2: bytearray, section3: bytearray) -> None:
    """
    Write three sections to a .SYD file with a 12-byte offset header.

    Each section is padded to a 4-byte boundary before writing.
    """
    section1 = pad_to_4(section1)
    section2 = pad_to_4(section2)
    section3 = pad_to_4(section3)

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


# ---------------------------------------------------------------------------
# YAML formatting helpers
# ---------------------------------------------------------------------------

class BlockList(list):
    """A list serialised in YAML block style (one item per line)."""
    pass


class FlowDict(dict):
    """A dict serialised in YAML flow style (all on one line)."""
    pass


class FlowListDumper(yaml.Dumper):
    """
    Custom YAML dumper:
    - plain list  → flow style  (all on one line)
    - BlockList   → block style (one item per line)
    - FlowDict    → flow style  (all on one line)
    """
    pass


def _represent_list(dumper, data):
    return dumper.represent_sequence('tag:yaml.org,2002:seq', data, flow_style=True)


def _represent_block_list(dumper, data):
    return dumper.represent_sequence('tag:yaml.org,2002:seq', data, flow_style=False)


def _represent_flow_dict(dumper, data):
    return dumper.represent_mapping('tag:yaml.org,2002:map', data, flow_style=True)


FlowListDumper.add_representer(list,      _represent_list)
FlowListDumper.add_representer(BlockList, _represent_block_list)
FlowListDumper.add_representer(FlowDict,  _represent_flow_dict)


def dump_yaml(output_path: str, data: dict) -> None:
    """Write *data* to *output_path* using FlowListDumper."""
    with open(output_path, 'w') as f:
        yaml.dump(data, f, Dumper=FlowListDumper,
                  default_flow_style=False, sort_keys=False, width=float('inf'))


def load_yaml(yaml_path: str) -> dict:
    """Load a YAML file produced by one of the dump scripts."""
    with open(yaml_path, 'r') as f:
        return yaml.safe_load(f)


# ---------------------------------------------------------------------------
# CLI argument handling
# ---------------------------------------------------------------------------

def parse_two_args(argv: list[str], usage: str) -> tuple[str, str]:
    """
    Expect exactly two positional arguments (input, output).

    Prints *usage* and exits with code 1 if the count is wrong or the
    input file does not exist.
    """
    import sys
    if len(argv) != 3:
        print(f"Usage: {argv[0]} {usage}")
        sys.exit(1)
    input_file, output_file = argv[1], argv[2]
    if not Path(input_file).exists():
        print(f"Error: Input file '{input_file}' not found", file=sys.stderr)
        sys.exit(1)
    return input_file, output_file
