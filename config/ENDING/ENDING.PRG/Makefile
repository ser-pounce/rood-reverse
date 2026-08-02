$(BUILD)/data/ENDING/ENDING.PRG: LDFLAGS += \
	--defsym=vs_scratch=0x1F800000

$(BUILD)/data/ENDING/ENDING.PRG.elf: LDFLAGS += \
	--retain-symbols-file=config/MENU/ENDING.PRG/exports.txt

$(BUILD)/src/ENDING/ENDING.PRG/D4.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/ENDING/ENDING.PRG/D4.o: CC1VER := 2.8.1-psx
$(BUILD)/src/ENDING/ENDING.PRG/D4.o: CC1FLAGS += -Wno-return-type -Wno-uninitialized
