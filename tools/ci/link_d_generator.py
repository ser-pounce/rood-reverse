#!/usr/bin/env python3
"""Regenerate build/config/<binary>/link.d files from splat.yaml + src walk.

Each per-binary link.d is normally written by splat. In CI we don't run splat,
so we synthesise the same set of object-file dependencies directly from the
two authoritative inputs that are checked in:

  * config/<binary>/splat.yaml   — every subsegment + top-level segment.
    This is splat's source of truth for what gets emitted under build/.
  * src/<binary>/**/*.c          — hand-written C sources. Subsegments of
    type `c, <name>` produce build/src/<binary>/<name>.o which is compiled
    from a matching src/.../<name>.c.

The set of .o entries is what `make` needs as link-time prerequisites; the
order inside link.d doesn't matter for `make` (it just walks the prereq
list), so we compare against the committed seeds set-wise.

Subsegment-to-object rules (mirrors splat behaviour for the formats this
project uses):

  list form  [addr]                          -> end marker, no .o
  list form  [addr, <type>]                  -> <HEX>.<sfx>.o          (anon)
  list form  [addr, <type>, <name>, ...]     -> <name>.<sfx>.o
  dict form  {start, type, name, ...}        -> same as list form
  top-level  [0, header]                     -> header.o
  top-level  [addr, overlay]                 -> overlay.o (top-level only)

  type 'c'/'asm'/'hasm'                      -> <name>.o or <HEX>.o
  type 'data'/'rodata'/'bss'                 -> <name>.<type>.o or <HEX>.<type>.o
  type '.data'/'.rodata'/'.bss'/'.sbss'      -> MERGED, no extra .o emitted
                                                (consumed by sibling c/asm)
  type 'rgbClut'/'rgba16'/'rgba16Header'/    -> build/assets/<binary>/
       'rgba16Compressed'                       <name>.<type>.img.o
  type 'vsStringTable'                       -> build/assets/<binary>/
                                                <name>.vsString.o
  any with linker_entry: false               -> skipped

Top-level [addr, header] and [addr, overlay] are well-known names; anything
else with only [addr] is an end marker (no .o).

C-source walk: every src/<binary>/**/*.c produces build/src/<binary>/<rel>.o.
This both catches plain c subsegments (we don't have to invert the name->c
mapping) AND catches files like 2MBYTE.OBJ.c that the splat.yaml references
only via a `.data, 2MBYTE.OBJ` merged section.

Usage:
    python tools/ci/link_d_generator.py --render        # write link.d files
    python tools/ci/link_d_generator.py --diff          # compare to seeds
"""
from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
SEEDS = ROOT / "fixtures" / "ci" / "seeds"

BINARIES = ["SLUS_010.40"] + [
    f"{b}.PRG"
    for b in (
        "TITLE/TITLE",
        "BATTLE/BATTLE",
        "BATTLE/INITBTL",
        "GIM/SCREFF2",
        "ENDING/ENDING",
        "MENU/MAINMENU",
        *(f"MENU/MENU{c}" for c in "012345789BCDEF"),
    )
]

IMG_TYPES = {"rgbClut", "rgba16", "rgba16Header", "rgba16Compressed"}
DATA_LIKE = {"data", "rodata", "bss"}
MERGED_SECTIONS = {".data", ".rodata", ".bss", ".sbss"}
TOP_LEVEL_NAMED = {"header", "overlay"}  # produce <name>.o at top level


