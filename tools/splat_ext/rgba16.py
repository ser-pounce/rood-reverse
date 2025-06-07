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

    def needs_header(self):
        return not (hasattr(self, 'width') and hasattr(self, 'height'))
    
    def split(self, rom_bytes):
        offset = self.rom_start
        if (self.needs_header()):
            header = Header.from_buffer_copy(rom_bytes[self.rom_start:])
            width, height = header.w, header.h
            offset += ctypes.sizeof(Header)
        else:
            width, height = self.width, self.height
        path = self.make_path()
        img = to_rgba8888(rom_bytes[offset:], width * height)
        to_png(img, width, height, path)


if __name__ == '__main__':
    data, width, height = to_bytes(sys.argv[1])
    with open(sys.argv[2], "wb") as f:
        if len(sys.argv) == 3:
            header = Header(width, height)
            f.write(bytearray(header))
        f.write(data)