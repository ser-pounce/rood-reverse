import sys
import png
from tools.splat_ext.img import PSXSegImg


class PSXSegRgb4(PSXSegImg):

    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        if len(kwargs['yaml']) < 5:
            raise ValueError("PSXSegRgb4 requires width and height")
    
    def split(self, rom_bytes):
        with open(self.make_path(), "wb") as f:
            data = bytes(
                nibble
                for b in rom_bytes[self.rom_start:self.rom_end]
                for nibble in [b & 0x0F, (b >> 4) & 0x0F]
            )
            img = png.Writer(width=self.width, height=self.height, bitdepth=4)
            img.write_array(f, data)


if __name__ == '__main__':
    _, _, data, _ = png.Reader(sys.argv[1]).read_flat()
    packed = bytearray(
        (data[i] & 0x0F) | ((data[i+1] & 0x0F) << 4)
        for i in range(0, len(data), 2)
    )
    with open(sys.argv[2], "wb") as f:
        f.write(packed)