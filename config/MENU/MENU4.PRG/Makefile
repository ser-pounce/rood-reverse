$(BUILD)/data/MENU/MENU4.PRG.elf: LDFLAGS += \
	--retain-symbols-file=config/MENU/MENU4.PRG/exports.txt
$(BUILD)/src/MENU/MENU4.PRG/%.o: ASFLAGS += \
	-no-pad-sections
$(BUILD)/src/MENU/MENU4.PRG/%.o: CC1VER := 2.8.0-psx
$(BUILD)/src/MENU/MENU4.PRG/%.o: CC1FLAGS += -Wno-uninitialized

$(BUILD)/config/MENU/MENU4.PRG/link.d: \
	config/SLUS_010.40/symbol_addrs.txt \
	config/BATTLE/BATTLE.PRG/symbol_addrs.txt \
	config/MENU/MAINMENU.PRG/symbol_addrs.txt

$(BUILD)/src/MENU/MENU4.PRG/120.o: $(BUILD)/assets/MENU/MENU4.PRG/status.vsString $(BUILD)/assets/MENU/ITEMHELP.BIN.h
