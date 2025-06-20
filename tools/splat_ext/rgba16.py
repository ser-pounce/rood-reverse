import sys
import ctypes
from tools.splat_ext.img import PSXSegImg
from tools.etc.rgba16 import to_rgba8888, to_png, to_bytes


class Header(ctypes.LittleEndianStructure):
    _fields_ = [
        ("w", ctypes.c_uint16),
        ("h", ctypes.c_uint16),
    ]

class PSXSegRgba16(PSXSegImg):

    def split(self, rom_bytes):
        path = self.make_path()
        img = to_rgba8888(rom_bytes[self.rom_start:], self.width * self.height)
        to_png(img, self.width, self.height, path)


if __name__ == '__main__':
    data, _, _ = to_bytes(sys.argv[1])
    with open(sys.argv[2], "wb") as f:
        f.write(data)