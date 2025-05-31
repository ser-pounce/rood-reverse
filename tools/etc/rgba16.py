import ctypes
import png


class Pixel(ctypes.LittleEndianStructure):
    _fields_ = [
        ("r", ctypes.c_uint16, 5),
        ("g", ctypes.c_uint16, 5),
        ("b", ctypes.c_uint16, 5),
        ("a", ctypes.c_uint16, 1),
    ]

def to_png(data, w, h, path):
    dat = Pixel * (w * h)
    dat = dat.from_buffer_copy(data)
    img = bytearray(
        [channel for p in dat for channel in (p.r, p.g, p.b, 31 if p.a == 0 else 0)]
    )
    with open(path, "wb") as f:
        png.Writer(width=w, height=h, alpha=True, greyscale=False, bitdepth=5) \
            .write_array(f, img)

def to_bytes(png_path):

    w, h, data, _ = png.Reader(png_path).read_flat()

    output = bytes()

    for i in range(0, len(data), 4):
        r, g, b, a = data[i : i + 4]
        output += Pixel(r >> 3, g >> 3, b >> 3, 1 if a == 0 else 0)
        
    return (output, w, h)