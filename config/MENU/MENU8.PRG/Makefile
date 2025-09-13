$(BUILD)/data/MENU/MENU8.PRG.elf: LDSCRIPT += \
	config/SLUS_010.40/exports.txt \
	config/BATTLE/BATTLE.PRG/exports.txt \
    config/MENU/MAINMENU.PRG/exports.txt
$(BUILD)/src/MENU/MENU8.PRG/%.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/MENU/MENU8.PRG/%.o: CC1VER := 2.8.0-psx
#$(addprefix $(BUILD)/src/MENU/MENU8.PRG/,88.o 21A0.o): $(addprefix $(BUILD)/assets/MENU/MENU8.PRG/, menu.vsString rename.vsString)
