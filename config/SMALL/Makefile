.PRECIOUS: $(BUILD)/assets/%/help_data.yaml

$(BUILD)/data/%.HF0 $(BUILD)/data/%.HF1 &: $(BUILD)/assets/%/help_data.yaml | $$(@D)/
	@echo Converting $<
	$(VPYTHON) -m tools.data.SMALL.help_builder $< $|
	@$(DIFF) $(DIFFFLAGS) $(BUILD)/data/$*.HF0 data/$*.HF0
	@$(DIFF) $(DIFFFLAGS) $(BUILD)/data/$*.HF1 data/$*.HF1

$(BUILD)/assets/%/help_data.yaml: data/%.HF0 data/%.HF1 | $$(@D)/
	@echo Converting $<
	@$(VPYTHON) -m tools.data.SMALL.help_dumper $^ $|

helpfiles := 01 02 03 04 05 06 07 08 09 10 11 12 13 14

all: $(helpfiles:%=$(BUILD)/data/SMALL/HELP%.HF0)
