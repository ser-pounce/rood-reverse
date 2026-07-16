#!/usr/bin/env python3
"""
Decode/encode the dialogue script format (reverse engineered from
func_8006ABF0 and related code).

FORMAT: one top-level opcode per line, plain keyword + args, no delimiters
needed at the top level since one opcode = one line. Newlines between
lines are purely cosmetic and are ignored on encode; blank lines and
';'-prefixed comment lines are also ignored. This means you can freely
add/remove blank lines and comments when editing a dumped script without
affecting re-encoding.

The full opcode set is considered fully mapped at this point: decode()
treats anything outside it (an unrecognized top-level opcode byte, an
unnamed signal sub-op, or a truncated/short operand) as a hard error and
raises immediately rather than degrading gracefully - malformed data isn't
a case worth handling quietly here.

Top-level opcodes:
    wait <n>                 wait n frames                          (0x01)
    text <content>            a text block - see below               (0x02)
    bgenable                 enable background illustrations/timers (0x03)
    copyright / logo / fin / title   (named signal sub-ops)          (0x04)
    bgfadein                 fade in background                     (0x05)
    bgfadeout                fade out background                    (0x06)
    scrollfreeze              freeze text scroll speed               (0x07)
    illustimer <id> <value>   set illustration timer (u16, LE)        (0x08)
    end                       end of stream                          (0xFF)
    unk <0xNN>                 (encode-only) manually emit a raw top-level
                                opcode byte outside the known set; decode
                                will never produce this itself

`text` lines carry their payload as the *rest of the line*, which is a run
of literal characters (font-table mapped) plus inline vertical-bar tags -
same |...| delimiter convention as the other custom string decoder, reused
here deliberately for consistency across tooling even though the two
formats' actual byte encodings are unrelated:
    |f1|             select italic font, the default font       (sub-op 0x01)
    |f2|             select small-caps font                     (sub-op 0x02)
    |f3|             underline whatever font is currently active (sub-op 0x03)
                      - independent of |f1|/|f2|, stacks with either
                      rather than switching between them, and has no known
                      "off" code (sticky for the rest of the block); the
                      byte value doubles as the tag's digit directly, so
                      there's no separate name-to-byte table to maintain
    |<|               shift x by -1 (single occurrence - 0x1F only ever
                      appears alone in practice, so there's no count/run
                      form; two shifts in a row is just |<||<|). The '<'
                      is a visual hint that it moves the position back.
    |byte 0xNN|      emit this exact byte (>=0x20) verbatim - used for
                      font-table slots that don't have a confirmed glyph
                      yet (this is a font-table gap, not malformed data,
                      so it stays a soft fallback rather than a hard error)
    |unk 0xNN|        (encode-only) manually emit a raw byte (<0x20) that
                      isn't a known sub-op; decode will never produce this

|f1| and |f2| are mutually exclusive font selections (sticky until the
other is set); text starts in |f1| (italic) by default even without an
explicit tag, so |f1| mainly shows up to switch back after a |f2| run.

A literal '|' in text content is written doubled ('||').

Font table: mostly identity-mapped to ASCII for 0x20-0x7E. Known
customizations beyond that live in FONT_TABLE_OVERRIDES below - currently
just 0x7F -> 'u with diaeresis'. Any renderable byte (>=0x20) without a
confirmed mapping decodes as |byte 0xNN| rather than guessing at a glyph.

Usage:
    python3 scripttool.py decode <file> <offset> [--length N] [-o out.txt]
    python3 scripttool.py encode <textfile> -o <outfile.bin>
"""
import argparse
import sys

SIGNAL_NAMES = {
    0: "copyright",
    1: "logo",
    2: "fin",
    3: "title",
}
SIGNAL_NAMES_REV = {v: k for k, v in SIGNAL_NAMES.items()}

SIMPLE_TOP_OPS = {
    0x03: "bgenable",
    0x05: "bgfadein",
    0x06: "bgfadeout",
    0x07: "scrollfreeze",
}
SIMPLE_TOP_OPS_REV = {v: k for k, v in SIMPLE_TOP_OPS.items()}

