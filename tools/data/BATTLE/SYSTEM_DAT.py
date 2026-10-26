import argparse
import struct
from pathlib import Path

from PIL import Image
from PIL.PngImagePlugin import PngInfo

from tools.kaitai.parsers.data.BATTLE.system_dat import SystemDat
from tools.libdata.img import (
    decode_grayscale,
    decode_highcolor,
    encode_highColor,
    get_png_bit_depth,
    pack_4bpp,
)


FONT_TABLES = (
    ("font0.png", 256, 224),
    ("font1.png", 256, 224),
    ("font2.png", 256, 158),
)


def decode_image(image: SystemDat.Image, output_path: Path) -> None:
    info = PngInfo()
    info.add_text(
        "system_dat_xy",
        f"{image.header.x},{image.header.y}",
    )
    decode_grayscale(
        bytes(image.pixels.indices),
        image.header.w * 4,
        image.header.h,
        4,
        output_path,
        info,
    )


def decode_system_dat(input_path: Path, output_dir: Path) -> None:
    data = SystemDat.from_file(str(input_path))
    output_dir.mkdir(parents=True, exist_ok=True)

    for name, image in (
        ("ui_tex0.png", data.ui_tex0),
        ("ui_tex1.png", data.ui_tex1),
        ("grid0.png", data.grid0),
        ("grid1.png", data.grid1),
        ("baseEffect.png", data.base_effect),
    ):
        if image is None:
            raise ValueError(f"Parser did not produce image resource {name}")
        decode_image(image, output_dir / name)

    clut0 = data.clut0
    clut1 = data.clut1
    if clut0 is None or clut1 is None:
        raise ValueError("Parser did not produce both CLUT resources")
    decode_highcolor(
        len(clut0.pixels.colors), 1, clut0.pixels.colors, output_dir / "clut0.png"
    )
    decode_highcolor(clut1.w, clut1.h, clut1.pixels.colors, output_dir / "clut1.png")

    font = data.font
    if font is None:
        raise ValueError("Parser did not produce the font resource")
    for (name, width, height), table in zip(
        FONT_TABLES,
        (font.table0, font.table1, font.table2),
        strict=True,
    ):
        decode_grayscale(bytes(table.indices), width, height, 4, output_dir / name)


def _load_indexed_png(path: Path, width: int, height: int) -> bytes:
    with Image.open(path) as image:
        if image.mode != "P":
            raise ValueError(f"{path} must be a paletted grayscale PNG")
        if image.size != (width, height):
            raise ValueError(f"{path} must be {width}x{height}, got {image.width}x{image.height}")
        pixels = image.tobytes()
    if get_png_bit_depth(path) != 4:
        raise ValueError(f"{path} must be a 4-bit PNG")
    return pixels


def encode_image(path: Path) -> bytes:
    x, y = _read_png_ints(path, "system_dat_xy", 2)
    with Image.open(path) as image:
        width, height = image.size
    word_width = width // 4
    pixels = _load_indexed_png(path, word_width * 4, height)
    rect_height = height
    return struct.pack("<4h", x, y, word_width, rect_height) + pack_4bpp(pixels)


def _read_png_ints(path: Path, key: str, count: int) -> tuple[int, ...]:
    with Image.open(path) as image:
        raw_value = image.info.get(key)
    if raw_value is None:
        raise ValueError(f"{path} is missing required PNG metadata {key!r}")
    values = tuple(int(value) for value in raw_value.split(","))
    if len(values) != count:
        raise ValueError(f"{path}: expected {count} values in {key}, got {len(values)}")
    return values


def encode_clut(path: Path, *, width: int | None = None) -> bytes:
    with Image.open(path) as image:
        if image.mode != "RGB":
            raise ValueError(f"{path} must be an RGB PNG")
        image.load()
        image_width, height = image.size
        clut_data = encode_highColor(image)

    return struct.pack("<2h", image_width if width is None else width, height) + clut_data


def encode_font_table(path: Path, width: int, height: int) -> bytes:
    return pack_4bpp(_load_indexed_png(path, width, height))


def encode_system_dat(input_dir: Path, output_path: Path) -> None:
    resources = [
        encode_image(input_dir / "ui_tex0.png"),
        encode_image(input_dir / "ui_tex1.png"),
        encode_clut(input_dir / "clut0.png", width=128),
        encode_image(input_dir / "grid0.png"),
        encode_image(input_dir / "grid1.png"),
        encode_image(input_dir / "baseEffect.png"),
        encode_clut(input_dir / "clut1.png"),
        b"".join(
            encode_font_table(input_dir / name, width, height)
            for name, width, height in FONT_TABLES
        ),
    ]

    offset = 8 * 4
    offsets = []
    for resource in resources:
        offsets.append(offset)
        offset += len(resource)

    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_bytes(struct.pack("<8I", *offsets) + b"".join(resources))


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description="Decode or encode BATTLE/SYSTEM.DAT")
    parser.add_argument("input", type=Path, help="SYSTEM.DAT file to decode or PNG directory to encode")
    parser.add_argument("output", type=Path, help="output PNG directory or SYSTEM.DAT file")
    args = parser.parse_args(argv)

    if args.input.is_dir():
        encode_system_dat(args.input, args.output)
    elif args.input.suffix.lower() == ".dat":
        decode_system_dat(args.input, args.output)
    else:
        parser.error("Input must be a .DAT file to decode or a PNG directory to encode")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
