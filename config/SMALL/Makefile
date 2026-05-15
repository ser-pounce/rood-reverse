.PRECIOUS: $(BUILD)/assets/%/help_data.yaml $(BUILD)/assets/SMALL/%.obj

$(BUILD)/data/%.HF0 $(BUILD)/data/%.HF1 &: $(BUILD)/assets/%/help_data.yaml | $$(@D)/
	echo Converting $<
	$(VPYTHON) -m tools.data.SMALL.help_builder $< $|

$(BUILD)/assets/%/help_data.yaml: | $$(@D)/
	echo Converting data/$*.HF0 data/$*.HF1
	$(VPYTHON) -m tools.data.SMALL.help_dumper data/$*.HF0 data/$*.HF1 $|

$(BUILD)/data/SMALL/%.ARM: $(BUILD)/assets/SMALL/%.obj | $$(@D)/
	echo Converting $<
	$(VPYTHON) -m tools.data.SMALL.buildArmFile $< $@ $(JPFONT)

$(BUILD)/assets/SMALL/%.obj: | $$(@D)/
	echo Converting data/SMALL/$*.ARM
	$(VPYTHON) -m tools.data.SMALL.dumpArmFile data/SMALL/$*.ARM $@ $(JPFONT)

ENDSCR := $(patsubst %,ENDSCR%,00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15)

$(BUILD)/assets/SMALL/%.DIS/ $(BUILD)/assets/SMALL/%.DIS.png:
	echo Converting data/SMALL/$*.DIS
	$(VPYTHON) -m tools.data.SMALL.generic_DIS data/SMALL/$*.DIS $@

$(BUILD)/assets/SMALL/IQ.DIS/:
	echo Converting data/SMALL/IQ.DIS
	$(VPYTHON) -m tools.data.SMALL.IQ_DIS data/SMALL/IQ.DIS $@

$(patsubst %,$(BUILD)/data/SMALL/%.DIS,ATTACK END RANK): $(BUILD)/data/SMALL/%.DIS: $(BUILD)/assets/SMALL/%.DIS/ | $$(@D)/
$(patsubst %,$(BUILD)/data/SMALL/%.DIS,ESC TIME $(ENDSCR)): $(BUILD)/data/SMALL/%.DIS: $(BUILD)/assets/SMALL/%.DIS.png | $$(@D)/

$(BUILD)/data/SMALL/%.DIS:
	echo Converting $<
	$(VPYTHON) -m tools.data.SMALL.generic_DIS $< $@

$(BUILD)/data/SMALL/IQ.DIS: $(BUILD)/assets/SMALL/IQ.DIS/
	echo Converting $<
	$(VPYTHON) -m tools.data.SMALL.IQ_DIS $< $@

$(patsubst %,$(BUILD)/data/SMALL/%.ARM,DUMMY SCEN018): JPFONT := true

helpfiles := 01 02 03 04 05 06 07 08 09 10 11 12 13 14
helpfiles := $(helpfiles:%=$(BUILD)/data/SMALL/HELP%.HF)
scenefiles := 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 \
              16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31
scenefiles := DUMMY $(scenefiles:%=SCEN0%)

TARGETS += $(helpfiles:%=%0) $(helpfiles:%=%1) $(scenefiles:%=$(BUILD)/data/SMALL/%.ARM)
TARGETS += $(patsubst %,$(BUILD)/data/SMALL/%.DIS,ATTACK END ESC IQ RANK TIME $(ENDSCR))