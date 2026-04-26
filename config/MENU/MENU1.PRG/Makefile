$(BUILD)/data/MENU/MENU1.PRG.elf: LDFLAGS += \
	--retain-symbols-file=config/MENU/MENU1.PRG/exports.txt
$(BUILD)/src/MENU/MENU1.PRG/%.o: ASFLAGS += \
	-no-pad-sections
$(BUILD)/src/MENU/MENU1.PRG/%.o: CC1VER := 2.8.1-psx

$(BUILD)/config/MENU/MENU1.PRG/link.d: \
	config/SLUS_010.40/symbol_addrs.txt \
	config/BATTLE/BATTLE.PRG/symbol_addrs.txt \
	config/MENU/MAINMENU.PRG/symbol_addrs.txt
