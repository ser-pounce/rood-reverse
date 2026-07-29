# Matching decomp notes

Durable technique for this project, as opposed to `SESSION_HANDOFF.md`, which is
rewritten every session. Add to this file whenever a target's shape teaches you
something that will recur.

The compiler is gcc 2.7.2 or 2.8.1 through `maspsx`; see
`config/BATTLE/BATTLE.PRG/Makefile` for which unit gets which. All of the below
was observed against 2.7.2-cdk and 2.8.1-psx and holds for both unless noted.

## The loop

```sh
python3 tools/dev/dcmp.py src/BATTLE/BATTLE.PRG/5BF94.c func_800D2518
python3 tools/dev/dcmp.py src/BATTLE/BATTLE.PRG/5BF94.c   # everything pending
```

Rebuilds one object and diffs by instruction **encoding**, not disassembly text.
objdump prints `move` and decimal where spimdisasm prints `addu` and hex, so a
textual diff is entirely false positives. Fields a relocation fills in (`%hi` /
`%lo` immediates, `jal` targets) are masked on *both* sides whenever *either*
side relocates them, because a `--defsym` symbol such as `_camera` is a
relocation in our object and a baked-in `0x1F800064` in the disassembly.

Splat clears a function's target `.s` only on a full `make`, and building one
object does not rerun it, so the loop is *edit C, run dcmp, repeat*, then one
full `make` as the arbiter. A full `make` is what proves a unit; dcmp only
proves a function.

Two diagnostics from which files fail a full build:

- Every MENU overlay fails as well as BATTLE.PRG: the new code is the wrong
  **length**. They link against BATTLE.PRG.
- Only BATTLE.PRG fails: the length is right and the content is wrong.

## Is it even compiler output?

Some of this game is hand-written assembly, and no C will ever match it. Two
sessions have been lost to functions that were never compiled. Check first.

**The decisive test: an 8-byte stack frame plus a call means hand-written.** gcc
always lays down the 0x10 outgoing-argument area, so the smallest frame any
compiled function in this project uses when it calls anything is 0x18. Across
every function in `build/src/**/matchings/`, eight use an 8-byte frame and not
one of them calls anything.

Other tells, roughly most to least conclusive:

- callee-saved registers spilled to absolute addresses rather than the stack
  (`sw $s0, 0x1F800204($at)`)
- `jr` through a register that is not `$ra`
- a function that falls through into the next instead of returning, or a `jr $ra`
  with no delay slot of its own
- a branch into the middle of another function
- any use of `$at`
- a `nop` where no load or branch delay requires one
- self-modifying code, e.g. storing halfwords into another function's body

The test cannot decide leaf functions, which have no frame either way.

**Known hand-written regions.** All of BATTLE `2EA3C` (31 functions: zero stack
frames, scratchpad register spills, 205 GTE ops, 12 register jumps). Most of
`573B8.c`, which already holds several `__asm__` blocks and is the style to
follow. Parts of `6E644` (110 GTE ops among 217 functions, but ~128 have real
frames, so most of it is genuine C).

When a function is hand-written, transcribe it into an `__asm__` block in the
style of `573B8.c`. That removes the
`INCLUDE_ASM` and puts the code in the source tree, which is the correct end
state; it is not decomp and should not be described as such.

## Shape rules

Each of these was a real diff that cost time. When instruction *counts* match and
only registers or ordering differ, the source shape is wrong, not the allocator.

1. **`&&` between two bit tests on the same value gets folded.**
   `(x & 1) == 0 && (x & 0xF00) == 0` becomes one `andi 0xF01`. A target that
   keeps two `andi`s was written as separate `if (...) continue;` statements.
   `fold_truthop` only fires across `&&` and `||`.

2. **Where a `u_char` return truncation lands tells you the return shape.** An
   `andi 0xFF` after the merge point needs an intermediate `int` local. One
   inside a `j` delay slot on a single arm needs the inverted condition,
   `if (c == 0) return 0; return expr;`. Written the obvious way round,
   `if (c != 0) return expr; return 0;`, gcc fills the branch delay slot with the
   zero and drops the `j` entirely.

3. **`addu dst, base, index` versus `addu dst, index, base` is a real signal.**
   Pointer arithmetic (`(T*)p + i`) canonicalises to base-first and cannot be
   flipped by writing `i + (T*)p`. Index-first means the original did integer
   arithmetic: `(T*)(i * sizeof *e + (u_int)p)`.

