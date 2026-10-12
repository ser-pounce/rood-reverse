#!/usr/bin/env python3
"""Expand cc1's unsigned divide macros the way ASPSX did (stdin -> stdout).

GNU as expands `divu/remu rd,rs,rt` with the divide in the delay slot of the
zero check; ASPSX emitted the divide first and left the slot empty:

    divu  $0,rs,rt
    bnez  rt,1f
    nop
    break 7
1:  mflo/mfhi rd

This is the same expansion as maspsx --expand-div; signed division and all
other instructions are passed through for GNU as unchanged.
"""
import re
import sys

MACRO = re.compile(r"^\t(divu|remu)\t(\$\w+),(\$\w+),(\$\w+)\s*$")

n = 0
for line in sys.stdin:
    m = MACRO.match(line)
    if not m or m.group(2) in ("$0", "$zero"):
        sys.stdout.write(line)
        continue
    op, rd, rs, rt = m.groups()
    n += 1
    label = f".L_aspsx_divu_{n}"
    sys.stdout.write(
        "\t.set\tnoreorder\n"
        f"\tdivu\t$0,{rs},{rt}\n"
        f"\tbnez\t{rt},{label}\n"
        "\tnop\n"
        "\tbreak\t7\n"
        f"{label}:\n"
        "\t.set\treorder\n"
        f"\t{'mfhi' if op == 'remu' else 'mflo'}\t{rd}\n"
    )
