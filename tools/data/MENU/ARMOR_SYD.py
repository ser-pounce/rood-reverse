import struct
import yaml
from pathlib import Path
from tools.libdata.yaml import configure_yaml, dump
from tools.data.MENU.syd_cli import align, run_cli, write_syd
from tools.kaitai.parsers.data.MENU.armor_syd import ArmorSyd
from tools.kaitai.parsers.lib.syd import Syd

RECORD_FIELDS = [
    "subid",
    "wepid",
    "category",
    "gemslots",
    "strength",
    "intelligence",
    "agility",
]

def build_material_table(table) -> list:
    return [
        [
            [
                list(material_row.equipment)
                for material_row in armor_row.materials[1:]
            ]
            for armor_row in outer_row.equipment
        ]
        for outer_row in table.materials[1:]
    ]


def decode(in_path: str, out_path: str) -> None:
    configure_yaml()
    data = ArmorSyd.from_file(str(in_path))

    output = {
        "combinations": [list(row.data)[1:] for row in data.combinations.rows[1:]],
        "materials": build_material_table(data.materialcombinations),
        "info": [{field: getattr(armor, field) for field in RECORD_FIELDS} for armor in data.info[1:]],
    }

    with open(out_path, "w", encoding="utf-8") as f:
        dump(output, f, default_flow_style=None)


def build_material_row_bytes(cells) -> bytes:
    return bytes(Syd.Materials[v].value for v in cells)


def build_armor_row_bytes(material_rows) -> bytes:
    out = bytearray(bytes(4))
    for row in material_rows:
        out += build_material_row_bytes(row)
    return bytes(out)


def build_material_block(materials) -> bytes:
    out = bytearray(bytes(4 * 8 * 4))
    for outer in materials:
        for armor_row in outer:
            out += build_armor_row_bytes(armor_row)
    return bytes(out)


def build_info_bytes(rec: dict) -> bytes:
    values = [rec[f] for f in RECORD_FIELDS]
    return struct.pack("<4B3bx", *values)


def encode(in_path: Path, out_path: Path) -> None:
    obj = yaml.safe_load(in_path.read_text(encoding="utf-8"))

    comb_block = align(b"".join(
        bytes([0] + row) for row in ([0] * 64, *obj["combinations"])
    ))

    mat_block = build_material_block(obj["materials"])

    info_block = b"".join(
        build_info_bytes(rec) for rec in ({f: 0 for f in RECORD_FIELDS}, *obj["info"])
    )

    write_syd(out_path, [comb_block, mat_block, info_block])


if __name__ == "__main__":
    run_cli(decode, encode)