$(BUILD)/data/MENU/MENU2.PRG.elf: LDSCRIPT += \
	config/SLUS_010.40/exports.txt \
	config/MENU/MAINMENU.PRG/exports.txt \
	config/BATTLE/BATTLE.PRG/exports.txt
$(BUILD)/data/MENU/MENU2.PRG.elf: LDFLAGS += \
	--defsym=D_1F800000=0x1F800000
$(BUILD)/src/MENU/MENU2.PRG/%.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/MENU/MENU2.PRG/%.o: CC1VER := 2.8.0-psx
$(BUILD)/src/MENU/MENU2.PRG/64.o $(BUILD)/src/MENU/MENU2.PRG/143C.o: $(BUILD)/assets/MENU/MENU2.PRG/battleAbilities.vsString $(BUILD)/assets/MENU/MENU2.PRG/battleAbilitiesMenu.vsString
