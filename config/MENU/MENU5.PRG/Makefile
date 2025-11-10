$(BUILD)/data/MENU/MENU5.PRG.elf: LDSCRIPT += \
	config/SLUS_010.40/exports.txt \
	config/MENU/MAINMENU.PRG/exports.txt \
	config/BATTLE/BATTLE.PRG/exports.txt
$(BUILD)/data/MENU/MENU5.PRG.elf: LDFLAGS += --defsym=D_1F800000=0x1F800000
$(BUILD)/src/MENU/MENU5.PRG/%.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/MENU/MENU5.PRG/%.o: CC1VER := 2.8.0-psx
$(BUILD)/src/MENU/MENU5.PRG/4D8.o: $(BUILD)/src/include/lbas.h $(BUILD)/assets/MENU/MENU5.PRG/mapNames.vsString
$(BUILD)/src/MENU/MENU5.PRG/E84.o: $(patsubst %,$(BUILD)/assets/MENU/MENU5.PRG/%.vsString,mapNames connectingMaps doors paling)
