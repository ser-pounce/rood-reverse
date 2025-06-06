import sys
import ctypes
from tools.etc.rgba16 import to_png_raw, to_bytes, to_rgba8888
from tools.splat_ext.rgba16 import PSXSegRgba16


class BlockHeader(ctypes.LittleEndianStructure):
    _fields_ = [
        ("black", ctypes.c_uint32, 16),
        ("rgba", ctypes.c_uint32, 16),
    ]

class PSXSegRgba16Compressed(PSXSegRgba16):

    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        if len(kwargs['yaml']) < 5:
            raise ValueError("PSXSegRgba16Compressed requires width and height")
    
    def split(self, rom_bytes):
        data = bytearray()
        i = self.rom_start
        while i < self.rom_end:
            block = BlockHeader.from_buffer_copy(rom_bytes[i:])
            i += ctypes.sizeof(BlockHeader)
            data.extend(b'\x00' * block.black * 2 * 4)
            data.extend(to_rgba8888(rom_bytes[i:], block.rgba * 2))
            i += block.rgba * 4
            
        path = self.make_path()
        to_png_raw(data, self.width, self.height, path)


if __name__ == '__main__':
    data, w, h = to_bytes(sys.argv[1])
    wordLen = len(data) // ctypes.sizeof(ctypes.c_uint32)
    words = (ctypes.c_uint32 * wordLen).from_buffer_copy(data)
    output = bytearray()
    i = 0
    while i < wordLen:
        header = BlockHeader()
        while i < wordLen and words[i] == 0x80008000:
            header.black += 1
            i += 1
        while i < wordLen and words[i] != 0x80008000:
            header.rgba += 1
            i += 1
        output.extend(header)
        output.extend(data[
            (i - header.rgba) * ctypes.sizeof(ctypes.c_uint32) : 
            i * ctypes.sizeof(ctypes.c_uint32)
        ])
    
    with open(sys.argv[2], "wb") as f:
        f.write(output)
    