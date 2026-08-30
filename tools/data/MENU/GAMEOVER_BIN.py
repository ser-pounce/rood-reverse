import argparse
from pathlib import Path

from PIL import Image
from kaitaistruct import KaitaiStream

from tools.kaitai.parsers.lib.img import Img
from tools.libdata.img import decode_grayscale, pack_4bpp


def main(argv=None):
    parser = argparse.ArgumentParser(description="Decode or encode GAMEOVER.BIN")
    parser.add_argument('input', type=Path)
    parser.add_argument('output', type=Path)
    args = parser.parse_args(argv)

    suffix = args.input.suffix.lower()
    if suffix == '.bin':
        with open(args.input, 'rb') as f:
            indices = Img.Indices(0, KaitaiStream(f))
        decode_grayscale(bytes(indices.indices), 96, 128, 4, args.output)
    elif suffix == '.png':
        img = Image.open(args.input)
        img.load()
        args.output.write_bytes(pack_4bpp(img.tobytes()))
    else:
        parser.error('Could not infer mode from input file extension; supply a .BIN or .png input file')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