4. **A constant kept live in a register across basic blocks was a local.** A
   constant rematerialised at each use is an inline literal. Assigning it to a
   local fixes that, and where you *declare* that local relative to the other
   locals sets which register it gets.

5. **A tight `lw lw sw sw` group whose neighbours keep their `nop`s is a struct
   assignment.** gcc expands one into a single block move that the scheduler can
   neither break apart nor hoist across, which is why the loads either side stay
   unscheduled. Individual field copies get scheduled and batched instead.

6. **`x <<= n; x >>= n;` as two statements is not `(x << n) >> n`.** The split
   form changes which register the value lands in. When a whole-function register
   permutation will not budge, look for a compound expression the original wrote
   as separate statements. Check how the rest of the same file spells it.

7. **Word-at-a-time reads of a byte-typed struct are normal.** Several structs
   here declare `u_char` bitfields where the original declared a 32-bit unit, so
   the target does `lw 0x8; andi 0x200000` where the current struct would give
   `lbu 0xA; andi 0x20`. Use `((u_int*)p)[2] & 0x200000` rather than changing the
   struct, which would break every function that already matches against the
   byte-typed fields.

8. **`volatile` is occasionally the honest answer.** A field re-read on every use
   with no intervening store that could justify it was `volatile` in the
   original. `3A1A0.h` carries two of these. Prefer the field-level qualifier to
   a cast at the use site, but only when the field has no other readers, since it
   costs those readers their CSE.

## Struct archaeology

Field names in this tree encode their intended offset, and several have drifted:
`D_800F4538_t.unk1868` actually sat at 0x1878 because the preceding
`D_800F4538_unk1864` is 0x14 bytes. Before concluding a struct has a hole, dump
the real layout:

```sh
gcc -m32 -g3 -w -fno-builtin -funsigned-char \
    -I include/psx -I src/include -I ./ -I src/BATTLE/BATTLE.PRG \
    -D "__attribute__(x)=" -o /tmp/layout /tmp/layout.c
gdb -batch -ex 'ptype /o D_800F4538_t' /tmp/layout
```

where `/tmp/layout.c` includes the headers and declares one variable of each type
you care about. `ptype /o` prints byte offsets and sizes, including bitfield bit
positions. Note that `-D "__attribute__(x)="` breaks `offsetof`, so use
`((unsigned)(unsigned long)&(((T*)0)->f))` if you want offsets in C instead.

## Converting an asm segment into a C unit

Change `[0xNNNN, asm]` to `[0xNNNN, c]` in the overlay's `splat.yaml`, then
generate the unit as one `INCLUDE_ASM` per `^glabel` in
`build/src/…/<unit>.s`, in address order. Two things will bite:

- **Do not name the segment's rodata subsegment after the C unit.** Doing that
  (`[0x1354, .rodata, 6E644]`) switches on splat's rodata migration, which emits
  only the entries a function in the unit references by name and silently drops
  the rest. For `6E644` that lost 188 of 280 bytes and shifted the whole overlay.
  Keeping it standalone under a different name (`6E644_rodata`) preserves the
  layout exactly.
- **`make clean` after changing a segment's type.** Objects and `nonmatchings/`
  from the previous type survive and produce duplicate-symbol link errors that
  have nothing to do with the real problem.

- **A matched function can still own labels used by neighboring assembly.**
   `func_800D826C` matched by itself, but converting it to C removed
   `.L800D8278`, which `func_800D820C` and `func_800D836C` branch into. `dcmp.py`
   cannot detect that cross-function dependency; the full link reports a
   truncated `R_MIPS_PC16` relocation. Keep the function in assembly until the
   whole shared-entry cluster can be transcribed or decompiled together. Also
   check for one-instruction entry points between generated files:
   `func_800E6EAC` is a bare `jr $ra` whose delay slot is the first instruction
   of `func_800E6EB0`, so the initial asm-to-C conversion omitted it entirely.

## Other things that waste time

- **Single-object builds cannot revert a function to `INCLUDE_ASM`**, because
  splat has to regenerate the `nonmatchings/*.s` set first.
- **`make format` reformats two files nobody touched**,
  `src/SLUS_010.40/main.c` and `src/MENU/MENU7.PRG/260.c`, which are committed in
  a shape the current clang-format disagrees with. Revert those two with
  `git checkout --` afterwards.
- **A stubborn one-register diff is evidence of the wrong shape, not a job for
  the permuter.** `func_800688D4` survived 128,000 permuter iterations without
  reaching zero; it is probably hand-written.
