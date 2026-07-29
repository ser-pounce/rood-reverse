#!/usr/bin/env python3
"""Compare compiled functions against their target assembly, by encoding.

    tools/dev/dcmp.py <unit.c> [<func> ...]

Rebuilds the unit's object, then for each named function compares the 32-bit
instruction encodings against build/.../nonmatchings/<unit>/<func>.s.  With no
function names it checks everything you have written in C whose target .s is
still on disk, which is the set that matters: splat clears a function's .s only
on a full `make`, and building a single object does not rerun it.

    tools/dev/dcmp.py src/BATTLE/BATTLE.PRG/5BF94.c func_800D2518
    tools/dev/dcmp.py src/BATTLE/BATTLE.PRG/5BF94.c

Why encodings and not text: objdump prints `move a0,a1` and decimal immediates
where spimdisasm prints `addu $a0, $a1, $zero` and hex, so a textual diff of the
two is entirely false positives.

Fields that a relocation fills in (%hi/%lo immediates, jal targets) are masked
on *both* sides whenever *either* side relocates them, because the object is not
linked.  That matters for `--defsym` symbols: `_camera` is defined at
0x1F800000 by config/BATTLE/BATTLE.PRG/Makefile, so it is a relocation in our
object and a baked-in absolute in the disassembly.  Relocation symbol names are
compared only where both sides carry one.

A full `make` remains the arbiter: this only tells you a single function is
right, not that the unit still links to the same bytes.
"""
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
OBJDUMP = "mipsel-linux-gnu-objdump"

JUMP_OPS = {0x02, 0x03}  # j, jal


def masked(word, reloc):
    """Encoding with any relocated field zeroed, so unlinked code compares."""
    if not reloc:
        return word
    if (word >> 26) in JUMP_OPS:
        return word & 0xFC000000
    return word & 0xFFFF0000


def mine(obj, func):
    """[(word, relocsym)] for one function in an unlinked object."""
    out = subprocess.run(
        [OBJDUMP, "-dr", obj], capture_output=True, text=True, check=True,
        cwd=ROOT).stdout
    insns = []
    inside = False
    for line in out.splitlines():
        m = re.match(r"^[0-9a-f]+ <([^>]+)>:$", line)
        if m:
            # A branch target inside the function is its own objdump symbol
            # header; only a real function label ends the one we are reading.
            if not m.group(1).startswith("."):
                inside = m.group(1) == func
            continue
        if not inside:
            continue
        m = re.match(r"^\s+[0-9a-f]+:\t([0-9a-f]{8}) ", line)
        if m:
            insns.append([int(m.group(1), 16), None])
            continue
        m = re.match(r"^\s+[0-9a-f]+: (R_MIPS_\S+)\s+(\S+)", line)
        if m and insns:
            insns[-1][1] = m.group(2).split("+")[0].split("-")[0]
    return [tuple(i) for i in insns]


ASM_INSN = re.compile(
    r"^\s*/\* [0-9A-Fa-f]+ [0-9A-Fa-f]+ ([0-9A-Fa-f]{8}) \*/\s+(\S+)\s*(.*)$")
SYM = re.compile(r"%(?:hi|lo)\(([A-Za-z_]\w*)\)")


def target(unit_dir, func):
    """[(word, relocsym)] from the spimdisasm .s, text section only.

    Returns None when there is no .s at all, which is what splat leaves behind
    once a function matches and its INCLUDE_ASM is gone.
    """
    path = os.path.join(ROOT, unit_dir, func + ".s")
    if not os.path.exists(path):
        return None
    insns = []
    inside = False
    with open(path) as fh:
        for line in fh:
            if line.startswith("glabel "):
                inside = line.split()[1].strip() == func
                continue
            if line.startswith("endlabel"):
                inside = False
                continue
            if not inside:
                continue
            m = ASM_INSN.match(line)
            if not m:
                continue
            # The comment holds the little-endian bytes; swap to get the word.
            word = int.from_bytes(bytes.fromhex(m.group(1)), "little")
            mn, ops = m.group(2), m.group(3)
            sym = None
            found = SYM.search(ops)
            if found:
                sym = found.group(1)
            elif mn in ("jal", "j") and not ops.strip().startswith(".L"):
                sym = ops.strip()
            insns.append((word, sym))
    return insns


def show(insns, i):
    if i >= len(insns):
        return "-"
    word, sym = insns[i]
    return f"{word:08x} {sym or ''}".strip()


def main():
    if len(sys.argv) < 2:
        print(__doc__)
        return 2

    cfile = os.path.relpath(os.path.abspath(sys.argv[1]), ROOT)
    funcs = sys.argv[2:]
    unit = os.path.splitext(os.path.basename(cfile))[0]
    obj = os.path.join("build", os.path.splitext(cfile)[0] + ".o")
    unit_dir = os.path.join(os.path.dirname(obj), "nonmatchings", unit)

    os.utime(os.path.join(ROOT, cfile), None)
    r = subprocess.run(["make", obj], cwd=ROOT, capture_output=True, text=True)
    if r.returncode != 0:
        print("BUILD FAILED")
        print(r.stdout[-6000:])
        print(r.stderr[-6000:])
        return 1

    with open(os.path.join(ROOT, cfile), errors="replace") as fh:
        still_asm = set(re.findall(
            r"INCLUDE_ASM\(\s*\"[^\"]+\"\s*,\s*(\w+)\s*\)", fh.read()))

    if not funcs:
        # Everything written in C whose target .s is still on disk, which is
        # exactly the set worth checking: splat only clears a function's .s on a
        # full `make`, and building one object does not rerun it.  Functions
        # still behind INCLUDE_ASM are skipped -- comparing one against its own
        # source only shows where the assembler put its nops.
        try:
            have = sorted(f[:-2] for f in os.listdir(os.path.join(ROOT, unit_dir))
                          if f.endswith(".s"))
        except OSError:
            have = []
        funcs = [f for f in have if f not in still_asm]
        if not funcs:
            print("nothing to check: every function with a target .s is still "
                  "INCLUDE_ASM")
            return 0

    rc = 0
    for func in funcs:
        if func in still_asm:
            print(f"{func:<22} still INCLUDE_ASM -- would only compare its own "
                  "assembled source, skipping")
            continue
        got, want = mine(os.path.join(ROOT, obj), func), target(unit_dir, func)
        if want is None:
            print(f"{func:<22} no target .s -- already matched, nothing to diff")
            continue
        if not want:
            # A rodata-only .s, e.g. a jump table split out on its own.
            continue
        if not got:
            print(f"{func:<22} not in object (still INCLUDE_ASM?)")
            continue

        n = max(len(got), len(want))
        gm, wm = [], []
        for i in range(n):
            g = got[i] if i < len(got) else (None, None)
            w = want[i] if i < len(want) else (None, None)
            reloc = bool(g[1]) or bool(w[1])
            both = g[1] and w[1]
            gm.append((masked(g[0], reloc) if g[0] is not None else None,
                       g[1] if both else None))
            wm.append((masked(w[0], reloc) if w[0] is not None else None,
                       w[1] if both else None))
        gm, wm = gm[:len(got)], wm[:len(want)]

        if gm == wm:
            print(f"{func:<22} MATCH ({len(got)} insns)")
            continue

        rc = 1
        print(f"{func:<22} DIFF (got {len(got)}, want {len(want)})")
        for i in range(n):
            g = gm[i] if i < len(gm) else None
            w = wm[i] if i < len(wm) else None
            if g != w:
                print(f"    >>> {i:>4}  {show(got, i):<28} | {show(want, i)}")
    return rc


if __name__ == "__main__":
    sys.exit(main())
