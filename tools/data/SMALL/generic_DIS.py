#!/usr/bin/env python3
"""
generic_DIS.py — Dump any valid PSX TIM file (or multi-entry TIM blob) to PNG(s).

Supports:
  - 4bpp  (16-colour CLUT)
  - 8bpp  (256-colour CLUT)
  - 16bpp (direct RGBA5551, no CLUT)

Usage:
  python generic_DIS.py <input> <output_dir>
"""

import struct
import sys
from pathlib import Path

from tools.etc.psx_img import parse_cluts, unpack_pixels, write_png, decode_16bpp_pixels, read_png, encode_cluts, rgba_to_psx5551, psx5551_to_rgba


def parse_tim_entry(data: bytes, offset: int) -> dict:
    pos = offset

    magic = struct.unpack_from('<I', data, pos)[0]
    assert magic == 0x10, f"Bad magic at 0x{offset:X}: 0x{magic:08X}"
    pos += 4

    mode = struct.unpack_from('<I', data, pos)[0]
    pos += 4

    bpp_map = {0: 4, 1: 8, 2: 16}
    bpp = bpp_map.get(mode & 3)
    if bpp is None:
        raise ValueError(f"Unsupported mode at 0x{offset:X}: 0x{mode:08X}")

    entry = {
        'offset':   offset,
        'mode':     mode,
        'bpp':      bpp,
        'has_clut': bool(mode & 8),
        'clut':     None,
        'image':    None,
    }

    if mode & 8:
        clut_len = struct.unpack_from('<I', data, pos)[0]
        cx, cy, cw, ch = struct.unpack_from('<4H', data, pos + 4)
        entry['clut'] = {
            'data_offset': pos + 12,
            'n_cluts':     ch,
            'n_entries':   cw,
            'rect':        {'x': cx, 'y': cy, 'w': cw, 'h': ch},
        }
        pos += clut_len

    img_len = struct.unpack_from('<I', data, pos)[0]
    px, py, pw, ph = struct.unpack_from('<4H', data, pos + 4)
    actual_w = pw * 16 // bpp if bpp < 16 else pw
    pixel_data_offset = pos + 12
    pixel_data_size   = img_len - 12

    entry['image'] = {
        'data_offset': pixel_data_offset,
        'data_size':   pixel_data_size,
        'width':       actual_w,
        'height':      ph,
        'rect':        {'x': px, 'y': py, 'w': pw, 'h': ph},
    }
    entry['entry_size'] = (pixel_data_offset + pixel_data_size) - offset

    return entry


def dump_entry(data: bytes, entry: dict, output_path: Path, entry_index: int) -> None:
    img   = entry['image']
    bpp   = entry['bpp']
    w, h  = img['width'], img['height']
    pdata = data[img['data_offset']:img['data_offset'] + img['data_size']]

    if bpp == 16:
        # Decode with alpha always 255
        n_pixels = w * h
        words = struct.unpack_from(f'<{n_pixels}H', pdata)
        pixels = bytearray(n_pixels * 4)
        for i, word in enumerate(words):
            r, g, b, _ = psx5551_to_rgba(word)
            pixels[i * 4:i * 4 + 4] = (r, g, b, 255)
        pixels = bytes(pixels)
        img_rect = tuple(entry['image']['rect'][k] for k in ['x', 'y', 'w', 'h']) if entry['image']['rect'] else None
        write_png(output_path, pixels, w, h, bpp, cluts_before=[], cluts_after=[], img_rect=img_rect)
    else:
        if not entry['has_clut'] or entry['clut'] is None:
            raise ValueError(f"Entry {entry_index} is {bpp}bpp but has no CLUT")

        clut_info = entry['clut']
        cluts     = parse_cluts(data, clut_info['data_offset'], clut_info['n_cluts'], clut_info['n_entries'])
        pixels    = unpack_pixels(pdata, bpp, w * h)
        img_rect  = tuple(entry['image']['rect'][k] for k in ['x', 'y', 'w', 'h']) if entry['image']['rect'] else None
        clut_rect = tuple(entry['clut']['rect'][k] for k in ['x', 'y', 'w', 'h']) if entry['clut']['rect'] else None
        write_png(output_path, pixels, w, h, bpp, cluts_before=cluts, cluts_after=[], img_rect=img_rect, clut_rect=clut_rect)


