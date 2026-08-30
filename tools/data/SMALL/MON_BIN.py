import argparse
import struct
import yaml
from pathlib import Path

from tools.etc.vsString import decode, encode
from tools.kaitai.parsers.data.SMALL.mon_bin import MonBin
from tools.libdata.yaml import configure_yaml, dump
from tools.libdata.util import build_offset_table

MONSTER_COUNT = 150
NAME_FIELD_SIZE = 28

# (ksy_id, needs_decode)
RECORD_FIELDS = (
    ("name", True),
    ("zudid", False),
    ("classid", False),
    ("killflagsoffset", False),
    ("killflagscount", False),
    ("description", True),
)

MONSTER_STRUCT = struct.Struct(f"<4h8x{NAME_FIELD_SIZE}s")

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
        dump(records, f)


def validate_record(rec: dict) -> None:
    for ksy_id, _ in RECORD_FIELDS:
        if ksy_id not in rec:
            raise ValueError(f"Record missing required field {ksy_id!r}: {rec}")


def encode_name(name: str) -> bytes:
    encoded = encode(name, padding=None)
    if len(encoded) > NAME_FIELD_SIZE:
        raise ValueError(
            f"Monster name is {len(encoded)} bytes; maximum is "
            f"{NAME_FIELD_SIZE}: {name!r}"
        )

    buffer = bytearray(_NAME_TEMPLATE)
    buffer[:len(encoded)] = encoded
    return bytes(buffer)


def build_monster_block(rec: dict) -> bytes:
    return MONSTER_STRUCT.pack(
        rec["zudid"],
        rec["classid"],
        rec["killflagsoffset"],
        rec["killflagscount"],
        encode_name(rec["name"]),
    )


def encode_yml(in_path: Path, out_path: Path) -> None:
    records = yaml.safe_load(in_path.read_text(encoding="utf-8"))

    if not isinstance(records, list) or len(records) != MONSTER_COUNT:
        count = len(records) if isinstance(records, list) else "not a list"
        raise ValueError(f"Expected {MONSTER_COUNT} monsters, got {count}")
    for rec in records:
        validate_record(rec)

    monster_blocks = [build_monster_block(rec) for rec in records]
    desc_blocks = [encode(rec["description"]) for rec in records]
    string_table = build_offset_table(desc_blocks)

    with open(out_path, "wb") as f:
        f.write(b"".join(monster_blocks))
        f.write(string_table)


def main(argv=None) -> int:
    parser = argparse.ArgumentParser(description="Decode or encode MON.BIN")
    parser.add_argument("input", type=Path)
    parser.add_argument("output", type=Path)
    args = parser.parse_args(argv)

    suffix = args.input.suffix.lower()
    if suffix == ".bin":
        decode_bin(args.input, args.output)
    elif suffix == ".yml":
        encode_yml(args.input, args.output)
    else:
        parser.error("Could not infer mode from input file extension; expected .BIN or .yml")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
