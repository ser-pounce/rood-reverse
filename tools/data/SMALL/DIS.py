import argparse
import struct
import yaml
from pathlib import Path

from PIL import Image
from PIL.PngImagePlugin import PngInfo

from tools.kaitai.parsers.lib.img import Img
from tools.kaitai.parsers.data.SMALL.img_dis import ImgDis
from tools.libdata.img import decode_grayscale, decode_highcolor, encode_highColor, get_chunk, pack_4bpp


# pypng: Can output 4/8 bit grascale .pngs, but doesn't offer a nice
# interface for chunks.
# Pillow: Has excellent chunk support but no 4/8 bit grayscale support.
# Pillow wins on overall simplicity.


def decode_clut(section: Img.Clutsection, info: PngInfo) -> None:
    clut = [c.raw for c in section.clut.colors]
    info.add_text('tim_clut_rect', ','.join(map(str, (section.rect.x, section.rect.y, section.rect.w, section.rect.h))))
    info.add(b'clUb', struct.pack(f'<{len(clut)}H', *clut), after_idat=True)


def decode_tim(tim: Img.Tim, output_path: Path) -> None:
    info = PngInfo()
    info.add_text('tim_offset', f'{tim.rect.x},{tim.rect.y}')

    if tim.has_clut:
        decode_clut(tim.clut, info)

    if tim.mode == 2:
        decode_highcolor(tim.rect.w, tim.rect.h, tim.indices.indices, output_path, info)
        
    else:
        bpp = 4 if tim.mode == 0 else 8
        decode_grayscale(bytes(tim.indices.indices), tim.rect.w * 16 // bpp, tim.rect.h, bpp, output_path, info)


def parse_ints(raw: str | None, count: int) -> tuple[int, ...]:
    if not raw:
        raise ValueError(f'No values present')
    
    parts = raw.split(',')

    if len(parts) != count:
        raise ValueError(f'Requested {count} values, {len(parts)} present')
    try:
        return tuple(int(p.strip()) for p in parts)
    except ValueError:
        raise ValueError(f'Error when parsing values')


def get_bit_depth(png_path: str) -> int:
    with open(png_path, 'rb') as f:
        f.seek(24)
        bitdepth = f.read(1)[0]

    if bitdepth not in (4, 8):
        raise ValueError(f'Expected 4-bit or 8-bit indexed PNG: {png_path}')

    return bitdepth


def encode_clut(img: Image, mode: int) -> bytes:
    clut_bytes = get_chunk(img, 'clUb')

    if clut_bytes is not None:
        clut = list(struct.unpack(f'<{len(clut_bytes) // 2}H', clut_bytes))
        packed_clut_bytes = struct.pack(f'<{len(clut)}H', *clut)
        clut_len = 12 + len(packed_clut_bytes)
        clut_rect = parse_ints(img.text.get('tim_clut_rect'), 4)

        out = struct.pack("<II", 0x10, mode | 8)
        out += struct.pack("<I4h", clut_len, *clut_rect) + packed_clut_bytes
    else:
        out = struct.pack("<II", 0x10, mode)

    return out


def build_tim(img: Image, pixel_data: bytes, width: int, mode: int) -> bytes:
    img_offset = parse_ints(img.text.get('tim_offset'), 2)
    out = encode_clut(img, mode)
    out += struct.pack("<I4h", 12 + len(pixel_data), img_offset[0], img_offset[1], width, img.height)
    out += pixel_data
    return out


def encode_grayscale(img: Image) -> bytes:
    pixel_data = img.tobytes()
    bitdepth = get_bit_depth(img.filename)
    
    if bitdepth == 4:
        pixel_data = pack_4bpp(pixel_data)

    return build_tim(img, pixel_data, img.width * bitdepth // 16, 1 if bitdepth == 8 else 0)


def encode_tim(png_path: Path) -> bytes:
    img = Image.open(png_path)
    img.load()

    if img.mode == 'RGBA':
        return build_tim(img, encode_highColor(img), img.width, 2)

    elif img.mode == 'P':
        return encode_grayscale(img)

    else:
        raise ValueError(f'Unsupported PNG mode for TIM encode: {img.mode}')


def encode_iq_table(iq_table_path: str) -> bytes:
    with open(iq_table_path) as f:
        entries = yaml.safe_load(f)

    table_bytes = bytearray()
    for entry in entries:
        table_bytes += struct.pack(
            '<4H',
            entry['zoneId'], entry['mapId'], entry['parTime'], entry['rankCap'],
        )

    return bytes(table_bytes)


def encode_tims(png_files: list[str], iq_table_path: str) -> bytes:

    output = b"".join(encode_tim(png_file) for png_file in png_files)

    if iq_table_path.exists():
        output += encode_iq_table(iq_table_path)

    return output


def decode_iq_table(iqTable: ImgDis.IqTable, output_dir: str):
    entries = [
        {
            'zoneId': entry.zone_id,
            'mapId': entry.map_id,
            'parTime': entry.par_time,
            'rankCap': entry.rank_cap,
        }
        for entry in iqTable.iq_data
    ]
    with open(output_dir / "iq_table.yaml", 'w') as f:
        yaml.safe_dump(entries, f, default_flow_style=False, sort_keys=False)


def decode_tims(dis: ImgDis, output_dir: Path):
    if isinstance(dis.sections[-1].body, ImgDis.IqTable):
        decode_iq_table(dis.sections[-1].body, output_dir)
        dis.sections = dis.sections[:-1]

    if output_dir.exists() and output_dir.is_file():
        raise ValueError(f"Output path must be a directory for {len(dis.sections)} PNG files: {output_dir}")

    for i, tim in enumerate([s.body for s in dis.sections]):
        decode_tim(tim, output_dir / f"{i:04d}.png")


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
        args.output.write_bytes(encode_tims(png_files, args.input / "iq_table.yaml"))

    else:
        dis = ImgDis.from_file(str(args.input))

        if not dis.sections:
            raise ValueError(f"No valid sections in {args.input}")
    
        if len(dis.sections) == 1:
            decode_tim(dis.sections[0].body, args.output)
        else:
            decode_tims(dis, args.output)

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
