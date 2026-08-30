import argparse
from pathlib import Path

from kaitaistruct import KaitaiStream, BytesIO

from tools.etc.vsString import write_table
from tools.kaitai.parsers.lib.string_table import StringTable


def vsString_dumpTable(data: bytes, keys_path: Path, output_path: Path):
    table = StringTable(0, KaitaiStream(BytesIO(data)))
    write_table([s.text for s in table.string_refs], keys_path, output_path)


def main(argv=None):
    parser = argparse.ArgumentParser(description="Dump a StringTable binary file into a vsString table")
    parser.add_argument('input', type=Path)
    parser.add_argument('keys_file', type=Path)
    parser.add_argument('output', type=Path)
    args = parser.parse_args(argv)

    vsString_dumpTable(args.input.read_bytes(), args.keys_file, args.output)
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
