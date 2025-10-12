import sys
from pathlib import Path
from tools.etc.vsString_yaml import *


def main():
    if len(sys.argv) < 4:
        print(f"Usage: python {sys.argv[0]} <path_to_yaml> <output_data> <output_header>")
        sys.exit(1)

    yaml_path = Path(sys.argv[1])
    data_path = Path(sys.argv[2])
    header_path = Path(sys.argv[3])

    strings, offsets, enums, indices = read_yaml(yaml_path)
    write_data(data_path, offsets, strings)
    header = write_binary_header(offsets)
    write_binary_data(data_path.with_suffix(data_path.suffix + '.bin'), header, strings)
    write_header(header_path, header_path.stem, enums, indices)


if __name__ == "__main__":
    main()