import argparse
import struct
from pathlib import Path
from typing import Any

import png

from tools.splat_ext.rgbClut import (
    psx5551_to_rgba, rgba_to_psx5551,
    make_splt_chunk, read_splt_chunks, inject_splt_before_iend,
    crc32_chunk, Palette,
)

import struct as _struct

IDXD_CHUNK = b'idxD'


def make_idxd_chunk(indices: bytes) -> bytes:
    """Create an idxD chunk storing raw pixel indices."""
    import zlib as _zlib
    compressed = _zlib.compress(indices)
    crc = crc32_chunk(IDXD_CHUNK, compressed)
    return _struct.pack('>I', len(compressed)) + IDXD_CHUNK + compressed + _struct.pack('>I', crc)


def read_idxd_chunk(png_path: Path) -> bytes | None:
    """Read and decompress the idxD chunk from a PNG file, or return None if absent."""
    import zlib as _zlib
    data = png_path.read_bytes()
    pos = 8  # skip PNG signature
    while pos < len(data):
        length     = _struct.unpack_from('>I', data, pos)[0]
        chunk_type = data[pos + 4:pos + 8]
        chunk_data = data[pos + 8:pos + 8 + length]
        pos += 12 + length
        if chunk_type == IDXD_CHUNK:
            return _zlib.decompress(chunk_data)
    return None

# Image layout constants
IMG_W,   IMG_H   = 448, 256
BLOCK_W, BLOCK_H = 64,  32
N_COLOURS        = 256
CLUT_0_COLS      = {1, 2, 3, 4}  # columns 1-4 use CLUT 0
CLUT_1_COLS      = {0, 5, 6}     # columns 0, 5, 6 use CLUT 1
CLUT_BYTES       = N_COLOURS * 2  # 2 bytes per PSX 5551 entry


def read_cluts(clut_path: Path) -> tuple[Palette, Palette]:
    """Read two 256-colour CLUTs from offset 0 of the clut file."""
    data = clut_path.read_bytes()
    def parse(offset: int) -> Palette:
        return [psx5551_to_rgba(e) for e, in struct.iter_unpack('<H', data[offset:offset + CLUT_BYTES])]
    return parse(0), parse(CLUT_BYTES)


def clut_for_col(col: int, clut0: Palette, clut1: Palette) -> Palette:
    return clut0 if col in CLUT_0_COLS else clut1


def build_lookup(clut: Palette) -> dict[int, int]:
    """Build reverse lookup: 5551 word -> palette index."""
    lookup: dict[int, int] = {}
    for i, (r, g, b, a) in enumerate(clut):
        word = struct.unpack('<H', rgba_to_psx5551(r, g, b, a))[0]
        lookup.setdefault(word, i)
    return lookup


def cmd_to_png(args: argparse.Namespace) -> None:
    """Decode index binary + clut file -> RGBA PNG with CLUTs stored as sPLT chunks."""
    clut0, clut1 = read_cluts(args.clut)
    indices = list(args.input.read_bytes())

    rgba_pixels: list[int] = []
    for row in range(IMG_H):
        for x in range(IMG_W):
            clut       = clut_for_col(x // BLOCK_W, clut0, clut1)
            r, g, b, _ = clut[indices[row * IMG_W + x]]
            rgba_pixels.extend([r, g, b, 255])

    img = png.Writer(width=IMG_W, height=IMG_H, bitdepth=8, alpha=True, greyscale=False)
    with open(args.output, 'wb') as f:
        img.write_array(f, rgba_pixels)

    # Store CLUTs as sPLT and raw indices as idxD so to-bin is fully self-contained
    inject_splt_before_iend(args.output, [
        make_splt_chunk('clut_0', clut0),
        make_splt_chunk('clut_1', clut1),
        make_idxd_chunk(bytes(indices)),
    ])


def cmd_to_bin(args: argparse.Namespace) -> None:
    """Re-encode RGBA PNG -> index binary using idxD chunk stored in the PNG."""
    indices = read_idxd_chunk(args.input)
    if indices is None:
        raise ValueError('PNG is missing idxD chunk; re-export from the original binary')
    if len(indices) != IMG_W * IMG_H:
        raise ValueError(f'idxD chunk has wrong size: expected {IMG_W * IMG_H}, got {len(indices)}')
    args.output.write_bytes(indices)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='SPMCIMG encode/decode')
    sub = parser.add_subparsers(dest='command', required=True)

    p_to_png = sub.add_parser('to-png', help='Decode index binary to RGBA PNG')
    p_to_png.add_argument('input',  type=Path, help='Input index .bin file')
    p_to_png.add_argument('clut',   type=Path, help='CLUT .bin file')
    p_to_png.add_argument('output', type=Path, help='Output .png file')
    p_to_png.set_defaults(func=cmd_to_png)

    p_to_bin = sub.add_parser('to-bin', help='Re-encode RGBA PNG to index binary')
    p_to_bin.add_argument('input',  type=Path, help='Input .png file')
    p_to_bin.add_argument('output', type=Path, help='Output index .bin file')
    p_to_bin.set_defaults(func=cmd_to_bin)

    args = parser.parse_args()
    args.func(args)