def encode_tim_from_png(png_path: Path) -> bytes:

    pixels, width, height, bitdepth, cluts_before, cluts_after, img_rect, clut_rect = read_png(png_path)

    if bitdepth == 16:
        if clut_rect is not None:
            raise ValueError("16bpp should not have clut_rect")
        if img_rect is None:
            img_rect = (0, 0, width, height)
        # Convert RGBA8888 to 16-bit pixels, STP=1 only for black
        pixel_data = bytearray()
        for i in range(0, len(pixels), 4):
            r, g, b, a = pixels[i:i+4]
            stp_a = 255 if r == 0 and g == 0 and b == 0 else 0
            pixel = rgba_to_psx5551(r, g, b, stp_a)
            pixel_data.extend(struct.pack('<H', pixel))
        img_len = 12 + len(pixel_data)
        header = struct.pack('<IIIHHHH', 0x10, 2, img_len, img_rect[0], img_rect[1], img_rect[2], img_rect[3])
        return header + pixel_data
    else:
        # Indexed
        if not cluts_before:
            raise ValueError("Indexed image needs CLUT")
        cluts = cluts_before
        if clut_rect is None:
            first_clut = cluts[0]
            clut_rect = (0, 0, len(first_clut), len(cluts))
        if img_rect is None:
            img_rect = (0, 0, width * bitdepth // 16, height)
        # Encode CLUTs
        clut_bytes = encode_cluts(cluts)
        clut_len = 12 + len(clut_bytes)
        mode = (bitdepth == 8) | 8  # 1 for 8bpp, 0 for 4bpp, | 8 for has_clut
        clut_header = struct.pack('<IIIHHHH', 0x10, mode, clut_len, clut_rect[0], clut_rect[1], clut_rect[2], clut_rect[3])
        # Pixels
        if bitdepth == 4:
            if len(pixels) != width * height:
                raise ValueError(f"Unexpected 4bpp pixel count: {len(pixels)} != {width*height}")
            packed_pixels = bytearray((width * height + 1) // 2)
            for i in range(0, len(pixels), 2):
                hi = pixels[i] & 0x0F
                lo = pixels[i + 1] & 0x0F if i + 1 < len(pixels) else 0
                packed_pixels[i // 2] = hi | (lo << 4)
            pixel_data = bytes(packed_pixels)
        else:
            pixel_data = pixels
        img_len = 12 + len(pixel_data)
        pw = width * bitdepth // 16
        img_header = struct.pack('<IHHHH', img_len, img_rect[0], img_rect[1], pw, img_rect[3])
        return clut_header + clut_bytes + img_header + pixel_data


def dump_file(input_path: Path, output_path: Path, data: bytes = None) -> None:
    """Parse and dump a TIM chain.

    *data* may be supplied directly (e.g. a sub-slice of a larger file);
    if omitted the file at *input_path* is read from disk.
    """
    if data is None:
        data = input_path.read_bytes()

    file_size = len(data)
    offset    = 0
    entries   = []

    while offset < file_size:
        if file_size - offset < 8:
            break
        entry = parse_tim_entry(data, offset)
        entries.append(entry)
        offset += entry['entry_size']

    if len(entries) == 1:
        if output_path.exists() and output_path.is_dir():
            out_path = output_path / f"{input_path.stem}.png"
        else:
            out_path = output_path
            out_path.parent.mkdir(parents=True, exist_ok=True)
        dump_entry(data, entries[0], out_path, 0)
    else:
        if output_path.exists() and output_path.is_file():
            raise ValueError(f"Output path must be a directory for {len(entries)} PNG files: {output_path}")
        output_path.mkdir(parents=True, exist_ok=True)
        for i, entry in enumerate(entries):
            out_path = output_path / f"{i:04d}.png"
            dump_entry(data, entry, out_path, i)


if __name__ == '__main__':
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} <input> <output>")
        print("  If input is .DIS, output is a PNG file for a single-entry TIM or a directory for multiple entries")
        print("  If input is .png, output is a .DIS file")
        print("  If input is a directory, output is a .DIS file (stitched from PNGs)")
        sys.exit(1)

    input_path = Path(sys.argv[1])
    output_path = Path(sys.argv[2])

    if input_path.suffix.lower() == '.png':
        # PNG to TIM (single PNG)
        tim_bytes = encode_tim_from_png(input_path)
        output_path.write_bytes(tim_bytes)
    elif input_path.is_dir():
        # Directory of PNGs to TIM
        png_files = sorted(input_path.glob('*.png'))
        if not png_files:
            print(f"Error: no PNG files in {input_path}")
            sys.exit(1)
        tim_data = b''
        for png_file in png_files:
            tim_bytes = encode_tim_from_png(png_file)
            tim_data += tim_bytes
        output_path.write_bytes(tim_data)
    else:
        # TIM to PNG
        dump_file(input_path, output_path)