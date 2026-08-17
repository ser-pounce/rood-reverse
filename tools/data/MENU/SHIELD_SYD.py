import struct
import yaml
from pathlib import Path
from tools.libdata.yaml import configure_yaml, dump
from tools.kaitai.parsers.data.MENU.shield_syd import ShieldSyd
from tools.data.MENU.syd_cli import align, run_cli, write_syd

RECORD_FIELDS = [
    "subid",
    "wepid",
    "category",
    "gemslots",
    "strength",
    "intelligence",
    "agility",
]


def decode(in_path: Path, out_path: Path) -> None:
    configure_yaml()
    data = ShieldSyd.from_file(str(in_path))

    output = {
        "combinations": [list(row.data)[1:] for row in data.combinations[1:]],
        "materials": [list(row.data)[1:] for row in data.materials[1:]],
        "info": [{field: getattr(shield, field) for field in RECORD_FIELDS} for shield in data.info[1:]],
    }

    with open(out_path, "w", encoding="utf-8") as f:
        dump(output, f, default_flow_style=None)


def row_bytes(values, size, enum_cls=None) -> bytes:
    data = bytes(
        enum_cls[v].value if enum_cls and isinstance(v, str) else v
        for v in values
    )
    return b"\x00" + data


def block_bytes(rows, size, enum_cls=None) -> bytes:
    header = b"\x00" * (size + 1)
    return header + b"".join(row_bytes(r, size, enum_cls) for r in rows)


def encode(in_path: Path, out_path: Path) -> None:
    obj = yaml.safe_load(in_path.read_text(encoding="utf-8"))

    comb_block = align(block_bytes(obj["combinations"], size=16))
    mat_block = block_bytes(obj["materials"], size=7, enum_cls=ShieldSyd.Materials)
    info_block = b"".join(
        struct.pack(
            "<4B3bx",
            *(rec[f] for f in RECORD_FIELDS),
        )
        for rec in ({f: 0 for f in RECORD_FIELDS}, *obj["info"])
    )

    write_syd(out_path, [comb_block, mat_block, info_block])


if __name__ == "__main__":
    run_cli(decode, encode)
