import sys
from pathlib import Path
import ctypes
from splat.segtypes.segment import Segment
from splat.util import options
from tools.etc.rgba16 import to_png, to_bytes


class Header(ctypes.LittleEndianStructure):
    _fields_ = [
        ("w", ctypes.c_uint16),
        ("h", ctypes.c_uint16),
    ]

class PSXSegRgba16(Segment):

    def out_path(self) -> Path:
        type_extension = f".{self.type}" if options.opts.image_type_in_extension else ""
        return options.opts.asset_path / self.dir / f"{self.name}{type_extension}.png"
    
    def split(self, rom_bytes):

        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)

        h = Header.from_buffer_copy(rom_bytes[self.rom_start:])
        to_png(rom_bytes[self.rom_start + ctypes.sizeof(h):], h.w, h.h, path)


if __name__ == '__main__':
    data, w, h = to_bytes(sys.argv[1])
    header = Header(w, h)
    
    with open(sys.argv[2], "wb") as f:
        f.write(bytearray(header))
        f.write(data)