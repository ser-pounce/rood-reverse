$(BUILD)/src/MENU/MENUC.PRG/%.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/MENU/MENUC.PRG/%.o: CC1VER := 2.8.0-psx
$(BUILD)/src/MENU/MENUC.PRG/168.o: $(BUILD)/assets/MENU/MENU12.BIN.h $(BUILD)/src/include/lbas.h
$(BUILD)/src/MENU/MENUC.PRG/168.o: CC1FLAGS += -Wno-uninitialized
$(BUILD)/src/MENU/MENUC.PRG/9258.o: CC1VER := 2.7.2-cdk
$(BUILD)/data/MENU/MENUC.PRG.elf: LDFLAGS += --defsym=D_1F800000=0x1F800000

$(BUILD)/config/MENU/MENUC.PRG/link.d: \
	config/SLUS_010.40/symbol_addrs.txt \
	config/BATTLE/BATTLE.PRG/symbol_addrs.txt \
	config/MENU/MAINMENU.PRG/symbol_addrs.txt
