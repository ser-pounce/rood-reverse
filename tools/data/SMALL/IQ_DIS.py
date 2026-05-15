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

from tools.data.SMALL.generic_DIS import dump_file, encode_tim_from_png

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


def encode_table(table_path: Path) -> bytes:
    """Encode a YAML table file to binary."""
    with open(table_path, 'r', encoding='utf-8') as f:
        records = yaml.safe_load(f)
    
    if not isinstance(records, list) or len(records) != TABLE_ENTRIES:
        raise ValueError(f"Table must have exactly {TABLE_ENTRIES} entries, got {len(records) if isinstance(records, list) else 'not a list'}")
    
    table_bytes = bytearray()
    for record in records:
        values = tuple(record.get(k, 0) for k in ENTRY_KEYS)
        table_bytes.extend(struct.pack(ENTRY_FMT, *values))
    
    return bytes(table_bytes)


def encode_iq(input_dir: Path, output_path: Path) -> None:
    """Encode PNGs and table YAML back to IQ file."""
    # Find PNG files
    png_files = sorted(input_dir.glob('*.png'))
    if not png_files:
        raise ValueError(f"No PNG files found in {input_dir}")
    
    # Encode TIM chain
    tim_data = b''
    for png_file in png_files:
        tim_bytes = encode_tim_from_png(png_file)
        tim_data += tim_bytes
    
    # Find and encode table
    table_file = None
    for f in input_dir.glob('*_table.yaml'):
        table_file = f
        break
    
    if table_file is None:
        raise ValueError(f"No *_table.yaml found in {input_dir}")
    
    table_data = encode_table(table_file)
    
    # Write IQ file
    output_path.write_bytes(tim_data + table_data)


if __name__ == '__main__':
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} <input> <output>")
        print("  If input is .IQ, output is directory for PNGs + YAML table")
        print("  If input is a directory, output is .IQ file (stitched from PNGs + YAML)")
        sys.exit(1)

    input_path = Path(sys.argv[1])
    output_path = Path(sys.argv[2])

    if input_path.suffix.lower() == '.iq' or (not input_path.is_dir() and not input_path.suffix.lower() == '.png'):
        # IQ to PNGs + YAML
        data = input_path.read_bytes()
        if len(data) <= SPLIT_OFFSET:
            print(f"Error: file is only {len(data)} bytes; expected more than 0x{SPLIT_OFFSET:X}.")
            sys.exit(1)
        
        if not output_path.exists():
            output_path.mkdir(parents=True, exist_ok=True)
        elif not output_path.is_dir():
            print(f"Error: output must be a directory for IQ dump: {output_path}")
            sys.exit(1)
        
        dump_file(input_path, output_path, data=data[:SPLIT_OFFSET])
        dump_table(data[SPLIT_OFFSET:], input_path.stem, output_path)
    elif input_path.is_dir():
        # PNGs + YAML to IQ
        encode_iq(input_path, output_path)
    else:
        print(f"Error: unsupported input type: {input_path}")
        sys.exit(1)