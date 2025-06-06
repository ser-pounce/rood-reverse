import sys
import ctypes
import png


class Pixel(ctypes.LittleEndianStructure):
    _fields_ = [
        ("r", ctypes.c_uint16, 5),
        ("g", ctypes.c_uint16, 5),
        ("b", ctypes.c_uint16, 5),
        ("a", ctypes.c_uint16, 1),
    ]

def to_rgba8888(data, count):
    pxls = Pixel * count
    pxls = pxls.from_buffer_copy(data)
    img = bytearray(
        [channel for p in pxls for channel in (p.r, p.g, p.b, 31 if p.a == 0 else 0)]
    )
    return img

def to_png(data, w, h, path):
    img = to_rgba8888(data, w * h)
    to_png_raw(img, w, h, path)
        
def to_png_raw(data, w, h, path):
    with open(path, "wb") as f:
        png.Writer(width=w, height=h, alpha=True, greyscale=False, bitdepth=5) \
            .write_array(f, data)

def to_bytes(png_path):

    w, h, data, _ = png.Reader(png_path).read_flat()

    output = bytes()

    for i in range(0, len(data), 4):
        r, g, b, a = data[i : i + 4]
        output += Pixel(r >> 3, g >> 3, b >> 3, 1 if a == 0 else 0)
        
    return (output, w, h)

if __name__ == '__main__':
    with open(sys.argv[1], mode="rb") as f:
        data = f.read()
    to_png(data, int(sys.argv[2]), int(sys.argv[3]), sys.argv[4])
