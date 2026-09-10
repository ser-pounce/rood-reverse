import argparse
from pathlib import Path
from typing import Any

from kaitaistruct import KaitaiStream, BytesIO
from PIL import Image
from PIL.PngImagePlugin import PngInfo

from tools.splat_ext.img import PSXSegSizedImg
from tools.libdata.img import (
    generate_grayscale_palette, get_png_bit_depth, pack_4bpp,
    read_clut_chunk, write_clut_chunk, write_indexed_png,
)
from tools.kaitai.parsers.lib.img import Img


BITDEPTH_TO_MODE = {4: 0, 8: 1}


class PSXSegIndexed(PSXSegSizedImg):

    bitdepth:    int
    num_cluts:   int
    plte_clut:   int | None
    cluts_after: bool

    def __init__(self, **kwargs: Any) -> None:
        super().__init__(**kwargs)

        yaml = kwargs['yaml']

        if isinstance(yaml, dict):
            self.bitdepth    = int(yaml.get('bitdepth', 4))
            self.num_cluts   = int(yaml.get('num_cluts', 1))
            self.cluts_after = bool(yaml.get('cluts_after', False))
            self.plte_clut   = yaml.get('plte_clut')
        elif isinstance(yaml, (list, tuple)):
            self.bitdepth    = int(yaml[5]) if len(yaml) > 5 else 4
            self.num_cluts   = int(yaml[6]) if len(yaml) > 6 else 1
            self.cluts_after = bool(yaml[7]) if len(yaml) > 7 else False
            self.plte_clut   = yaml[8] if len(yaml) > 8 else None
       
        if self.bitdepth not in BITDEPTH_TO_MODE:
            raise ValueError(f'PSXSegIndexed: bitdepth must be 4 or 8, got {self.bitdepth}')

        if self.plte_clut is not None:
            self.plte_clut = int(self.plte_clut)
            if not (0 <= self.plte_clut < self.num_cluts):
                raise ValueError(f'PSXSegIndexed: plte_clut {self.plte_clut} out of range for num_cluts={self.num_cluts}')

    def split(self, rom_bytes: bytes) -> None:
        parsed = Img.ClutsIndices(
            BITDEPTH_TO_MODE[self.bitdepth],
            self.num_cluts,
            self.cluts_after,
            KaitaiStream(BytesIO(rom_bytes[self.rom_start:self.rom_end]))
        )

        if self.plte_clut == None:
            palette = bytes(generate_grayscale_palette(1 << self.bitdepth))
        else:
            cluts = parsed.cluts
            assert cluts is not None
            palette = bytes(
                channel
                for color in cluts[self.plte_clut].colors
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

    @classmethod
    def encode_to_binary(cls, image_path: Path) -> tuple[bytes, list[tuple[str, int]]]:
        pixel_bytes, raw_clut, cluts_after = encode(image_path)
        symbol_name = PSXSegIndexed.symbol_name_from_path(image_path)

        first, second = (pixel_bytes, raw_clut) if cluts_after else (raw_clut, pixel_bytes)

        first_name, second_name = (
            (symbol_name, f'{symbol_name}_clut') if cluts_after
            else (f'{symbol_name}_clut', symbol_name)
        )

        binary = first + second
        symbols = [(first_name, 0), (second_name, len(first))]
        return binary, symbols


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
    PSXSegIndexed.run_encoder()
