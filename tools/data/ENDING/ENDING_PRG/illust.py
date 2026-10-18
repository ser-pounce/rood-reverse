import argparse
from io import BytesIO
from pathlib import Path

from kaitaistruct import KaitaiStream

from tools.kaitai.parsers.lib.img import Img
from tools.libdata.img import decode_tim, encode_tim

# ---------------------------------------------------------------------------
# Stream format
#
#   0x00-0x7B  literal: copy (op + 1) raw bytes
#   0x7C       repeat the previous back-reference (when it directly follows one; at the start
#              of a command the decoder reads it as a 125-byte literal, which the encoder
#              never produces)
#   0x7D       RLE:      [7D][count - 1][value]       -> value x count
#   0x7E       RLE pair: [7E][count - 1][a][b]        -> (a, b) x count
#   0x7F       end of stream
#   0x80-0xFF  back-reference, 2 bytes: 1LLL OOOO OOOOOOOO
#                length = LLL + 3, distance = OOOO:OOOOOOOO + 1
# ---------------------------------------------------------------------------

OP_REPEAT = 0x7C
OP_RLE = 0x7D
OP_PAIR = 0x7E
OP_END = 0x7F
OP_REF = 0x80  # any opcode with this bit set is a back-reference

MIN_MATCH = 3
MAX_MATCH = MIN_MATCH + 7  # the 3-bit length field gives 3..10
WINDOW = 1 << 12  # the 12-bit distance field gives 1..4096
MAX_COUNT = 256  # RLE count bytes hold count - 1
MAX_LITERAL = OP_REPEAT  # literal opcodes are 0x00-0x7B, so at most 124 bytes


def pack_backref(length: int, distance: int) -> bytes:
    return ((OP_REF << 8) | ((length - MIN_MATCH) << 12) | (distance - 1)).to_bytes(2)


def unpack_backref(op: int, low: int) -> tuple[int, int]:
    """(length, distance) from the opcode byte and the byte after it."""
    return ((op >> 4) & 7) + MIN_MATCH, (((op & 0x0F) << 8) | low) + 1


def copy_backreference(output: bytearray, length: int, distance: int, input_pos: int) -> None:
    if distance > len(output):
        raise ValueError(
            f"Back-reference at input offset 0x{input_pos:X} reaches before "
            f"start of output (distance {distance}, output size {len(output)})"
        )
    for _ in range(length):  # byte by byte: overlapping copies repeat the pattern
        output.append(output[-distance])


def decompress(data: bytes) -> bytes:
    output = bytearray()
    pos = 0
    try:
        while True:
            op = data[pos]
            pos += 1
            if op == OP_END:
                return bytes(output)
            if op == OP_RLE:
                output += bytes((data[pos + 1],)) * (data[pos] + 1)
                pos += 2
            elif op == OP_PAIR:
                output += bytes((data[pos + 1], data[pos + 2])) * (data[pos] + 1)
                pos += 3
            elif op < OP_REF:
                count = op + 1
                if pos + count > len(data):
                    raise ValueError(f"Truncated literal block at input offset 0x{pos:X}")
                output += data[pos : pos + count]
                pos += count
            else:
                length, distance = unpack_backref(op, data[pos])
                pos += 1
                copy_backreference(output, length, distance, pos)
                while data[pos] == OP_REPEAT:
                    pos += 1
                    copy_backreference(output, length, distance, pos)
    except IndexError:
        raise ValueError(f"Truncated compressed stream at input offset 0x{pos:X}") from None


# ---------------------------------------------------------------------------
# Encoder
#
# The encoder is a greedy "best compression ratio" chooser. At each position the candidates are
#   * a back-reference (distance 2..4096, length 3..10 measured up to 10, longest wins,
#     nearest distance on ties)                    -> 2 bytes
#   * byte-RLE of up to 256 repeats                -> 3 bytes
#   * pair-RLE of up to 256 repeats (2 bytes each) -> 4 bytes; with a == b it covers
#     a single-byte run of up to 512
# A candidate is only valid if it covers more bytes than it costs; among valid candidates the
# highest (covered // cost) wins, and ties go to the reference, then byte-RLE, then pair-RLE.
# No valid candidate -> literal byte (blocks of at most 124).
# A reference identical to the previous token is written as the single byte OP_REPEAT.
# ---------------------------------------------------------------------------

