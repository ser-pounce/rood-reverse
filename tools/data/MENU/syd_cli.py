import sys
import struct
from pathlib import Path
from typing import Callable


def align(data: bytes) -> bytes:
    return data + b"\x00" * (-len(data) % 4)


def run_cli(decode: Callable, encode: Callable) -> None:
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} <input> <output>")
        sys.exit(1)

    in_path = Path(sys.argv[1])
    out_path = Path(sys.argv[2])

    if in_path.suffix == ".SYD":
        decode(in_path, out_path)
    elif in_path.suffix == ".yml":
        encode(in_path, out_path)
    else:
        print(f"Unrecognized extension {in_path.suffix!r} — expected .SYD or .yml")
        sys.exit(1)


def write_syd(out_path: Path, blocks: list[bytes]) -> None:
    header_fmt = f"<{len(blocks)}I"
    header_size = struct.calcsize(header_fmt)

    offsets = []
    running = header_size
    for block in blocks:
        offsets.append(running)
        running += len(block)

    with open(out_path, "wb") as f:
        f.write(struct.pack(header_fmt, *offsets))
        for block in blocks:
            f.write(block)