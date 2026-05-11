#!/usr/bin/env python3
"""
Repacks the shared menu BG image.

Output format:
  - 512 bytes: color palette (256 x RGBA5551 little-endian u16)
  - Remaining: RLE compressed pixel data (palette indices)

RLE encoding:
  Each control u32:
    low  16 bits = number of zero words following
    high 16 bits = number of literal words following

Input PNG must be an 8-bit indexed PNG as produced by unpack_menu.py,
with palette stored in the sPLT chunk (authoritative) or PLTE chunk.
"""

import struct
import sys
from pathlib import Path

from tools.etc.psx_img import encode_image, read_png


IMAGE_W = 192
IMAGE_H = 240


def rle_compress(data: bytes) -> bytes:
    """
    Compress pixel index bytes into RLE format.
    Input bytes are packed into u32 words first (little-endian), then:

    Control u32:
      low  16 bits = zero run length
      high 16 bits = literal run length
    """
    # Pack indices into u32 words
    words = []
    for i in range(0, len(data), 4):
        chunk = list(data[i:i+4])
        while len(chunk) < 4:
            chunk.append(0)
        words.append(chunk[0] | (chunk[1] << 8) | (chunk[2] << 16) | (chunk[3] << 24))

    out = bytearray()
    i   = 0
    n   = len(words)

    while i < n:
        zero_count = 0
        while i + zero_count < n and words[i + zero_count] == 0 and zero_count < 0xFFFF:
            zero_count += 1
        i += zero_count

        literal_start = i
        literal_count = 0
        while i < n and words[i] != 0 and literal_count < 0xFFFF:
            literal_count += 1
            i += 1

        out += struct.pack('<I', (zero_count & 0xFFFF) | ((literal_count & 0xFFFF) << 16))
        for j in range(literal_count):
            out += struct.pack('<I', words[literal_start + j])

    return bytes(out)


def repack(input_path: Path, output_path: Path) -> None:
    pixels, width, height, bitdepth, cluts_before, cluts_after = read_png(input_path)

    if (width, height) != (IMAGE_W, IMAGE_H):
        raise ValueError(f"Expected {IMAGE_W}x{IMAGE_H} image, got {width}x{height}")
    if bitdepth != 8:
        raise ValueError(f"Expected 8-bit indexed PNG, got bitdepth={bitdepth}")

    # encode_image gives us [palette_bytes][pixel_bytes] — we want [palette_bytes][rle_bytes]
    palette_bytes = bytes(encode_image(b'', cluts_before, [], bitdepth))
    compressed    = rle_compress(pixels)

    output_path.write_bytes(palette_bytes + compressed)


if __name__ == '__main__':
    if len(sys.argv) < 2:
        print(f"Usage: {sys.argv[0]} <input.png> [output_file]")
        sys.exit(1)

    inp = Path(sys.argv[1])
    out = Path(sys.argv[2]) if len(sys.argv) > 2 else inp.with_suffix('.bin')
    repack(inp, out)