# the three text sub-op byte values (1-3) are used directly as the |fN|
# tag's digit, so there's no separate name<->byte table needed for these
FONT_SUBOP_MIN = 1
FONT_SUBOP_MAX = 3

# --- font table -------------------------------------------------------
# 0x20-0x7E defaults to identity (standard ASCII). Add confirmed
# customizations here as they're discovered; anything not listed decodes
# as |byte 0xNN| instead of a guessed glyph. This is the one place where
# an "unknown" value is expected/normal rather than a sign of corrupt data.
FONT_TABLE_OVERRIDES = {
    0x7F: '\u00fc',  # u with diaeresis (u-umlaut)
}

FONT_TABLE = {b: chr(b) for b in range(0x20, 0x7F)}
FONT_TABLE.update(FONT_TABLE_OVERRIDES)
FONT_TABLE_REV = {v: k for k, v in FONT_TABLE.items()}


class ScriptFormatError(Exception):
    """Raised for anything outside the confirmed format - malformed/
    truncated data on decode, or invalid tag syntax on encode."""
    pass


# ---------------------------------------------------------------------------
# Decode: bytes -> tagged text
# ---------------------------------------------------------------------------

def escape_text(s):
    return s.replace('|', '||')


def decode_text_block(payload, block_offset):
    """Decode the payload of an opcode-0x02 text block into inline-tagged text."""
    out = []
    literal_buf = []
    i = 0
    n = len(payload)

    def flush_literal():
        if literal_buf:
            out.append(escape_text(''.join(literal_buf)))
            literal_buf.clear()

    while i < n:
        b = payload[i]
        if b == 0x1F:
            flush_literal()
            out.append("|<|")
            i += 1
        elif FONT_SUBOP_MIN <= b <= FONT_SUBOP_MAX:
            flush_literal()
            out.append(f"|f{b}|")
            i += 1
        elif b >= 0x20:
            if b in FONT_TABLE:
                literal_buf.append(FONT_TABLE[b])
            else:
                flush_literal()
                out.append(f"|byte 0x{b:02X}|")
            i += 1
        else:
            raise ScriptFormatError(
                f"offset 0x{block_offset + i:X}: unrecognized text sub-op byte "
                f"0x{b:02X} inside text block")

    flush_literal()
    return ''.join(out)


def decode(data, start, length, out):
    end = len(data) if length is None else min(len(data), start + length)
    pos = start
    lines = []

    while pos < end:
        op = data[pos]

        if op == 0x01:
            if pos + 1 >= end:
                raise ScriptFormatError(f"offset 0x{pos:X}: truncated 'wait' (needs 2 bytes)")
            n = data[pos + 1]
            lines.append(f"wait {n}")
            pos += 2

        elif op == 0x02:
            if pos + 1 >= end:
                raise ScriptFormatError(f"offset 0x{pos:X}: truncated 'text' (missing length byte)")
            strlen = data[pos + 1]
            payload_start = pos + 2
            payload_end = payload_start + strlen
            if payload_end > end:
                raise ScriptFormatError(
                    f"offset 0x{pos:X}: truncated 'text' payload "
                    f"(need {strlen} bytes, only {end - payload_start} available)")
            payload = data[payload_start:payload_end]
            lines.append(f"text {decode_text_block(payload, payload_start)}")
            pos = payload_end

        elif op in SIMPLE_TOP_OPS:
            lines.append(SIMPLE_TOP_OPS[op])
            pos += 1

        elif op == 0x04:
            if pos + 1 >= end:
                raise ScriptFormatError(f"offset 0x{pos:X}: truncated signal (needs 2 bytes)")
            sub = data[pos + 1]
            if sub not in SIGNAL_NAMES:
                raise ScriptFormatError(
                    f"offset 0x{pos:X}: unrecognized signal sub-op {sub} "
                    f"(known: {sorted(SIGNAL_NAMES)})")
            lines.append(SIGNAL_NAMES[sub])
            pos += 2

        elif op == 0x08:
            if pos + 3 >= end:
                raise ScriptFormatError(f"offset 0x{pos:X}: truncated 'illustimer' (needs 4 bytes)")
            illust_id = data[pos + 1]
            lo = data[pos + 2]
            hi = data[pos + 3]
            value = lo | (hi << 8)
            lines.append(f"illustimer {illust_id} {value}")
            pos += 4

        elif op == 0xFF:
            lines.append("end")
            pos += 1
            break

        else:
            raise ScriptFormatError(f"offset 0x{pos:X}: unrecognized top-level opcode 0x{op:02X}")

    text = '\n'.join(lines)
    out.write(text)
    if not text.endswith('\n'):
        out.write('\n')
    return pos


