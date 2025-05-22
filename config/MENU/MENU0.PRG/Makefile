build/data/MENU/MENU0.PRG.elf: LDSCRIPT += \
	config/MENU/MAINMENU.PRG/exports.txt \
	config/SLUS_010.40/exports.txt
build/data/MENU/MENU0.PRG: fixup = $(call pad,+1)
build/src/MENU/MENU0.PRG/%.o: ASFLAGS += -no-pad-sections
build/src/MENU/MENU0.PRG/%.o: CC1VER := 2.8.0
