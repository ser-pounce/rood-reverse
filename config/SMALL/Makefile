.PRECIOUS: $(BUILD)/assets/%.HF0.yaml

$(BUILD)/data/%.HF0: $(BUILD)/assets/%.HF0.yaml | $$(@D)/
	@echo Converting $<
	@$(VPYTHON) -m tools.data.SMALL.help_toBinary $< $@
	@$(DIFF) $(DIFFFLAGS) $@ data/$*.HF0

$(BUILD)/assets/%.HF0.yaml: data/%.HF0 | $$(@D)/
	@echo Converting $<
	@$(VPYTHON) -m tools.data.SMALL.help_toYaml $< $@

helpfiles := 01 02 03 04 05 06 07 08 09 10 11 12 13 14

all: $(helpfiles:%=$(BUILD)/data/SMALL/HELP%.HF0)
