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
	$(addprefix libgte/, \
		MTX_005 REG13 REG12 REG11 MTX_12 MTX_09 MTX_004 \
		MTX_06 MTX_05 SMP_05 SMP_04 SMP_02 CMB_02 MTX_07 CMB_00 \
	) \
): ASFLAGS += -no-pad-sections

$(patsubst %,$(BUILD)/src/SLUS_010.40/%.c.o,2MBYTE.OBJ libcd/SYS overlay 25AC main): CC1VER := 2.8.1-psx

$(BUILD)/src/SLUS_010.40/lib%.c.o: PREPROCESS.s = $(PSQ_PATCH)
$(BUILD)/src/SLUS_010.40/libsn/SNMAIN.c.o: PREPROCESS.s = $(MAS) $(MASFLAGS)

$(BUILD)/config/SLUS_010.40/link.d: \
	config/BATTLE/BATTLE.PRG/symbol_addrs.txt \
	config/ENDING/ENDING.PRG/symbol_addrs.txt
