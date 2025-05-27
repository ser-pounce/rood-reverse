$(BUILD)/data/MENU/MENU7.PRG.elf: LDSCRIPT += \
	config/SLUS_010.40/exports.txt
$(BUILD)/data/MENU/MENU7.PRG: fixup = $(call pad,+2)
$(BUILD)/src/MENU/MENU7.PRG/%.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/MENU/MENU7.PRG/%.o: CC1VER := 2.8.0
