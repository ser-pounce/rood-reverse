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

            decoded = decode(chunk)

            if debug_mode:
                print(f"[{idx:3d}] [0x{start_pos:04x}] {decoded}")
            else:
                print(f"line{idx}: {decoded}")

            idx += 1


if __name__ == '__main__':
    main()

