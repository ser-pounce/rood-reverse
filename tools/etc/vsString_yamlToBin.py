import sys
from pathlib import Path
from tools.etc.vsString_yaml import read_yaml, write_binary, write_header


def main():
    if len(sys.argv) < 4:
        print("Usage: python mcman.py <path_to_yaml> <output_bin> <output_header>")
        sys.exit(1)

    yaml_path = Path(sys.argv[1])
    bin_path = Path(sys.argv[2])
    header_path = Path(sys.argv[3])

    strings, offsets, enums = read_yaml(yaml_path)
    write_binary(bin_path, offsets, strings)
    write_header(header_path, yaml_path.stem, enums)


if __name__ == "__main__":
    main()