import struct
from pathlib import Path
from typing import Any

from PIL import Image
from PIL.PngImagePlugin import PngInfo

from tools.kaitai.parsers.lib.img import Img


def get_png_bit_depth(png_path: Path) -> int:
    with open(png_path, 'rb') as f:
        f.seek(24)
        bitdepth = f.read(1)[0]

    if bitdepth not in (4, 8):
        raise ValueError(f'Expected 4-bit or 8-bit indexed PNG: {png_path}')

    return bitdepth


def write_indexed_png(
    data: bytes,
    width: int,
    height: int,
    palette: bytes,
    output_path: Path,
    bpp: int | None = None,
    info: PngInfo | None = None,
) -> None:
    img = Image.frombytes('P', (width, height), data)
    img.putpalette(palette)

    save_kwargs: dict[str, Any] = {'pnginfo': info}
    if bpp is not None:
        save_kwargs['bits'] = bpp

    img.save(output_path, **save_kwargs)


def generate_grayscale_palette(n_colors: int) -> list[int]:
    scale = 255 // (n_colors - 1)
    palette = []
    for i in range(n_colors):
        v = (i * scale)
        palette.extend((v, v, v))
    return palette


def decode_grayscale(data: bytes, width: int, height: int, bpp: int, output_path: Path, info: PngInfo | None = None) -> None:
    palette = bytes(generate_grayscale_palette(1 << bpp))
    write_indexed_png(data, width, height, palette, output_path, bpp=bpp, info=info)


def decode_8bpp_bin(pixels: bytes, width: int, height: int, clut: list[tuple[int, int, int]], output_path: Path) -> None:
    palette = bytes(channel for color in clut for channel in color)
    write_indexed_png(pixels, width, height, palette, output_path)


def decode_highcolor(width: int, height: int, colors: list[Img.Rgb5], output_path: Path, info: PngInfo | None = None) -> None:
    pixels = bytearray(width * height * 4)
    stp_packed = bytearray((width * height + 7) // 8)

    for i, pixel in enumerate(colors):
        r8, g8, b8, a8 = pixel.r8, pixel.g8, pixel.b8, pixel.a8
        assert r8 is not None and g8 is not None and b8 is not None and a8 is not None
        pixels[i * 4 : i * 4 + 4] = bytes((r8, g8, b8, a8))
        if pixel.stp:
            stp_packed[i >> 3] |= 0x80 >> (i & 7)

    if info is None:
        info = PngInfo()

    img = Image.frombytes('RGBA', (width, height), bytes(pixels))
    info.add(b'stPd', bytes(stp_packed), after_idat=True)
    img.save(output_path, pnginfo=info)


CLUT_CHUNK_AFTER  = b'clUa'
CLUT_CHUNK_BEFORE = b'clUb'


def write_clut_chunk(info: PngInfo, raw_cluts: bytes, cluts_after: bool) -> None:
    chunk_name = CLUT_CHUNK_AFTER if cluts_after else CLUT_CHUNK_BEFORE
    info.add(chunk_name, raw_cluts, after_idat=True)


def read_clut_chunk(img: Image.Image) -> tuple[bytes, bool]:
    raw_after  = get_chunk(img, CLUT_CHUNK_AFTER.decode())
    raw_before = get_chunk(img, CLUT_CHUNK_BEFORE.decode())

    if raw_after is not None and raw_before is not None:
        raise ValueError(f'found both {CLUT_CHUNK_AFTER} and {CLUT_CHUNK_BEFORE} chunks')

    if raw_after is not None:
        return raw_after, True
    if raw_before is not None:
        return raw_before, False
    return bytes(), False


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


def get_chunk(img: Image.Image, name: str) -> bytes | None:
    name_bytes = name.encode("latin-1")
    chunks: list[tuple[bytes, bytes]] = getattr(img, 'private_chunks', [])
    return next((chunk[1] for chunk in chunks if chunk[0] == name_bytes), None)


def encode_highColor(img: Image.Image) -> bytes:
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
