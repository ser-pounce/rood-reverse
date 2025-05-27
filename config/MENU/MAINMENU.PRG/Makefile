$(BUILD)/data/MENU/MAINMENU.PRG.elf: LDSCRIPT += \
	config/SLUS_010.40/exports.txt
$(BUILD)/src/MENU/MAINMENU.PRG/%.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/MENU/MAINMENU.PRG/%.o: CC1VER := 2.8.0
$(BUILD)/data/MENU/MAINMENU.PRG: fixup = $(call pad,+1)
