import struct
import yaml
from pathlib import Path
from tools.libdata.yaml import configure_yaml, dump
from tools.kaitai.parsers.data.MENU.blade_syd import BladeSyd
from tools.data.MENU.syd_cli import run_cli, write_syd

RECORD_FIELDS = [
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
    "attackshapeangle",
    "attackshape",
]

def build_material_table(table) -> list:
    return [
        [
            [
                list(material_row.weapons)[1:]
                for material_row in weapon_row.materials
            ]
            for weapon_row in outer_row.weapons[1:]
        ]
        for outer_row in table.materials
    ]

def decode(in_path: str, out_path: str) -> None:
    configure_yaml()
    data = BladeSyd.from_file(str(in_path))

    output = {
        "combinations": [list(row.data)[1:] for row in data.combinations[1:]],
        "materials": build_material_table(data.materialcombinations),
        "info": [{field: getattr(weapon, field) for field in RECORD_FIELDS} for weapon in data.info[1:]],
    }

    with open(out_path, "w", encoding="utf-8") as f:
        dump(output, f, default_flow_style=None)


def material_value(v, enum_cls=BladeSyd.Materials):
    return enum_cls[v].value if isinstance(v, str) else v


def build_material_block(materials) -> bytes:
    out = bytearray()
    for outer in materials:
        out += bytes(5 * 10)
        for weapon_row in outer:
            for material_row in weapon_row:
                out += bytes([0])
                out += bytes(material_value(v) for v in material_row)
    return bytes(out)


def build_info_bytes(rec: dict) -> bytes:
    values = [rec[f] for f in RECORD_FIELDS[:-2]]
    packed = (rec["attackshapeangle"] << 3) | rec["attackshape"]
    return struct.pack("<8B3b4BB", *values, packed)


def encode(in_path: Path, out_path: Path) -> None:
    obj = yaml.safe_load(in_path.read_text(encoding="utf-8"))

    comb_rows = [bytes(96)]
    for row in obj["combinations"]:
        comb_rows.append(bytes([0] + row))
    comb_block = b"".join(comb_rows)

    mat_block = build_material_block(obj["materials"])

    info_block = b"".join(
        build_info_bytes(rec) for rec in ({f: 0 for f in RECORD_FIELDS}, *obj["info"])
    )

    write_syd(out_path, [comb_block, mat_block, info_block])


if __name__ == "__main__":
    run_cli(decode, encode)
