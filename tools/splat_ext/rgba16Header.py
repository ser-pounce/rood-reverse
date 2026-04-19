import ctypes
import sys
from pathlib import Path
from typing import Any

from tools.splat_ext.img import PSXSegImg
from tools.etc.rgba16 import to_rgba8888, to_png, to_bytes


class Header(ctypes.LittleEndianStructure):
    _fields_ = [
        ("w", ctypes.c_uint16),
        ("h", ctypes.c_uint16),
    ]

HEADER_SIZE = ctypes.sizeof(Header)


class PSXSegRgba16Header(PSXSegImg):
    def split(self, rom_bytes: bytes) -> None:
        header = Header.from_buffer_copy(rom_bytes[self.rom_start:])
        img    = to_rgba8888(rom_bytes[self.rom_start + HEADER_SIZE:], header.w * header.h)
        to_png(img, header.w, header.h, self.make_path())


if __name__ == '__main__':
    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument('input',  type=Path, help='Input PNG file')
    parser.add_argument('output', type=Path, help='Output file')
    parser.add_argument('--dat',  action='store_true', help='Write a .dat text file instead of a .o object file')
    args = parser.parse_args()

    data, width, height = to_bytes(str(args.input))
    binary      = bytes(Header(width, height)) + data
    symbol_name = args.input.name.split('.')[0]

    if args.dat:
        with open(args.output, 'w') as h:
            for byte in binary:
                h.write(f'0x{byte:02X},')
    else:
        PSXSegRgba16Header.write_object_file(
            binary,
            args.output,
            [(f'{symbol_name}_header', 0),
             (f'{symbol_name}_data',   HEADER_SIZE)],
            *PSXSegRgba16Header.objcopy_from_env(),
        )