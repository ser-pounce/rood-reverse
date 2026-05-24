#!/usr/bin/env python3
"""Parse splat-generated .s files into a per-region size manifest, and render
minimal stub .s files from that manifest at CI time.

Two modes:
  --build      Walk build/src/**.s, write fixtures/ci/asm-manifest.json.
  --render     Read manifest, write stub .s files into build/src/... at the
               same paths. Each stub preserves sections, alignment, and global
               symbols (glabel/dlabel) — the only thing the stub elides is the
               actual byte contents, replaced by .zero <N>.

The point: CI doesn't need the disk to link, and we don't need to commit ~3,600
real .s files — just one JSON manifest plus this script.
"""
from __future__ import annotations

import argparse
import json
import re
import sys
from pathlib import Path
from typing import Any

ROOT = Path(__file__).resolve().parents[2]
BUILD = ROOT / "build" / "src"
MANIFEST = ROOT / "fixtures" / "ci" / "asm-manifest.json"

LABEL_RE = re.compile(r"^(glabel|dlabel|jlabel|alabel|ehlabel)\s+(\S+)")
END_RE = re.compile(r"^(enddlabel|endlabel)\b")
SECTION_RE = re.compile(r"^\.section\s+([.\w]+)")
ALIGN_RE = re.compile(r"^\.(align|balign)\s+(0x[0-9a-fA-F]+|\d+)")
WORD_RE = re.compile(r"^\.word\b\s*(.*)$")
SHORT_RE = re.compile(r"^\.(short|half|hword)\b\s*(.*)$")
BYTE_RE = re.compile(r"^\.byte\b\s*(.*)$")
ZERO_RE = re.compile(r"^\.(zero|space|skip)\s+(0x[0-9a-fA-F]+|\d+)")
ASCII_RE = re.compile(r'^\.(ascii|asciz)\s+"((?:[^"\\]|\\.)*)"')
INSN_BLANK = {".text", ".data", ".rodata", ".bss", ".sbss"}
LOCAL_LABEL = re.compile(r"^\.L\S+:\s*$")
NUMBERED_LABEL = re.compile(r"^\d+:\s*$")
PLAIN_LABEL = re.compile(r"^\w+:\s*$")


def _count_args(args: str) -> int:
    """Count comma-separated args on a directive line, ignoring trailing comments."""
    args = re.split(r"/\*|//|;", args, maxsplit=1)[0].strip()
    if not args:
        return 0
    return args.count(",") + 1


def _ascii_bytes(s: str, terminated: bool) -> int:
    n, i = 0, 0
    while i < len(s):
        if s[i] == "\\" and i + 1 < len(s):
            esc = s[i + 1]
            if esc == "x" and i + 3 < len(s):
                i += 4
            elif esc in "0123":
                # Octal up to 3 digits
                j = i + 1
                while j < i + 4 and j < len(s) and s[j] in "01234567":
                    j += 1
                i = j
            else:
                i += 2
            n += 1
        else:
            i += 1
            n += 1
    return n + (1 if terminated else 0)


def _strip_inline_comment(line: str) -> str:
    out, i, n = [], 0, len(line)
    while i < n:
        if line[i : i + 2] == "/*":
            j = line.find("*/", i + 2)
            i = n if j < 0 else j + 2
            continue
        if line[i : i + 2] == "//":
            break
        out.append(line[i])
        i += 1
    return "".join(out)


def _line_bytes(line: str) -> int:
    """Bytes contributed by a single normalized .s line (excluding labels/section/align)."""
    s = line.strip()
    if not s:
        return 0
    if s.startswith(".include") or s.startswith(".set") or s.startswith(".type"):
        return 0
    if s.startswith(".global") or s.startswith(".local") or s.startswith(".internal"):
        return 0
    if s.startswith(".size") or s.startswith(".ent") or s.startswith(".end") or s.startswith(".aent"):
        return 0
    if s.startswith(".if") or s.startswith(".endif") or s.startswith(".else"):
        return 0
    if s.startswith(".file") or s.startswith(".ident") or s.startswith(".previous"):
        return 0
    if s.startswith("nonmatching") or s.startswith("/*") or s.startswith("//"):
        return 0
    if LOCAL_LABEL.match(s) or NUMBERED_LABEL.match(s) or PLAIN_LABEL.match(s):
        return 0
    if m := ZERO_RE.match(s):
        return int(m.group(2), 0)
    if m := ASCII_RE.match(s):
        return _ascii_bytes(m.group(2), terminated=m.group(1) == "asciz")
    if m := WORD_RE.match(s):
        return 4 * max(1, _count_args(m.group(1)))
    if m := SHORT_RE.match(s):
        return 2 * max(1, _count_args(m.group(2)))
    if m := BYTE_RE.match(s):
        return 1 * max(1, _count_args(m.group(1)))
    if s.startswith(".double") or s.startswith(".quad"):
        return 8 * max(1, _count_args(s.split(None, 1)[1] if " " in s else ""))
    if s.startswith(".float") or s.startswith(".single"):
        return 4 * max(1, _count_args(s.split(None, 1)[1] if " " in s else ""))
    if s.startswith("."):
        return 0  # unknown pseudo-op — assume zero bytes
    # MIPS instruction (one per line in splat output)
    return 4


def _apply_align(offset: int, align_arg: int, kind: str) -> int:
    """.align N means 2^N alignment in GAS (default); .balign N is N bytes."""
    boundary = (1 << align_arg) if kind == "align" else align_arg
    if boundary <= 1:
        return offset
    rem = offset % boundary
    return offset if rem == 0 else offset + (boundary - rem)


