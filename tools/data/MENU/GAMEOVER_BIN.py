#!/usr/bin/env python3
import argparse
import logging
from pathlib import Path

from tools.etc.psx_img import decode_raw_image, encode_raw_image

logger = logging.getLogger(__name__)

IMAGE_W = 96
IMAGE_H = 128


def decode(infile: Path, outfile: Path) -> None:
    decode_raw_image(infile, outfile, IMAGE_W, IMAGE_H, 4)


def encode(infile: Path, outfile: Path) -> None:
    encode_raw_image(infile, outfile, IMAGE_W, IMAGE_H, 4)


def main(argv=None):
    parser = argparse.ArgumentParser(description="Decode or encode GAMEOVER.BIN")
    parser.add_argument('input',   type=Path)
    parser.add_argument('output',  type=Path)
    parser.add_argument('--debug', action='store_true')
    args = parser.parse_args(argv)

    logging.basicConfig(level=logging.DEBUG if args.debug else logging.INFO, format='%(message)s')

    suffix = args.input.suffix.lower()
    if suffix == '.bin':
        decode(args.input, args.output)
    elif suffix == '.png':
        encode(args.input, args.output)
    else:
        parser.error('Could not infer mode from input file extension; supply a .BIN or .png input file')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
