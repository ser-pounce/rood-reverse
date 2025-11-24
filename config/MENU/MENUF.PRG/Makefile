$(BUILD)/data/MENU/MENUF.PRG.elf: LDSCRIPT += \
	config/SLUS_010.40/exports.txt\
	config/BATTLE/BATTLE.PRG/exports.txt
$(BUILD)/src/MENU/MENUF.PRG/%.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/MENU/MENUF.PRG/%.o: CC1VER := 2.8.0-psx
$(BUILD)/src/MENU/MENUF.PRG/%.o: CC1FLAGS += -Wno-uninitialized
$(BUILD)/src/MENU/MENUF.PRG/3B8.o: $(BUILD)/src/include/lbas.h
