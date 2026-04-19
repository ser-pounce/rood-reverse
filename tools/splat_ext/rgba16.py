import sys
import ctypes
from pathlib import Path
from typing import Any

from tools.splat_ext.img import PSXSegImg
from tools.etc.rgba16 import to_rgba8888, to_png, to_bytes


class PSXSegRgba16(PSXSegImg):

    def split(self, rom_bytes: bytes) -> None:
        img = to_rgba8888(rom_bytes[self.rom_start:], self.width * self.height)
        to_png(img, self.width, self.height, self.make_path())


if __name__ == '__main__':
    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument('input',  type=Path, help='Input PNG file')
    parser.add_argument('output', type=Path, help='Output file')
    parser.add_argument('--dat',  action='store_true', help='Write a .dat text file instead of a .o object file')
    args = parser.parse_args()

    data, _, _  = to_bytes(str(args.input))
    binary      = bytes(data)
    symbol_name = args.input.name.split('.')[0]

    if args.dat:
        with open(args.output, 'w') as h:
            for byte in binary:
                h.write(f'0x{byte:02X},')
    else:
        PSXSegRgba16.write_object_file(
            binary,
            args.output,
            [(symbol_name, 0)],
            *PSXSegRgba16.objcopy_from_env(),
        )