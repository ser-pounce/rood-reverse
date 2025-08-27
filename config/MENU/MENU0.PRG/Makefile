$(BUILD)/data/MENU/MENU0.PRG.elf: LDSCRIPT += \
	config/MENU/MAINMENU.PRG/exports.txt \
	config/BATTLE/BATTLE.PRG/exports.txt \
	config/SLUS_010.40/exports.txt
$(BUILD)/data/MENU/MENU0.PRG.elf: LDFLAGS += --defsym=D_1F800000=0x1F800000
$(BUILD)/data/MENU/MENU0.PRG: fixup = $(call pad,+1)
$(BUILD)/src/MENU/MENU0.PRG/%.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/MENU/MENU0.PRG/%.o: CC1VER := 2.8.0-psx
