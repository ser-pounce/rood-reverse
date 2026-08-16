import struct
import sys
from pathlib import Path

import yaml

from tools.kaitai.parsers.data.SMALL.mon_bin import MonBin
from tools.libdata.yaml import configure_yaml
from tools.libdata.offset_table import build_offset_table
from tools.etc.vsString import decode, encode

MONSTER_COUNT = 150
NAME_FIELD_SIZE = 28

# (ksy_id, needs_decode)
RECORD_FIELDS = [
    ("name", True),
    ("zudid", False),
    ("classid", False),
    ("killflagsoffset", False),
    ("killflagscount", False),
    ("description", True),
]

# "Empty" name buffer: junk bytes from the pad string (mirroring the
# original buffer-reuse artifact), null-padded out to the full field
# size. A name's encoded bytes are overlaid on top of this.
_NAME_TEMPLATE = encode('|>14||m184||m184|_Ô|m184||m184|', padding=None).ljust(NAME_FIELD_SIZE, b"\x00")


def build_record(monster) -> dict:
    rec = {}
    for field, needs_decode in RECORD_FIELDS:
        value = getattr(monster, field)
        rec[field] = decode(value) if needs_decode else value
    return rec


def decode_bin(in_path: Path, out_path: Path) -> None:
    configure_yaml()

    data = MonBin.from_file(str(in_path))
    records = [build_record(monster) for monster in data.monsters]

    with open(out_path, "w", encoding="utf-8") as f:
        yaml.dump(records, f, allow_unicode=True, sort_keys=False, default_flow_style=False)


def validate_record(rec: dict) -> None:
    for ksy_id, _ in RECORD_FIELDS:
        if ksy_id not in rec:
            raise ValueError(f"Record missing required field {ksy_id!r}: {rec}")


def encode_name(name: str) -> bytes:
    encoded = encode(name, padding=None)
    buffer = bytearray(_NAME_TEMPLATE)
    buffer[:len(encoded)] = encoded
    return bytes(buffer[:NAME_FIELD_SIZE])


def build_monster_block(rec: dict) -> bytes:
    return struct.pack(
        f"<4h8x{NAME_FIELD_SIZE}s",
        rec["zudid"],
        rec["classid"],
        rec["killflagsoffset"],
        rec["killflagscount"],
        encode_name(rec["name"]),
    )


def encode_yml(in_path: Path, out_path: Path) -> None:
    with open(in_path, "r", encoding="utf-8") as f:
        records = yaml.safe_load(f)

    if len(records) != MONSTER_COUNT:
        raise ValueError(f"Expected {MONSTER_COUNT} monsters, got {len(records)}")
    for rec in records:
        validate_record(rec)

    monster_blocks = [build_monster_block(rec) for rec in records]
    desc_blocks = [encode(rec["description"]) for rec in records]
    string_table = build_offset_table(desc_blocks)

    with open(out_path, "wb") as f:
        f.write(b"".join(monster_blocks))
        f.write(string_table)


def main():
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} <input> <output>")
        sys.exit(1)

    in_path = Path(sys.argv[1])
    out_path = Path(sys.argv[2])

    if in_path.suffix == ".BIN":
        decode_bin(in_path, out_path)
    elif in_path.suffix == ".yml":
        encode_yml(in_path, out_path)
    else:
        print(f"Unrecognized extension {in_path.suffix!r} — expected .BIN or .yml")
        sys.exit(1)


if __name__ == "__main__":
    main()
