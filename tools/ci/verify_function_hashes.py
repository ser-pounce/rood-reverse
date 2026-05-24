#!/usr/bin/env python3
"""Per-symbol hash verification for ci-smoke.

For every glabel/dlabel in asm-manifest.json that carries a `sha256`:
  - Skip if the symbol is still INCLUDE_ASM'd in src/ (the byte content is
    a stub `.zero <N>` placeholder — comparing it against itself proves
    nothing, and the manifest's retail hash won't match either).
  - Otherwise read the corresponding symbol's bytes from the built .elf,
    hash, compare. Any mismatch fails ci-smoke.

This catches:
  - Buggy decomp (C compiles but bytes differ from retail).
  - Dropped INCLUDE_ASM without C body (symbol resolves to nothing / 0).
  - Fixture tampering (manifest hash drifts from actual build output).

Replaces the per-PRG expected.sha256 check: strictly stronger (catches
per-function regressions even within an otherwise-stable PRG hash) and
doesn't require maintainer hash refreshes on every decomp commit.
"""
from __future__ import annotations

import hashlib
import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
ASM_MANIFEST = ROOT / "fixtures" / "ci" / "asm-manifest.json"

_INCLUDE_ASM_RE = re.compile(r"INCLUDE_ASM\(\s*\"[^\"]+\"\s*,\s*(\w+)\s*\)")


def _active_include_asm_names() -> set[str]:
    names: set[str] = set()
    src = ROOT / "src"
    if not src.is_dir():
        return names
    for c in src.rglob("*.c"):
        for m in _INCLUDE_ASM_RE.finditer(c.read_text()):
            names.add(m.group(1))
    return names


def _binary_from_manifest_path(rel: str) -> str | None:
    """`build/src/SLUS_010.40/.../foo.s` → `SLUS_010.40`.
    `build/src/MENU/MENU0.PRG/.../foo.s` → `MENU/MENU0.PRG`."""
    parts = rel.split("/")
    if len(parts) < 3 or parts[0] != "build" or parts[1] != "src":
        return None
    if len(parts) >= 4 and parts[3].endswith(".PRG"):
        return f"{parts[2]}/{parts[3]}"
    return parts[2]


def _load_elf_symbol_bytes(elf_path: Path) -> dict[str, bytes]:
    """Return {symbol_name: <bytes>} for every named non-zero-size symbol
    in the .elf — same shape as asm_manifest's per-.o map."""
    from elftools.elf.elffile import ELFFile  # type: ignore

    out: dict[str, bytes] = {}
    with elf_path.open("rb") as f:
        elf = ELFFile(f)
        symtab = elf.get_section_by_name(".symtab")
        if symtab is None:
            return out
        secs = [elf.get_section(i) for i in range(elf.num_sections())]
        for sym in symtab.iter_symbols():
            if not sym.name or sym["st_size"] == 0:
                continue
            sec_idx = sym["st_shndx"]
            if not isinstance(sec_idx, int) or sec_idx >= len(secs):
                continue
            sec = secs[sec_idx]
            if sec is None or not hasattr(sec, "data"):
                continue
            off = sym["st_value"] - sec["sh_addr"]
            data = sec.data()
            if off < 0 or off + sym["st_size"] > len(data):
                continue
            out[sym.name] = bytes(data[off:off + sym["st_size"]])
    return out


def verify() -> int:
    if not ASM_MANIFEST.is_file():
        print(f"error: missing {ASM_MANIFEST}", file=sys.stderr)
        return 1
    files = json.loads(ASM_MANIFEST.read_text())
    active = _active_include_asm_names()
    # --- DEBUG (temporary): diagnose CI vs local active-set discrepancy ---
    import platform
    print(f"DEBUG platform: {platform.system()} {platform.machine()} py{sys.version_info[:2]}")
    print(f"DEBUG ROOT={ROOT}")
    src = ROOT / "src"
    print(f"DEBUG src.is_dir()={src.is_dir()} cwd={Path.cwd()}")
    c_files = sorted(src.rglob("*.c")) if src.is_dir() else []
    print(f"DEBUG .c files scanned: {len(c_files)}")
    print(f"DEBUG active total: {len(active)}")
    for n in ("func_8009F858", "func_8009FC20", "func_800A01C8", "func_800A0ABC",
              "func_8009F794", "func_8009F898"):
        print(f"DEBUG  active[{n}] = {n in active}")
    target = ROOT / "src" / "BATTLE" / "BATTLE.PRG" / "30D14.c"
    if target.is_file():
        t = target.read_text()
        print(f"DEBUG 30D14.c len={len(t)} matches={sum(1 for _ in _INCLUDE_ASM_RE.finditer(t))}")
        # Slice around the first failing func.
        idx = t.find("func_8009F858")
        if idx >= 0:
            print(f"DEBUG 30D14.c near F858 [{idx-60}:{idx+60}]={t[max(0,idx-60):idx+60]!r}")
    # --- END DEBUG ---

    # Bucket entries-with-hash by target binary, filtering stubbed funcs out.
    by_binary: dict[str, list[dict]] = {}
    total_hashed = 0
    for rel, ops in files.items():
        binary = _binary_from_manifest_path(rel)
        if binary is None:
            continue
        for op in ops:
            if op.get("op") != "label" or "sha256" not in op:
                continue
            total_hashed += 1
            if op.get("kind") == "glabel" and op["name"] in active:
                continue          # function still stubbed
            by_binary.setdefault(binary, []).append(op)

    if total_hashed == 0:
        print("warn: asm-manifest carries no sha256 fields — verification skipped")
        return 0

    elf_sym_cache: dict[str, dict[str, bytes]] = {}
    mismatches: list[str] = []
    missing: list[str] = []
    checked = 0

    for binary, entries in sorted(by_binary.items()):
        elf = ROOT / "build" / "data" / f"{binary}.elf"
        if not elf.is_file():
            mismatches.append(f"missing .elf: {elf.relative_to(ROOT)}")
            continue
        if binary not in elf_sym_cache:
            elf_sym_cache[binary] = _load_elf_symbol_bytes(elf)
        sym_bytes = elf_sym_cache[binary]
        for e in entries:
            actual = sym_bytes.get(e["name"])
            if actual is None:
                missing.append(f"{binary}:{e['name']} not in linked .elf")
                continue
            actual_sha = hashlib.sha256(actual).hexdigest()
            if actual_sha != e["sha256"]:
                mismatches.append(
                    f"{binary}:{e['name']} expected {e['sha256'][:12]}.. "
                    f"got {actual_sha[:12]}.. ({len(actual)} bytes)"
                )
            checked += 1

    print(f"verified {checked} decompiled symbols against asm-manifest hashes "
          f"({total_hashed - checked} stubbed, skipped)")

    if missing:
        print(f"\n{len(missing)} symbol(s) missing from .elf:", file=sys.stderr)
        for m in missing[:20]:
            print(f"  {m}", file=sys.stderr)
        if len(missing) > 20:
            print(f"  ... {len(missing) - 20} more", file=sys.stderr)
    if mismatches:
        print(f"\n{len(mismatches)} hash mismatch(es):", file=sys.stderr)
        for m in mismatches[:20]:
            print(f"  {m}", file=sys.stderr)
        if len(mismatches) > 20:
            print(f"  ... {len(mismatches) - 20} more", file=sys.stderr)
        return 1
    if missing:
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(verify())
