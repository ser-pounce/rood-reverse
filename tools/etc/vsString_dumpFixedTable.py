import argparse
from pathlib import Path

from tools.etc.vsString import write_table


def positive_int(value: str) -> int:
    try:
        parsed = int(value, 0)
    except ValueError:
        raise argparse.ArgumentTypeError(f"{value!r} is not an integer")
    if parsed <= 0:
        raise argparse.ArgumentTypeError(f"{parsed} is not positive")
    return parsed


def main(argv=None):
    parser = argparse.ArgumentParser(description="Dump a fixed-record-size binary file into a vsString table")
    parser.add_argument('input', type=Path)
    parser.add_argument('keys_file', type=Path)
    parser.add_argument('output', type=Path)
    parser.add_argument('record_size', type=positive_int)
    args = parser.parse_args(argv)

    data = args.input.read_bytes()
    count = len(data) // args.record_size
    records = [data[i * args.record_size : (i + 1) * args.record_size] for i in range(count)]

    write_table(records, args.keys_file, args.output)
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
