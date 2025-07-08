$(BUILD)/data/MENU/MENU7.PRG.elf: LDSCRIPT += \
	config/SLUS_010.40/exports.txt \
	config/BATTLE/BATTLE.PRG/exports.txt \
	config/MENU/MAINMENU.PRG/exports.txt
$(BUILD)/data/MENU/MENU7.PRG.elf: LDFLAGS += \
	--defsym=D_1F800000=0x1F800000
$(BUILD)/src/MENU/MENU7.PRG/260.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/MENU/MENU7.PRG/260.o: CC1VER := 2.8.0
$(BUILD)/src/MENU/MENU7.PRG/260.o: $(BUILD)/src/include/lbas.h
