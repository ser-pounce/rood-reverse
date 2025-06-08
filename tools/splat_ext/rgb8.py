import sys
import png
from tools.splat_ext.img import PSXSegImg


class PSXSegRgb8(PSXSegImg):

    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        if len(kwargs['yaml']) < 5:
            raise ValueError("PSXSegRgb8 requires width and height")
    
    def split(self, rom_bytes):
        with open(self.make_path(), "wb") as f:
            raw = rom_bytes[self.rom_start:self.rom_end]
            data = bytearray()
            for i in range(0, len(raw) - 1, 2):
                data.extend([raw[i+1], raw[i]])
            img = png.Writer(width=self.width, height=self.height, bitdepth=8)
            img.write_array(f, data)


if __name__ == '__main__':
    _, _, data, _ = png.Reader(sys.argv[1]).read_flat()
    swapped = bytearray()
    for i in range(0, len(data) - 1, 2):
        swapped.extend([data[i+1], data[i]])
    with open(sys.argv[2], "wb") as f:
        f.write(swapped)