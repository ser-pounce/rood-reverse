$(BUILD)/data/MENU/MENU1.PRG.elf: LDSCRIPT += \
	config/SLUS_010.40/exports.txt
$(BUILD)/data/MENU/MENU1.PRG: fixup = $(call pad,+2)
$(BUILD)/src/MENU/MENU1.PRG/%.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/MENU/MENU1.PRG/%.o: CC1VER := 2.8.0