def parse_s(path: Path) -> list[dict[str, Any]]:
    """Walk a .s file, return list of ops describing its layout.

    Op types:
      {op: "section", name: ".text"}
      {op: "align",   kind: "align"|"balign", n: int, padded_to: int}
      {op: "label",   kind: "glabel"|"dlabel"|"jlabel"|...,  name: str, size: int}
      {op: "zero",    size: int}   # bytes between section/label boundaries
    """
    ops: list[dict[str, Any]] = []
    section_offset = 0
    cur_label: dict[str, Any] | None = None
    pending_zero = 0

    def flush():
        nonlocal cur_label, pending_zero
        if cur_label is not None:
            ops.append(cur_label)
            cur_label = None
        elif pending_zero > 0:
            ops.append({"op": "zero", "size": pending_zero})
        pending_zero = 0

    with path.open() as f:
        for raw in f:
            line = _strip_inline_comment(raw).rstrip()
            s = line.strip()
            if not s:
                continue
            if m := SECTION_RE.match(s):
                flush()
                ops.append({"op": "section", "name": m.group(1)})
                section_offset = 0
                continue
            if m := ALIGN_RE.match(s):
                flush()
                kind, arg = m.group(1), int(m.group(2), 0)
                new_off = _apply_align(section_offset, arg, kind)
                if new_off != section_offset:
                    ops.append({"op": "align", "kind": kind, "n": arg, "pad": new_off - section_offset})
                    section_offset = new_off
                continue
            if m := LABEL_RE.match(s):
                flush()
                cur_label = {"op": "label", "kind": m.group(1), "name": m.group(2), "size": 0}
                continue
            if END_RE.match(s):
                flush()
                continue
            n = _line_bytes(s)
            if n == 0:
                continue
            section_offset += n
            if cur_label is not None:
                cur_label["size"] += n
            else:
                pending_zero += n
    flush()
    return ops


def render(ops: list[dict[str, Any]]) -> str:
    out: list[str] = ['.include "macro.inc"', ""]
    for op in ops:
        k = op["op"]
        if k == "section":
            out.append(f".section {op['name']}")
        elif k == "align":
            out.append(f".{op['kind']} {op['n']}")
        elif k == "label":
            out.append(f"{op['kind']} {op['name']}")
            if op["size"] > 0:
                out.append(f".zero 0x{op['size']:X}")
            if op["kind"] == "glabel":
                out.append(f"endlabel {op['name']}")
            elif op["kind"] == "dlabel":
                out.append(f"enddlabel {op['name']}")
        elif k == "zero":
            out.append(f".zero 0x{op['size']:X}")
    out.append("")
    return "\n".join(out)


def build_manifest() -> int:
    if not BUILD.is_dir():
        print(f"error: missing {BUILD} — run `make check` first", file=sys.stderr)
        return 1
    files: dict[str, list[dict[str, Any]]] = {}
    for p in sorted(BUILD.rglob("*.s")):
        rel = p.relative_to(ROOT).as_posix()
        try:
            files[rel] = parse_s(p)
        except Exception as e:
            print(f"warn: failed to parse {rel}: {e}", file=sys.stderr)
    MANIFEST.parent.mkdir(parents=True, exist_ok=True)
    MANIFEST.write_text(json.dumps(files, indent=1) + "\n")
    print(f"wrote {MANIFEST} ({len(files)} files, {sum(len(v) for v in files.values())} ops)")
    return 0


_INCLUDE_ASM_RE = re.compile(r"INCLUDE_ASM\(\s*\"[^\"]+\"\s*,\s*(\w+)\s*\)")


def _active_include_asm_names() -> set[str]:
    """Scan src/**/*.c for INCLUDE_ASM(folder, funcX) macros — return funcX set.

    After a contributor decompiles funcX (drops the INCLUDE_ASM, adds a C body),
    the manifest may still list funcX as a nonmatching .s, but rendering its
    stub would create a duplicate-symbol conflict with the new C definition.
    Skip stubs for any glabel whose name isn't in this set.
    """
    names: set[str] = set()
    src = ROOT / "src"
    if not src.is_dir():
        return names
    for c in src.rglob("*.c"):
        for m in _INCLUDE_ASM_RE.finditer(c.read_text()):
            names.add(m.group(1))
    return names


def render_stubs() -> int:
    if not MANIFEST.is_file():
        print(f"error: missing {MANIFEST}", file=sys.stderr)
        return 1
    files = json.loads(MANIFEST.read_text())
    active = _active_include_asm_names()
    skipped = 0
    for rel, ops in files.items():
        # If this file is a per-function nonmatching stub for a glabel that
        # no longer has an active INCLUDE_ASM in src/, skip it — the C body
        # already defines the symbol; rendering would cause a link collision.
        if "nonmatchings" in rel.split("/"):
            glabels = [op["name"] for op in ops
                       if op.get("op") == "label" and op.get("kind") == "glabel"]
            if glabels and not any(name in active for name in glabels):
                skipped += 1
                continue
        out = ROOT / rel
        out.parent.mkdir(parents=True, exist_ok=True)
        out.write_text(render(ops))
    rendered = len(files) - skipped
    print(f"rendered {rendered} stub .s files from {MANIFEST} ({skipped} skipped — decompiled)")
    return 0


def main() -> int:
    p = argparse.ArgumentParser()
    p.add_argument("--build", action="store_true", help="Scan build/src, write manifest.")
    p.add_argument("--render", action="store_true", help="Read manifest, write stub .s files.")
    args = p.parse_args()
    if args.build == args.render:
        p.error("specify exactly one of --build / --render")
    return build_manifest() if args.build else render_stubs()


if __name__ == "__main__":
    raise SystemExit(main())
