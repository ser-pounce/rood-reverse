import struct
from pathlib import Path

from PIL import Image
from PIL.PngImagePlugin import PngInfo


def rgb888_to_bgr555(r: int, g: int, b: int) -> int:
    return ((b >> 3) << 10) | ((g >> 3) << 5) | (r >> 3)


def generate_grayscale_palette(n_colors: int) -> list[tuple[int, int, int]]:
    scale = 255 // (n_colors - 1)
    palette = []
    for i in range(n_colors):
        v = (i * scale)
        palette.extend((v, v, v))
    return palette


def decode_grayscale(data: bytes, width: int, height: int, bpp: int, output_path: Path, info: PngInfo = None) -> None:
    img = Image.frombytes('P', (width, height), data)
    img.putpalette(generate_grayscale_palette(1 << bpp))
    img.save(output_path, pnginfo=info, bits=bpp)


def pack_4bpp(data: bytes) -> bytes:
    packed = bytearray((len(data) + 1) // 2)
    for i in range(0, len(data), 2):
        lo = data[i] & 0x0F
        hi = data[i + 1] & 0x0F if i + 1 < len(data) else 0
        packed[i // 2] = lo | (hi << 4)
    return bytes(packed)


def decode_8bpp_bin(pixels: bytes, width: int, height: int, clut: list[tuple[int, int, int]], output_path: Path) -> None:
    img = Image.frombytes('P', (width, height), pixels)
    img.putpalette(bytes(channel for color in clut for channel in color))
    img.save(output_path)


def encode_8bpp_bin(pixels: bytes, palette: list[int], output_path: Path) -> None:

    words = [
        rgb888_to_bgr555(*palette[i:i + 3]) | 0x8000
        for i in range(0, 256 * 3, 3)
    ]

    output_path.write_bytes(struct.pack('<256H', *words) + pixels)
