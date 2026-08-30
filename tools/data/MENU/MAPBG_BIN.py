import argparse
from pathlib import Path

from PIL import Image

from tools.kaitai.parsers.data.MENU.mapbg_bin import MapbgBin
from tools.libdata.img import decode_8bpp_bin, encode_rgb555


def decode_bin(input_path: Path, output_path: Path) -> None:
    mapbg = MapbgBin.from_file(input_path)
    decode_8bpp_bin(
        mapbg.indices,
        320, 240,
        [(c.r8, c.g8, c.b8) for c in mapbg.clut.colors],
        output_path
    )


def encode_bin(input_path: Path, output_path: Path) -> None:
    img = Image.open(input_path)
    img.load()

    if img.mode != 'P':
        raise ValueError(f'{input_path} must be paletted')

    output_path.write_bytes(encode_rgb555(img.getpalette()) + img.tobytes())


def main(argv=None) -> int:
    parser = argparse.ArgumentParser(description="Decode or encode MAPBG.BIN")
    parser.add_argument('input', type=Path)
    parser.add_argument('output', type=Path)
    args = parser.parse_args(argv)

    suffix = args.input.suffix.lower()
    if suffix == '.bin':
        decode_bin(args.input, args.output)
    elif suffix == '.png':
        encode_bin(args.input, args.output)
    else:
        parser.error(f"Could not infer mode from input file extension; expected .BIN or .png, got {suffix!r}")

    return 0


if __name__ == '__main__':
    raise SystemExit(main())
