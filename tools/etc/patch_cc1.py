#!/usr/bin/env python3
# SPDX-License-Identifier: MIT
# From ReGame-Labs/dcb_decomp tools/patch_cc1.py, commit 6c9caf124450cafa1b5f402d03d82b90bb02d16e.
# Copyright (c) 2026 ReGame Labs. See LICENSES/dcb_decomp-MIT.txt.
# Unmodified apart from this header; used as `patch_cc1.py IN OUT`.
"""Binary-patch bin/gcc-2.7.2-psx/cc1 into the cc1 the PsyQ libraries were built with.

usage: tools/patch_cc1.py [in out]   (default: bin/gcc-2.7.2-psx/cc1 ->
                                       build/tools/gcc-2.7.2-psx/cc1)

Differences between our GCC 2.7.2 build and the compiler of the PsyQ 4.7
libraries (which also need -mhard-float, see FLOAT_ABI in the Makefile).
1 and 2/18 show up together: a short loaded once and used both sign-extended
and raw (`lh` + `lhu` of the same field in the ROM), and a bogus
`addiu $sp,-8/-16` frame (`.frame ... vars=8/16`) with no stack accesses.

1. try_combine: when three insns (load HI, sll 16, sra 16) combine into a
   sign-extending load while the HImode load is still needed, ours rewrites the
   second load as a SUBREG of the extended value; the ROM keeps both loads
   (the "two independent SETs" split). The SIGN_EXTEND special case is
   skipped here.
2. (Now part of 18.) regclass: the combined-away temporaries keep stale
   reference counts; with no costs their preferred class was ST_REGS (FP
   condition codes, no SImode), global.c couldn't place them and reload gave
   them stack slots.
3. (Now part of 16.) reorg's mark_target_live_regs stopped its forward scan
   at a conditional jump before looking at the jump's own delay slot, so a
   register set there (`beqz v1,L; move v0,zero`) still counted as live
   (libpad func_8002184C).
4. reorg's fill_simple_delay_slots never fills the slot of an unconditional
   jump from its target (2.7.2 only fills it from the insns before the jump);
   the ROM does, like GCC 2.8: `j L; <first insn at L>` with the jump
   redirected past it (_SsSetControlChange's four `j default; sra a0,a0,16`,
   the early `move v0,zero` of SsUtKeyOff, _SsVmInit's branch layout).
5. find_best_addr: a `reg + const_int` address (`4(p)` with p holding &sym)
   stays as it is instead of being folded into the constant `sym+4`.
6. alter_reg: a pseudo spilled to the stack gets a slot aligned to its own
   mode (4 bytes for SImode) instead of BIGGEST_ALIGNMENT (8), like GCC 2.8's
   `inherent_size == total_size ? 0 : -1`. Two spilled pseudos then sit at
   0x5C/0x60 instead of 0x60/0x68 (libmcrd MemCardGetDirentry's frame); a
   HImode one in a 4-byte slot keeps the 8-byte alignment (_SsVmKeyOn).
7. mark_target_live_regs: its forward scan follows a simple jump to the
   label itself (GCC 2.8), so the label kills the registers a REG_DEAD note
   left pending before the jump. A branch can then take an insn that sets
   one of its own inputs from its target (prnt: `bne v1,v0,L; sltiu v0,..`).
8. expand_increment: a post-increment whose value is used, of a MEM that the
   add insn can't take (`if (count++ > N)` on a global), goes through
   GCC 2.8's queue path: the address goes to a register (`la v0,sym`), the old
   value is loaded into a temp, and the add and the store are queued
   (`lw v1,0(v0); move a0,v1; addiu v1,v1,1; ... sw v1,0(v0)`, trapIntr).
9. cse's COST macro uses GCC 2.8's notreg_cost: a lowpart SUBREG of a wider
   integer register costs what the register does, not rtx_cost * 2, so cse
   keeps `(subreg:HI (reg:SI n) 0)` over an equal HImode pseudo and a short
   field is loaded twice, `lh` for a compare and `lhu` for its raw value
   (libgpu func_80065C54/func_80065CEC).
10. local-alloc ties the register holding a called function pointer to the
   call's result register ($v0), as with GCC 2.8's mips.md, whose call
   patterns take the address as a register operand (libgpu func_800649E8).
11. combine re-enables volatile MEMs in the recognizer when it ends, as
   GCC 2.8 does, so sched1 can recognize and schedule insns with volatile
   MEMs (trapIntr's loop exit test).
12. -fforce-mem no longer loads a MEM into a register before extending it
   (GCC 2.8), so `(int)s.byte` is one `zero_extend (mem)` that cse doesn't
   replace with a value just stored there (SetGraphDebug reloads D.level).
13. global-alloc's prune_preferences checks conflicts in both directions
   (GCC 2.8), so a pseudo doesn't take a register that a conflicting
   lower-priority pseudo prefers (_spu_note2pitch).
14. jump_optimize turns `if (...) { x = a; goto l; } x = b;` into
   `x = a; if (...) goto l; x = b;` (GCC 2.8), so the ROM sets x before
   the test (SpuSetNoiseClock's `bltz v0,END; li a1,0`).
15. jump_optimize's store-flag conversion of `x = a; if (...) x = b;` with A
   or B zero needs, with cheap branches, a power of two as the other value
   (GCC 2.8), so SpuSetCommonAttr's `x < 0 ? 0 : x` clamps stay branches
   instead of `nor/sra/and`.
16. mark_target_live_regs follows both paths of a conditional jump, as
   GCC 2.8's find_dead_or_set_registers: a register set before any use on
   both paths is dead (prnt's `beqz v0,L; sll v0,s0,2`).
17. (Dropped.) A conditional jump that starts the opposite thread is
   followed like any other, as GCC 2.8's find_dead_or_set_registers does:
   _SpuSetAnyVoice's `beqz v0,L; li v0,8` takes the `li` from L because v0
   is set on both paths of the `beqz t1` that begins the fallthrough. The
   patch stopped the scan there for a __fixsfsi draft that doesn't match
   either way.

18. try_combine zeroes the reference counts of an I2 destination that the
   new I2 pattern doesn't mention (GCC 2.8); only registers stale in 2.8 too
   get a (bogus, unused) stack slot (_SsVmSetSeqVol's frame), and of those
   only the ones referenced more than twice (see the code).

The whole build matches with the patched cc1 (none of the functions that
already matched changes).
"""
import os
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
# the prebuilt compilers (tools/dl_deps.sh), or the Docker image's (BIN_DIR)
STOCK = os.path.join(ROOT, os.environ.get("BIN_DIR", "bin"), "gcc-2.7.2-psx", "cc1")
PATCHED = f"{ROOT}/build/tools/gcc-2.7.2-psx/cc1"


