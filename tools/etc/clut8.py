import sys
import png

        
def to_png(raw, w, h, path):
    with open(path, "wb") as f:
        img = png.Writer(width=w, height=h, bitdepth=8)
        img.write_array(f, raw)

def to_bytes(png_path):
    w, h, data, _ = png.Reader(png_path).read_flat()
    return (data, w, h)

if __name__ == '__main__':
    width, height = int(sys.argv[2]), int(sys.argv[3])
    with open(sys.argv[1], mode="rb") as f:
        data = f.read()
    to_png(data, width, height, sys.argv[4])
