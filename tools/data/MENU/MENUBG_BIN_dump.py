#!/usr/bin/env python3
"""
Unpacks shared menu BG.

Format:
  - 512 bytes: color palette (256 x RGBA5551 little-endian u16)
  - Remaining: RLE compressed pixel data (palette indices)

RLE encoding (matching C decompressor):
  Each control u32:
    low  16 bits = number of zero (transparent) words to emit
    high 16 bits = number of literal words to copy verbatim

Output image: 192x240 indexed PNG with sPLT chunk encoding the original palette.
"""

import struct
import sys
from pathlib import Path

from tools.etc.psx_img import parse_cluts, write_png


PALETTE_SIZE = 512   # bytes (256 * 2)
IMAGE_W      = 192
IMAGE_H      = 240
IMAGE_PIXELS = IMAGE_W * IMAGE_H


def rle_decompress(data: bytes) -> bytes:
    """
    Decompress RLE data into a flat bytes of palette indices.

    Control u32:
      low  16 bits -> emit this many zero u32 words
      high 16 bits -> copy this many literal u32 words
    """
    words      = []
    pos        = 0
    data_words = len(data) // 4

    while pos < data_words:
        control, = struct.unpack_from('<I', data, pos * 4)
        pos += 1

        for _ in range(control & 0xFFFF):
            words.append(0)

        for _ in range(control >> 16):
            words.append(struct.unpack_from('<I', data, pos * 4)[0])
            pos += 1

    indices = []
    for w in words:
        indices.append((w >>  0) & 0xFF)
        indices.append((w >>  8) & 0xFF)
        indices.append((w >> 16) & 0xFF)
        indices.append((w >> 24) & 0xFF)
    return bytes(indices)


def unpack(input_path: Path, output_path: Path) -> None:
    raw = input_path.read_bytes()

    if len(raw) < PALETTE_SIZE:
        raise ValueError(f"File too small: {len(raw)} bytes, need at least {PALETTE_SIZE}")

    compressed = raw[PALETTE_SIZE:]

    pixels = rle_decompress(compressed)

    if len(pixels) < IMAGE_PIXELS:
        pixels = pixels + bytes(IMAGE_PIXELS - len(pixels))
    pixels = pixels[:IMAGE_PIXELS]

    cluts_before = parse_cluts(raw, 0, 1, 256)
    write_png(output_path, pixels, IMAGE_W, IMAGE_H, 8, cluts_before, [])


if __name__ == '__main__':
    if len(sys.argv) < 2:
        print(f"Usage: {sys.argv[0]} <input_file> [output.png]")
        sys.exit(1)

    inp = Path(sys.argv[1])
    out = Path(sys.argv[2]) if len(sys.argv) > 2 else inp.with_suffix('.png')
    unpack(inp, out)