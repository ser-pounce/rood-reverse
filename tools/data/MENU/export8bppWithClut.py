#!/usr/bin/env python3
from pathlib import Path
import struct
import argparse
import logging
import png

logger = logging.getLogger(__name__)


def bgr1555_to_rgba8888(color16: int):
    b = (color16 >> 10) & 0x1F
    g = (color16 >> 5) & 0x1F
    r = (color16 >> 0) & 0x1F
    r8 = r << 3
    g8 = g << 3
    b8 = b << 3
    alpha = 0 if color16 == 0x0000 else 255
    return (r8, g8, b8, alpha)


def read_palette_and_pixels(path: Path, width: int, height: int):
    with open(path, "rb") as f:
        data = f.read()
    if len(data) < 512:
        raise ValueError("Input file is too short to contain a 512-byte palette")
    palette_bytes = data[:512]
    pixel_bytes = data[512:512 + (width * height)]
    if len(pixel_bytes) < width * height:
        raise ValueError(f"Input file does not contain enough image data for {width}x{height}")
    palette = []
    for i in range(256):
        off = i * 2
        color16 = struct.unpack_from("<H", palette_bytes, off)[0]
        palette.append(bgr1555_to_rgba8888(color16))
    pixels = list(pixel_bytes)
    return palette, pixels


def export_png(infile: Path, outfile: Path, width: int, height: int):
    palette, pixels = read_palette_and_pixels(infile, width, height)
    writer = png.Writer(width=width, height=height, palette=palette)
    outfile.parent.mkdir(parents=True, exist_ok=True)
    with open(outfile, "wb") as f:
        writer.write_array(f, pixels)


def main(argv=None):
    parser = argparse.ArgumentParser(description="Export an 8bpp image with 256-entry CLUT (ABGR1555) to PNG")
    parser.add_argument("input", type=Path)
    parser.add_argument("output", type=Path)
    parser.add_argument("width", type=int)
    parser.add_argument("height", type=int)
    parser.add_argument("--debug", action="store_true")
    args = parser.parse_args(argv)
    logging.basicConfig(level=logging.DEBUG if args.debug else logging.INFO, format="%(message)s")
    try:
        export_png(args.input, args.output, args.width, args.height)
    except Exception as e:
        logger.error(str(e))
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