def parse_subsegments(yaml_text: str) -> list[dict]:
    """Yield {form, addr, type, name, linker_entry, top_level} for each
    segment / subsegment entry in the splat.yaml.

    We do this with a regex pass rather than PyYAML to avoid a runtime dep.
    Splat's subsegment lines have two stable shapes:

        - [hex, type, name, ...]
        - {start: hex, type: T, name: N, ..., linker_entry: false}

    Top-level segments use the same list form: `  - [0, header]`,
    `  - [0x52800]`.
    """
    entries: list[dict] = []
    indent_top = None       # indent of top-level seg `  - `
    indent_sub = None       # indent of subseg `      - ` under subsegments
    in_subsegments = False
    for raw in yaml_text.splitlines():
        if not raw.strip() or raw.lstrip().startswith("#"):
            continue
        # detect "subsegments:" key (any indent) to flag following items
        stripped = raw.strip()
        if stripped == "subsegments:":
            in_subsegments = True
            indent_sub = None  # will be set by first child
            continue
        # leading-spaces count
        lead = len(raw) - len(raw.lstrip())
        if not raw.lstrip().startswith("- "):
            # could be a key like `start:` (within a dict-form top-level seg).
            # Leaving the subsegments block is detected by an outdent that
            # introduces a non-`- ` line at indent <= indent_sub - 2.
            if in_subsegments and indent_sub is not None and lead < indent_sub:
                in_subsegments = False
            continue
        item = raw.lstrip()[2:].rstrip()  # drop "- "
        # Top-level seg starting `start:` (dict form) — we don't need a .o for
        # the container; subsegments inside it provide the .o entries.
        if item.startswith("start:"):
            in_subsegments = False
            continue
        if item.startswith("["):
            entry = _parse_list_form(item)
        elif item.startswith("{"):
            entry = _parse_dict_form(item)
        else:
            continue
        if entry is None:
            continue
        # Classify as top-level vs subsegment by indent.
        # Top-level seg lines look like `  - [0, header]` (2-space indent
        # before `-`); subsegments look like `      - ...` (6-space indent).
        entry["top_level"] = (lead <= 2) or (not in_subsegments)
        if in_subsegments and indent_sub is None:
            indent_sub = lead
        entries.append(entry)
    return entries


_HEX = r"0x[0-9A-Fa-f]+|[0-9]+"


def _parse_list_form(item: str) -> dict | None:
    # Strip trailing comment.
    body = item
    if "#" in body:
        body = body.split("#", 1)[0].rstrip()
    if not (body.startswith("[") and body.endswith("]")):
        return None
    inner = body[1:-1].strip()
    if not inner:
        return None
    parts = [p.strip() for p in inner.split(",")]
    addr = parts[0]
    if len(parts) == 1:
        return {"addr": addr, "type": None, "name": None,
                "linker_entry": True}
    typ = parts[1]
    name = parts[2] if len(parts) >= 3 else None
    return {"addr": addr, "type": typ, "name": name, "linker_entry": True}


def _parse_dict_form(item: str) -> dict | None:
    body = item
    if "#" in body:
        body = body.split("#", 1)[0].rstrip()
    if not (body.startswith("{") and body.endswith("}")):
        return None
    inner = body[1:-1]
    fields: dict[str, str] = {}
    for kv in _split_dict_fields(inner):
        if ":" not in kv:
            continue
        k, v = kv.split(":", 1)
        fields[k.strip()] = v.strip()
    typ = fields.get("type")
    name = fields.get("name")
    linker_entry = fields.get("linker_entry", "true").lower() != "false"
    return {"addr": fields.get("start", ""), "type": typ, "name": name,
            "linker_entry": linker_entry}


def _split_dict_fields(inner: str) -> list[str]:
    # Split on commas not inside nested braces/brackets/quotes.
    out, depth, buf = [], 0, []
    for ch in inner:
        if ch in "[{":
            depth += 1
            buf.append(ch)
        elif ch in "]}":
            depth -= 1
            buf.append(ch)
        elif ch == "," and depth == 0:
            out.append("".join(buf))
            buf = []
        else:
            buf.append(ch)
    if buf:
        out.append("".join(buf))
    return out


def _hex_label(addr: str) -> str:
    # Splat uses uppercase hex without 0x prefix.
    a = addr.strip()
    if a.lower().startswith("0x"):
        a = a[2:]
    # Trim leading zeros for canonical form (splat does '22C', not '0022C').
    return a.lstrip("0").upper() or "0"


