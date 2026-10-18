$(BUILD)/data/ENDING/ENDING.PRG: $(BUILD)/data/SLUS_010.40.elf
$(BUILD)/data/ENDING/ENDING.PRG: private LDLIBS += $(BUILD)/data/SLUS_010.40.elf
$(BUILD)/data/ENDING/ENDING.PRG $(BUILD)/data/ENDING/ENDING.PRG.elf: private LDSCRIPT := link.ld

$(BUILD)/data/ENDING/ENDING.PRG: LDFLAGS += \
	--defsym=vs_scratch=0x1F800000

$(BUILD)/src/ENDING/ENDING.PRG/D4.c.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/ENDING/ENDING.PRG/D4.c.o: CC1VER := 2.8.1-psx
$(BUILD)/src/ENDING/ENDING.PRG/D4.c.o: CC1FLAGS += -Wno-return-type -Wno-uninitialized

$(BUILD)/assets/ENDING/ENDING.PRG/%.yaml.bin: $(BUILD)/assets/ENDING/ENDING.PRG/%.yaml | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.data.ENDING.ENDING_PRG.$* $< $@

$(BUILD)/assets/ENDING/ENDING.PRG/%.yaml.o: $(BUILD)/assets/ENDING/ENDING.PRG/%.yaml.bin | $$(@D)/
	$(ECHO) Assembling $@
	$(OBJCOPY) $(OBJCOPYFLAGS) --add-symbol $*=.data:0 $< $@

$(BUILD)/assets/ENDING/ENDING.PRG/%.tim.png.bin: $(BUILD)/assets/ENDING/ENDING.PRG/%.tim.png | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.data.ENDING.ENDING_PRG.tim $< $@

$(BUILD)/assets/ENDING/ENDING.PRG/%.tim.png.o: $(BUILD)/assets/ENDING/ENDING.PRG/%.tim.png.bin | $$(@D)/
	$(ECHO) Assembling $@
	$(OBJCOPY) $(OBJCOPYFLAGS) --add-symbol $*=.data:0 $< $@
