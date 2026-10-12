$(BUILD)/data/SLUS_010.40: $(patsubst %,$(BUILD)/data/%.PRG.elf,BATTLE/INITBTL TITLE/TITLE)
$(BUILD)/data/SLUS_010.40: private LDLIBS += $(patsubst %,$(BUILD)/data/%.PRG.elf,BATTLE/INITBTL TITLE/TITLE)
$(BUILD)/data/SLUS_010.40: private LDFLAGS += \
	--defsym=.ctors=0x80010000 \
	--defsym=__nCtors=0x00000000 \
	--defsym=g_pActiveMusicConfig2=0x80037820\
	--defsym=vs_scratch=0x1F800000

$(BUILD)/data/SLUS_010.40.elf: LDFLAGS += \
	--retain-symbols-file=config/SLUS_010.40/exports.txt

$(BUILD)/src/SLUS_010.40/main.c.o: CC1FLAGS += -Wno-return-type
$(BUILD)/src/SLUS_010.40/25AC.c.o: MASFLAGS += --expand-div

$(patsubst %,$(BUILD)/src/SLUS_010.40/%.c.o, \
	libsn/SNMAIN 2MBYTE.OBJ overlay 25AC main \
	$(addprefix libgte/, REG13 REG12 REG11 MTX_12 MTX_09 SMP_05) \
): ASFLAGS += -no-pad-sections

$(patsubst %,$(BUILD)/src/SLUS_010.40/libgte/%.s.o, \
	MTX_005 MTX_004 MTX_06 MTX_05 SMP_04 SMP_02 CMB_02 MTX_07 CMB_00 \
): ASFLAGS += -no-pad-sections

$(patsubst %,$(BUILD)/src/SLUS_010.40/%.c.o,2MBYTE.OBJ libcd/SYS overlay 25AC main): CC1VER := 2.8.1-psx

$(BUILD)/src/SLUS_010.40/lib%.c.o: PREPROCESS.s = $(PSQ_PATCH)
$(BUILD)/src/SLUS_010.40/libsn/SNMAIN.c.o: PREPROCESS.s = $(MAS) $(MASFLAGS)

# libspu SPU was built with the CDK 2.7.2 cc1 (MIPS-as syntax); recipe established in
# noprompt/rood-reverse#186. ASPSX expanded unsigned divides with the divide first and an empty
# delay slot (_spu_FsetRXXa); GNU as would move the divide into the zero check's delay slot.
$(BUILD)/src/SLUS_010.40/libspu/SPU.c.o: CC1VER := 2.7.2-cdk
$(BUILD)/src/SLUS_010.40/libspu/SPU.c.o: CC1FLAGS += -mmips-as
$(BUILD)/src/SLUS_010.40/libspu/SPU.c.o: PREPROCESS.s = $(PSQ_PATCH) | $(PYTHON) tools/etc/aspsx_divu.py

# libcd bios.c 1.86 from CD_sync on (BIOS_2) matches the PsyQ library compiler built without
# strength reduction. Original object padding is explicit in splat.yaml.
$(BUILD)/src/SLUS_010.40/libcd/BIOS_2.c.o: CC1VER := 2.7.2-psyq
$(BUILD)/src/SLUS_010.40/libcd/BIOS_2.c.o: CC1FLAGS += -mhard-float -fno-strength-reduce
$(patsubst %,$(BUILD)/src/SLUS_010.40/libcd/%.c.o,BIOS BIOS_2): ASFLAGS += -no-pad-sections

# StGetNext preserves volatile stream-header reads and the SDK ring-size load.
# The typed PsyZ/SotN pattern matches CDK MIPS-as; the PSX compiler adds masks.
$(BUILD)/src/SLUS_010.40/libcd/C_009.c.o: CC1VER := 2.7.2-cdk
$(BUILD)/src/SLUS_010.40/libcd/C_009.c.o: CC1FLAGS += -mmips-as

# libgpu SYS (sys.c 1.140) was built by the compiler of the PsyQ libraries: GCC 2.7.2 with the
# GCC 2.8-style changes reproduced by tools/etc/patch_cc1.py, and -mhard-float (with the FP
# registers fixed, loop.c's lower invariant threshold keeps _exeque's status constants in the loop).
$(BUILD)/src/SLUS_010.40/libgpu/SYS.c.o: CC1VER := 2.7.2-psyq
$(BUILD)/src/SLUS_010.40/libgpu/SYS.c.o: CC1FLAGS += -mhard-float

# libgpu FONT: the same PsyQ library compiler; FntFlush reads its text through a signed char
# (lb), as the PsyQ libraries were built with -fsigned-char.
$(BUILD)/src/SLUS_010.40/libgpu/FONT.c.o: CC1VER := 2.7.2-psyq
$(BUILD)/src/SLUS_010.40/libgpu/FONT.c.o: CC1FLAGS += -mhard-float -fsigned-char

# Isolate the callback initializer: its shared interior-field base and return delay
# slot match CDK 2.7.2 in MIPS-as mode; the rest of PADMAIN keeps its compiler.
$(BUILD)/src/SLUS_010.40/libpad/PADMAIN_VSYNC.c.o: CC1VER := 2.7.2-cdk
$(BUILD)/src/SLUS_010.40/libpad/PADMAIN_VSYNC.c.o: CC1FLAGS += -mmips-as
$(patsubst %,$(BUILD)/src/SLUS_010.40/libpad/%.c.o,PADMAIN PADMAIN_VSYNC PADMAIN_2): ASFLAGS += -no-pad-sections

# DS_stop and DS_cw match CDK MIPS-as scheduling without the post-loop CSE pass
# (-fno-rerun-cse-after-loop for libds, as found in noprompt/rood-reverse#186).
# The leading reset callback stays in DSSYS_1 on the default compiler.
$(BUILD)/src/SLUS_010.40/libds/DSSYS_1_2.c.o: CC1VER := 2.7.2-cdk
$(BUILD)/src/SLUS_010.40/libds/DSSYS_1_2.c.o: CC1FLAGS += -mmips-as -fno-rerun-cse-after-loop
$(patsubst %,$(BUILD)/src/SLUS_010.40/libds/%.c.o,DSSYS_1 DSSYS_1_2): ASFLAGS += -no-pad-sections

# Queue/ready helpers retain shared global bases without the post-loop CSE pass.
$(patsubst %,$(BUILD)/src/SLUS_010.40/libds/%.c.o,DSSYS_2_QUEUE DSSYS_2): CC1FLAGS += -fno-rerun-cse-after-loop
$(patsubst %,$(BUILD)/src/SLUS_010.40/libds/%.c.o,DSSYS_2_QUEUE DSSYS_2_FLUSH DSSYS_2 DSSYS_2_2): ASFLAGS += -no-pad-sections

# DS_CQ_flush's forward parameter-clear loop is reversed and strength-reduced
# by CDK with post-loop CSE enabled.
$(BUILD)/src/SLUS_010.40/libds/DSSYS_2_FLUSH.c.o: CC1VER := 2.7.2-cdk
$(BUILD)/src/SLUS_010.40/libds/DSSYS_2_FLUSH.c.o: CC1FLAGS += -mmips-as

$(BUILD)/config/SLUS_010.40/link.d: \
	config/BATTLE/BATTLE.PRG/symbol_addrs.txt \
	config/ENDING/ENDING.PRG/symbol_addrs.txt