MIN_DISTANCE = 2
ALIGNMENT = 4


def repeats(data: bytes, pos: int, unit: int) -> int:
    pattern = data[pos : pos + unit]
    count = 1
    while count < MAX_COUNT and data[pos + count * unit : pos + (count + 1) * unit] == pattern:
        count += 1
    return count


def find_match(data: bytes, pos: int) -> tuple[int, int]:
    """Best back-reference at pos as (length, distance); length is 0 if there is none.

    Scans earlier occurrences of the next 3 bytes nearest-first (distance 2..4096),
    measures each match up to MAX_MATCH, and keeps the longest (the nearest on ties).
    """
    if pos + MIN_MATCH > len(data):
        return 0, 0
    key = data[pos : pos + MIN_MATCH]
    lowest = max(0, pos - WINDOW)
    end = pos - MIN_DISTANCE + MIN_MATCH  # rfind needs the whole key inside [lowest, end)
    best_length = best_distance = 0
    while (earlier := data.rfind(key, lowest, end)) != -1:
        distance = pos - earlier
        length = MIN_MATCH  # the key already matches
        while (
            length < MAX_MATCH
            and pos + length < len(data)
            and data[pos + length] == data[pos + length - distance]
        ):
            length += 1
        if length > best_length:
            best_length, best_distance = length, distance
            if length == MAX_MATCH:
                break
        end = earlier + 2
    return best_length, best_distance


def next_token(data: bytes, pos: int) -> tuple[bytes, int] | None:
    """Encoded token at pos and how many input bytes it covers, or None for a literal.
    """
    candidates = []

    length, distance = find_match(data, pos)
    if length:
        candidates.append((length, pack_backref(length, distance)))

    run = repeats(data, pos, 1)
    candidates.append((run, bytes((OP_RLE, run - 1)) + data[pos : pos + 1]))

    pairs = repeats(data, pos, 2)
    candidates.append((2 * pairs, bytes((OP_PAIR, pairs - 1)) + data[pos : pos + 2]))

    candidates = [(covered, token) for covered, token in candidates if covered > len(token)]
    if not candidates:
        return None
    covered, token = max(candidates, key=lambda c: c[0] // len(c[1]))
    return token, covered


def flush_literal(output: bytearray, literal: bytearray) -> None:
    if literal:
        output.append(len(literal) - 1)
        output += literal
        literal.clear()


def compress(data: bytes) -> bytes:
    output = bytearray()
    literal = bytearray()
    last_ref = None

    pos = 0
    while pos < len(data):
        token = next_token(data, pos)
        if token is None:
            literal.append(data[pos])
            pos += 1
            last_ref = None
            if len(literal) == MAX_LITERAL:
                flush_literal(output, literal)
            continue

        encoded, consumed = token
        flush_literal(output, literal)
        if encoded == last_ref:
            output.append(OP_REPEAT)
        else:
            output += encoded
            last_ref = encoded if encoded[0] >= OP_REF else None
        pos += consumed

    flush_literal(output, literal)
    output.append(OP_END)
    output.extend(bytes(-len(output) % ALIGNMENT))
    return bytes(output)


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(
        description="Convert between ENDING illustration BIN and PNG files"
    )
    parser.add_argument("input", type=Path, help="input BIN or PNG file")
    parser.add_argument("output", type=Path, help="output PNG or BIN file")
    args = parser.parse_args(argv)

    args.output.parent.mkdir(parents=True, exist_ok=True)
    suffix = args.input.suffix.lower()
    if suffix == ".bin":
        decoded = decompress(args.input.read_bytes())
        tim = Img.Tim(KaitaiStream(BytesIO(decoded)))
        decode_tim(tim, args.output)
        print(f"Decoded {len(decoded)} TIM bytes to {args.output}")
    elif suffix == ".png":
        tim = encode_tim(args.input)
        encoded = compress(tim)
        args.output.write_bytes(encoded)
        print(f"Encoded {len(tim)} TIM bytes into {args.output}")
    else:
        parser.error(f"Expected a .BIN or .png input file, got {args.input.suffix!r}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
