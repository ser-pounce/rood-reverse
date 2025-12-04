$(BUILD)/src/MENU/MENU1.PRG/%.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/MENU/MENU1.PRG/%.o: CC1VER := 2.8.0-psx

$(BUILD)/config/MENU/MENU1.PRG/link.d: \
	config/SLUS_010.40/symbol_addrs.txt \
	config/BATTLE/BATTLE.PRG/symbol_addrs.txt \
	config/MENU/MAINMENU.PRG/symbol_addrs.txt

$(BUILD)/src/MENU/MENU1.PRG/30.o: $(BUILD)/assets/BATTLE/BATTLE.PRG/menuStrings.vsString $(BUILD)/assets/MENU/MENU1.PRG/strings.vsString
