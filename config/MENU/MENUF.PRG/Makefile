$(BUILD)/src/MENU/MENUF.PRG/%.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/MENU/MENUF.PRG/%.o: CC1VER := 2.8.0-psx
$(BUILD)/src/MENU/MENUF.PRG/%.o: CC1FLAGS += -Wno-uninitialized

$(BUILD)/config/MENU/MENUF.PRG/link.d: \
	config/SLUS_010.40/symbol_addrs.txt \
	config/BATTLE/BATTLE.PRG/symbol_addrs.txt \
	config/MENU/MAINMENU.PRG/symbol_addrs.txt

$(BUILD)/src/MENU/MENUF.PRG/3B8.o: $(BUILD)/src/include/lbas.h
