import argparse
import struct
import yaml
from pathlib import Path

from tools.kaitai.parsers.data.SMALL.img_dis import ImgDis
from tools.libdata.img import (
    decode_tim,
    encode_tim,
)


def encode_iq_table(iq_table_path: Path) -> bytes:
    with open(iq_table_path) as f:
        entries = yaml.safe_load(f)

    table_bytes = bytearray()
    for entry in entries:
        table_bytes += struct.pack(
            '<4H',
            entry['zoneId'], entry['mapId'], entry['parTime'], entry['rankCap'],
        )

    return bytes(table_bytes)


def encode_tims(png_files: list[str], iq_table_path: Path) -> bytes:

    output = b"".join(encode_tim(Path(png_file)) for png_file in png_files)

    if iq_table_path.exists():
        output += encode_iq_table(iq_table_path)

    return output


def decode_iq_table(iqTable: ImgDis.IqTable, output_dir: Path):
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
