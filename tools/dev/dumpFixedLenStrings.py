import argparse
from pathlib import Path

from tools.etc.vsString import decode


def positive_int(value):
    try:
        number = int(value, 0)
    except ValueError:
        raise argparse.ArgumentTypeError(f"{value!r} is not an integer")
    if number <= 0:
        raise argparse.ArgumentTypeError("must be a positive integer")
    return number


def load_data(path, record_length, count=None):
    with path.open("rb") as f:
        if count is None:
            return f.read()
        return f.read(record_length * count)


def decode_strings(data, record_length):
    return [
        decode(data[offset:offset + record_length])
        for offset in range(0, len(data), record_length)
    ]


def format_strings(strings):
    return [f"line{idx}: {s}" for idx, s in enumerate(strings)]


def main():
    parser = argparse.ArgumentParser(
        description="Dump fixed-length strings from a binary file."
    )
    parser.add_argument("binary_file", type=Path)
    parser.add_argument("length", type=positive_int,
                        help="size of each string record in bytes")
    parser.add_argument("count", type=positive_int, nargs="?", default=None,
                        help="number of strings to dump (default: until end of file)")
    args = parser.parse_args()

    if not args.binary_file.is_file():
        parser.error(f"file not found: {args.binary_file}")

    data = load_data(args.binary_file, args.length, args.count)
    for line in format_strings(decode_strings(data, args.length)):
        print(line)


if __name__ == "__main__":
    main()