$(BUILD)/data/SLUS_010.40: $(patsubst %,$(BUILD)/data/%.PRG.elf,BATTLE/INITBTL TITLE/TITLE)
$(BUILD)/data/SLUS_010.40: LDLIBS += $(patsubst %,$(BUILD)/data/%.PRG.elf,BATTLE/INITBTL TITLE/TITLE)
$(BUILD)/data/SLUS_010.40: LDFLAGS += \
	--defsym=.ctors=0x80010000 \
	--defsym=__nCtors=0x00000000 \
	--defsym=g_pActiveMusicConfig2=0x80037820\
	--defsym=vs_scratch=0x1F800000

$(BUILD)/data/SLUS_010.40.elf: LDFLAGS += \
	--retain-symbols-file=config/SLUS_010.40/exports.txt

$(BUILD)/src/SLUS_010.40/main.o: CC1FLAGS += -Wno-return-type
$(BUILD)/src/SLUS_010.40/25AC.o: MASFLAGS += --expand-div

$(patsubst %,$(BUILD)/src/SLUS_010.40/%.o, \
	libsn/SNENTRY libsn/SNMAIN libsn/SNDTORS 2MBYTE.OBJ overlay 25AC 31724 31B7C 31C0C 32154 main libcd/SYS libcd/SYS_2 \
	$(addprefix libgte/, \
		MTX_005 REG13 REG12 REG11 MTX_12 MTX_09 MTX_004 \
		MTX_06 MTX_05 SMP_05 SMP_04 SMP_02 CMB_02 MTX_07 CMB_00 \
	) \
): ASFLAGS += -no-pad-sections

# libcd SYS is one PsyQ object, split at the CdReset/CdFlush boundary: CdReset only matches under
# 2.8.1-psx (its CD_initvol() result is copied to v1 before the test), while everything from CdFlush on
# only matches under 2.7.2-psx like the other libcd units (per-access lui for globals, ra/sp restore
# before jr). SYS_2 takes the default 2.7.2-psx.
$(patsubst %,$(BUILD)/src/SLUS_010.40/%.o,2MBYTE.OBJ libcd/SYS overlay 25AC main 31B7C): CC1VER := 2.8.1-psx

# libc MEMMOVE was built with the CDK 2.7.2 compiler: its backward copy loop keeps the n-- index
# (2.7.2-psx strength-reduces it into a pointer walk). Every other libc unit is byte-identical
# under either 2.7.2 build.
$(BUILD)/src/SLUS_010.40/libc/MEMMOVE.o: CC1VER := 2.7.2-cdk

# libpad PADIF/PADSEQD and libetc INTR_DMA were built with the CDK 2.7.2 cc1 (MIPS-as syntax): its
# reorg fills delay slots from branch-target threads (return moves, redundant arg moves), which
# 2.7.2-psx never does. All matched code in these units is byte-identical either way.
$(patsubst %,$(BUILD)/src/SLUS_010.40/%.o,libpad/PADIF libpad/PADSEQD libetc/INTR_DMA): CC1VER := 2.7.2-cdk
$(patsubst %,$(BUILD)/src/SLUS_010.40/%.o,libpad/PADIF libpad/PADSEQD libetc/INTR_DMA): CC1FLAGS += -mmips-as

# libcd BIOS was built with the CDK 2.7.2 cc1 (MIPS-as syntax): getintr's result[] loops keep their
# index (no strength reduction) and reorg fills delay slots from branch-target threads. Previously
# matched BIOS code is byte-identical either way.
$(BUILD)/src/SLUS_010.40/libcd/BIOS.o: CC1VER := 2.7.2-cdk
$(BUILD)/src/SLUS_010.40/libcd/BIOS.o: CC1FLAGS += -mmips-as

# libspu SPU was built with the CDK 2.7.2 cc1 (MIPS-as syntax): its newer reorg drops the spurious
# `addiu v1,v1,-1` after the DMA timeout loops that 2.7.2-psx's mark_target_live_regs emits. All
# previously matched SPU functions are byte-identical under either compiler.
$(BUILD)/src/SLUS_010.40/libspu/SPU.o: CC1VER := 2.7.2-cdk
$(BUILD)/src/SLUS_010.40/libspu/SPU.o: CC1FLAGS += -mmips-as

# libspu S_SNC was built with the CDK 2.7.2 cc1 (MIPS-as syntax): SpuSetNoiseClock copies n_clock
# to v0 and tests the copy, a register preference 2.7.2-psx does not reproduce. The unit has no
# previously matched code.
$(BUILD)/src/SLUS_010.40/libspu/S_SNC.o: CC1VER := 2.7.2-cdk
$(BUILD)/src/SLUS_010.40/libspu/S_SNC.o: CC1FLAGS += -mmips-as

# libcd SYS_2 was built with -mhard-float: with the FP registers not fixed, loop.c's invariant
# threshold is larger and the CdControl* retry loops hoist their 1/-1 constants. Every matched
# libcd/libds function is byte-identical with or without it.
$(BUILD)/src/SLUS_010.40/libcd/SYS_2.o: CC1FLAGS += -mhard-float

# Sony's PsyQ library objects were assembled by GNU as in reorder mode (the assembler fills
# j/jr/jal delay slots with the preceding instruction, including the tail of a lui/sw macro),
# not by ASPSX. Feed cc1 output straight to as; only `move` must keep the old addu encoding.
# libsn/SNMAIN is SN Systems hand-written asm and keeps the ASPSX (maspsx) path.
$(BUILD)/src/SLUS_010.40/lib%.o: MAS := sed -E -e '1i .include "macro.inc"' -e 's/^\tmove\t([^,]+),(.+)$$/\taddu\t\1,\2,$$0/'
$(BUILD)/src/SLUS_010.40/lib%.o: MASFLAGS :=
$(BUILD)/src/SLUS_010.40/libsn/SNMAIN.o: MAS = $(VPYTHON) tools/maspsx/maspsx.py
$(BUILD)/src/SLUS_010.40/libsn/SNMAIN.o: MASFLAGS := --aspsx-version=2.77 --macro-inc

# A few PsyQ library units were built without the post-loop CSE pass (stores to one global struct
# share a single `la base` register instead of per-store lui/sw macros).
$(patsubst %,$(BUILD)/src/SLUS_010.40/%.o,libspu/S_INI libspu/S_SRMD libspu/S_SRMT libapi/PAD libetc/INTR \
	libds/DSREADY libds/DSSYS_1 libds/DSREAD \
): \
	CC1FLAGS += -fno-rerun-cse-after-loop

# libgpu/SYS was built without the post-loop CSE pass and without -fforce-mem: SetGraphDebug tests
# the value it just stored (andi a0,0xff) but reloads the field for its printf, and the
# SetGraphQueue/DrawSyncCallback/MoveImage/MoveImage2 bodies only match with both. Every other
# matched SYS function is byte-identical either way (func_8002A30C's copy loop is spelled to be).
$(BUILD)/src/SLUS_010.40/libgpu/SYS.o: CC1FLAGS += -fno-rerun-cse-after-loop -fno-force-mem

$(BUILD)/config/SLUS_010.40/link.d: \
	config/BATTLE/BATTLE.PRG/symbol_addrs.txt \
	config/ENDING/ENDING.PRG/symbol_addrs.txt
