.PRECIOUS: $(BUILD)/assets/%/help_data.yaml $(BUILD)/assets/SMALL/%.obj

$(BUILD)/data/%.HF0 $(BUILD)/data/%.HF1 &: $(BUILD)/assets/%/help_data.yaml | $$(@D)/
	echo Converting $<
	$(VPYTHON) -m tools.data.SMALL.help_builder $< $|

$(BUILD)/assets/%/help_data.yaml: data/%.HF0 data/%.HF1 | $$(@D)/
	echo Converting $<
	$(VPYTHON) -m tools.data.SMALL.help_dumper $^ $|

$(BUILD)/data/SMALL/%.ARM: $(BUILD)/assets/SMALL/%.obj | $$(@D)/
	echo Converting $<
	$(VPYTHON) -m tools.data.SMALL.buildArmFile $< $@

$(BUILD)/assets/SMALL/%.obj: data/SMALL/%.ARM | $$(@D)/
	echo Converting $<
	$(VPYTHON) -m tools.data.SMALL.dumpArmFile $< $@

helpfiles := 01 02 03 04 05 06 07 08 09 10 11 12 13 14
helpfiles := $(helpfiles:%=$(BUILD)/data/SMALL/HELP%.HF)
scenefiles := 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 \
              16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31
scenefiles := DUMMY $(scenefiles:%=SCEN0%)

all: $(helpfiles:%=%0) $(helpfiles:%=%1) $(scenefiles:%=$(BUILD)/data/SMALL/%.ARM)
