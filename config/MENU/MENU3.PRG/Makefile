$(BUILD)/data/MENU/MENU3.PRG.elf: LDFLAGS += \
	--retain-symbols-file=config/MENU/MENU3.PRG/exports.txt
$(BUILD)/src/MENU/MENU3.PRG/%.o: ASFLAGS += \
	-no-pad-sections
$(BUILD)/src/MENU/MENU3.PRG/16C.o: CC1VER := 2.8.0-psx
$(BUILD)/src/MENU/MENU3.PRG/68C4.o: CC1VER := 2.7.2-cdk

$(BUILD)/config/MENU/MENU3.PRG/link.d: \
	config/SLUS_010.40/symbol_addrs.txt \
	config/BATTLE/BATTLE.PRG/symbol_addrs.txt \
	config/MENU/MAINMENU.PRG/symbol_addrs.txt