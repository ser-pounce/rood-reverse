#!/usr/bin/env python3
"""Prepare a disk-free build tree for CI smoke.

What we do, in order:
  1. Write deterministic filler bytes to data/<rel> for every entry in
     fixtures/ci/data-manifest.tsv. (Splat would normally extract these from
     the retail ISO; we don't have it in CI.)
  2. Render stub .s files into build/src/... from fixtures/ci/asm-manifest.json
     via tools/ci/asm_manifest.py. The stubs preserve every section, global
     symbol, and alignment from the real splat output — only the byte
     contents are replaced with .zero <N>.
  3. Copy fixtures/ci/seeds/ subtrees into the project root: linker scripts
     (build/config/*/link.{d,ld}), splat-generated headers (include/*.inc),
     etc. Anything splat would write that isn't a .s file.
  4. Drop a stub config/SLUS-01040.xml so the disk-extraction step is skipped.
"""
from __future__ import annotations

import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
FIXTURE = ROOT / "fixtures" / "ci"
DATA_MANIFEST = FIXTURE / "data-manifest.tsv"
SEEDS = FIXTURE / "seeds"
MARKER = FIXTURE / ".installed"
ASM_TOOL = ROOT / "tools" / "ci" / "asm_manifest.py"


def write_data() -> None:
    for line in DATA_MANIFEST.read_text().splitlines():
        line = line.strip()
        if not line or line.startswith("#"):
            continue
        rel, size = line.split("\t", 1)
        size = int(size)
        if size <= 0:
            continue
        out = ROOT / "data" / rel
        out.parent.mkdir(parents=True, exist_ok=True)
        out.write_bytes(bytes([i & 0xFF for i in range(size)]))


def copy_seeds() -> None:
    if not SEEDS.is_dir():
        return
    for src in SEEDS.rglob("*"):
        if not src.is_file():
            continue
        rel = src.relative_to(SEEDS)
        dst = ROOT / rel
        dst.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(src, dst)


def render_asm_stubs() -> None:
    subprocess.run([sys.executable, str(ASM_TOOL), "--render"], check=True)


def touch_disk_config() -> None:
    cfg = ROOT / "config" / "SLUS-01040.xml"
    cfg.parent.mkdir(parents=True, exist_ok=True)
    if not cfg.exists():
        cfg.write_text(
            '<?xml version="1.0"?><iso_project><!-- CI smoke stub --></iso_project>\n'
        )


def main() -> int:
    if not DATA_MANIFEST.is_file():
        print(f"error: missing {DATA_MANIFEST}", file=sys.stderr)
        return 1
    write_data()
    render_asm_stubs()
    copy_seeds()
    touch_disk_config()
    MARKER.write_text("ok\n")
    print("CI fixture ready (stubs + seeds installed)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
