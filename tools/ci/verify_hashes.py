#!/usr/bin/env python3
"""Compare SHA-256 of build outputs against fixtures/ci/expected.sha256."""
from __future__ import annotations

import hashlib
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
EXPECTED = ROOT / "fixtures" / "ci" / "expected.sha256"
BUILD_DATA = ROOT / "build" / "data"


def sha256_file(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def load_expected() -> list[tuple[str, str]]:
    rows: list[tuple[str, str]] = []
    for line in EXPECTED.read_text().splitlines():
        line = line.strip()
        if not line or line.startswith("#"):
            continue
        digest, rel = line.split(maxsplit=1)
        rows.append((rel.strip(), digest.strip()))
    return rows


def main() -> int:
    update = "--update" in sys.argv
    paths = [a for a in sys.argv[1:] if a != "--update"]

    if paths:
        targets = [Path(p) for p in paths]
    elif update:
        print("error: --update requires explicit build output paths", file=sys.stderr)
        return 1
    else:
        if not EXPECTED.is_file():
            print(f"error: missing {EXPECTED}", file=sys.stderr)
            return 1
        targets = [BUILD_DATA / rel for rel, _ in load_expected()]

    lines: list[str] = []
    fail = 0
    for path in targets:
        if not path.is_file():
            print(f"missing output: {path}")
            fail += 1
            continue
        digest = sha256_file(path)
        try:
            rel = path.resolve().relative_to(BUILD_DATA.resolve()).as_posix()
        except ValueError:
            print(f"error: {path} is not under {BUILD_DATA}", file=sys.stderr)
            return 1
        lines.append(f"{digest}  {rel}")

    if update:
        EXPECTED.parent.mkdir(parents=True, exist_ok=True)
        EXPECTED.write_text("\n".join(sorted(lines, key=lambda x: x.split("  ", 1)[1])) + "\n")
        print(f"updated {EXPECTED} ({len(lines)} files)")
        return 0

    expected = {rel: digest for rel, digest in load_expected()}
    for rel in sorted(expected):
        path = BUILD_DATA / rel
        want = expected[rel]
        if not path.is_file():
            print(f"missing output: {rel}")
            fail += 1
            continue
        got = sha256_file(path)
        if got != want:
            print(f"hash mismatch: {rel}")
            print(f"  expected {want}")
            print(f"  got      {got}")
            fail += 1
    if fail:
        return 1
    print(f"CI smoke hashes OK ({len(expected)} artifacts)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
