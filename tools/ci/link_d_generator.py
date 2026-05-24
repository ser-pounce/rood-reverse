#!/usr/bin/env python3
"""Regenerate build/config/<binary>/link.d files from asm-manifest + src walk.

The committed seed link.d files under fixtures/ci/seeds/ are produced by splat
from each binary's splat.yaml. They list every .o that contributes to the
final ELF, in splat segment order, plus an empty prereq block and an -include
line for the per-object .d files.

This generator reproduces the *set* of .o entries (not the original order)
from two CI inputs that are already shipped in fixtures/ci/:

  * fixtures/ci/asm-manifest.json — keys are build/src/<binary>/<path>.s
    (every .s file splat would emit). Stripping .s and swapping to .o gives
    the asm-derived .o list.
  * src/<binary>/**/*.c — hand-written C sources. Each maps to
    build/src/<binary>/<rel>.o.

Image / asset .o entries (e.g. build/assets/.../foo.img.o) and any other
non-src/non-asm artefacts are *not* recovered from these two inputs.

Usage:
    python tools/ci/link_d_generator.py --render        # writes link.d files
    python tools/ci/link_d_generator.py --diff          # compares to seeds
"""
from __future__ import annotations

import argparse
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
ASM_MANIFEST = ROOT / "fixtures" / "ci" / "asm-manifest.json"
SEEDS = ROOT / "fixtures" / "ci" / "seeds"

# Mirror BINARIES from the top-level Makefile.
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


def asm_objs_for(binary: str, manifest: dict) -> list[str]:
    prefix = f"build/src/{binary}/"
    out: list[str] = []
    seen: set[str] = set()
    for key in manifest:
        if not key.startswith(prefix) or not key.endswith(".s"):
            continue
        o = key[:-2] + ".o"
        if o not in seen:
            seen.add(o)
            out.append(o)
    return out


def c_objs_for(binary: str) -> list[str]:
    src_dir = ROOT / "src" / binary
    if not src_dir.is_dir():
        return []
    out: list[str] = []
    for c in sorted(src_dir.rglob("*.c")):
        rel = c.relative_to(src_dir).with_suffix(".o")
        out.append(f"build/src/{binary}/{rel.as_posix()}")
    return out


def render_link_d(binary: str, manifest: dict) -> str:
    asm_objs = asm_objs_for(binary, manifest)
    c_objs = c_objs_for(binary)
    # Union, preserving (manifest order, then sorted C order). De-dup
    # because an asm and a c source can theoretically map to the same .o
    # (they won't in practice — splat emits one or the other).
    seen: set[str] = set()
    objs: list[str] = []
    for o in (*asm_objs, *c_objs):
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


def cmd_render(manifest: dict) -> None:
    for binary in BINARIES:
        out = ROOT / "build" / "config" / binary / "link.d"
        out.parent.mkdir(parents=True, exist_ok=True)
        out.write_text(render_link_d(binary, manifest))
        print(f"wrote {out.relative_to(ROOT)}")


def cmd_diff(manifest: dict) -> int:
    matches = 0
    diffs: list[tuple[str, set[str], set[str]]] = []
    for binary in BINARIES:
        seed = SEEDS / "build" / "config" / binary / "link.d"
        if not seed.is_file():
            print(f"missing seed: {seed}")
            continue
        generated = render_link_d(binary, manifest)
        seed_text = seed.read_text()
        if generated == seed_text:
            matches += 1
            print(f"MATCH  {binary}")
            continue
        # set-equivalence check
        gen_objs = _extract_objs(generated)
        seed_objs = _extract_objs(seed_text)
        if gen_objs == seed_objs:
            print(f"ORDER  {binary} (same set, different order)")
        else:
            only_seed = seed_objs - gen_objs
            only_gen = gen_objs - seed_objs
            print(f"DIFFER {binary}")
            for o in sorted(only_seed):
                print(f"   - seed-only: {o}")
            for o in sorted(only_gen):
                print(f"   - gen-only:  {o}")
            diffs.append((binary, only_seed, only_gen))
    print(f"\n{matches}/{len(BINARIES)} exact matches")
    return 0 if not diffs else 1


def _extract_objs(text: str) -> set[str]:
    objs: set[str] = set()
    for line in text.splitlines():
        line = line.strip().rstrip("\\").strip()
        if line.endswith(".o") and " " not in line and ":" not in line:
            objs.add(line)
    return objs


def main() -> int:
    ap = argparse.ArgumentParser()
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("--render", action="store_true")
    g.add_argument("--diff", action="store_true")
    args = ap.parse_args()
    manifest = json.loads(ASM_MANIFEST.read_text())
    if args.render:
        cmd_render(manifest)
        return 0
    return cmd_diff(manifest)


if __name__ == "__main__":
    raise SystemExit(main())