def objs_from_splat(binary: str) -> tuple[set[str], list[str]]:
    yml = ROOT / "config" / binary / "splat.yaml"
    if not yml.is_file():
        return set(), []
    entries = parse_subsegments(yml.read_text())
    objs: list[str] = []
    seen: set[str] = set()
    src_prefix = f"build/src/{binary}/"
    asset_prefix = f"build/assets/{binary}/"

    def add(path: str) -> None:
        if path not in seen:
            seen.add(path)
            objs.append(path)

    for e in entries:
        typ = e["type"]
        name = e["name"]
        addr = e["addr"]
        if not e["linker_entry"]:
            continue
        if e["top_level"]:
            # Top-level seg: [0, header], [0x800, overlay], or end markers.
            if typ in TOP_LEVEL_NAMED:
                add(f"{src_prefix}{typ}.o")
            # Anything else at top level (incl. type==None which is end marker,
            # or `start:` dict form which we already skipped) emits no .o.
            continue
        if typ is None:
            continue
        if typ in MERGED_SECTIONS:
            continue  # merged into sibling c/asm/standalone
        if typ in IMG_TYPES:
            if name:
                add(f"{asset_prefix}{name}.{typ}.img.o")
            continue
        if typ == "vsStringTable":
            if name:
                add(f"{asset_prefix}{name}.vsString.o")
            continue
        if typ in ("c", "asm", "hasm"):
            stem = name if name else _hex_label(addr)
            add(f"{src_prefix}{stem}.o")
            continue
        if typ in DATA_LIKE:
            stem = name if name else _hex_label(addr)
            add(f"{src_prefix}{stem}.{typ}.o")
            continue
        # Unknown type — ignore (matches splat's "no linker entry" default
        # for exotic types we don't model).
    return seen, objs


def objs_from_csrc(binary: str) -> list[str]:
    src_dir = ROOT / "src" / binary
    if not src_dir.is_dir():
        return []
    out: list[str] = []
    for c in sorted(src_dir.rglob("*.c")):
        rel = c.relative_to(src_dir).with_suffix(".o")
        out.append(f"build/src/{binary}/{rel.as_posix()}")
    return out


def render_link_d(binary: str) -> str:
    splat_seen, splat_order = objs_from_splat(binary)
    c_objs = objs_from_csrc(binary)
    seen: set[str] = set()
    objs: list[str] = []
    for o in (*splat_order, *c_objs):
        if o not in seen:
            seen.add(o)
            objs.append(o)

    elf = f"build/data/{binary}.elf"
    lines = [f"{elf}: \\"]
    for i, o in enumerate(objs):
        suffix = " \\" if i < len(objs) - 1 else ""
        lines.append(f"    {o}{suffix}")
    for o in objs:
        lines.append(f"{o}:")
    dlist = " ".join(o[:-2] + ".d" for o in objs)
    lines.append(f"-include {dlist}")
    return "\n".join(lines) + "\n"


def _extract_objs(text: str) -> set[str]:
    objs: set[str] = set()
    for line in text.splitlines():
        s = line.strip().rstrip("\\").strip()
        if s.endswith(".o") and " " not in s and ":" not in s:
            objs.add(s)
    return objs


def cmd_render() -> int:
    for binary in BINARIES:
        out = ROOT / "build" / "config" / binary / "link.d"
        out.parent.mkdir(parents=True, exist_ok=True)
        out.write_text(render_link_d(binary))
        print(f"wrote {out.relative_to(ROOT)}")
    return 0


def cmd_diff() -> int:
    matches = 0
    set_matches = 0
    diffs: list[str] = []
    for binary in BINARIES:
        seed = SEEDS / "build" / "config" / binary / "link.d"
        if not seed.is_file():
            print(f"missing seed: {seed}")
            continue
        gen = render_link_d(binary)
        seed_text = seed.read_text()
        if gen == seed_text:
            matches += 1
            set_matches += 1
            print(f"MATCH  {binary}")
            continue
        gen_set = _extract_objs(gen)
        seed_set = _extract_objs(seed_text)
        if gen_set == seed_set:
            set_matches += 1
            print(f"ORDER  {binary} (same set, different order)")
            continue
        only_seed = sorted(seed_set - gen_set)
        only_gen = sorted(gen_set - seed_set)
        diffs.append(binary)
        print(f"DIFFER {binary}")
        for o in only_seed:
            print(f"   - seed-only: {o}")
        for o in only_gen:
            print(f"   - gen-only:  {o}")
    print()
    print(f"exact match: {matches}/{len(BINARIES)}")
    print(f"set match  : {set_matches}/{len(BINARIES)}")
    return 0 if not diffs else 1


def main() -> int:
    ap = argparse.ArgumentParser()
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("--render", action="store_true")
    g.add_argument("--diff", action="store_true")
    args = ap.parse_args()
    if args.render:
        return cmd_render()
    return cmd_diff()


if __name__ == "__main__":
    raise SystemExit(main())
