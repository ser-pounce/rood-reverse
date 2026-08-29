import argparse
import struct
from pathlib import Path

from PIL import Image

from tools.libdata.img import rgb888_to_bgr555
from tools.kaitai.parsers.data.MENU.mapbg_bin import MapbgBin


def decode(input_path: Path, output_path: Path) -> None:
    mapbg = MapbgBin.from_file(input_path)
    clut = bytes(b for color in mapbg.clut.colors for b in (color.r8, color.g8, color.b8))
    img = Image.frombytes('P', (320, 240), bytes(mapbg.indices))
    img.putpalette(clut)
    img.save(output_path)


def encode(input_path: Path, output_path: Path) -> None:
    img = Image.open(input_path)
    img.load()

    if img.mode != 'P':
        raise ValueError(f'{input_path} must be paletted')

    palette = img.getpalette()

    words = [
        rgb888_to_bgr555(*palette[i:i + 3]) | 0x8000
        for i in range(0, 256 * 3, 3)
    ]

    output_path.write_bytes(struct.pack('<256H', *words) + bytes(img.tobytes()))


def main(argv=None) -> int:
    parser = argparse.ArgumentParser(description="Decode or encode MAPBG.BIN")
    parser.add_argument('input', type=Path)
    parser.add_argument('output', type=Path)
    args = parser.parse_args(argv)

    suffix = args.input.suffix.lower()
    if suffix == '.bin':
        decode(args.input, args.output)
    elif suffix == '.png':
        encode(args.input, args.output)
    else:
        parser.error(f"Could not infer mode from input file extension; expected .BIN or .png, got {suffix!r}")

    return 0


if __name__ == '__main__':
    raise SystemExit(main())
