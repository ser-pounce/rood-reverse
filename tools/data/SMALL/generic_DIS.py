import argparse
import struct
from pathlib import Path

import yaml
from PIL import Image
from PIL.PngImagePlugin import PngInfo

from tools.kaitai.parsers.data.SMALL.img import Img
from tools.kaitai.parsers.data.SMALL.image_dis import ImageDis


# pypng: Can output 4/8 bit grascale .pngs, but doesn't offer a nice
# interface for chunks.
# Pillow: Has excellent chunk support but no 4/8 bit grayscale support.
# Pillow wins on overall simplicity. 


def _build_pnginfo(text: dict[str, str], raw: dict[bytes, bytes]) -> PngInfo:
    info = PngInfo()
    for keyword, value in text.items():
        info.add_text(keyword, value)
    for chunk_type, data in raw.items():
        info.add(chunk_type, data, after_idat=True)
    return info


def _read_private_chunks(img: Image.Image) -> dict[bytes, bytes]:
    return {c[0]: c[1] for c in reversed(img.private_chunks)}


def _read_ihdr_bitdepth(png_path: Path) -> int:
    with open(png_path, 'rb') as f:
        f.seek(24)  # signature(8) + length(4) + type(4) + width(4) + height(4)
        return f.read(1)[0]


def _parse_rect(value: str | None) -> tuple[int, int, int, int] | None:
    if not value:
        return None
    parts = value.split(',')
    if len(parts) != 4:
        return None
    try:
        return tuple(int(p.strip()) for p in parts)
    except ValueError:
        return None


def _parse_point(value: str | None) -> tuple[int, int] | None:
    if not value:
        return None
    parts = value.split(',')
    if len(parts) != 2:
        return None
    try:
        return tuple(int(p.strip()) for p in parts)
    except ValueError:
        return None


def _write_tim_png(
    output_path: Path,
    img: Image.Image,
    img_offset:  tuple[int, int] | None,
    clut:        list[int],
    clut_rect:   tuple[int, int, int, int] | None,
    extra_raw:   dict[bytes, bytes] | None = None,
    bits:        int | None = None,
) -> None:
    text: dict[str, str] = {}
    if img_offset is not None:
        text['tim_offset'] = f'{img_offset[0]},{img_offset[1]}'
    if clut_rect is not None:
        text['tim_clut_rect'] = ','.join(map(str, clut_rect))

    raw: dict[bytes, bytes] = dict(extra_raw) if extra_raw else {}
    if clut:
        raw[b'clUb'] = struct.pack(f'<{len(clut)}H', *clut)

    meta = _build_pnginfo(text, raw)
    save_kwargs = {'pnginfo': meta}
    if bits is not None:
        save_kwargs['bits'] = bits
    img.save(output_path, **save_kwargs)


def _read_tim_png(png_path: Path) -> tuple[
    Image.Image,
    tuple[int, int] | None,
    list[int],
    tuple[int, int, int, int] | None,
    dict[bytes, bytes],
]:
    img = Image.open(png_path)
    img.load()

    img_offset = _parse_point(img.text.get('tim_offset'))
    clut_rect  = _parse_rect(img.text.get('tim_clut_rect'))

    private = _read_private_chunks(img)
    clut_bytes = private.pop(b'clUb', b'')
    clut = list(struct.unpack(f'<{len(clut_bytes) // 2}H', clut_bytes)) if clut_bytes else []

    return img, img_offset, clut, clut_rect, private


def _clut_from_tim(tim: Img.Tim) -> tuple[list[int], tuple[int, int, int, int] | None]:
    if not tim.has_clut:
        return [], None
    section = tim.clut
    return (
        [c.raw for c in section.clut.colors],
        (section.rect.x, section.rect.y, section.rect.w, section.rect.h),
    )


