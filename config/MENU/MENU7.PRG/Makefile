$(BUILD)/data/MENU/MENU7.PRG.elf: LDFLAGS += \
	--defsym=D_1F800000=0x1F800000 \
	--retain-symbols-file=config/MENU/MENU7.PRG/exports.txt
$(BUILD)/src/MENU/MENU7.PRG/260.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/MENU/MENU7.PRG/260.o: CC1VER := 2.8.0-psx

$(BUILD)/config/MENU/MENU7.PRG/link.d: \
	config/SLUS_010.40/symbol_addrs.txt \
	config/BATTLE/BATTLE.PRG/symbol_addrs.txt \
	config/MENU/MAINMENU.PRG/symbol_addrs.txt

$(BUILD)/src/MENU/MENU7.PRG/260.o: \
	$(BUILD)/src/include/lbas.h $(BUILD)/assets/MENU/MENU7.PRG/container.vsString $(BUILD)/assets/MENU/MCMAN.BIN.h
