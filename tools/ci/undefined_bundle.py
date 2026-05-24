#!/usr/bin/env python3
"""Bundle / unpack the splat undefined_*.txt files as a single committed file.

The undefined_funcs_auto.txt and undefined_syms_auto.txt files under
fixtures/ci/seeds/build/config/**/ are real content consumed by the build
(splat-generated symbol lists) — not layout metadata, so we can't synthesize
them. But there are 42 of them, which is noisy in PR diffs. Bundle them as
one JSON map of {path: raw text} so each PR shows changes inline within a
single file.

Two modes:
  --build   Scan fixtures/ci/seeds/build/config/**/undefined_*.txt, write
            fixtures/ci/undefined-bundle.json.
  --render  Read the bundle, write each txt back to build/config/.
"""
from __future__ import annotations

import argparse
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
SEEDS_ROOT = ROOT / "fixtures" / "ci" / "seeds" / "build" / "config"
BUNDLE = ROOT / "fixtures" / "ci" / "undefined-bundle.json"


def build_bundle(scan_root: Path) -> int:
    seeds_prefix = ROOT / "fixtures" / "ci" / "seeds"
    bundle: dict[str, str] = {}
    for p in sorted(scan_root.rglob("undefined_*.txt")):
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
    print(f"rendered {len(bundle)} undefined_*.txt files from {BUNDLE}")
    return 0


def main() -> int:
    p = argparse.ArgumentParser()
    p.add_argument("--build", action="store_true",
                   help="Scan fixtures/ci/seeds/build/config and write the bundle.")
    p.add_argument("--scan-from", default=None,
                   help="(--build) Directory to scan instead of the seeds tree.")
    p.add_argument("--render", action="store_true",
                   help="Read bundle, write undefined_*.txt into build/config/.")
    args = p.parse_args()
    if args.build == args.render:
        p.error("specify exactly one of --build / --render")
    if args.build:
        return build_bundle(Path(args.scan_from) if args.scan_from else SEEDS_ROOT)
    return render_stubs()


if __name__ == "__main__":
    raise SystemExit(main())
