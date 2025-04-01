from pathlib import Path
from splat.segtypes.segment import Segment
from splat.util import options
import png
import sys

class PSXSegRgba16(Segment):

    def out_path(self) -> Path:
        type_extension = f".{self.type}" if options.opts.image_type_in_extension else ""
        return options.opts.asset_path / self.dir / f"{self.name}{type_extension}.png"
    
    def split(self, rom_bytes):
        w = self.from_Uint16(rom_bytes, self.rom_start)
        h = self.from_Uint16(rom_bytes, self.rom_start + 2)

        img = bytearray()

        for i in range(self.rom_start + 4, self.rom_end, 2):
            s = self.from_Uint16(rom_bytes, i)

            r = s & 0x1F
            g = (s >> 5) & 0x1F
            b = (s >> 10) & 0x1F
            a = 31 if ((s >> 15) & 1) == 0 else 0
            img += bytes((r, g, b, a))

        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)

        with open(path, "wb") as f:
            png.Writer(width=w, height=h, alpha=True, greyscale=False, bitdepth=5) \
                .write_array(f, img)

    @staticmethod
    def from_Uint16(bytes, pos):
        return int.from_bytes(bytes[pos : pos + 2], byteorder='little')
    
    @staticmethod
    def to_Uint16(val):
        return val.to_bytes(2, byteorder='little')
            
    @staticmethod
    def to_bytes(input_path, output_path):
        w, h, data, _ = png.Reader(input_path).read_flat()
        
        with open(output_path, "wb") as f:
            f.write(PSXSegRgba16.to_Uint16(w))
            f.write(PSXSegRgba16.to_Uint16(h))

            for i in range(0, len(data), 4):
                r, g, b, a = data[i : i + 4]
                f.write(PSXSegRgba16.to_Uint16(
                    (r >> 3)          | 
                    ((g & 0xF8) << 2) | 
                    ((b & 0xF8) << 7) | 
                    (0x8000 if a == 0 else 0)
                ))

if __name__ == '__main__':
    PSXSegRgba16.to_bytes(sys.argv[1], sys.argv[2])