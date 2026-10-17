import argparse
from pathlib import Path
from typing import Any

import yaml


def encode_byte_array(input_path: Path) -> bytes:
    values: Any = yaml.safe_load(input_path.read_text(encoding="utf-8"))
    if not isinstance(values, list):
        raise ValueError(f"{input_path}: expected a YAML array of bytes")

    for index, value in enumerate(values):
        if (
            isinstance(value, bool)
            or not isinstance(value, int)
            or not 0 <= value <= 0xFF
        ):
            raise ValueError(
                f"{input_path}: item {index} must be an integer from 0 to 255"
            )

    return bytes(values)


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description="Encode glyph widths array")
    parser.add_argument("input", type=Path, help="input YAML byte array")
    parser.add_argument("output", type=Path, help="output binary path")
    args = parser.parse_args(argv)

    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_bytes(encode_byte_array(args.input))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