# ---------------------------------------------------------------------------
# Encode: tagged text -> bytes
# ---------------------------------------------------------------------------

def parse_inline_tags(s):
    """Tokenize a text-line's content into ('chars', str) / ('tag', inner)."""
    tokens = []
    i = 0
    n = len(s)
    buf = []

    def flush_buf():
        if buf:
            tokens.append(('chars', ''.join(buf)))
            buf.clear()

    while i < n:
        c = s[i]
        if c == '|':
            if i + 1 < n and s[i + 1] == '|':
                buf.append('|')
                i += 2
                continue
            close = s.find('|', i + 1)
            if close == -1:
                raise ScriptFormatError(f"unterminated '|' tag starting at char {i}: {s[i:i+20]!r}")
            inner = s[i + 1:close]
            if not inner:
                raise ScriptFormatError(f"empty tag at char {i}")
            flush_buf()
            tokens.append(('tag', inner))
            i = close + 1
        else:
            buf.append(c)
            i += 1

    flush_buf()
    return tokens


def encode_text_content(content):
    """Encode a `text` line's content (chars + inline |tags|) into the
    opcode-0x02 payload bytes (without the 0x02/len header)."""
    tokens = parse_inline_tags(content)
    payload = bytearray()
    for tok in tokens:
        if tok[0] == 'chars':
            for ch in tok[1]:
                if ch not in FONT_TABLE_REV:
                    raise ScriptFormatError(
                        f"character {ch!r} (U+{ord(ch):04X}) has no known font-table byte; "
                        f"use |byte 0xNN| if you know the raw value, or add it to "
                        f"FONT_TABLE_OVERRIDES if it's a confirmed custom glyph")
                payload.append(FONT_TABLE_REV[ch])
            continue

        _, inner = tok

        if inner == '<':
            payload.append(0x1F)
            continue

        if inner.startswith('f') and inner[1:].isdigit():
            num = int(inner[1:])
            if not (FONT_SUBOP_MIN <= num <= FONT_SUBOP_MAX):
                raise ScriptFormatError(
                    f"|{inner}| out of range: f must be {FONT_SUBOP_MIN}-{FONT_SUBOP_MAX}")
            payload.append(num)
            continue

        parts = inner.split()
        name, args = parts[0], parts[1:]
        if name in ('byte', 'unk'):
            if len(args) != 1:
                raise ScriptFormatError(f"|{name}| needs exactly 1 argument, got {args}")
            val = int(args[0], 0)
            if not (0 <= val <= 0xFF):
                raise ScriptFormatError(f"|{name}| value out of byte range: {val}")
            payload.append(val)
        else:
            raise ScriptFormatError(f"'|{inner}|' is not a valid inline text tag")
    return bytes(payload)


