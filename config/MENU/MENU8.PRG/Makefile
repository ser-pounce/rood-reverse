$(BUILD)/src/MENU/MENU8.PRG/%.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/MENU/MENU8.PRG/%.o: CC1VER := 2.8.0-psx

$(BUILD)/config/MENU/MENU8.PRG/link.d: \
	config/SLUS_010.40/symbol_addrs.txt \
	config/BATTLE/BATTLE.PRG/symbol_addrs.txt \
	config/MENU/MAINMENU.PRG/symbol_addrs.txt

$(addprefix $(BUILD)/src/MENU/MENU8.PRG/,88.o 21A0.o): $(addprefix $(BUILD)/assets/MENU/MENU8.PRG/, menu.vsString rename.vsString)
