import struct
from pathlib import Path
from typing import Any

from tools.etc.psx_img import (
    Palette,
    decode_image,
    encode_image,
    encode_cluts,
    pack_pixels,
    read_png,
    write_png,
)
from tools.splat_ext.img import PSXSegImg


# ---------------------------------------------------------------------------
# Splat segment
# ---------------------------------------------------------------------------

class PSXSegRgbClut(PSXSegImg):

    cluts_before: int
    cluts_after:  int
    bitdepth:     int
    clut_entries: int
    plte_clut:    int

    def __init__(self, **kwargs: Any) -> None:
        super().__init__(**kwargs)

        if len(kwargs['yaml']) < 5:
            raise ValueError('PSXSegRgbClut requires width and height')

        if isinstance(kwargs['yaml'], dict):
            self.cluts_before = int(kwargs['yaml'].get('cluts_before', 0))
            self.cluts_after  = int(kwargs['yaml'].get('cluts_after',  0))
            self.bitdepth     = int(kwargs['yaml'].get('bitdepth', 4))
            self.plte_clut    = int(kwargs['yaml'].get('plte_clut', 0))
        else:
            # List-style YAML: clut count parameters must use dict-style
            self.cluts_before = 1
            self.cluts_after  = 0
            self.bitdepth     = 4
            self.plte_clut    = 0

        if self.bitdepth not in (4, 8):
            raise ValueError(f'PSXSegRgbClut: bitdepth must be 4 or 8, got {self.bitdepth}')
        self.clut_entries = 1 << self.bitdepth  # 4-bit -> 16, 8-bit -> 256

    def split(self, rom_bytes: bytes) -> None:
        pixels, before_cluts, after_cluts = decode_image(
            rom_bytes, self.rom_start, self.width, self.height,
            self.bitdepth, self.cluts_before, self.cluts_after,
        )
        png_path = self.make_path()
        write_png(png_path, pixels, self.width, self.height,
                  self.bitdepth, before_cluts, after_cluts, self.plte_clut)


# ---------------------------------------------------------------------------
# CLI re-encoder
# ---------------------------------------------------------------------------

if __name__ == '__main__':
    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument('input',  type=Path, help='Input PNG file')
    parser.add_argument('output', type=Path, help='Output file')
    parser.add_argument('--dat',  action='store_true', help='Write a .dat text file instead of a .o object file')
    args = parser.parse_args()

    pixels, width, height, bitdepth, cluts_before, cluts_after = read_png(args.input)

    packed            = pack_pixels(list(pixels), bitdepth)
    clut_bytes_before = encode_cluts(cluts_before)
    clut_bytes_after  = encode_cluts(cluts_after)

    binary        = bytes(clut_bytes_before + packed + clut_bytes_after)
    symbol_name   = args.input.name.split('.')[0]
    symbol_offset = len(clut_bytes_before)  # pixel data starts after any leading CLUTs

    if args.dat:
        with open(args.output, 'w') as h:
            for byte in binary:
                h.write(f'0x{byte:02X},')
    else:
        if cluts_before:
            symbols = [(f'{symbol_name}_clut', 0), (symbol_name, symbol_offset)]
        elif cluts_after:
            symbols = [(symbol_name, 0), (f'{symbol_name}_clut', len(packed))]
        else:
            symbols = [(symbol_name, 0)]

        PSXSegRgbClut.write_object_file(
            binary,
            args.output,
            symbols,
            *PSXSegRgbClut.objcopy_from_env(),
        )
