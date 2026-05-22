#!/usr/bin/env python3
"""Prepare data/ and build/ seeds for CI smoke (synthetic zero-filled inputs)."""
from __future__ import annotations

import shutil
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
FIXTURE = ROOT / "fixtures" / "ci"
MANIFEST = FIXTURE / "data-manifest.tsv"
SEEDS = FIXTURE / "seeds" / "build"
DATA_SEEDS = FIXTURE / "data"
SPLAT_INPUTS = (
    "SLUS_010.40",
    "BATTLE/BATTLE.PRG",
    "BATTLE/INITBTL.PRG",
    "TITLE/TITLE.PRG",
    "GIM/SCREFF2.PRG",
    "ENDING/ENDING.PRG",
    "MENU/MAINMENU.PRG",
    "MENU/MENU0.PRG",
    "MENU/MENU1.PRG",
    "MENU/MENU2.PRG",
    "MENU/MENU3.PRG",
    "MENU/MENU4.PRG",
    "MENU/MENU5.PRG",
    "MENU/MENU7.PRG",
    "MENU/MENU8.PRG",
    "MENU/MENU9.PRG",
    "MENU/MENUB.PRG",
    "MENU/MENUC.PRG",
    "MENU/MENUD.PRG",
    "MENU/MENUE.PRG",
    "MENU/MENUF.PRG",
)


def read_manifest() -> list[tuple[str, int]]:
    rows: list[tuple[str, int]] = []
    for line in MANIFEST.read_text().splitlines():
        line = line.strip()
        if not line or line.startswith("#"):
            continue
        rel, size = line.split("\t", 1)
        rows.append((rel, int(size)))
    return rows


def write_zeros(data_root: Path, rows: list[tuple[str, int]]) -> None:
    for rel, size in rows:
        if size <= 0:
            continue
        out = data_root / rel
        out.parent.mkdir(parents=True, exist_ok=True)
        # Deterministic filler (not retail game bytes).
        out.write_bytes(bytes([i & 0xFF for i in range(size)]))


def copy_seeds() -> None:
    if not SEEDS.is_dir():
        raise FileNotFoundError(f"missing {SEEDS} — run make ci-fixture-seeds")
    for src in SEEDS.rglob("*"):
        if not src.is_file():
            continue
        rel = src.relative_to(SEEDS)
        dst = ROOT / "build" / rel
        dst.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(src, dst)
    for link_d in (ROOT / "build" / "config").rglob("link.d"):
        link_d.touch()
    lbas = ROOT / "build" / "src" / "include" / "lbas.h"
    if lbas.is_file():
        lbas.touch()
    for lba in (ROOT / "build" / "config").glob("*_LBA.txt"):
        lba.touch()


def _install_data_fixture(data_root: Path) -> None:
    """Install frozen PRG stubs; asset pipelines use seeded build/assets/."""
    if DATA_SEEDS.is_dir():
        for src in DATA_SEEDS.rglob("*"):
            if not src.is_file():
                continue
            rel = src.relative_to(DATA_SEEDS)
            dst = data_root / rel
            dst.parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(src, dst)
        return
    write_zeros(data_root, [(p, size) for p, size in read_manifest() if p in SPLAT_INPUTS])


def _touch_tree(root: Path) -> None:
    if not root.is_dir():
        return
    for f in root.rglob("*"):
        if f.is_file():
            f.touch()


def touch_disk_config() -> None:
    cfg = ROOT / "config" / "SLUS-01040.xml"
    cfg.parent.mkdir(parents=True, exist_ok=True)
    if not cfg.exists():
        cfg.write_text(
            '<?xml version="1.0"?><iso_project><!-- CI smoke stub --></iso_project>\n'
        )


def main() -> int:
    if not MANIFEST.is_file():
        print(f"error: missing {MANIFEST}", file=sys.stderr)
        return 1
    copy_seeds()
    data_root = ROOT / "data"
    data_root.mkdir(parents=True, exist_ok=True)
    _install_data_fixture(data_root)
    _touch_tree(ROOT / "build" / "assets")
    touch_disk_config()
    print("CI fixture ready")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
