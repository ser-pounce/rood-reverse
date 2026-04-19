import argparse
import sys
from pathlib import Path

from tools.splat_ext.rgbClut import decode_image, write_png, read_png, pack_pixels


def cmd_to_png(args: argparse.Namespace) -> None:
    raw    = args.input.read_bytes()
    pixels, _, _ = decode_image(raw, 0, args.width, args.height, 8, 0, 0)
    write_png(args.output, pixels, args.width, args.height, 8, [], [])


def cmd_to_bin(args: argparse.Namespace) -> None:
    pixels, width, height, bitdepth, _, _ = read_png(args.input)
    args.output.write_bytes(pack_pixels(list(pixels), bitdepth))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Raw 8-bit pixel index encode/decode')
    sub = parser.add_subparsers(dest='command', required=True)

    p_to_png = sub.add_parser('to-png', help='Convert raw index binary to PNG')
    p_to_png.add_argument('input',  type=Path, help='Input .bin file')
    p_to_png.add_argument('width',  type=int)
    p_to_png.add_argument('height', type=int)
    p_to_png.add_argument('output', type=Path, help='Output .png file')
    p_to_png.set_defaults(func=cmd_to_png)

    p_to_bin = sub.add_parser('to-bin', help='Convert PNG back to raw index binary')
    p_to_bin.add_argument('input',  type=Path, help='Input .png file')
    p_to_bin.add_argument('output', type=Path, help='Output .bin file')
    p_to_bin.set_defaults(func=cmd_to_bin)

    args = parser.parse_args()
    args.func(args)