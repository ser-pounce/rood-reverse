import argparse
from pathlib import Path
from typing import Any

from kaitaistruct import KaitaiStream, BytesIO
from PIL import Image
from PIL.PngImagePlugin import PngInfo

from tools.splat_ext.img import PSXSegImg
from tools.libdata.img import (
    generate_grayscale_palette, get_png_bit_depth, pack_4bpp,
    read_clut_chunk, write_clut_chunk, write_indexed_png,
)
from tools.kaitai.parsers.lib.img import Img


BITDEPTH_TO_MODE = {4: 0, 8: 1}


class PSXSegRgbClut(PSXSegImg):

    bitdepth:    int
    num_cluts:   int
    plte_clut:   int | None
    cluts_after: bool

    def __init__(self, **kwargs: Any) -> None:
        super().__init__(**kwargs)

        if len(kwargs['yaml']) < 5:
            raise ValueError('PSXSegRgbClut requires width and height')

        yaml = kwargs['yaml']

        if not isinstance(yaml, dict):
            raise ValueError('Abbreviated syntax not supported')
        
        self.bitdepth    = int(yaml.get('bitdepth', 4))
        self.num_cluts   = int(yaml.get('num_cluts', 1))
        plte_clut        = yaml.get('plte_clut')
        self.plte_clut   = int(plte_clut) if plte_clut is not None else None
        self.cluts_after = bool(yaml.get('cluts_after', False))

        if self.bitdepth not in BITDEPTH_TO_MODE:
            raise ValueError(f'PSXSegRgbClut: bitdepth must be 4 or 8, got {self.bitdepth}')

    def split(self, rom_bytes: bytes) -> None:
        parsed = Img.ClutsIndices(
            BITDEPTH_TO_MODE[self.bitdepth],
            self.num_cluts,
            self.cluts_after,
            KaitaiStream(BytesIO(rom_bytes[self.rom_start:self.rom_end]))
        )

        if self.plte_clut is None:
            palette = generate_grayscale_palette(1 << self.bitdepth)
        else:
            palette = bytes(
                channel
                for color in parsed.cluts[self.plte_clut].colors
                for channel in (color.r8, color.g8, color.b8)
            )

        info = PngInfo()
        if self.num_cluts > 0:
            raw_cluts = parsed._raw_cluts_a if self.cluts_after else parsed._raw_cluts_b
            write_clut_chunk(info, b''.join(raw_cluts), self.cluts_after)

        write_indexed_png(
            bytes(parsed.indices.indices), self.width, self.height,
            palette, self.make_path(), bpp=self.bitdepth, info=info,
        )


def encode(image_path: Path) -> tuple[bytes, bytes, bool]:
    img = Image.open(image_path)
    img.load()

    if img.mode != 'P':
        raise ValueError('Input image must be a palettized (P-mode) PNG')

    try:
        raw_clut, cluts_after = read_clut_chunk(img)
    except ValueError as e:
        raise ValueError(f'{image_path}: {e}') from e

    indices = img.tobytes()
    bitdepth = get_png_bit_depth(image_path)
    pixel_bytes = pack_4bpp(indices) if bitdepth == 4 else indices

    return pixel_bytes, raw_clut, cluts_after


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('input',  type=Path, help='Input PNG file')
    parser.add_argument('output', type=Path, help='Output file')
    parser.add_argument('--dat',  action='store_true', help='Write a .dat text file instead of a .o object file')
    args = parser.parse_args()

    pixel_bytes, raw_clut, cluts_after = encode(args.input)
    symbol_name = args.input.name.split('.')[0]

    first, second = (pixel_bytes, raw_clut) if cluts_after else (raw_clut, pixel_bytes)
    first_name, second_name = (
        (symbol_name, f'{symbol_name}_clut') if cluts_after
        else (f'{symbol_name}_clut', symbol_name)
    )
    binary = first + second
    symbols = [(first_name, 0), (second_name, len(first))]

    if args.dat:
        with open(args.output, 'w') as h:
            for byte in binary:
                h.write(f'0x{byte:02X},')
    else:
        PSXSegRgbClut.write_object_file(
            binary, args.output, symbols, *PSXSegRgbClut.objcopy_from_env(),
        )
