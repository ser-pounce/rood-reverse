#!/usr/bin/env python3
from pathlib import Path
import struct
import argparse
import logging
import png

logger = logging.getLogger(__name__)


def rgba8888_to_bgr1555(r: int, g: int, b: int, alpha: int) -> int:
    r5 = r >> 3
    g5 = g >> 3
    b5 = b >> 3
    a5 = alpha >> 3
    
    a1 = 1 if a5 == 31 else 0
    
    color16 = (a1 << 15) | (b5 << 10) | (g5 << 5) | (r5 << 0)
    
    return color16


def read_png_palette_and_pixels(path: Path):
    r = png.Reader(filename=str(path))
    width, height, rows, info = r.read()
    if 'palette' not in info:
        raise ValueError('PNG is not indexed (no palette)')
    pal = info['palette']
    rgba_palette = []
    for i, entry in enumerate(pal):
        if len(entry) == 3:
            rr, gg, bb = entry
            aa = 255
        else:
            rr, gg, bb, aa = entry
        rgba_palette.append((rr, gg, bb, aa))
    pixels = []
    for row in rows:
        if isinstance(row, (bytes, bytearray)):
            pixels.extend(row)
        else:
            pixels.extend(row)
    return width, height, rgba_palette, pixels


def export_bin(infile: Path, outfile: Path):
    width, height, rgba_palette, pixels = read_png_palette_and_pixels(infile)
    if len(pixels) != width * height:
        raise ValueError('Pixel data length does not match image dimensions')
    words = []
    for i in range(256):
        if i < len(rgba_palette):
            words.append(rgba8888_to_bgr1555(*rgba_palette[i]))
        else:
            words.append(0)
    outfile.parent.mkdir(parents=True, exist_ok=True)
    with open(outfile, 'wb') as f:
        for w in words:
            f.write(struct.pack('<H', w))
        f.write(bytes(pixels))


def main(argv=None):
    p = argparse.ArgumentParser()
    p.add_argument('input', type=Path)
    p.add_argument('output', type=Path)
    p.add_argument('--debug', action='store_true')
    args = p.parse_args(argv)
    logging.basicConfig(level=logging.DEBUG if args.debug else logging.INFO, format='%(message)s')
    try:
        export_bin(args.input, args.output)
    except Exception as e:
        logger.error(str(e))
        return 1
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
