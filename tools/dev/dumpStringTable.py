import sys
import struct
from tools.etc.vsString import decode


if len(sys.argv) != 3:
    print("Usage: python dumpStringTable.py <binary_file> <table_offset>")
    sys.exit(1)

bin_path = sys.argv[1]
table_offset = int(sys.argv[2], 0)

with open(bin_path, "rb") as f:
    # Read string count (2-byte little endian)
    f.seek(table_offset)
    string_count = struct.unpack("<H", f.read(2))[0]
    
    # Read string offsets
    string_offsets = [string_count]  # First offset is the count itself
    for _ in range(string_count - 1):  # Read one less offset since we have the first one
        offset = struct.unpack("<H", f.read(2))[0]
        string_offsets.append(offset)
    
    # Get total file size
    f.seek(0, 2)  # Seek to end of file
    file_size = f.tell()
    
    # Read and decode strings
    for i in range(string_count):
        offset = string_offsets[i]
        start_pos = table_offset + (offset * 2)
        f.seek(start_pos)
        string_data = f.read(file_size - start_pos)  # Read to end of file
        decoded = decode(string_data)
        print(f"[{i:3d}] [0x{offset:04x}] {decoded}")
