import argparse
from pathlib import Path

from PIL import Image
from PIL.PngImagePlugin import PngInfo

from tools.kaitai.parsers.data.MENU.mcdata_bin import McdataBin


IMG_W, IMG_H = 448, 256
BLOCK_W      = 64
CLUT_0_COLS  = {1, 2, 3, 4}


def decode_bin(input_path: Path, clut_path: Path, output_path: Path) -> None:
    mcdata = McdataBin.from_file(str(clut_path))

    clut0, clut1 = ([(c.r8, c.g8, c.b8) for c in clut.colors] for clut in mcdata.cluts)
    indices = input_path.read_bytes()

    pixels = bytearray(IMG_W * IMG_H * 3)
    for row in range(IMG_H):
        for x in range(IMG_W):
            clut = clut0 if (x // BLOCK_W) in CLUT_0_COLS else clut1
            r, g, b = clut[indices[row * IMG_W + x]]
            i = (row * IMG_W + x) * 3
            pixels[i : i + 3] = (r, g, b)

    img = Image.frombytes('RGB', (IMG_W, IMG_H), bytes(pixels))

    meta = PngInfo()
    meta.add(b'clUt', mcdata._raw_cluts[0] + mcdata._raw_cluts[1], after_idat=True)
    meta.add(b'idxD', bytes(indices), after_idat=True)
    img.save(output_path, pnginfo=meta)


def encode_bin(input_path: Path, output_path: Path) -> None:
    img = Image.open(input_path)
    img.load()

    private = {c[0]: c[1] for c in reversed(img.private_chunks)}
    indices = private.get(b'idxD')
    if indices is None:
        raise ValueError('PNG is missing idxD chunk')

    output_path.write_bytes(indices)


def main(argv=None) -> int:
    parser = argparse.ArgumentParser(description='SPMCIMG encode/decode')
    parser.add_argument('input', type=Path)
    parser.add_argument('output', type=Path)
    parser.add_argument('--clut', type=Path, help='CLUT .bin file (required for decode)')
    args = parser.parse_args(argv)

    suffix = args.input.suffix.lower()
    if suffix == '.bin':
        if args.clut is None:
            parser.error('--clut is required when decoding')
        decode_bin(args.input, args.clut, args.output)
    elif suffix == '.png':
        encode_bin(args.input, args.output)
    else:
        parser.error(f"Could not infer mode from input file extension; expected .bin or .png, got {suffix!r}")

    return 0


if __name__ == '__main__':
    raise SystemExit(main())