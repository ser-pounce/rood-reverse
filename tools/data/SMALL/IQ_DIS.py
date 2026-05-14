#!/usr/bin/env python3
"""
dump_tim_with_table.py — Split a binary file into a TIM chain and a 64-entry
metadata table, then dump both.

Layout:
  [0x00000 – 0x10440)  TIM file chain  → PNG(s) in <output_dir>
  [0x10440 – EOF)      64 × 8-byte entries → <output_dir>/<stem>_table.yaml

Each table entry holds four 2-byte little-endian values:
  zoneId  mapId  unk4  unk6

Usage:
  python dump_tim_with_table.py <input> <output_dir>
"""

import struct
import sys
from pathlib import Path

import yaml

from tools.data.SMALL.generic_DIS import dump_file

SPLIT_OFFSET  = 0x10440
TABLE_ENTRIES = 64
ENTRY_FMT     = '<4H'
ENTRY_KEYS    = ('zoneId', 'mapId', 'unk4', 'unk6')
ENTRY_SIZE    = struct.calcsize(ENTRY_FMT)


def dump_table(chunk: bytes, stem: str, output_dir: Path) -> None:
    expected = TABLE_ENTRIES * ENTRY_SIZE
    if len(chunk) < expected:
        raise ValueError(f"Table chunk is {len(chunk)} bytes; need at least {expected}.")

    records = [
        dict(zip(ENTRY_KEYS, (int(v) for v in struct.unpack_from(ENTRY_FMT, chunk, i * ENTRY_SIZE))))
        for i in range(TABLE_ENTRIES)
    ]

    out_path = output_dir / f"{stem}_table.yaml"
    with open(out_path, 'w', encoding='utf-8') as f:
        yaml.dump(records, f, default_flow_style=False, sort_keys=False, allow_unicode=True)

    print(f"  Written: {out_path}  ({len(records)} entries)")


if __name__ == '__main__':
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} <input> <output_dir>")
        sys.exit(1)

    input_path = Path(sys.argv[1])
    output_dir = Path(sys.argv[2])

    if not output_dir.is_dir():
        print(f"Error: output directory does not exist: {output_dir}")
        sys.exit(1)

    data = input_path.read_bytes()
    if len(data) <= SPLIT_OFFSET:
        print(f"Error: file is only {len(data)} bytes; expected more than 0x{SPLIT_OFFSET:X}.")
        sys.exit(1)

    dump_file(input_path, output_dir, data=data[:SPLIT_OFFSET])
    dump_table(data[SPLIT_OFFSET:], input_path.stem, output_dir)