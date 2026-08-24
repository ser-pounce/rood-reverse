.PRECIOUS: $(BUILD)/assets/%/help_data.yaml $(BUILD)/assets/SMALL/%.obj

$(BUILD)/data/%.HF0 $(BUILD)/data/%.HF1 &: $(BUILD)/assets/%/help_data.yaml | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.data.SMALL.HELP $< $|

$(BUILD)/assets/%/help_data.yaml: | $$(@D)/
	$(ECHO) Converting data/$*.HF0 data/$*.HF1
	$(VPYTHON) -m tools.data.SMALL.HELP data/$*.HF0 $|

$(BUILD)/data/SMALL/%.ARM: $(BUILD)/assets/SMALL/%.obj | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.data.SMALL.ARM $< $@ $(JPFONT)

$(BUILD)/assets/SMALL/%.obj: | $$(@D)/
	$(ECHO) Converting data/SMALL/$*.ARM
	$(VPYTHON) -m tools.data.SMALL.ARM data/SMALL/$*.ARM $@ $(JPFONT)

ENDSCR := $(patsubst %,ENDSCR%,00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15)

$(BUILD)/assets/SMALL/%.DIS.png: | $$(@D)/
	$(ECHO) Converting data/SMALL/$*.DIS
	$(VPYTHON) -m tools.data.SMALL.generic_DIS data/SMALL/$*.DIS $@

$(BUILD)/assets/SMALL/%.DIS/:
	$(ECHO) Converting data/SMALL/$*.DIS
	$(VPYTHON) -m tools.data.SMALL.generic_DIS data/SMALL/$*.DIS $@

$(BUILD)/data/SMALL/%.DIS: | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.data.SMALL.generic_DIS $< $@

$(patsubst %,$(BUILD)/data/SMALL/%.DIS,ATTACK END IQ RANK): $(BUILD)/data/SMALL/%.DIS: $(BUILD)/assets/SMALL/%.DIS/
$(patsubst %,$(BUILD)/data/SMALL/%.DIS,ESC TIME $(ENDSCR)): $(BUILD)/data/SMALL/%.DIS: $(BUILD)/assets/SMALL/%.DIS.png

$(BUILD)/assets/SMALL/MON.BIN.yml:
	$(ECHO) Converting data/SMALL/MON.BIN
	$(VPYTHON) -m tools.data.SMALL.MON_BIN data/SMALL/MON.BIN $@

$(BUILD)/data/SMALL/MON.BIN: $(BUILD)/assets/SMALL/MON.BIN.yml
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.data.SMALL.MON_BIN $< $@

$(patsubst %,$(BUILD)/data/SMALL/%.ARM,DUMMY SCEN018): JPFONT := --jp-font

helpfiles := 01 02 03 04 05 06 07 08 09 10 11 12 13 14
helpfiles := $(helpfiles:%=$(BUILD)/data/SMALL/HELP%.HF)
scenefiles := 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 \
              16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31
scenefiles := DUMMY $(scenefiles:%=SCEN0%)

TARGETS += $(helpfiles:%=%0) $(helpfiles:%=%1) $(scenefiles:%=$(BUILD)/data/SMALL/%.ARM)
TARGETS += $(patsubst %,$(BUILD)/data/SMALL/%.DIS,ATTACK END ESC IQ RANK TIME $(ENDSCR))
TARGETS += $(BUILD)/data/SMALL/MON.BIN