def encode(text):
    text = text.replace('\r\n', '\n').replace('\r', '\n')
    out = bytearray()

    for lineno, raw_line in enumerate(text.split('\n'), start=1):
        line = raw_line.strip()
        if not line or line.startswith(';'):
            continue  # blank lines, and comment lines, are purely cosmetic

        if line.startswith('text ') or line == 'text':
            content = raw_line[len('text'):]
            if content.startswith(' '):
                content = content[1:]  # drop exactly one separating space
            try:
                payload = encode_text_content(content)
            except ScriptFormatError as e:
                raise ScriptFormatError(f"line {lineno}: {e}") from e
            if len(payload) > 255:
                raise ScriptFormatError(f"line {lineno}: text block too long "
                                         f"({len(payload)} bytes, max 255)")
            out.append(0x02)
            out.append(len(payload))
            out.extend(payload)
            continue

        parts = line.split()
        keyword = parts[0]
        args = parts[1:]

        try:
            if keyword == 'wait':
                if len(args) != 1:
                    raise ScriptFormatError(f"'wait' needs exactly 1 argument, got {args}")
                n = int(args[0], 0)
                if not (0 <= n <= 255):
                    raise ScriptFormatError(f"'wait' argument out of byte range: {n}")
                out += bytes([0x01, n])

            elif keyword in SIMPLE_TOP_OPS_REV:
                out.append(SIMPLE_TOP_OPS_REV[keyword])

            elif keyword in SIGNAL_NAMES_REV:
                out += bytes([0x04, SIGNAL_NAMES_REV[keyword]])

            elif keyword == 'illustimer':
                if len(args) != 2:
                    raise ScriptFormatError(f"'illustimer' needs exactly 2 arguments, got {args}")
                illust_id, value = int(args[0], 0), int(args[1], 0)
                if not (0 <= illust_id <= 255):
                    raise ScriptFormatError(f"'illustimer' id out of byte range: {illust_id}")
                if not (0 <= value <= 0xFFFF):
                    raise ScriptFormatError(f"'illustimer' value out of u16 range: {value}")
                out += bytes([0x08, illust_id, value & 0xFF, (value >> 8) & 0xFF])

            elif keyword == 'end':
                out.append(0xFF)
                break  # anything after `end` is not part of the stream

            elif keyword == 'unk':
                if len(args) != 1:
                    raise ScriptFormatError(f"'unk' needs exactly 1 argument, got {args}")
                out.append(int(args[0], 0) & 0xFF)

            else:
                raise ScriptFormatError(f"'{keyword}' is not a recognized top-level opcode")
        except ScriptFormatError as e:
            raise ScriptFormatError(f"line {lineno}: {e}") from e

    return bytes(out)


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                  formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest='cmd', required=True)

    d = sub.add_parser('decode', help='binary script bytes -> tagged text')
    d.add_argument('file')
    d.add_argument('offset', type=lambda x: int(x, 0))
    d.add_argument('--length', type=lambda x: int(x, 0), default=None)
    d.add_argument('-o', '--output', type=argparse.FileType('w', encoding='utf-8'),
                    default=sys.stdout)

    e = sub.add_parser('encode', help='tagged text -> binary script bytes')
    e.add_argument('file', help='input text file containing tagged script text')
    e.add_argument('-o', '--output', required=True, help='output binary file')

    args = ap.parse_args()

    if args.cmd == 'decode':
        with open(args.file, 'rb') as f:
            data = f.read()
        if args.offset >= len(data):
            sys.stderr.write(f"offset 0x{args.offset:X} is beyond file size 0x{len(data):X}\n")
            sys.exit(1)
        try:
            end_pos = decode(data, args.offset, args.length, args.output)
        except ScriptFormatError as e:
            sys.stderr.write(f"format error: {e}\n")
            sys.exit(1)
        if args.output is not sys.stdout:
            args.output.close()
            print(f"wrote decoded text, stopped at offset 0x{end_pos:X}", file=sys.stderr)

    elif args.cmd == 'encode':
        with open(args.file, 'r', encoding='utf-8') as f:
            text = f.read()
        try:
            data = encode(text)
        except ScriptFormatError as e:
            sys.stderr.write(f"parse error: {e}\n")
            sys.exit(1)
        with open(args.output, 'wb') as f:
            f.write(data)
        print(f"wrote {len(data)} bytes to {args.output}", file=sys.stderr)


if __name__ == '__main__':
    main()