#!/usr/bin/env python3
"""Record data/ file sizes for the CI fixture (no file contents)."""
from __future__ import annotations

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
DATA = ROOT / "data"
OUT = ROOT / "fixtures" / "ci" / "data-manifest.tsv"

EXTRA = (
    "SYSTEM.CNF",
    "license_data.dat",
    "DBGFNT.TIM",
    "BATTLE/SYSTEM.DAT",
    "MENU/ITEMHELP.BIN",
    "MENU/MENU12.BIN",
    "MENU/MCMAN.BIN",
    "MENU/MCDATA.BIN",
    "MENU/BLADE.SYD",
    "MENU/ARMOR.SYD",
    "MENU/SHIELD.SYD",
)


def collect_paths() -> set[str]:
    needed: set[str] = set(EXTRA)
    for y in (ROOT / "config").rglob("splat.yaml"):
        text = y.read_text()
        m = re.search(r"target_path: data/(\S+)", text)
        if m:
            needed.add(m.group(1))
    for mk in (ROOT / "config").rglob("Makefile"):
        for m in re.finditer(r"data/([A-Za-z0-9_./-]+)", mk.read_text()):
            path = m.group(1).rstrip("/")
            if path.endswith(".elf") or path in {"MENU/MENU", "MENU"}:
                continue
            needed.add(path)
    if DATA.is_dir():
        for p in DATA.rglob("*"):
            if not p.is_file():
                continue
            rel = p.relative_to(DATA).as_posix()
            if rel.startswith("SMALL/HELP") or rel.startswith("SMALL/SCEN"):
                needed.add(rel)
            if rel.endswith(".ARM") or rel.endswith(".DIS"):
                needed.add(rel)
    return needed


def main() -> int:
    if not DATA.is_dir():
        print("error: data/ missing — run make once with your disk dump first", file=sys.stderr)
        return 1
    paths = collect_paths()
    lines: list[str] = []
    missing = 0
    for rel in sorted(paths):
        fp = DATA / rel
        if fp.is_file():
            lines.append(f"{rel}\t{fp.stat().st_size}")
        else:
            lines.append(f"{rel}\t0")
            missing += 1
    OUT.parent.mkdir(parents=True, exist_ok=True)
    OUT.write_text("\n".join(lines) + "\n")
    print(f"wrote {OUT} ({len(lines)} entries, {missing} placeholders with size 0)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
