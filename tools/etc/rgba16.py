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
        [channel for p in pxls for channel in (p.r, p.g, p.b, 31 if p.a == 0 else 30)]
    )
    return img

def to_png(data, w, h, path):
    with open(path, "wb") as f:
        png.Writer(width=w, height=h, alpha=True, greyscale=False, bitdepth=5) \
            .write_array(f, data)

def to_bytes(png_path):
    w, h, data, _ = png.Reader(png_path).read_flat()
    output = bytes()
    for i in range(0, len(data), 4):
        r, g, b, a = data[i : i + 4]
        print
        output += Pixel(r >> 3, g >> 3, b >> 3, 0 if (a >> 3) == 31 else 1)
    return (output, w, h)

if __name__ == '__main__':
    width, height = int(sys.argv[2]), int(sys.argv[3])
    with open(sys.argv[1], mode="rb") as f:
        data = f.read()
    img = to_rgba8888(data, width * height)
    to_png(img, width, height, sys.argv[4])
