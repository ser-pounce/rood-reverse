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
	libsn/SNMAIN 2MBYTE.OBJ overlay 25AC 31724 32154 main \
	$(addprefix libgte/, \
		MTX_005 REG13 REG12 REG11 MTX_12 MTX_09 MTX_004 \
		MTX_06 MTX_05 SMP_05 SMP_04 SMP_02 CMB_02 MTX_07 CMB_00 \
	) \
): ASFLAGS += -no-pad-sections

$(patsubst %,$(BUILD)/src/SLUS_010.40/%.o,2MBYTE.OBJ libcd/SYS overlay 25AC main): CC1VER := 2.8.1-psx

# Sony's PsyQ library objects were assembled by GNU as in reorder mode (the assembler fills
# j/jr/jal delay slots with the preceding instruction, including the tail of a lui/sw macro),
# not by ASPSX. Feed cc1 output straight to as; only `move` must keep the old addu encoding.
# libsn/SNMAIN is SN Systems hand-written asm and keeps the ASPSX (maspsx) path.
$(BUILD)/src/SLUS_010.40/lib%.o: MAS := sed -E -e '1i .include "macro.inc"' -e 's/^\tmove\t([^,]+),(.+)$$/\taddu\t\1,\2,$$0/'
$(BUILD)/src/SLUS_010.40/lib%.o: MASFLAGS :=
$(BUILD)/src/SLUS_010.40/libsn/SNMAIN.o: MAS = $(VPYTHON) tools/maspsx/maspsx.py
$(BUILD)/src/SLUS_010.40/libsn/SNMAIN.o: MASFLAGS := --aspsx-version=2.77 --macro-inc

$(BUILD)/config/SLUS_010.40/link.d: \
	config/BATTLE/BATTLE.PRG/symbol_addrs.txt \
	config/ENDING/ENDING.PRG/symbol_addrs.txt
