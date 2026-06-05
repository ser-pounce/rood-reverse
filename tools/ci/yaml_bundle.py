#!/usr/bin/env python3
"""Bundle / unpack the .yaml asset descriptors as a single committed file.

The .yaml files under fixtures/ci/seeds/build/assets/ are real content
consumed by the build (vsString tables, asset combinations, etc.) — not
layout metadata, so we can't synthesize them. But there are 51 of them,
which is noisy in PR diffs. Bundle them as one JSON map of
{path: raw text} so each PR shows changes inline within a single file.

Two modes:
  --build   Scan fixtures/ci/seeds/build/assets/**/*.yaml, write
            fixtures/ci/yaml-bundle.json.
  --render  Read the bundle, write each yaml back to build/assets/.
"""
from __future__ import annotations

import argparse
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
SEEDS_ROOT = ROOT / "fixtures" / "ci" / "seeds" / "build" / "assets"
BUNDLE = ROOT / "fixtures" / "ci" / "yaml-bundle.json"


def build_bundle(scan_root: Path) -> int:
    seeds_prefix = ROOT / "fixtures" / "ci" / "seeds"
    bundle: dict[str, str] = {}
    for p in sorted(scan_root.rglob("*.yaml")):
        try:
            rel = p.relative_to(seeds_prefix).as_posix()
        except ValueError:
            rel = p.relative_to(ROOT).as_posix()
        bundle[rel] = p.read_text()
    BUNDLE.write_text(json.dumps(bundle, indent=1, sort_keys=True) + "\n")
    print(f"wrote {BUNDLE} ({len(bundle)} entries, {BUNDLE.stat().st_size} bytes)")
    return 0


def render_stubs() -> int:
    if not BUNDLE.is_file():
        print(f"error: missing {BUNDLE}", file=sys.stderr)
        return 1
    bundle = json.loads(BUNDLE.read_text())
    for rel, content in bundle.items():
        out = ROOT / rel
        out.parent.mkdir(parents=True, exist_ok=True)
        out.write_text(content)
    print(f"rendered {len(bundle)} yaml files from {BUNDLE}")
    return 0


def main() -> int:
    p = argparse.ArgumentParser()
    p.add_argument("--build", action="store_true",
                   help="Scan fixtures/ci/seeds/build/assets and write the bundle.")
    p.add_argument("--scan-from", default=None,
                   help="(--build) Directory to scan instead of the seeds tree.")
    p.add_argument("--render", action="store_true",
                   help="Read bundle, write yamls into build/assets/.")
    args = p.parse_args()
    if args.build == args.render:
        p.error("specify exactly one of --build / --render")
    if args.build:
        return build_bundle(Path(args.scan_from) if args.scan_from else SEEDS_ROOT)
    return render_stubs()


if __name__ == "__main__":
    raise SystemExit(main())
