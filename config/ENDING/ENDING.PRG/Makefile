$(BUILD)/data/ENDING/ENDING.PRG: LDFLAGS += \
	--defsym=vs_scratch=0x1F800000

$(BUILD)/data/ENDING/ENDING.PRG.elf: LDFLAGS += \
	--retain-symbols-file=config/MENU/ENDING.PRG/exports.txt

$(BUILD)/src/ENDING/ENDING.PRG/D4.c.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/ENDING/ENDING.PRG/D4.c.o: CC1VER := 2.8.1-psx
$(BUILD)/src/ENDING/ENDING.PRG/D4.c.o: CC1FLAGS += -Wno-return-type -Wno-uninitialized

$(BUILD)/assets/ENDING/ENDING.PRG/credits.yaml.bin: $(BUILD)/assets/ENDING/ENDING.PRG/credits.yaml | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.data.ENDING.ENDING_PRG.credits $< $@

$(BUILD)/assets/ENDING/ENDING.PRG/credits.yaml.o: $(BUILD)/assets/ENDING/ENDING.PRG/credits.yaml.bin | $$(@D)/
	$(ECHO) Assembling $@
	$(OBJCOPY) $(OBJCOPYFLAGS) --add-symbol D_8006E3FC=.data:0 $< $@
