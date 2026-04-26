$(BUILD)/data/MENU/MENUE.PRG.elf: LDFLAGS += \
	--retain-symbols-file=config/MENU/MENUE.PRG/exports.txt
$(BUILD)/src/MENU/MENUE.PRG/494.o: ASFLAGS += \
	-no-pad-sections
$(BUILD)/src/MENU/MENUE.PRG/494.o: CC1VER := 2.8.1-psx

$(BUILD)/config/MENU/MENUE.PRG/link.d: \
	config/SLUS_010.40/symbol_addrs.txt \
	config/BATTLE/BATTLE.PRG/symbol_addrs.txt \
	config/MENU/MAINMENU.PRG/symbol_addrs.txt