def patch(src, dst):
    d = bytearray(open(src, "rb").read())
    phoff, = struct.unpack_from("<I", d, 0x1C)
    phentsize, phnum = struct.unpack_from("<HH", d, 0x2A)
    segs, phidx = [], []
    for i in range(phnum):
        t, off, va, _, fsz = struct.unpack_from("<5I", d, phoff + i * phentsize)
        if t == 1:
            segs.append((va, off, fsz))
            phidx.append(i)

    def fo(va):
        for v, o, s in segs:
            if v <= va < v + s:
                return va - v + o
        raise ValueError(hex(va))

    def put(va, old, new):
        o = fo(va)
        if d[o:o + len(old)] != bytes(old):
            sys.exit(f"patch_cc1: unexpected bytes at {va:#x}: {d[o:o + len(old)].hex()}")
        d[o:o + len(new)] = new

    # 1. try_combine+9186: `jne` after `cmp $SIGN_EXTEND` -> `jmp` to the same target
    va = 0x08128E9F
    o = fo(va)
    rel = int.from_bytes(d[o + 2:o + 6], "little", signed=True)
    put(va, b"\x0f\x85" + d[o + 2:o + 6],
        b"\xe9" + (rel + 1).to_bytes(4, "little", signed=True) + b"\x90")

    # Patch 4 adds code after the end of the text segment (the rest of
    # its last page is zero padding in the file) and grow the segment over it.
    ti = next(i for i, (v, o, s) in enumerate(segs) if v <= 0x08172000 < v + s)
    tva, toff, tsz = segs[ti]
    end = [tva + tsz]

    def append(build):
        """Place the code build(cave, jump, code) produces after the segment."""
        cave = (end[0] + 15) & ~15
        code = bytearray()

        def jump(opcode, target):  # opcode + rel32 to target
            code.extend(opcode)
            code.extend((target - (cave + len(code) + 4)).to_bytes(4, "little", signed=True))

        build(code, jump)
        o = cave - tva + toff
        if d[o:o + len(code)] != bytes(len(code)):
            sys.exit("patch_cc1: no room after the text segment")
        d[o:o + len(code)] = code
        end[0] = cave + len(code)
        for field in (16, 20):  # p_filesz, p_memsz
            struct.pack_into("<I", d, phoff + phidx[ti] * phentsize + field, end[0] - tva)
        return cave

    # 4. fill_simple_delay_slots+2819 (`if (delay_list)` before
    # emit_delay_sequence): first, as GCC 2.8 does, fill an empty slot of an
    # unconditional jump from its target:
    #   if (GET_CODE (insn) == JUMP_INSN && slots_filled != slots_to_fill
    #       && simplejump_p (insn))
    #     delay_list = fill_slots_from_thread (insn, const_true_rtx,
    #         next_active_insn (JUMP_LABEL (insn)), 0, 1, 1,
    #         own_thread_p (JUMP_LABEL (insn), JUMP_LABEL (insn), 0), 0,
    #         slots_to_fill, &slots_filled);
    # Locals: insn -0x84, delay_list -0x78, slots_filled -0x80, slots_to_fill -0x8c.
    def fill_jump_from_target(code, jump):
        skip = []

        def jcc(opcode):  # forward branch to `done`, fixed up below
            code.extend(opcode)
            skip.append(len(code))
            code.extend(bytes(4))

        code += b"\x8b\x85\x7c\xff\xff\xff"        # mov -0x84(%ebp),%eax  (insn)
        code += b"\x66\x83\x38\x1c"                # cmpw $JUMP_INSN,(%eax)
        jcc(b"\x0f\x85")
        code += b"\x8b\x45\x80"                    # mov -0x80(%ebp),%eax
        code += b"\x3b\x85\x74\xff\xff\xff"        # cmp -0x8c(%ebp),%eax
        jcc(b"\x0f\x84")
        code += b"\xff\xb5\x7c\xff\xff\xff"        # push insn
        jump(b"\xe8", 0x080F6486)                  # call simplejump_p
        code += b"\x83\xc4\x04\x85\xc0"            # add $4,%esp; test %eax,%eax
        jcc(b"\x0f\x84")
        code += b"\x8b\x85\x7c\xff\xff\xff"        # mov insn,%eax
        code += b"\x8b\x40\x20"                    # mov 0x20(%eax),%eax   (JUMP_LABEL)
        code += b"\x6a\x00\x50\x50"                # push 0; push label; push label
        jump(b"\xe8", 0x08170F0F)                  # call own_thread_p
        code += b"\x83\xc4\x0c\x50"                # add $12,%esp; push own
        code += b"\x8b\x85\x7c\xff\xff\xff"        # mov insn,%eax
        code += b"\xff\x70\x20"                    # push JUMP_LABEL
        jump(b"\xe8", 0x080DBF36)                  # call next_active_insn
        code += b"\x83\xc4\x04\x59"                # add $4,%esp; pop %ecx (own)
        code += b"\x8d\x55\x80\x52"                # lea -0x80(%ebp),%edx; push (&slots_filled)
        code += b"\xff\xb5\x74\xff\xff\xff"        # push slots_to_fill
        code += b"\x6a\x00\x51"                    # push 0 (own_opposite); push own
        code += b"\x6a\x01\x6a\x01\x6a\x00\x50"    # push 1; push 1; push 0; push thread
        code += b"\xff\x35" + (0x082D3980).to_bytes(4, "little")  # push const_true_rtx
        code += b"\xff\xb5\x7c\xff\xff\xff"        # push insn
        jump(b"\xe8", 0x08173610)                  # call fill_slots_from_thread
        code += b"\x83\xc4\x28\x89\x45\x88"        # add $40,%esp; mov %eax,delay_list
        for f in skip:
            code[f:f + 4] = (len(code) - (f + 4)).to_bytes(4, "little", signed=True)
        code += b"\x83\x7d\x88\x00"                # cmpl $0,delay_list  (the replaced insns)
        jump(b"\x0f\x84", 0x08173331)             # je
        jump(b"\xe9", 0x081732EE)                  # jmp back

    cave = append(fill_jump_from_target)
    put(0x081732E8, bytes.fromhex("837d88007443"),
        b"\xe9" + (cave - (0x081732E8 + 5)).to_bytes(4, "little", signed=True) + b"\x90")

    # 5. find_best_addr: don't fold a `reg + const_int` address (e.g. `4(p)`
    #    with p a pseudo holding &sym) into a constant `sym+4`. GCC 2.8 only
    #    keeps a folded address when it is cheaper, and a small reg+offset is
    #    already the cheapest; the PsyQ cc1 behaved like that (libmcrd/libgs
    #    `addiu v1,s0,-4; sw v0,4(v1)`). The test `code == REG` before the
    #    fold jumps to a cave (the body of `trace`, only used by -mdebugb)
    #    that also skips PLUS with a CONST_INT second operand.
    cave, back_fold, back_skip = 0x081C96DA, 0x080FD1F3, 0x080FD221
    code = bytearray(
        b"\x66\x83\xf8\x34"      # cmp ax, REG
        b"\x74\x12"                # je skip
        b"\x66\x83\xf8\x41"      # cmp ax, PLUS
        b"\x75\x11"                # jne fold
        b"\x8b\x4d\xac"           # mov ecx, [ebp-0x54]   (addr)
        b"\x8b\x49\x08"           # mov ecx, [ecx+8]      (XEXP (addr, 1))
        b"\x66\x83\x39\x2f"      # cmp word [ecx], CONST_INT
        b"\x75\x05"                # jne fold
    )
    code += b"\xe9" + (back_skip - (cave + len(code) + 5)).to_bytes(4, "little", signed=True)
    code += b"\xe9" + (back_fold - (cave + len(code) + 5)).to_bytes(4, "little", signed=True)
    o = fo(cave)
    if d[o:o + 4] != b"\xf3\x0f\x1e\xfb":
        sys.exit("patch_cc1: unexpected bytes at trace")
    d[o:o + len(code)] = code
    site = 0x080FD1ED
    put(site, b"\x66\x83\xf8\x34\x74\x2e",
        b"\xe9" + (cave - (site + 5)).to_bytes(4, "little", signed=True) + b"\x90")


    # 7. mark_target_live_regs+3822: the forward scan follows a simple jump
    #    to `JUMP_LABEL` itself, as GCC 2.8's find_dead_or_set_registers does,
    #    not to `next_active_insn (JUMP_LABEL)`: the label then kills the
    #    registers left pending dead (REG_DEAD) before the jump. Drop the call
    #    and keep JUMP_LABEL in %eax.
    o = fo(0x0817247B)
    put(0x0817247B, b"\x83\xec\x0c\x50\xe8" + d[o + 5:o + 9] + b"\x83\xc4\x10", b"\x90" * 12)

    # 8. expand_increment+1111 (the post-increment fallback, reached when the
    #    queued add can't take OP0): as GCC 2.8, for a MEM with an add insn
    #      addr = general_operand (XEXP (op0, 0), mode)
    #             ? force_reg (Pmode, XEXP (op0, 0)) : copy_to_reg (XEXP (op0, 0));
    #      op0 = change_address (op0, VOIDmode, addr);
    #      temp = force_reg (GET_MODE (op0), op0);
    #      if (! insn_operand_predicate[icode][2] (op1, mode))
    #        op1 = force_reg (mode, op1);
    #      enqueue_insn (op0, gen_move_insn (op0, temp));
    #      return enqueue_insn (temp, GEN_FCN (icode) (temp, temp, op1));
    #    Locals: op0 %edi, post 0xc(%ebp), mode -0x24, icode -0x1c, op1 -0x3c.
    #    The code goes over bc_expand_expr (only used with -fbytecode), since
    #    the page after the text segment is full.
    def increment_mem(code, jump):
        def short(opcode):  # 8-bit forward branch, fixed up by `here`
            code.extend(opcode + b"\x00")
            return len(code)

        def here(at):
            code[at - 1] = len(code) - at

        code += b"\x83\x7d\x0c\x00"                # cmpl $0,post  (the replaced insns)
        jump(b"\x0f\x84", 0x080AE8EE)             # je (preincrement)
        code += b"\x81\x7d\xe4\x51\x01\x00\x00"    # cmpl $CODE_FOR_nothing,icode
        jump(b"\x0f\x84", 0x080AE8DB)             # je back
        code += b"\x66\x83\x3f\x39"                # cmpw $MEM,(%edi)
        jump(b"\x0f\x85", 0x080AE8DB)             # jne back
        code += b"\xff\x75\xdc\xff\x77\x04"        # push mode; push XEXP (op0, 0)
        jump(b"\xe8", 0x08184AD9)                  # call general_operand
        code += b"\x83\xc4\x08\x8b\x57\x04\x85\xc0"  # add $8,%esp; mov 4(%edi),%edx; test
        copy = short(b"\x74")                      # je copy
        code += b"\x52\x6a\x04"                    # push addr; push $SImode
        jump(b"\xe8", 0x080C276E)                  # call force_reg
        code += b"\x83\xc4\x08"
        have = short(b"\xeb")                      # jmp have
        here(copy)
        code += b"\x52"                            # push addr
        jump(b"\xe8", 0x080C2639)                  # call copy_to_reg
        code += b"\x83\xc4\x04"
        here(have)
        code += b"\x50\x6a\x00\x57"                # push addr; push $VOIDmode; push op0
        jump(b"\xe8", 0x080DB2AB)                  # call change_address
        code += b"\x83\xc4\x0c\x89\xc7"            # add $12,%esp; mov %eax,%edi
        code += b"\x57\x0f\xb6\x47\x02\x50"        # push op0; push GET_MODE (op0)
        jump(b"\xe8", 0x080C276E)                  # call force_reg
        code += b"\x83\xc4\x08\x89\xc6"            # add $8,%esp; mov %eax,%esi  (temp)
        code += b"\x8b\x55\xe4\x8d\x04\x92"        # mov icode,%edx; lea (%edx,%edx,4),%eax
        code += b"\x8b\x04\xc5" + (0x082B7388).to_bytes(4, "little")  # insn_operand_predicate[icode][2]
        code += b"\xff\x75\xdc\xff\x75\xc4\xff\xd0"  # push mode; push op1; call *%eax
        code += b"\x83\xc4\x08\x85\xc0"            # add $8,%esp; test
        ok = short(b"\x75")                        # jne ok
        code += b"\xff\x75\xc4\xff\x75\xdc"        # push op1; push mode
        jump(b"\xe8", 0x080C276E)                  # call force_reg
        code += b"\x83\xc4\x08\x89\x45\xc4"        # add $8,%esp; mov %eax,op1
        here(ok)
        code += b"\x56\x57"                        # push temp; push op0
        jump(b"\xe8", 0x080C9ADD)                  # call gen_move_insn
        code += b"\x83\xc4\x08\x50\x57"            # add $8,%esp; push %eax; push op0
        jump(b"\xe8", 0x0809ECB6)                  # call enqueue_insn
        code += b"\x83\xc4\x08\x8b\x55\xe4"        # add $8,%esp; mov icode,%edx
        code += b"\x8b\x04\x95" + (0x082B6E20).to_bytes(4, "little")  # insn_gen_function[icode]
        code += b"\xff\x75\xc4\x56\x56\xff\xd0"    # push op1; push temp; push temp; call *%eax
        code += b"\x83\xc4\x0c\x50\x56"            # add $12,%esp; push %eax; push temp
        jump(b"\xe8", 0x0809ECB6)                  # call enqueue_insn
        code += b"\x83\xc4\x08"                    # add $8,%esp
        jump(b"\xe9", 0x080AE93F)                  # jmp to the epilogue (returns %eax)

    cave = 0x080AAEA3
    code = bytearray()

    def jump(opcode, target):
        code.extend(opcode)
        code.extend((target - (cave + len(code) + 4)).to_bytes(4, "little", signed=True))

    increment_mem(code, jump)
    if len(code) > 0x9B5:
        sys.exit("patch_cc1: increment_mem doesn't fit")
    put(cave, b"\xf3\x0f\x1e\xfb", code)
    put(0x080AE8D5, bytes.fromhex("837d0c007413"),
        b"\xe9" + (cave - (0x080AE8D5 + 5)).to_bytes(4, "little", signed=True) + b"\x90")

    # 9. cse's COST: GCC 2.8's notreg_cost. A lowpart SUBREG of a wider
    #    integer REG costs what the REG does (0 cheap, 1 pseudo, 2 hard)
    #    instead of rtx_cost (x, SET) * 2 = 4, so cse_insn takes it over an
    #    equivalent pseudo, e.g. `(subreg:HI (reg:SI 73) 0)` for a short
    #    that was loaded sign-extended, and keeps both loads of the field
    #    (libgpu func_80065C54: `lh` for the compare, `lhu` for the value).
    #    New function after increment_mem; the rtx_cost calls of the COST
    #    macro in cse.c go to it and their `* 2` becomes a plain move.
    def notreg_cost(code, jump):
        fix = {}

        def br(opcode, label):  # forward branch to a label below (rel8, or rel32 for 0f 8x)
            code.extend(opcode + bytes(1 if len(opcode) == 1 else 4))
            fix.setdefault(label, []).append((len(code), len(opcode)))

        def label(name):
            for at, n in fix.pop(name, []):
                if n == 1:
                    assert len(code) - at < 0x80
                    code[at - 1] = len(code) - at
                else:
                    code[at - 4:at] = (len(code) - at).to_bytes(4, "little")

        code += b"\x53"                            # push %ebx
        code += b"\x8b\x44\x24\x08"                # mov 8(%esp),%eax      (x)
        code += b"\x66\x83\x38\x36"                # cmpw $SUBREG,(%eax)
        br(b"\x0f\x85", "other")
        code += b"\x8b\x48\x04"                    # mov 4(%eax),%ecx      (SUBREG_REG)
        code += b"\x66\x83\x39\x34"                # cmpw $REG,(%ecx)
        br(b"\x0f\x85", "other")
        code += b"\x0f\xb6\x50\x02"                # movzbl 2(%eax),%edx   (GET_MODE (x))
        code += b"\x0f\xb6\x59\x02"                # movzbl 2(%ecx),%ebx   (its REG's mode)
        mode_class, mode_size = (0x082BCA80).to_bytes(4, "little"), (0x082BCB00).to_bytes(4, "little")
        code += b"\x83\x3c\x95" + mode_class + b"\x01"  # cmpl $MODE_INT,mode_class(,%edx,4)
        br(b"\x0f\x85", "other")
        code += b"\x83\x3c\x9d" + mode_class + b"\x01"  # cmpl $MODE_INT,mode_class(,%ebx,4)
        br(b"\x0f\x85", "other")
        code += b"\x8b\x14\x95" + mode_size        # mov mode_size(,%edx,4),%edx
        code += b"\x3b\x14\x9d" + mode_size        # cmp mode_size(,%ebx,4),%edx
        br(b"\x0f\x8d", "other")                   # jge (not narrower)
        code += b"\x50"                            # push x
        jump(b"\xe8", 0x080DAA26)                  # call subreg_lowpart_p
        code += b"\x83\xc4\x04\x85\xc0"            # add $4,%esp; test %eax,%eax
        br(b"\x0f\x84", "other")
        # TRULY_NOOP_TRUNCATION is 1 without -mips3. CHEAP_REG, as insert has it:
        code += b"\x8b\x44\x24\x08\x8b\x48\x04"    # mov x,%eax; mov 4(%eax),%ecx
        code += b"\x8b\x51\x04"                    # mov 4(%ecx),%edx      (REGNO)
        code += b"\xf6\x41\x03\x08"                # testb $8,3(%ecx)      (REG_USERVAR_P)
        br(b"\x74", "fixed")
        code += b"\x83\xfa\x43"                    # cmp $FIRST_PSEUDO_REGISTER-1,%edx
        br(b"\x7e", "zero")
        label("fixed")
        code += b"\x83\xfa\x1e"                    # cmp $FRAME_POINTER_REGNUM,%edx
        br(b"\x74", "zero")
        code += b"\x83\xfa\x1d"                    # cmp $STACK_POINTER_REGNUM,%edx
        br(b"\x74", "zero")
        code += b"\x85\xd2"                        # test %edx,%edx        (ARG_POINTER_REGNUM)
        br(b"\x74", "zero")
        code += b"\x83\xfa\x43"                    # cmp $FIRST_PSEUDO_REGISTER-1,%edx
        br(b"\x7e", "hard")
        code += b"\x83\xfa\x47"                    # cmp $LAST_VIRTUAL_REGISTER,%edx
        br(b"\x7e", "zero")
        code += b"\xb8\x01\x00\x00\x00\x5b\xc3"    # pseudo: return 1
        label("hard")
        code += b"\x80\xba" + (0x082D42E0).to_bytes(4, "little") + b"\x00"  # cmpb $0,fixed_regs(%edx)
        br(b"\x75", "class")
        code += b"\x80\xba" + (0x082D4220).to_bytes(4, "little") + b"\x00"  # cmpb $0,global_regs(%edx)
        br(b"\x74", "two")
        label("class")
        code += b"\x83\x3c\x95" + (0x082BE500).to_bytes(4, "little") + b"\x00"  # REGNO_REG_CLASS != NO_REGS
        br(b"\x75", "zero")
        label("two")
        code += b"\xb8\x02\x00\x00\x00\x5b\xc3"    # return 2
        label("zero")
        code += b"\x31\xc0\x5b\xc3"                # return 0
        label("other")
        code += b"\xff\x74\x24\x0c\xff\x74\x24\x0c"  # push outer_code; push x
        jump(b"\xe8", 0x080F8E96)                  # call rtx_cost
        code += b"\x83\xc4\x08\x01\xc0\x5b\xc3"    # add $8,%esp; add %eax,%eax; pop %ebx; ret
        assert not fix

    # Patches 9 and 10 go in the rest of bc_expand_expr, after increment_mem.
    free = [cave + len(code)]

    def in_bc(build):
        start = (free[0] + 15) & ~15
        code = bytearray()

        def jump(opcode, target):
            code.extend(opcode)
            code.extend((target - (start + len(code) + 4)).to_bytes(4, "little", signed=True))

        build(code, jump)
        if start + len(code) > 0x080AAEA3 + 0x9B5:
            sys.exit("patch_cc1: no room left in bc_expand_expr")
        d[fo(start):fo(start) + len(code)] = code
        free[0] = start + len(code)
        return start

    start = in_bc(notreg_cost)
    for site, double, move in (
            (0x080FA621, b"\x01\xc0", b"\x89\xc0"),          # insert
            (0x080FD7E7, b"\x01\xc0", b"\x89\xc0"),          # find_best_addr
            (0x080FD9DC, b"\x01\xc0", b"\x89\xc0"),
            (0x080FDB0B, b"\x01\xc0", b"\x89\xc0"),
            (0x08103FB1, b"\x01\xc0", b"\x89\xc0"),          # fold_rtx
            (0x081047B0, b"\x8d\x1c\x00", b"\x89\xc3\x90"),  # (lea (%eax,%eax),%ebx)
            (0x081048F4, b"\x01\xc0", b"\x89\xc0"),
            (0x08104C54, b"\x8d\x1c\x00", b"\x89\xc3\x90"),
            (0x08104DDD, b"\x01\xc0", b"\x89\xc0"),
            (0x08108B72, b"\x01\xc0", b"\x89\xc0"),          # cse_insn
            (0x08108CF4, b"\x01\xc0", b"\x89\xc0"),
            (0x08108E2C, b"\x01\xc0", b"\x89\xc0"),
            (0x08108FAE, b"\x01\xc0", b"\x89\xc0"),
            (0x08109759, b"\x8d\x1c\x00", b"\x89\xc3\x90"),
            (0x08109857, b"\x01\xc0", b"\x89\xc0"),
            (0x0810C394, b"\x8d\x34\x00", b"\x89\xc6\x90"),  # cse_set_around_loop
            (0x0810C4D9, b"\x01\xc0", b"\x89\xc0")):
        put(site, b"\xe8" + (0x080F8E96 - (site + 5)).to_bytes(4, "little", signed=True)
            + b"\x83\xc4\x10" + double,
            b"\xe8" + (start - (site + 5)).to_bytes(4, "little", signed=True)
            + b"\x83\xc4\x10" + move)

    # 10. block_alloc+1015, where an operand is tied to the output operand 0:
    #    GCC 2.8's mips.md matches the address of a call as
    #    `(call (mem (match_operand 1 "call_insn_operand" "ri")) ...)`, so the
    #    register holding a function pointer is an operand that dies in the
    #    call_value insn and local-alloc suggests $v0 (its output) for it; ours
    #    has the whole MEM as operand 1 ("m") and doesn't. For a CALL_INSN,
    #    take the register inside that MEM, as for a 'p' operand (libgpu
    #    func_800649E8: `lh v1,6(s0); lw v0,D_80076754; ... jalr v0`).
    #    Locals: r1 -0x60, insn -0x5c.
    def tie_call_address(code, jump):
        code += b"\x0f\xb6\x00\x3c\x70"            # movzbl (%eax),%eax; cmp $'p',%al (replaced)
        jump(b"\x0f\x84", 0x08147A53)             # je (the PLUS/MULT loop)
        code += b"\x8b\x45\xa4"                    # mov -0x5c(%ebp),%eax  (insn)
        code += b"\x66\x83\x38\x1d"                # cmpw $CALL_INSN,(%eax)
        jump(b"\x0f\x85", 0x08147A68)
        code += b"\x8b\x45\xa0"                    # mov -0x60(%ebp),%eax  (r1)
        code += b"\x66\x83\x38\x39"                # cmpw $MEM,(%eax)
        jump(b"\x0f\x85", 0x08147A68)
        code += b"\x8b\x40\x04\x89\x45\xa0"        # r1 = XEXP (r1, 0)
        jump(b"\xe9", 0x08147A68)

    start = in_bc(tie_call_address)
    put(0x08147A41, b"\x0f\xb6\x00\x3c\x70",
        b"\xe9" + (start - (0x08147A41 + 5)).to_bytes(4, "little", signed=True))

    # 11. combine_instructions+2332, at its end: call init_recog () first, as
    #    GCC 2.8's combine does ("Make recognizer allow volatile MEMs again").
    #    Ours leaves volatile_ok = 0 until regclass, so sched1 can't recognize
    #    insns with volatile MEMs and doesn't schedule them (trapIntr's loop
    #    exit test: `lw a0,D_80070AAC; lhu v1,enabled; lw v0,D_80070AB0; lhu;
    #    lhu` like the copy at the loop entry).
    site = 0x08125D77
    replaced = bytes.fromhex("c783c09c000000000000")  # movl $0,0x9cc0(%ebx)

    def recog_volatile(code, jump):
        jump(b"\xe8", 0x0818390F)                  # call init_recog
        code += replaced
        jump(b"\xe9", site + len(replaced))

    start = in_bc(recog_volatile)
    put(site, replaced, b"\xe9" + (start - (site + 5)).to_bytes(4, "little", signed=True) + b"\x90" * 5)
    # 12. -fforce-mem doesn't copy a MEM into a register before extending it,
    #    as in GCC 2.8: expand_expr's NOP_EXPR (+10954) drops its
    #    `if (flag_force_mem && GET_CODE (op0) == MEM) op0 = copy_to_reg (op0)`
    #    and emit_unop_insn (+93) skips force_not_mem for SIGN_EXTEND and
    #    ZERO_EXTEND ("extension from memory is often done specially on RISC
    #    machines"). `(int)s.byte` then expands to `(zero_extend:SI (mem:QI))`
    #    instead of a QImode load and an extension of that register, and cse
    #    doesn't replace it with a value stored before: SetGraphDebug reloads
    #    D.level for the printf.
    put(0x080A7DF5, b"\x74\x21", b"\xeb\x21")

    def extend_from_mem(code, jump):
        def short(opcode):
            code.extend(opcode + b"\x00")
            return len(code)

        code += b"\x83\x3d" + (0x082C1930).to_bytes(4, "little") + b"\x00"  # cmpl $0,flag_force_mem
        skip1 = short(b"\x74")
        code += b"\x8b\x45\x14\x83\xe8\x64\x83\xf8\x01"  # code - SIGN_EXTEND <= 1 (ZERO_EXTEND)?
        skip2 = short(b"\x76")
        code += b"\x83\xec\x0c\xff\x75\x10"        # sub $12,%esp; push op0
        jump(b"\xe8", 0x080C285E)                  # call force_not_mem
        code += b"\x83\xc4\x10\x89\x45\x10"        # add $16,%esp; mov %eax,op0
        for at in (skip1, skip2):
            code[at - 1] = len(code) - at
        jump(b"\xe9", 0x080C81B9)

    start = in_bc(extend_from_mem)
    put(0x080C819C, bytes.fromhex("c7c030192c08"),
        b"\xe9" + (start - (0x080C819C + 5)).to_bytes(4, "little", signed=True))

    # 13. prune_preferences+695: global.c records a conflict only in the row
    #    of the allocno that becomes live second, so `CONFLICTP (allocno, j)`
    #    misses half of them. GCC 2.8 tests both directions when it merges
    #    the preferences of conflicting lower-priority allocnos into
    #    regs_someone_prefers; with only one, a higher-priority pseudo takes
    #    a register a conflicting one prefers (libspu _spu_note2pitch: the
    #    n/12 quotient in a1 instead of v1). Locals: allocno -0x2c, j -0x30;
    #    %ebx is the function's GOT pointer.
    def conflict_both_ways(code, jump):
        code += b"\x8b\x83\x4c\xa4\x00\x00"        # mov allocno_order,%eax
        code += b"\x8b\x55\xd0\x8b\x04\x90"        # allocno_order[j]
        code += b"\x0f\xaf\x83\x5c\xa4\x00\x00"    # * allocno_row_words
        code += b"\x8b\x55\xd4\x89\xd1"            # mov allocno,%edx; mov %edx,%ecx
        code += b"\xc1\xfa\x05\x01\xd0"            # + allocno / INT_BITS
        code += b"\x8b\x93\x58\xa4\x00\x00"        # mov conflicts,%edx
        code += b"\x8b\x04\x82"                    # the word
        code += b"\x83\xe1\x1f\xd3\xe8\xa8\x01"    # >> allocno % INT_BITS; test $1
        jump(b"\x0f\x85", 0x0814C795)             # jne (merge)
        jump(b"\xe9", 0x0814C88F)                  # jmp (next j)

    start = in_bc(conflict_both_ways)
    o = fo(0x0814C78F)
    put(0x0814C78F, b"\x0f\x84" + d[o + 2:o + 6],
        b"\x0f\x84" + (start - (0x0814C78F + 6)).to_bytes(4, "little", signed=True))

    # 14. jump_optimize: GCC 2.8's
    #      if (...) { x = a; goto l; } x = b;  ->  x = a; if (...) goto l; x = b;
    #    (A a register or a constant, the test not involving X), placed like
    #    in 2.8 right after the `if (...) x = a; else x = b;` case
    #    (+5084, where that case gives up), including its quirk of skipping
    #    the rest of the loop body when CHANGED was already set. The ROM keeps
    #    such an X live across the rest of the test: SpuSetNoiseClock's
    #    `bltz v0,END; li a1,0` and func_8006C0CC's `li v0,1` before loading
    #    p->cmd into v1. The code goes over bc_expand_end_case (-fbytecode).
    #    Locals: insn %edi, next -0x170, changed -0x150, this_is_simplejump
    #    -0xac; temp -0xb0, temp1 -0x12c, temp2 -0x90, temp3 -0x128, temp4
    #    -0x160 as in 2.8, insert_after -0x118 and prev_label -0x15c (the
    #    dead p and temp5 of the case before).
    def goto_after_set(code, jump):
        fix = {}

        def br(opcode, name):  # rel32 forward branch to a label below
            code.extend(opcode + bytes(4))
            fix.setdefault(name, []).append(len(code))

        def label(name):
            for at in fix.pop(name, []):
                code[at - 4:at] = (len(code) - at).to_bytes(4, "little")

        def off(n):
            return n.to_bytes(4, "little", signed=True)

        def ld(n):  # mov n(%ebp),%eax
            code.extend(b"\x8b\x85" + off(n))

        def st(n):  # mov %eax,n(%ebp)
            code.extend(b"\x89\x85" + off(n))

        def var(n):  # push n(%ebp)
            return b"\xff\xb5" + off(n)

        EAX, ECX, EDI = b"\x50", b"\x51", b"\x57"

        def call(fn, *args):  # cdecl call keeping %esp 16-byte aligned
            pad = -4 * len(args) % 16
            if pad:
                code.extend(b"\x83\xec" + bytes([pad]))
            for a in reversed(args):
                code.extend(a)
            jump(b"\xe8", fn)
            code.extend(b"\x83\xc4" + bytes([pad + 4 * len(args)]))

        def test_eax(opcode, name):  # test %eax,%eax; j<cc> name
            code.extend(b"\x85\xc0")
            br(opcode, name)

        def code_is(value, opcode, name):  # GET_CODE (%eax) vs value
            code.extend(b"\x66\x83\x38" + bytes([value]))
            br(opcode, name)

        JE, JNE = b"\x0f\x84", b"\x0f\x85"
        next_active_insn, prev_active_insn = 0x080DBF36, 0x080DBFB1
        single_set, rtx_equal_p = 0x080D6DEC, 0x080D7AF6
        delete_insn, no_labels_between_p = 0x080F6DEA, 0x080D661F
        reg_referenced_between_p, reg_set_between_p = 0x080D695B, 0x080D69E9

        code.extend(b"\x83\xbd" + off(-0xAC) + b"\x00")  # this_is_simplejump
        br(JE, "fail")
        call(next_active_insn, EDI)                     # temp2
        test_eax(JE, "fail")
        st(-0x90)
        code_is(0x1B, JNE, "fail")                      # INSN
        call(single_set, var(-0x90))
        test_eax(JE, "fail")
        code.extend(b"\x8b\x40\x04")                    # temp1 = SET_DEST
        st(-0x12C)
        code_is(0x34, JNE, "fail")                      # REG
        call(prev_active_insn, EDI)                     # temp3
        test_eax(JE, "fail")
        st(-0x128)
        code_is(0x1B, JNE, "fail")
        call(single_set, var(-0x128))                   # temp4
        test_eax(JE, "fail")
        st(-0x160)
        code.extend(b"\x8b\x40\x04")
        call(rtx_equal_p, EAX, var(-0x12C))
        test_eax(JE, "fail")
        ld(-0x160)
        code.extend(b"\x8b\x40\x08")                    # SET_SRC (temp4)
        for c in (0x34, 0x36, 0x2F, 0x30, 0x32, 0x3A, 0x3B, 0x72):  # REG, SUBREG, CONSTANT_P
            code_is(c, JE, "simple")
        br(b"\xe9", "fail")
        label("simple")
        ld(-0x128)
        code.extend(b"\x8b\x40\x1c")                    # REG_NOTES (temp3)
        test_eax(JE, "notes")
        code.extend(b"\x0f\xb6\x48\x02\x83\xf9\x03")    # REG_NOTE_KIND == REG_EQUIV
        br(JE, "kind")
        code.extend(b"\x83\xf9\x05")                    # or REG_EQUAL
        br(JNE, "fail")
        label("kind")
        code.extend(b"\x83\x78\x08\x00")                # the only note
        br(JNE, "fail")
        code.extend(b"\x8b\x40\x04\x8b\x8d" + off(-0x160) + b"\x8b\x49\x08")
        call(rtx_equal_p, EAX, ECX)                     # of the value A
        test_eax(JE, "fail")
        label("notes")
        call(prev_active_insn, var(-0x128))             # temp
        test_eax(JE, "fail")
        st(-0xB0)
        call(0x080F64E4, var(-0xB0))                    # condjump_p
        test_eax(JE, "fail")
        call(0x080F6486, var(-0xB0))                    # simplejump_p
        test_eax(JNE, "fail")
        ld(-0xB0)
        code.extend(b"\x8b\x40\x20")                    # JUMP_LABEL (temp)
        call(0x080DBEE5, EAX)                           # prev_real_insn
        code.extend(b"\x39\xf8")                        # == insn
        br(JNE, "fail")
        call(no_labels_between_p, var(-0xB0), EDI)
        test_eax(JE, "fail")
        ld(-0xB0)
        code.extend(b"\x8b\x40\x20")
        st(-0x15C)                                      # prev_label
        call(0x080DBE5B, var(-0xB0))                    # prev_nonnote_insn
        st(-0x118)                                      # insert_after
        ld(-0x15C)
        code.extend(b"\x83\x40\x18\x01")                # ++LABEL_NUSES
        code.extend(b"\x83\xbd" + off(-0x118) + b"\x00")
        br(JE, "tried")
        call(no_labels_between_p, var(-0x118), var(-0xB0))
        test_eax(JE, "tried")
        call(reg_referenced_between_p, var(-0x12C), var(-0x118), var(-0x128))
        test_eax(JNE, "tried")
        ld(-0x90)
        code.extend(b"\x8b\x40\x0c")                    # NEXT_INSN (temp2)
        call(reg_referenced_between_p, var(-0x12C), var(-0x128), EAX)
        test_eax(JNE, "tried")
        call(reg_set_between_p, var(-0x12C), var(-0x118), var(-0xB0))
        test_eax(JNE, "tried")
        ld(-0x160)
        code.extend(b"\x8b\x40\x08")
        code_is(0x2F, JE, "src")                        # CONST_INT
        call(reg_set_between_p, EAX, var(-0x118), var(-0xB0))
        test_eax(JNE, "tried")
        label("src")
        code.extend(b"\x8b\x47\x20")                    # JUMP_LABEL (insn)
        call(0x080F71E1, var(-0xB0), EAX)               # invert_jump
        test_eax(JE, "tried")
        ld(-0x128)
        code.extend(b"\x8b\x40\x10")                    # PATTERN (temp3)
        call(0x080DCAB3, EAX, var(-0x118), var(-0x128))  # emit_insn_after_with_line_notes
        call(delete_insn, var(-0x128))
        call(delete_insn, EDI)
        ld(-0x90)
        st(-0x170)                                      # next = temp2
        code.extend(b"\xc7\x85" + off(-0x150) + b"\x01\x00\x00\x00")  # changed = 1
        label("tried")
        ld(-0x15C)
        test_eax(JE, "check")
        code.extend(b"\x83\x68\x18\x01")                # --LABEL_NUSES
        br(JNE, "check")
        call(delete_insn, EAX)
        label("check")
        code.extend(b"\x83\xbd" + off(-0x150) + b"\x00")  # if (changed) continue
        br(JE, "fail")
        jump(b"\xe9", 0x080F4FFC)
        label("fail")
        code.extend(b"\xc7\xc0" + (0x082D52AC).to_bytes(4, "little"))  # the replaced insn
        jump(b"\xe9", 0x080F38C6)
        assert not fix

    cave = 0x0809CEFF
    code = bytearray()

    def jump(opcode, target):
        code.extend(opcode)
        code.extend((target - (cave + len(code) + 4)).to_bytes(4, "little", signed=True))

    goto_after_set(code, jump)
    if len(code) > 1194:
        sys.exit("patch_cc1: goto_after_set doesn't fit")
    put(cave, b"\xf3\x0f\x1e\xfb", code)
    put(0x080F38C0, bytes.fromhex("c7c0ac522d08"),
        b"\xe9" + (cave - (0x080F38C0 + 5)).to_bytes(4, "little", signed=True) + b"\x90")

    # 15. jump_optimize's store-flag conversion of `x = a; if (...) x = b;`
    #    with A or B zero (+6104 and +6134): as in GCC 2.8, when branches are
    #    cheap (BRANCH_COST < 2, the R3000) it also needs
    #    exact_log2 (INTVAL (other value)) >= 0 (STORE_FLAG_VALUE is 1). That
    #    INTVAL is also taken of a REG (its regno), as 2.8 does. So `vol = 0;
    #    if (v >= 0) vol = v;` stays a branch instead of becoming
    #    `nor/sra/and` (SpuSetCommonAttr's clamps). Locals: temp2 -0x90,
    #    temp3 -0x128; mips_cpu R6000/R4000 (2, 3) make BRANCH_COST 2.
    def store_flag_guard(code, jump):
        def cheap_or_pow2(yes, no):  # BRANCH_COST >= 2 || exact_log2 (INTVAL (%eax)) >= 0
            code.extend(b"\x8b\x15" + (0x082D536C).to_bytes(4, "little"))  # mov mips_cpu,%edx
            code.extend(b"\x83\xfa\x03")
            jump(b"\x0f\x84", yes)
            code.extend(b"\x83\xfa\x02")
            jump(b"\x0f\x84", yes)
            code.extend(b"\x8b\x40\x04\x85\xc0")        # INTVAL; test
            jump(b"\x0f\x84", no)
            code.extend(b"\x89\xc2\xf7\xda\x21\xc2\x39\xc2")  # (x & -x) == x
            jump(b"\x0f\x84", yes)
            jump(b"\xe9", no)

        a = len(code)
        jump(b"\x0f\x85", 0x080F3CDA)               # temp2 != 0 (the replaced je)
        code.extend(b"\x8b\x85" + (-0x128).to_bytes(4, "little", signed=True))  # temp2 == 0: temp3
        cheap_or_pow2(0x080F3DC0, 0x080F3CDA)
        b = len(code)
        jump(b"\x0f\x85", 0x080F3D10)               # temp3 != 0 (the replaced jne)
        code.extend(b"\x8b\x85" + (-0x90).to_bytes(4, "little", signed=True))   # temp3 == 0: temp2
        cheap_or_pow2(0x080F3CEA, 0x080F3D10)
        return a, b

    start = (free[0] + 15) & ~15
    code = bytearray()

    def jump(opcode, target):
        code.extend(opcode)
        code.extend((target - (start + len(code) + 4)).to_bytes(4, "little", signed=True))

    a, b = store_flag_guard(code, jump)
    if start + len(code) > 0x080AAEA3 + 0x9B5:
        sys.exit("patch_cc1: no room left in bc_expand_expr")
    d[fo(start):fo(start) + len(code)] = code
    free[0] = start + len(code)
    for site, target in ((0x080F3CD4, start + a), (0x080F3CE8, start + b)):
        o = fo(site)
        put(site, d[o:o + 2] + d[o + 2:o + 6],
            b"\xe9" + (target - (site + 5)).to_bytes(4, "little", signed=True) + b"\x90")

    # 16. mark_target_live_regs follows both paths of a conditional jump, as
    #    GCC 2.8's find_dead_or_set_registers does: a register is dead after
    #    the jump if it is set before being used on the target path and on
    #    the fallthrough (following at most one conditional jump, jump_count
    #    += 4). find_dead_or_set_registers is new code over
    #    bc_expand_constructor (-fbytecode only); the scan of
    #    mark_target_live_regs hands a conditional jump over to it (replacing
    #    patch 3's stop there). prnt: `beqz v0,L; sll v0,s0,2`, v0 being set
    #    on both paths from L's `bgez s0`. (2.8 also kills spill registers at
    #    labels from before reload; 2.7.2 has no record of those.)
    def dead_or_set(code, jump, start):
        fix = {}

        def br(opcode, name):
            code.extend(opcode + bytes(4))
            fix.setdefault(name, []).append(len(code))

        def label(name):
            fix[name + ":"] = len(code)

        def resolve():
            for name, sites in fix.items():
                if name.endswith(":"):
                    continue
                for at in sites:
                    code[at - 4:at] = (fix[name + ":"] - at).to_bytes(4, "little", signed=True)

        def s8(n):
            return (n & 0xFF).to_bytes(1, "little")

        def call(fn, *args):  # args: bytes pushing one dword each; keeps 16-byte alignment
            pad = -4 * len(args) % 16
            if pad:
                code.extend(b"\x83\xec" + bytes([pad]))
            for a in reversed(args):
                code.extend(a)
            jump(b"\xe8", fn)
            code.extend(b"\x83\xc4" + bytes([pad + 4 * len(args)]))

        def arg(n):  # push n(%ebp)
            return b"\xff\x75" + s8(n)

        def addr(n):  # lea n(%ebp),%ecx; push %ecx
            return b"\x8d\x4d" + s8(n) + b"\x51"

        ESI, EDI, EAX = b"\x56", b"\x57", b"\x50"
        JE, JNE, JG, JMP = b"\x0f\x84", b"\x0f\x85", b"\x0f\x8f", b"\xe9"
        PENDING = 0x082C7A50
        mark_referenced, mark_set = 0x0816DDAC, 0x0816E3F3
        SET, NEEDED, TSET, TRES, FRES, THIS = -0x1C, -0x2C, -0x3C, -0x4C, -0x5C, -0x60

        def copy16(dst, src_reg_disp):  # copy a struct resources from (%eax) to dst(%ebp)
            for k in range(0, 16, 4):
                code.extend(b"\x8b\x48" + s8(k) + b"\x89\x4d" + s8(dst + k))  # mov k(%eax),%ecx; mov %ecx,dst+k(%ebp)

        # find_dead_or_set_registers (target, res, jump_count, &set, &needed)
        code.extend(b"\x55\x89\xe5\x53\x56\x57\x83\xec\x5c")  # prologue, 0x5c of locals
        code.extend(b"\x8b\x45\x14"); copy16(SET, 0)       # set = *arg
        code.extend(b"\x8b\x45\x18"); copy16(NEEDED, 0)    # needed = *arg
        code.extend(b"\x8b\x75\x08")                       # insn = target
        label("loop")
        code.extend(b"\x85\xf6"); br(JE, "done")
        code.extend(b"\x8b\x7e\x0c")                       # next = NEXT_INSN (insn)
        code.extend(b"\x89\x75" + s8(THIS))                # this_jump_insn = insn
        code.extend(b"\x0f\xb7\x06")                       # movzwl (%esi),%eax
        code.extend(b"\x83\xf8\x1f"); br(JNE, "notlabel")  # CODE_LABEL
        for k in range(4, 16, 4):                          # pending &= ~needed; res &= ~pending; pending = 0
            code.extend(b"\x8b\x45" + s8(NEEDED + k) + b"\xf7\xd0\x21\x05" + (PENDING + k - 4).to_bytes(4, "little"))
        code.extend(b"\x8b\x4d\x0c")
        for k in range(4, 16, 4):
            code.extend(b"\xa1" + (PENDING + k - 4).to_bytes(4, "little") + b"\xf7\xd0\x21\x41" + s8(k))
            code.extend(b"\xc7\x05" + (PENDING + k - 4).to_bytes(4, "little") + bytes(4))
        br(JMP, "cont")
        label("notlabel")
        code.extend(b"\x83\xf8\x1e"); br(JE, "cont")       # BARRIER
        code.extend(b"\x83\xf8\x20"); br(JE, "cont")       # NOTE
        code.extend(b"\x83\xf8\x1b"); br(JNE, "jumpp")     # INSN
        code.extend(b"\x8b\x46\x10\x0f\xb7\x08")           # PATTERN; its code in %ecx
        code.extend(b"\x83\xf9\x2a"); br(JNE, "notuse")    # USE
        code.extend(b"\x8b\x40\x04\x0f\xb7\x08")           # XEXP (pat, 0)
        code.extend(b"\x80\xb9" + (0x082BCC80).to_bytes(4, "little") + b"\x69")  # rtx_class == 'i'
        br(JNE, "cont")
        call(mark_set, EAX, arg(0x0C), b"\x6a\x00", b"\x6a\x01")
        br(JMP, "cont")
        label("notuse")
        code.extend(b"\x83\xf9\x2b"); br(JE, "cont")       # CLOBBER
        code.extend(b"\x83\xf9\x13"); br(JNE, "jumpp")     # SEQUENCE: find a JUMP_INSN in it
        code.extend(b"\x8b\x40\x04\x8b\x08\x31\xd2")       # rtvec, its length, i = 0
        label("seq")
        code.extend(b"\x39\xca"); br(b"\x0f\x83", "jumpp")  # i >= len
        code.extend(b"\x8b\x5c\x90\x04\x89\x5d" + s8(THIS))  # this_jump_insn = XVECEXP (pat, 0, i)
        code.extend(b"\x66\x83\x3b\x1c"); br(JE, "jumpp")
        code.extend(b"\x42"); br(JMP, "seq")
        label("jumpp")
        code.extend(b"\x8b\x45" + s8(THIS) + b"\x66\x83\x38\x1c"); br(JNE, "mark")  # JUMP_INSN
        code.extend(b"\x8b\x4d\x10\x8d\x51\x01\x89\x55\x10\x83\xf9\x09")  # jump_count++ < 10
        br(JG, "done")
        call(0x080F6486, arg(THIS))                        # simplejump_p
        code.extend(b"\x85\xc0"); br(JNE, "simple")
        code.extend(b"\x8b\x45" + s8(THIS) + b"\x8b\x40\x10\x66\x83\x38\x2d"); br(JE, "simple")  # RETURN
        call(0x080F64E4, arg(THIS))                        # condjump_p
        code.extend(b"\x85\xc0"); br(JE, "done")
        code.extend(b"\x83\x45\x10\x04\x83\x7d\x10\x09"); br(JG, "done")  # (jump_count += 4) >= 10
        call(mark_referenced, ESI, addr(NEEDED), b"\x6a\x01")
        call(mark_set, ESI, addr(SET), b"\x6a\x00", b"\x6a\x01")
        code.extend(b"\x8d\x45" + s8(SET)); copy16(TSET, 0)
        code.extend(b"\x8b\x45\x0c"); copy16(TRES, 0); copy16(FRES, 0)
        for k in range(4, 16, 4):                          # both &= ~(set & ~needed)
            code.extend(b"\x8b\x55" + s8(NEEDED + k) + b"\xf7\xd2\x23\x55" + s8(SET + k) + b"\xf7\xd2")
            code.extend(b"\x21\x55" + s8(TRES + k) + b"\x21\x55" + s8(FRES + k))
        code.extend(b"\x8b\x45" + s8(THIS) + b"\x8b\x40\x20")  # JUMP_LABEL
        call(start, EAX, addr(TRES), arg(0x10), addr(TSET), addr(NEEDED))
        call(start, EDI, addr(FRES), arg(0x10), addr(SET), addr(NEEDED))
        code.extend(b"\x8b\x4d\x0c")
        for k in range(4, 16, 4):                          # res &= target_res | fallthrough_res
            code.extend(b"\x8b\x45" + s8(FRES + k) + b"\x0b\x45" + s8(TRES + k) + b"\x21\x41" + s8(k))
        br(JMP, "done")
        label("simple")
        code.extend(b"\x8b\x45" + s8(THIS) + b"\x8b\x78\x20")  # next = JUMP_LABEL
        label("mark")
        call(mark_referenced, ESI, addr(NEEDED), b"\x6a\x01")
        call(mark_set, ESI, addr(SET), b"\x6a\x00", b"\x6a\x01")
        code.extend(b"\x8b\x4d\x0c")
        for k in range(4, 16, 4):                          # res &= ~(set & ~needed)
            code.extend(b"\x8b\x55" + s8(NEEDED + k) + b"\xf7\xd2\x23\x55" + s8(SET + k) + b"\xf7\xd2\x21\x51" + s8(k))
        label("cont")
        code.extend(b"\x89\xfe"); br(JMP, "loop")
        label("done")
        code.extend(b"\x8d\x65\xf4\x5f\x5e\x5b\x5d\xc3")  # epilogue
        resolve()

    fdsr = 0x080B1E53
    code = bytearray()

    def jump(opcode, target):
        code.extend(opcode)
        code.extend((target - (fdsr + len(code) + 4)).to_bytes(4, "little", signed=True))

    dead_or_set(code, jump, fdsr)
    if len(code) > 821:
        sys.exit("patch_cc1: find_dead_or_set_registers doesn't fit")
    put(fdsr, b"\xf3\x0f\x1e\xfb", code)

    # In the scan: a jump that is neither simple nor a return (+3810) goes to
    # find_dead_or_set_registers (insn, res, jump_count - 1, &set, &needed)
    # if it is a conditional jump, then the scan ends (+4121).
    def scan_cond_jump2(code, jump):
        code.extend(b"\x83\xec\x0c\xff\x75\x88")                     # push this_jump_insn
        jump(b"\xe8", 0x080F64E4)                                     # condjump_p
        code.extend(b"\x83\xc4\x10\x85\xc0")
        jump(b"\x0f\x84", 0x081725A6)
        code.extend(b"\x83\xec\x0c\x8d\x45\xc4\x50\x8d\x45\xb4\x50")  # &needed; &set
        code.extend(b"\x8b\x85\x68\xff\xff\xff\x48\x50")             # jump_count - 1
        code.extend(b"\xff\xb5\x40\xff\xff\xff\xff\xb5\x58\xff\xff\xff")  # res; insn
        jump(b"\xe8", fdsr)
        code.extend(b"\x83\xc4\x20")
        jump(b"\xe9", 0x081725A6)

    start = in_bc(scan_cond_jump2)
    o = fo(0x0817246F)
    put(0x0817246F, d[o:o + 6],
        b"\x0f\x85" + (start - (0x0817246F + 6)).to_bytes(4, "little", signed=True))

    # 18. try_combine+14621: the I2 of a combination is dead if the new
    #    pattern doesn't set it any more. 2.7.2 zeroes the stale
    #    REG_N_SETS/REG_N_REFS of I2DEST only when no new I2 pattern was
    #    made; GCC 2.8 also does it when there is one that doesn't mention
    #    I2DEST (`newi2pat == 0 || ! reg_mentioned_p (i2dest, newi2pat)`).
    #    Left with their references, such registers had no costs, so
    #    regclass gave them ST_REGS and reload a stack slot nothing uses: a
    #    bogus frame (the old patch 2 hid it by never choosing ST_REGS). The
    #    ROM keeps it where 2.8 also keeps the registers (_SsVmSetSeqVol's
    #    `vars= 8`). Locals: i2dest -0x158, newi2pat -0x160.
    def i2dest_dead(code, jump):
        code.extend(b"\x83\xec\x08\xff\xb5\xa0\xfe\xff\xff\xff\xb5\xa8\xfe\xff\xff")  # newi2pat; i2dest
        jump(b"\xe8", 0x080D647E)                   # reg_mentioned_p (i2dest, newi2pat)
        code.extend(b"\x83\xc4\x10\x85\xc0")
        jump(b"\x0f\x85", 0x0812A475)               # mentioned: keep it
        jump(b"\xe9", 0x0812A3E0)                    # else go on to the update

    start = in_bc(i2dest_dead)
    o = fo(0x0812A3DA)
    put(0x0812A3DA, d[o:o + 6],
        b"\x0f\x85" + (start - (0x0812A3DA + 6)).to_bytes(4, "little", signed=True))

    #    Some registers stay stale in 2.8 as well (the sign correction of a
    #    division by a constant, when combine folds it away) and the ROM
    #    still gives them no slot when they are referenced just twice
    #    (GsSetFlatLight's nine `x / 255`), while _SsVmSetSeqVol's, used in a
    #    loop (4 weighted references), get one. So the old patch 2 stays for
    #    those: regclass+2986 starts its best-class search below ST_REGS for a
    #    pseudo with exactly two references (an empirical rule).
    def best_class_start(code, jump):
        code.extend(b"\xbe\x07\x00\x00\x00")                    # mov $ALL_REGS-1,%esi
        code.extend(b"\xa1" + (0x082D3A38).to_bytes(4, "little"))  # mov reg_n_refs,%eax
        code.extend(b"\x8b\x8d\xf0\xfe\xff\xff")                # mov i,%ecx
        code.extend(b"\x83\x3c\x88\x02\x75\x05")                # cmpl $2,(%eax,%ecx,4); jne
        code.extend(b"\xbe\x06\x00\x00\x00")                    # mov $MD_REGS,%esi
        jump(b"\xe9", 0x08143141)

    start = in_bc(best_class_start)
    put(0x0814313C, b"\xbe\x07\x00\x00\x00",
        b"\xe9" + (start - (0x0814313C + 5)).to_bytes(4, "little", signed=True))

    # 6. alter_reg+345 and +639: the align argument of both
    #    `assign_stack_local (mode, total_size, -1)` becomes GCC 2.8's
    #    `inherent_size == total_size ? 0 : -1` (-0x1c and -0x2c(%ebp)); the
    #    mode is in %eax at the first site.
    for site, back in ((0x08161CD6, 0x08161CDB), (0x08161DFC, 0x08161E01)):
        def slot_align(code, jump, back=back):
            code.extend(b"\x83\xec\x04\x8b\x4d\xe4\x31\xd2")   # sub $4,%esp; mov inherent,%ecx; xor %edx,%edx
            code.extend(b"\x3b\x4d\xd4\x74\x01\x4a\x52")        # cmp total,%ecx; je 1f; dec %edx; 1: push %edx
            jump(b"\xe9", back)

        start = in_bc(slot_align)
        put(site, b"\x83\xec\x04\x6a\xff",
            b"\xe9" + (start - (site + 5)).to_bytes(4, "little", signed=True))

    os.makedirs(os.path.dirname(dst), exist_ok=True)
    tmp = dst + ".tmp"
    with open(tmp, "wb") as f:
        f.write(d)
    os.chmod(tmp, 0o755)
    os.replace(tmp, dst)


def ensure():
    """Path of the patched cc1, (re)built when missing or stale."""
    me = os.path.abspath(__file__)
    if (not os.path.exists(PATCHED)
            or os.path.getmtime(PATCHED) < max(os.path.getmtime(STOCK), os.path.getmtime(me))):
        patch(STOCK, PATCHED)
    return PATCHED


if __name__ == "__main__":
    if len(sys.argv) == 3:
        patch(sys.argv[1], sys.argv[2])
    else:
        print(ensure())
