SLUS_010_LDLIBS := $(patsubst %,$(BUILD)/data/%.PRG.elf,BATTLE/INITBTL ENDING/ENDING TITLE/TITLE)
$(BUILD)/data/SLUS_010.40: $(SLUS_010_LDLIBS)
$(BUILD)/data/SLUS_010.40: private LDLIBS += $(SLUS_010_LDLIBS)
$(BUILD)/data/SLUS_010.40: private LDFLAGS += \
	--defsym=.ctors=0x80010000 \
	--defsym=__nCtors=0x00000000 \
	--defsym=g_pActiveMusicConfig2=0x80037820\
	--defsym=vs_scratch=0x1F800000

$(BUILD)/data/SLUS_010.40.elf: LDFLAGS += \
	--retain-symbols-file=config/SLUS_010.40/exports.txt

$(BUILD)/src/SLUS_010.40/main.c.o: CC1FLAGS += -Wno-return-type
$(BUILD)/src/SLUS_010.40/25AC.c.o: MASFLAGS += --expand-div
$(BUILD)/src/SLUS_010.40/libgpu/SYS.c.o: CC1VER := 2.7.2-cdk
$(BUILD)/src/SLUS_010.40/libgpu/SYS.c.o: CC1FLAGS += -mmips-as

$(patsubst %,$(BUILD)/src/SLUS_010.40/%.c.o, \
	libsn/SNMAIN 2MBYTE.OBJ 25AC main \
	$(addprefix libgte/, REG13 REG12 REG11 MTX_12 MTX_09 SMP_05) \
): ASFLAGS += -no-pad-sections

$(patsubst %,$(BUILD)/src/SLUS_010.40/libgte/%.s.o, \
	MTX_005 MTX_004 MTX_06 MTX_05 SMP_04 SMP_02 CMB_02 MTX_07 CMB_00 \
): ASFLAGS += -no-pad-sections

$(BUILD)/src/SLUS_010.40/overlay.s.o: ASFLAGS += -no-pad-sections

$(patsubst %,$(BUILD)/src/SLUS_010.40/%.c.o,2MBYTE.OBJ libcd/SYS 25AC main): CC1VER := 2.8.1-psx

$(BUILD)/src/SLUS_010.40/lib%.c.o: PREPROCESS.s = $(PSQ_PATCH)
$(BUILD)/src/SLUS_010.40/libsn/SNMAIN.c.o: PREPROCESS.s = $(MAS) $(MASFLAGS)

$(BUILD)/config/SLUS_010.40/link.d: \
	config/BATTLE/BATTLE.PRG/symbol_addrs.txt

$(BUILD)/src/SLUS_010.40/libgpu/SYS.c.o: CC1VER := 2.7.2-cdk
$(BUILD)/src/SLUS_010.40/libgpu/SYS.c.o: CC1FLAGS += -mmips-as