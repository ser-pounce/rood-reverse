import ctypes
import sys
from pathlib import Path
from typing import Any

from tools.splat_ext.img import PSXSegImg
from tools.etc.rgba16 import to_rgba8888, to_png, to_bytes


class BlockHeader(ctypes.LittleEndianStructure):
    _fields_ = [
        ("black", ctypes.c_uint32, 16),
        ("rgba",  ctypes.c_uint32, 16),
    ]

BLOCK_HEADER_SIZE = ctypes.sizeof(BlockHeader)
WORD_SIZE         = ctypes.sizeof(ctypes.c_uint32)
TRANSPARENT_PIXEL = b'\x00\x00\x00\x00'
TRANSPARENT_WORD  = 0x80008000


class PSXSegRgba16Compressed(PSXSegImg):

    def __init__(self, **kwargs: Any) -> None:
        super().__init__(**kwargs)
        if len(kwargs['yaml']) < 5:
            raise ValueError('PSXSegRgba16Compressed requires width and height')

    def split(self, rom_bytes: bytes) -> None:
        data = bytearray()
        i    = self.rom_start
        while i < self.rom_end:
            block = BlockHeader.from_buffer_copy(rom_bytes[i:])
            i    += BLOCK_HEADER_SIZE
            data.extend(TRANSPARENT_PIXEL * block.black * 2)
            data.extend(to_rgba8888(rom_bytes[i:], block.rgba * 2))
            i    += block.rgba * 4

        to_png(data, self.width, self.height, self.make_path())


def compress(data: bytes) -> bytearray:
    """Compress raw RGBA16 pixel data into the block-run format."""
    word_len = len(data) // WORD_SIZE
    words    = (ctypes.c_uint32 * word_len).from_buffer_copy(data)
    output   = bytearray()
    i        = 0
    while i < word_len:
        block = BlockHeader()
        while i < word_len and words[i] == TRANSPARENT_WORD:
            block.black += 1
            i           += 1
        while i < word_len and words[i] != TRANSPARENT_WORD:
            block.rgba += 1
            i          += 1
        output.extend(block)
        rgba_start = (i - block.rgba) * WORD_SIZE
        rgba_end   = i * WORD_SIZE
        output.extend(data[rgba_start:rgba_end])
    return output


if __name__ == '__main__':
    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument('input',  type=Path, help='Input PNG file')
    parser.add_argument('output', type=Path, help='Output file')
    parser.add_argument('--dat',  action='store_true', help='Write a .dat text file instead of a .o object file')
    args = parser.parse_args()

    data, w, h  = to_bytes(str(args.input))
    binary      = bytes(compress(data))
    symbol_name = args.input.name.split('.')[0]

    if args.dat:
        with open(args.output, 'w') as h:
            for byte in binary:
                h.write(f'0x{byte:02X},')
    else:
        PSXSegRgba16Compressed.write_object_file(
            binary,
            args.output,
            [(symbol_name, 0)],
            *PSXSegRgba16Compressed.objcopy_from_env(),
        )