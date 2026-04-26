$(BUILD)/data/MENU/MENU5.PRG.elf: LDFLAGS += \
	--retain-symbols-file=config/MENU/MENU5.PRG/exports.txt
$(BUILD)/data/MENU/MENU5.PRG: LDFLAGS += \
	--defsym=D_1F800000=0x1F800000
$(BUILD)/src/MENU/MENU5.PRG/%.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/MENU/MENU5.PRG/%.o: CC1VER := 2.8.1-psx

$(BUILD)/config/MENU/MENU5.PRG/link.d: \
	config/SLUS_010.40/symbol_addrs.txt \
	config/BATTLE/BATTLE.PRG/symbol_addrs.txt \
	config/MENU/MAINMENU.PRG/symbol_addrs.txt
