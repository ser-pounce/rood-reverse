#!/usr/bin/env python3
"""
Convert shared menu BG data in both directions.

When the input is a .bin file, this script decodes it to an indexed PNG.
When the input is a .png file, this script encodes it back to the .bin format.

Format:
  - 512 bytes: color palette (256 x RGBA5551 little-endian u16)
  - Remaining: RLE compressed pixel data (palette indices)

RLE encoding:
  Each control u32:
    low  16 bits = number of zero words following
    high 16 bits = number of literal words following

Output PNG: 192x240 indexed PNG with sPLT chunk encoding the original palette.
"""

import logging
import struct
import sys
from pathlib import Path

from tools.etc.psx_img import encode_image, parse_cluts, read_png, write_png

PALETTE_SIZE = 512   # bytes (256 * 2)
IMAGE_W      = 192
IMAGE_H      = 240
IMAGE_PIXELS = IMAGE_W * IMAGE_H


def rle_decompress(data: bytes) -> bytes:
    """Decompress RLE data into a flat byte stream of palette indices."""
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


def rle_compress(data: bytes) -> bytes:
    """Compress pixel index bytes into the menu BG RLE format."""
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


def decode_bin(input_path: Path, output_path: Path) -> None:
    raw = input_path.read_bytes()
    if len(raw) < PALETTE_SIZE:
        raise ValueError(f"File too small: {len(raw)} bytes, need at least {PALETTE_SIZE}")

    compressed = raw[PALETTE_SIZE:]
    pixels = rle_decompress(compressed)
    if len(pixels) < IMAGE_PIXELS:
        pixels = pixels + bytes(IMAGE_PIXELS - len(pixels))
    pixels = pixels[:IMAGE_PIXELS]

    cluts_before = parse_cluts(raw, 0, 1, 256)
    output_path.parent.mkdir(parents=True, exist_ok=True)
    write_png(output_path, pixels, IMAGE_W, IMAGE_H, 8, cluts_before, [])


def encode_png(input_path: Path, output_path: Path) -> None:
    pixels, width, height, bitdepth, cluts_before, cluts_after, _, _ = read_png(input_path)

    if (width, height) != (IMAGE_W, IMAGE_H):
        raise ValueError(f"Expected {IMAGE_W}x{IMAGE_H} image, got {width}x{height}")
    if bitdepth != 8:
        raise ValueError(f"Expected 8-bit indexed PNG, got bitdepth={bitdepth}")

    palette_bytes = bytes(encode_image(b'', cluts_before, [], bitdepth))
    compressed    = rle_compress(pixels)
    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_bytes(palette_bytes + compressed)


def main(argv=None):
    import argparse

    parser = argparse.ArgumentParser(
        description='Convert shared menu BG data automatically based on input extension.'
    )
    parser.add_argument('input', type=Path, help='Input .bin or .png file')
    parser.add_argument('output', type=Path, nargs='?', help='Optional output file')
    parser.add_argument('--debug', action='store_true', help='Enable debug logging')
    args = parser.parse_args(argv)

    if args.debug:
        logging.basicConfig(level=logging.DEBUG, format='%(message)s')
    else:
        logging.basicConfig(level=logging.INFO, format='%(message)s')

    suffix = args.input.suffix.lower()
    if suffix == '.bin':
        output_path = args.output or args.input.with_suffix('.png')
        decode_bin(args.input, output_path)
    elif suffix == '.png':
        output_path = args.output or args.input.with_suffix('.bin')
        encode_png(args.input, output_path)
    else:
        parser.error('Unsupported input extension. Use .bin to decode or .png to encode.')


if __name__ == '__main__':
    sys.exit(main())
