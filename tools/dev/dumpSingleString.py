#!/usr/bin/env python3
import sys
import struct
import argparse
from tools.etc.vsString import decode

parser = argparse.ArgumentParser(description="Decode a single string from a binary using file, offset, and length.")
parser.add_argument("file", help="Path to binary file")
parser.add_argument("offset", help="Byte offset into file (decimal or 0x hex)")
parser.add_argument("length", help="Number of bytes to read (decimal or 0x hex)")
parser.add_argument("-d", "--debug", action="store_true", help="Debug output")
args = parser.parse_args()

try:
    offset = int(args.offset, 0)
    length = int(args.length, 0)
except ValueError:
    print("Error: offset and length must be integers (decimal or 0x... hex)")
    sys.exit(1)

with open(args.file, "rb") as f:
    f.seek(0, 2)
    file_size = f.tell()

    if offset < 0 or offset >= file_size:
        print(f"Error: offset {offset} out of range (file size {file_size})")
        sys.exit(1)

    if length < 0 or offset + length > file_size:
        print(f"Error: length {length} out of range (offset+length > file size)")
        sys.exit(1)

    f.seek(offset)
    data = f.read(length)

    decoded = decode(data)

    if args.debug:
        print(f"Offset: 0x{offset:08x} ({offset})")
        print(f"Length: {length}")
        print(f"Raw bytes: {data!r}")
        print(f"Decoded: {decoded}")
    else:
        print(decoded)
