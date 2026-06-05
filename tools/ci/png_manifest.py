#!/usr/bin/env python3
"""Extract / render PNG shape manifest for CI smoke.

Splat extracts PSX image segments into PNG files under build/assets/<binary>/.
These PNGs feed `tools/make/img.mk` which converts them back to .img.dat /
.img.o for linking — so the build needs PNGs with the right dimensions and
bitdepth, but their pixel/palette *content* is irrelevant for ci-smoke
(retail matching is `make check`, not ci-smoke).

This script swaps the committed PNGs for a compact JSON manifest of shape
metadata + a renderer that writes zero-filled PNGs of identical shape.

Two modes:
  --build   Walk fixtures/ci/seeds/build/assets/**/*.png, write
            fixtures/ci/png-manifest.json.
  --render  Read manifest, write blank PNGs to build/assets/ at the same paths.
"""
from __future__ import annotations

import argparse
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
SEEDS_ROOT = ROOT / "fixtures" / "ci" / "seeds" / "build" / "assets"
MANIFEST = ROOT / "fixtures" / "ci" / "png-manifest.json"

# Lazy import — psx_img wants pypng which is only present inside the venv.
def _psx_img():
    sys.path.insert(0, str(ROOT))
    from tools.etc import psx_img  # type: ignore
    return psx_img


def build_manifest(scan_root: Path) -> int:
    psx_img = _psx_img()
    entries: dict[str, dict] = {}
    # Manifest keys are paths under build/assets/<...> — i.e. where the
    # renderer writes stubs at CI time. Normalize input paths whether the
    # scan root is the seeds copy (fixtures/ci/seeds/build/assets) or a live
    # build tree (build/assets).
    seeds_prefix = ROOT / "fixtures" / "ci" / "seeds"
    for p in sorted(scan_root.rglob("*.png")):
        try:
            rel = p.relative_to(seeds_prefix).as_posix()
        except ValueError:
            rel = p.relative_to(ROOT).as_posix()
        try:
            pixels, w, h, bd, cb, ca, img_rect, clut_rect = psx_img.read_png(p)
        except Exception as e:
            print(f"warn: skip {rel}: {e}", file=sys.stderr)
            continue
        entry: dict = {"w": w, "h": h, "bd": bd}
        if bd != 16:
            entry["nb"] = len(cb)
            entry["na"] = len(ca)
        if img_rect is not None:
            entry["ir"] = list(img_rect)
        if clut_rect is not None:
            entry["cr"] = list(clut_rect)
        entries[rel] = entry
    MANIFEST.write_text(json.dumps(entries, indent=1, sort_keys=True) + "\n")
    print(f"wrote {MANIFEST} ({len(entries)} entries)")
    return 0


def render_stubs() -> int:
    if not MANIFEST.is_file():
        print(f"error: missing {MANIFEST}", file=sys.stderr)
        return 1
    psx_img = _psx_img()
    entries = json.loads(MANIFEST.read_text())
    for rel, e in entries.items():
        out = ROOT / rel
        out.parent.mkdir(parents=True, exist_ok=True)
        w, h, bd = e["w"], e["h"], e["bd"]
        img_rect = tuple(e["ir"]) if "ir" in e else None
        clut_rect = tuple(e["cr"]) if "cr" in e else None
        if bd == 16:
            pixels = bytes(w * h * 4)
            psx_img.write_png(out, pixels, w, h, 16, [], [], img_rect=img_rect)
        else:
            # pypng.write_array takes one value per pixel; it packs nibbles
            # internally for bitdepth 4.
            pixels = bytes(w * h)
            zero_palette = [(0, 0, 0, 0)] * (16 if bd == 4 else 256)
            cluts_before = [zero_palette] * int(e.get("nb", 0))
            cluts_after = [zero_palette] * int(e.get("na", 0))
            psx_img.write_png(
                out, pixels, w, h, bd, cluts_before, cluts_after,
                img_rect=img_rect, clut_rect=clut_rect,
            )
    print(f"rendered {len(entries)} stub PNGs from {MANIFEST}")
    return 0


def main() -> int:
    p = argparse.ArgumentParser()
    p.add_argument("--build", action="store_true",
                   help="Scan fixtures/ci/seeds/build/assets and write manifest.")
    p.add_argument("--scan-from", default=None,
                   help="(--build) Directory to scan instead of seeds_root.")
    p.add_argument("--render", action="store_true",
                   help="Read manifest, write blank PNGs to build/assets/.")
    args = p.parse_args()
    if args.build == args.render:
        p.error("specify exactly one of --build / --render")
    if args.build:
        scan = Path(args.scan_from) if args.scan_from else SEEDS_ROOT
        return build_manifest(scan)
    return render_stubs()


if __name__ == "__main__":
    raise SystemExit(main())