def _indexed_palette(bitdepth: int) -> list[int]:
    n_colors = 1 << bitdepth
    scale = 255 // (n_colors - 1)
    palette = []
    for i in range(256):
        v = (i * scale) if i < n_colors else 0
        palette.extend((v, v, v))
    return palette


def _pack_indexed_pixels(pixels: list[int], bitdepth: int) -> bytes:
    if bitdepth != 4:
        return bytes(pixels)
    packed = bytearray((len(pixels) + 1) // 2)
    for i in range(0, len(pixels), 2):
        lo = pixels[i] & 0x0F
        hi = pixels[i + 1] & 0x0F if i + 1 < len(pixels) else 0
        packed[i // 2] = lo | (hi << 4)
    return bytes(packed)


def _pack_16bpp_pixels(img: Image.Image, stp_packed: bytes) -> list[int]:
    w, h = img.size
    rgba = img.tobytes()
    pixel_count = w * h
    raw_pixels = [0] * pixel_count

    for i in range(pixel_count):
        r5, g5, b5 = rgba[i * 4] >> 3, rgba[i * 4 + 1] >> 3, rgba[i * 4 + 2] >> 3
        stp = (stp_packed[i >> 3] >> (7 - (i & 7))) & 1
        raw_pixels[i] = (stp << 15) | (b5 << 10) | (g5 << 5) | r5

    return raw_pixels


def decode_tim(tim: Img.Tim, output_path: Path) -> None:
    clut, clut_rect = _clut_from_tim(tim)
    extra_raw: dict[bytes, bytes] = {}
    bits: int | None = None

    if tim.mode == 2:
        w, h = tim.rect.w, tim.rect.h
        pixels = bytearray(w * h * 4)
        stp_packed = bytearray((w * h + 7) // 8)

        for i, pixel in enumerate(tim.indices.index):
            pixels[i * 4 : i * 4 + 4] = (pixel.r8, pixel.g8, pixel.b8, pixel.a8)
            if pixel.stp:
                stp_packed[i >> 3] |= 0x80 >> (i & 7)

        img = Image.frombytes('RGBA', (w, h), bytes(pixels))
        extra_raw[b'stPd'] = bytes(stp_packed)

    else:
        bpp = {0: 4, 1: 8}[tim.mode]
        width, height = tim.rect.w * 16 // bpp, tim.rect.h

        img = Image.frombytes('P', (width, height), bytes(tim.indices.index))
        img.putpalette(_indexed_palette(bpp))
        bits = bpp

    _write_tim_png(
        output_path, img,
        img_offset=(tim.rect.x, tim.rect.y),
        clut=clut, clut_rect=clut_rect,
        extra_raw=extra_raw, bits=bits,
    )


def _write_iq_table_yaml(iq_table: ImageDis.IqTable, output_path: Path) -> None:
    entries = [
        {
            'zoneId': entry.zone_id,
            'mapId': entry.map_id,
            'parTime': entry.par_time,
            'rankCap': entry.rank_cap,
        }
        for entry in iq_table.iq_data
    ]
    with open(output_path, 'w') as f:
        yaml.safe_dump(entries, f, default_flow_style=False, sort_keys=False)


def _read_iq_table_yaml(path: Path) -> list[dict[str, int]]:
    with open(path) as f:
        return yaml.safe_load(f) or []


def _pack_iq_table(entries: list[dict[str, int]]) -> bytes:
    out = bytearray()
    for entry in entries:
        out += struct.pack(
            '<4H',
            entry['zoneId'], entry['mapId'], entry['parTime'], entry['rankCap'],
        )
    return bytes(out)


def decode_dis(input_path: Path, output_path: Path) -> None:
    dis = ImageDis.from_file(str(input_path))
    sections = dis.sections

    iq_table: ImageDis.IqTable | None = None
    if sections and isinstance(sections[-1].body, ImageDis.IqTable):
        iq_table = sections[-1].body
        sections = sections[:-1]

    tims: list[Img.Tim] = [s.body for s in sections]

    if len(tims) == 1 and iq_table is None:
        if output_path.exists() and output_path.is_dir():
            output_path = output_path / f"{input_path.stem}.png"
        decode_tim(tims[0], output_path)
        return

    if output_path.exists() and output_path.is_file():
        raise ValueError(f"Output path must be a directory for {len(tims)} PNG files: {output_path}")
    output_path.mkdir(parents=True, exist_ok=True)
    for i, tim in enumerate(tims):
        decode_tim(tim, output_path / f"{i:04d}.png")

    if iq_table is not None:
        _write_iq_table_yaml(iq_table, output_path / "iq_table.yaml")


def _pack_tim(
    pixel_data:   bytes,
    mode:         int,
    stored_width: int,
    height:       int,
    clut:         list[int],
    img_offset:   tuple[int, int],
    clut_rect:    tuple[int, int, int, int] | None,
) -> bytes:
    has_clut = bool(clut)
    flags = mode | (8 if has_clut else 0)
    out = struct.pack("<II", 0x10, flags)

    if has_clut:
        if clut_rect is None:
            raise ValueError("CLUT present but no clut_rect")
        clut_bytes = struct.pack(f'<{len(clut)}H', *clut)
        clut_len = 12 + len(clut_bytes)
        out += struct.pack("<I4h", clut_len, *clut_rect) + clut_bytes

    img_len = 12 + len(pixel_data)
    out += struct.pack("<I4h", img_len, img_offset[0], img_offset[1], stored_width, height)
    out += pixel_data

    return out


def encode_tim(png_path: Path) -> bytes:
    img, img_offset, clut, clut_rect, private = _read_tim_png(png_path)
    if img_offset is None:
        img_offset = (0, 0)

    if img.mode == 'RGBA':
        stp_packed = private.get(b'stPd')
        if stp_packed is None:
            raise ValueError(f'{png_path} is missing expected stPd chunk')
        raw_pixels = _pack_16bpp_pixels(img, stp_packed)
        pixel_data = struct.pack(f'<{len(raw_pixels)}H', *raw_pixels)
        mode = 2
        stored_width = img.width  # 16bpp: 1 pixel == 1 stored word, no scaling

    elif img.mode == 'P':
        bitdepth = _read_ihdr_bitdepth(png_path)
        if bitdepth not in (4, 8):
            raise ValueError(f'Expected 4-bit or 8-bit indexed PNG, got bitdepth={bitdepth}: {png_path}')
        if not clut:
            raise ValueError(f'Indexed image needs a CLUT: {png_path}')
        pixel_data = _pack_indexed_pixels(list(img.tobytes()), bitdepth)
        mode = 1 if bitdepth == 8 else 0
        stored_width = img.width * bitdepth // 16

    else:
        raise ValueError(f'Unsupported PNG mode for TIM encode: {img.mode}')

    if clut and clut_rect is None:
        raise ValueError(f'CLUT present but missing tim_clut_rect chunk: {png_path}')

    return _pack_tim(pixel_data, mode, stored_width, img.height, clut, img_offset, clut_rect)


def main(argv=None) -> int:
    parser = argparse.ArgumentParser(description="Convert PSX TIM/DIS files to/from PNG")
    parser.add_argument("input", type=Path)
    parser.add_argument("output", type=Path)
    args = parser.parse_args(argv)

    if args.input.suffix.lower() == ".png":
        args.output.write_bytes(encode_tim(args.input))
    elif args.input.is_dir():
        png_files = sorted(args.input.glob("*.png"))
        if not png_files:
            parser.error(f"No PNG files in {args.input}")
        output = b"".join(encode_tim(png_file) for png_file in png_files)

        iq_table_path = args.input / "iq_table.yaml"
        if iq_table_path.exists():
            output += _pack_iq_table(_read_iq_table_yaml(iq_table_path))

        args.output.write_bytes(output)
    else:
        decode_dis(args.input, args.output)

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
