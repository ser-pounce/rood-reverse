import sys
from tools.etc.vsString import write_table


if __name__ == '__main__':
    if len(sys.argv) != 5:
        print("Usage: vsString_dumpFixedTable.py <binary_file> <keys_file> <out_path> <record_size>")
        sys.exit(1)

    bin_path = sys.argv[1]
    keys_file = sys.argv[2]
    out_path = sys.argv[3]
    try:
        record_size = int(sys.argv[4], 0)
    except ValueError:
        print("Error: record_size must be an integer", file=sys.stderr)
        sys.exit(2)

    if record_size <= 0:
        print("Error: record_size must be positive", file=sys.stderr)
        sys.exit(2)

    with open(bin_path, "rb") as f:
        data = f.read()

    filesize = len(data)
    count = filesize // record_size
    offsets = [(i * record_size) // 2 for i in range(count)]

    write_table(data, offsets, keys_file, out_path)
