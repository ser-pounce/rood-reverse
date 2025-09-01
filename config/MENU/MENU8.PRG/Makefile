$(BUILD)/data/MENU/MENU8.PRG.elf: LDSCRIPT += \
	config/SLUS_010.40/exports.txt \
	config/BATTLE/BATTLE.PRG/exports.txt \
    config/MENU/MAINMENU.PRG/exports.txt
$(BUILD)/data/MENU/MENU8.PRG.elf: LDFLAGS += \
	--defsym=D_80105F01=0x80105F01 \
	--defsym=D_80105EF5=0x80105EF5
$(BUILD)/src/MENU/MENU8.PRG/%.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/MENU/MENU8.PRG/%.o: CC1VER := 2.8.0-psx
