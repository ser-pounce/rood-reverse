.PRECIOUS: $(BUILD)/assets/ENDING/ILLUST%.BIN.png

$(BUILD)/assets/ENDING/ILLUST%.BIN.png: data/ENDING/ILLUST%.BIN | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.data.ENDING.ENDING_PRG.illust $< $@

$(BUILD)/data/ENDING/ILLUST%.BIN: $(BUILD)/assets/ENDING/ILLUST%.BIN.png | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.data.ENDING.ENDING_PRG.illust $< $@

TARGETS += $(patsubst %,$(BUILD)/data/ENDING/ILLUST%.BIN,06 07 08 09 10 11 12 13 14 15 16)
