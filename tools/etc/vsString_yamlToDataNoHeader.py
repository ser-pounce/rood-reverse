import sys
from pathlib import Path
from tools.etc.vsString_yaml import *


def main():
    if len(sys.argv) < 4:
        print(f"Usage: python {sys.argv[0]} <path_to_yaml> <output_data> <length>")
        sys.exit(1)

    yaml_path = Path(sys.argv[1])
    data_path = Path(sys.argv[2])

    try:
        target_len = int(sys.argv[3], 0)
    except ValueError:
        print("Error: length must be an integer", file=sys.stderr)
        sys.exit(2)

    if target_len <= 0:
        print("Error: length must be positive", file=sys.stderr)
        sys.exit(2)

    strings, _, _, _ = read_yaml(yaml_path, 0)

    padded = []
    for i, s in enumerate(strings):
        blen = len(s)
        if blen > target_len:
            print(f"Error: encoded string {i} is {blen} bytes, larger than target {target_len}", file=sys.stderr)
            sys.exit(3)
        if blen < target_len:
            padded.append(s + b"\x00" * (target_len - blen))
        else:
            padded.append(s)

    write_binary_data(data_path, bytearray(), padded)


if __name__ == "__main__":
    main()