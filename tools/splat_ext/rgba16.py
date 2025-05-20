import sys
from pathlib import Path
import ctypes
import png
from splat.segtypes.segment import Segment
from splat.util import options


class Pixel(ctypes.LittleEndianStructure):
    _fields_ = [
        ("r", ctypes.c_uint16, 5),
        ("g", ctypes.c_uint16, 5),
        ("b", ctypes.c_uint16, 5),
        ("a", ctypes.c_uint16, 1),
    ]

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

        h = Header.from_buffer_copy(rom_bytes[self.rom_start:])
        dat = Pixel * (h.w * h.h)
        dat = dat.from_buffer_copy(rom_bytes[self.rom_start + ctypes.sizeof(h):])

        img = bytearray(
            [channel for p in dat for channel in (p.r, p.g, p.b, 31 if p.a == 0 else 0)]
        )

        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)

        with open(path, "wb") as f:
            png.Writer(width=h.w, height=h.h, alpha=True, greyscale=False, bitdepth=5) \
                .write_array(f, img)
            
    @staticmethod
    def to_bytes(input_path, output_path):

        w, h, data, _ = png.Reader(input_path).read_flat()
        h = Header(w, h)
        
        with open(output_path, "wb") as f:
            f.write(bytearray(h))

            for i in range(0, len(data), 4):
                r, g, b, a = data[i : i + 4]
                p = Pixel(r >> 3, g >> 3, b >> 3, 1 if a == 0 else 0)
                f.write(bytearray(p))

if __name__ == '__main__':
    PSXSegRgba16.to_bytes(sys.argv[1], sys.argv[2])