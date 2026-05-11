#!/usr/bin/env python3
import argparse
import logging
from pathlib import Path

from tools.etc.psx_img import encode_image, parse_cluts, read_png, write_png

logger = logging.getLogger(__name__)

IMAGE_W = 320
IMAGE_H = 240


def decode(infile: Path, outfile: Path) -> None:
    raw    = infile.read_bytes()
    pixels = raw[512:512 + IMAGE_W * IMAGE_H]

    if len(pixels) < IMAGE_W * IMAGE_H:
        raise ValueError(f"Input file does not contain enough image data for {IMAGE_W}x{IMAGE_H}")

    cluts_before = parse_cluts(raw, 0, 1, 256)
    outfile.parent.mkdir(parents=True, exist_ok=True)
    write_png(outfile, pixels, IMAGE_W, IMAGE_H, 8, cluts_before, [])


def encode(infile: Path, outfile: Path) -> None:
    pixels, width, height, bitdepth, cluts_before, cluts_after = read_png(infile)

    if (width, height) != (IMAGE_W, IMAGE_H):
        raise ValueError(f"Expected {IMAGE_W}x{IMAGE_H} image, got {width}x{height}")

    outfile.parent.mkdir(parents=True, exist_ok=True)
    outfile.write_bytes(encode_image(pixels, cluts_before, cluts_after, bitdepth))


def main(argv=None):
    parser = argparse.ArgumentParser(description="Decode or encode MAPBG.BIN")
    parser.add_argument('command', choices=['decode', 'encode'])
    parser.add_argument('input',   type=Path)
    parser.add_argument('output',  type=Path)
    parser.add_argument('--debug', action='store_true')
    args = parser.parse_args(argv)

    logging.basicConfig(level=logging.DEBUG if args.debug else logging.INFO, format='%(message)s')

    try:
        if args.command == 'decode':
            decode(args.input, args.output)
        else:
            encode(args.input, args.output)
    except Exception as e:
        logger.error(str(e))
        return 1
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
