
#!/usr/bin/env python3
"""
Dump fixed-length strings from a binary file using the project's decode() function.

This script is a minimal sibling of dumpStringTable.py. It reads the file from
offset 0 and splits it into records of `length` bytes, decodes each record
using tools.etc.vsString.decode, and prints them. An optional third argument
`debug` enables a debug-style output similar to the original script.

Usage:
  dumpFixedLenStrings.py <binary_file> <length> [debug]

Examples:
  ./dumpFixedLenStrings.py data.bin 32
  ./dumpFixedLenStrings.py data.bin 24 debug
"""

import sys
from pathlib import Path
from tools.etc.vsString import decode


def main():
    if len(sys.argv) < 3 or len(sys.argv) > 4:
        print("Usage: python dumpFixedLenStrings.py <binary_file> <length> [debug]")
        sys.exit(1)

    bin_path = Path(sys.argv[1])
    try:
        record_length = int(sys.argv[2], 0)
    except ValueError:
        print("Error: length must be an integer", file=sys.stderr)
        sys.exit(2)

    debug_mode = len(sys.argv) == 4 and sys.argv[3] == "debug"

    if record_length <= 0:
        print('Error: length must be a positive integer', file=sys.stderr)
        sys.exit(2)

    if not bin_path.exists():
        print(f'Error: file not found: {bin_path}', file=sys.stderr)
        sys.exit(2)

    with bin_path.open('rb') as f:
        idx = 0
        while True:
            start_pos = f.tell()
            chunk = f.read(record_length)
            if not chunk:
                break

            # Use the project's decode function directly (same behavior as dumpStringTable.py)
            decoded = decode(chunk)

            if debug_mode:
                print(f"[{idx:3d}] [0x{start_pos:04x}] {decoded}")
            else:
                print(f"line{idx}: {decoded}")

            idx += 1


if __name__ == '__main__':
    main()

