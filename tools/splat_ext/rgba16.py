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

    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        if len(kwargs['yaml']) > 3:
            self.width = kwargs['yaml'][3]
            self.height = kwargs['yaml'][4]

    def out_path(self) -> Path:
        type_extension = f".{self.type}" if options.opts.image_type_in_extension else ""
        return options.opts.asset_path / self.dir / f"{self.name}{type_extension}.png"
    
    def make_path(self) -> Path:
        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)
        return path
    
    def get_wh(self, rom_bytes):
        if hasattr(self, 'width') and hasattr(self, 'height'):
            return self.width, self.height
        else:
            header = Header.from_buffer_copy(rom_bytes[self.rom_start:])
            return header.w, header.h
        
    def get_data_offset(self):
        if hasattr(self, 'width') and hasattr(self, 'height'):
            return self.rom_start
        else:
            return self.rom_start + ctypes.sizeof(Header)
    
    def split(self, rom_bytes):
        path = self.make_path()
        to_png(rom_bytes[self.get_data_offset():], *self.get_wh(rom_bytes), path)


if __name__ == '__main__':
    data, w, h = to_bytes(sys.argv[1])
   
    with open(sys.argv[2], "wb") as f:
        if len(sys.argv) == 3:
            header = Header(w, h)
            f.write(bytearray(header))
        f.write(data)