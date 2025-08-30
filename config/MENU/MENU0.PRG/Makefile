$(BUILD)/data/MENU/MENU0.PRG.elf: LDSCRIPT += \
	config/MENU/MAINMENU.PRG/exports.txt \
	config/BATTLE/BATTLE.PRG/exports.txt \
	config/SLUS_010.40/exports.txt
$(BUILD)/data/MENU/MENU0.PRG.elf: LDFLAGS += --defsym=D_1F800000=0x1F800000
$(BUILD)/src/MENU/MENU0.PRG/%.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/MENU/MENU0.PRG/%.o: CC1VER := 2.8.0-psx
$(BUILD)/src/MENU/MENU0.PRG/%.o: CC1FLAGS += -Wno-uninitialized
$(BUILD)/src/MENU/MENU0.PRG/84.o: $(BUILD)/assets/MENU/MENU0.PRG/base.vsString $(BUILD)/assets/MENU/MENU0.PRG/teleportation.vsString
