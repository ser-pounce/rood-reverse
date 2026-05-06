$(BUILD)/data/MENU/MENU9.PRG.elf: LDFLAGS += \
	--retain-symbols-file=config/MENU/MENU9.PRG/exports.txt \
	--defsym=_toVsStringPercentAlias=0x80106D5C
$(BUILD)/data/MENU/MENU9.PRG: LDFLAGS += \
	--defsym=D_1F800000=0x1F800000
$(BUILD)/src/MENU/MENU9.PRG/%.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/MENU/MENU9.PRG/238.o: CC1FLAGS += -Wno-uninitialized
$(patsubst %,$(BUILD)/src/MENU/MENU9.PRG/%.o,238 592C): CC1VER := 2.8.1-psx
$(BUILD)/src/MENU/MENU9.PRG/57BC.o: CC1VER := 2.7.2-cdk

$(BUILD)/config/MENU/MENU9.PRG/link.d: \
	config/SLUS_010.40/symbol_addrs.txt \
	config/BATTLE/BATTLE.PRG/symbol_addrs.txt \
	config/MENU/MAINMENU.PRG/symbol_addrs.txt
