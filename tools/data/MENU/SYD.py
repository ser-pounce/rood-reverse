import argparse
import struct
from collections.abc import Callable, Mapping, Sequence
from dataclasses import dataclass
from pathlib import Path

import yaml

from tools.kaitai.parsers.data.MENU.armor_syd import ArmorSyd
from tools.kaitai.parsers.data.MENU.blade_syd import BladeSyd
from tools.kaitai.parsers.data.MENU.shield_syd import ShieldSyd
from tools.kaitai.parsers.data.MENU.syd import Syd
from tools.libdata.util import align
from tools.libdata.yaml import configure_yaml, dump


BLADE_BYTE_FIELDS = (
    "subid",
    "wepid",
    "category",
    "damagetype",
    "costtype",
    "cost",
    "unk6",
    "unk7",
    "strength",
    "intelligence",
    "agility",
    "unkb",
    "range",
    "unkd",
    "unke",
)

BLADE_FIELDS = BLADE_BYTE_FIELDS + (
    "attackshapeangle",
    "attackshape",
)

ARMOR_FIELDS = (
    "subid",
    "wepid",
    "category",
    "gemslots",
    "strength",
    "intelligence",
    "agility",
)

ARMOR_STRUCT = struct.Struct("<4B3bx")
BLADE_STRUCT = struct.Struct("<8B3b4BB")

Record = Mapping[str, int]


@dataclass(frozen=True)
class FormatConfig:
    parser: type
    fields: tuple[str, ...]
    encoder: Callable[[Record], bytes]


def encode_armor_info(record: Record) -> bytes:
    return ARMOR_STRUCT.pack(*(record[field] for field in ARMOR_FIELDS))


def encode_blade_info(record: Record) -> bytes:
    angle = record["attackshapeangle"]
    shape = record["attackshape"]
    if not 0 <= angle < 1 << 5:
        raise ValueError(f"attackshapeangle must fit in 5 bits: {angle}")
    if not 0 <= shape < 1 << 3:
        raise ValueError(f"attackshape must fit in 3 bits: {shape}")

    packed_shape = (angle << 3) | shape
    return BLADE_STRUCT.pack(
        *(record[field] for field in BLADE_BYTE_FIELDS), packed_shape
    )


FORMATS: dict[str, FormatConfig] = {
    "BLADE": FormatConfig(BladeSyd, BLADE_FIELDS, encode_blade_info),
    "ARMOR": FormatConfig(ArmorSyd, ARMOR_FIELDS, encode_armor_info),
    "SHIELD": FormatConfig(ShieldSyd, ARMOR_FIELDS, encode_armor_info),
}


def build_material_table(table) -> list[list[list[list[int]]]]:
    return [
        [
            [
                list(material_row.categories)
                for material_row in armor_row.materials
            ]
            for armor_row in outer_row.categories
        ]
        for outer_row in table.materials
    ]


def build_material_block(materials) -> bytes:
    return bytes(
        Syd.Materials[value].value
        for outer in materials
        for category in outer
        for row in category
        for value in row
    )


def build_syd(blocks: Sequence[bytes]) -> bytes:
    header_fmt = f"<{len(blocks)}I"
    header_size = struct.calcsize(header_fmt)

    offsets = []
    running = header_size
    for block in blocks:
        offsets.append(running)
        running += len(block)

    return struct.pack(header_fmt, *offsets) + b"".join(blocks)


def decode(config: FormatConfig, in_path: Path, out_path: Path) -> None:
    configure_yaml()
    data = config.parser.from_file(str(in_path))

    output = {
        "combinations": [list(row.data) for row in data.root.itemcombinations],
        "materials": build_material_table(data.root.materialcombinations),
        "info": [
            {field: getattr(item, field) for field in config.fields}
            for item in data.root.items
        ],
    }

    with out_path.open("w", encoding="utf-8") as file:
        dump(output, file, default_flow_style=None)


def encode(config: FormatConfig, in_path: Path, out_path: Path) -> None:
    obj = yaml.safe_load(in_path.read_text(encoding="utf-8"))

    comb_block = bytes(
        value
        for row in obj["combinations"]
        for value in row
    )

    comb_block = align(comb_block)

    mat_block = build_material_block(obj["materials"])

    info_block = b"".join(
        config.encoder(record) for record in obj["info"]
    )

    out_path.write_bytes(build_syd([comb_block, mat_block, info_block]))


def main(argv: Sequence[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description="Decode or encode an item SYD file")
    parser.add_argument("item_type", choices=FORMATS)
    parser.add_argument("input", type=Path)
    parser.add_argument("output", type=Path)
    args = parser.parse_args(argv)

    suffix = args.input.suffix.lower()
    if suffix == ".syd":
        decode(FORMATS[args.item_type], args.input, args.output)
    elif suffix == ".yml":
        encode(FORMATS[args.item_type], args.input, args.output)
    else:
        parser.error(
            f"Could not infer mode from input file extension {args.input.suffix!r}; "
            "expected .SYD or .yml"
        )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
