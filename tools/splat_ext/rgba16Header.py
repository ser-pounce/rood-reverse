import sys
import ctypes
from tools.splat_ext.img import PSXSegImg
from tools.etc.rgba16 import to_rgba8888, to_png, to_bytes


class Header(ctypes.LittleEndianStructure):
    _fields_ = [
        ("w", ctypes.c_uint16),
        ("h", ctypes.c_uint16),
    ]

class PSXSegRgba16Header(PSXSegImg):
    def split(self, rom_bytes):
        header = Header.from_buffer_copy(rom_bytes[self.rom_start:])
        path = self.make_path()
        img = to_rgba8888(rom_bytes[self.rom_start + ctypes.sizeof(Header):], header.w * header.h)
        to_png(img, header.w, header.h, path)


if __name__ == '__main__':
    data, width, height = to_bytes(sys.argv[1])
    with open(sys.argv[2], "wb") as f:
        header = Header(width, height)
        f.write(bytearray(header))
        f.write(data)