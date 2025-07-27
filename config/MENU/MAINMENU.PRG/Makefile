$(BUILD)/data/MENU/MAINMENU.PRG.elf: LDSCRIPT += \
	config/SLUS_010.40/exports.txt \
	config/MENU/MENU1.PRG/exports.txt \
	config/MENU/MENU7.PRG/exports.txt \
    config/BATTLE/BATTLE.PRG/exports.txt
$(BUILD)/src/MENU/MAINMENU.PRG/%.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/MENU/MAINMENU.PRG/%.o: CC1VER := 2.8.0-psx
$(BUILD)/src/MENU/MAINMENU.PRG/278.o: CC1VER := 2.7.2-cdk
$(BUILD)/src/MENU/MAINMENU.PRG/278.o: CC1FLAGS += -msoft-float 
$(BUILD)/data/MENU/MAINMENU.PRG: fixup = $(call pad,+1)
