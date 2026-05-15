#!/usr/bin/env python3
"""Convert between a mon.bin file and its YAML representation."""

import sys
import struct
import io
import yaml
from tools.etc.vsString import decode, encode


class LiteralString(str):
    pass


def literal_representer(dumper, data):
    return dumper.represent_scalar("tag:yaml.org,2002:str", str(data), style="|")


yaml.add_representer(LiteralString, literal_representer)


def maybe_literal(s: str) -> str:
    return LiteralString(s) if "\n" in s else s


# Struct layout: 6 shorts (12 bytes) + 4 u_chars (4 bytes) + char[28] = 44 bytes
MON_STRUCT_FORMAT = "<6h4B28s"
MON_STRUCT_SIZE   = struct.calcsize(MON_STRUCT_FORMAT)  # 44 bytes
NUM_ENTRIES       = 150

# Padding string appended to short encoded names
NAME_PAD_STRING = '|>14||m184||m184|_Ô|m184||m184|'
NAME_MIN_LENGTH = 13  # minimum encoded length before null padding
NAME_FIELD_SIZE = 28  # final null-padded size


# ---------------------------------------------------------------------------
# Decoding (bin -> yaml)
# ---------------------------------------------------------------------------

def parse_entries(data: bytes) -> list[dict]:
    entries = []
    for i in range(NUM_ENTRIES):
        offset = i * MON_STRUCT_SIZE
        (
            unk0, unk2, unk4, unk6,
            selected, animationState,
            unlocked, unkD, unkE, unkF,
            raw_name,
        ) = struct.unpack_from(MON_STRUCT_FORMAT, data, offset)

        entries.append({
            "unk0":           unk0,
            "unk2":           unk2,
            "unk4":           unk4,
            "unk6":           unk6,
            "selected":       selected,
            "animationState": animationState,
            "unlocked":       unlocked,
            "unkD":           unkD,
            "unkE":           unkE,
            "unkF":           unkF,
            "name":           maybe_literal(decode(raw_name)),
        })
    return entries


def parse_string_table(data: bytes, base_offset: int) -> list[str]:
    f = io.BytesIO(data)

    f.seek(base_offset)
    string_count = struct.unpack("<H", f.read(2))[0]

    string_offsets = [string_count]
    for _ in range(string_count - 1):
        offset = struct.unpack("<H", f.read(2))[0]
        string_offsets.append(offset)

    file_size = len(data)

    strings = []
    for offset in string_offsets:
        start_pos = base_offset + (offset * 2)
        f.seek(start_pos)
        string_data = f.read(file_size - start_pos)
        strings.append(maybe_literal(decode(string_data)))
    return strings


def decode_bin(in_path: str, out_path: str) -> None:
    with open(in_path, "rb") as f:
        data = f.read()

    struct_block_size = NUM_ENTRIES * MON_STRUCT_SIZE
    entries           = parse_entries(data)
    string_table      = parse_string_table(data, struct_block_size)

    doc = {
        "entries":      entries,
        "string_table": string_table,
    }

    with open(out_path, "w", encoding="utf-8") as f:
        yaml.dump(doc, f, allow_unicode=True, sort_keys=False, width=1000)


# ---------------------------------------------------------------------------
# Encoding (yaml -> bin)
# ---------------------------------------------------------------------------

def encode_name(name: str, pad_encoded: bytes) -> bytes:
    encoded = encode(name, padding=None)
    enc_len = len(encoded)

    if enc_len < NAME_MIN_LENGTH:
        # Append bytes from pad_encoded starting at enc_len
        encoded = encoded + pad_encoded[enc_len:NAME_MIN_LENGTH]

    # Null-pad to NAME_FIELD_SIZE
    encoded = encoded.ljust(NAME_FIELD_SIZE, b"\x00")
    return encoded


def build_entries(entries: list[dict]) -> bytes:
    pad_encoded = encode(NAME_PAD_STRING, padding=None)
    out = b""
    for e in entries:
        name_bytes = encode_name(e["name"], pad_encoded)
        out += struct.pack(
            "<6h4B",
            e["unk0"], e["unk2"], e["unk4"], e["unk6"],
            e["selected"], e["animationState"],
            e["unlocked"], e["unkD"], e["unkE"], e["unkF"],
        )
        out += name_bytes
    return out


def build_string_table(strings: list[str]) -> bytes:
    encoded_strings = [encode(s) for s in strings]
    count           = len(encoded_strings)

    # Header: count shorts. First value is count itself (= offset of first string
    # in units of 2 bytes), then cumulative offsets for subsequent strings.
    header_size = count * 2  # in bytes
    cursor      = header_size  # byte offset from start of table
    offsets     = []
    for enc in encoded_strings:
        offsets.append(cursor // 2)
        cursor += len(enc)

    # First offset entry is the count itself (matching the parse logic)
    header = struct.pack("<H", count)
    for off in offsets[1:]:
        header += struct.pack("<H", off)

    return header + b"".join(encoded_strings)


def encode_yaml(in_path: str, out_path: str) -> None:
    with open(in_path, "r", encoding="utf-8") as f:
        doc = yaml.safe_load(f)

    entries_bin  = build_entries(doc["entries"])
    string_table = build_string_table(doc["string_table"])

    with open(out_path, "wb") as f:
        f.write(entries_bin)
        f.write(string_table)


# ---------------------------------------------------------------------------
# Entry point
# ---------------------------------------------------------------------------

def main():
    if len(sys.argv) < 3:
        print(f"Usage: {sys.argv[0]} <input> <output>")
        sys.exit(1)

    in_path, out_path = sys.argv[1], sys.argv[2]

    if in_path.endswith(".BIN"):
        decode_bin(in_path, out_path)
    elif in_path.endswith(".yaml"):
        encode_yaml(in_path, out_path)
    else:
        print(f"Cannot determine mode from input filename: {in_path}")
        sys.exit(1)


if __name__ == "__main__":
    main()
