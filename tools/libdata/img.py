import struct
from pathlib import Path

from PIL import Image
from PIL.PngImagePlugin import PngInfo

from tools.kaitai.parsers.lib.img import Img


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


def decode_8bpp_bin(pixels: bytes, width: int, height: int, clut: list[tuple[int, int, int]], output_path: Path) -> None:
    img = Image.frombytes('P', (width, height), pixels)
    img.putpalette(bytes(channel for color in clut for channel in color))
    img.save(output_path)


def decode_highcolor(width: int, height: int, colors: list[Img.Rgb5], output_path: Path, info: PngInfo = None) -> None:
    pixels = bytearray(width * height * 4)
    stp_packed = bytearray((width * height + 7) // 8)

    for i, pixel in enumerate(colors):
        pixels[i * 4 : i * 4 + 4] = (pixel.r8, pixel.g8, pixel.b8, pixel.a8)
        if pixel.stp:
            stp_packed[i >> 3] |= 0x80 >> (i & 7)

    if info is None:
        info = PngInfo()

    img = Image.frombytes('RGBA', (width, height), bytes(pixels))
    info.add(b'stPd', bytes(stp_packed), after_idat=True)
    img.save(output_path, pnginfo=info)


def pack_4bpp(data: bytes) -> bytes:
    packed = bytearray((len(data) + 1) // 2)
    for i in range(0, len(data), 2):
        lo = data[i] & 0x0F
        hi = data[i + 1] & 0x0F if i + 1 < len(data) else 0
        packed[i // 2] = lo | (hi << 4)
    return bytes(packed)


def encode_rgb555(colors: list[int], stp: bool = True) -> bytes:
    words = [
        ((b >> 3) << 10) | ((g >> 3) << 5) | (r >> 3) | (stp << 15)
        for r, g, b in zip(*[iter(colors)] * 3)
    ]

    return struct.pack(f'<{len(words)}H', *words)


def get_chunk(img: Image, name: str) -> bytes:
    name_bytes = name.encode("latin-1")
    return next((c[1] for c in img.private_chunks if c[0] == name_bytes), None)


def encode_highColor(img: Image) -> bytes:
    stp_packed = get_chunk(img, 'stPd')

    if stp_packed is None:
        raise ValueError(f'Png file is missing expected stPd chunk')

    rgba = img.tobytes()
    pixel_count = img.width * img.height
    raw_pixels = [0] * pixel_count

    for i in range(pixel_count):
        r5, g5, b5 = rgba[i * 4] >> 3, rgba[i * 4 + 1] >> 3, rgba[i * 4 + 2] >> 3
        stp = (stp_packed[i >> 3] >> (7 - (i & 7))) & 1
        raw_pixels[i] = (stp << 15) | (b5 << 10) | (g5 << 5) | r5

    return struct.pack(f'<{len(raw_pixels)}H', *raw_pixels)
