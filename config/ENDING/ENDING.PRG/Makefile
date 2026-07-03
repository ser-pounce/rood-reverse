ending_LDLIBS := $(BUILD)/data/SLUS_010.40.elf

$(BUILD)/data/MENU/ENDING.PRG: $(ending_LDLIBS)
$(BUILD)/data/MENU/ENDING.PRG: LDLIBS += $(ending_LDLIBS)
$(BUILD)/data/MENU/ENDING.PRG: LDFLAGS += \
	--defsym=D_1F800000=0x1F800000
$(BUILD)/data/MENU/ENDING.PRG $(BUILD)/data/MENU/ENDING.PRG.elf: LDSCRIPT := link.ld

$(BUILD)/data/MENU/ENDING.PRG.elf: LDFLAGS += \
	--retain-symbols-file=config/MENU/ENDING.PRG/exports.txt

$(BUILD)/src/ENDING/ENDING.PRG/D4.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/ENDING/ENDING.PRG/D4.o: CC1VER := 2.8.1-psx
$(BUILD)/src/ENDING/ENDING.PRG/D4.o: CC1FLAGS += -Wno-return-type
