$(BUILD)/assets/MENU/GAMEOVER.BIN.png: imgWH := 24 128
$(BUILD)/assets/MENU/SPMCIMG.BIN.png: imgWH := 448 256

$(patsubst %, $(BUILD)/assets/MENU/%.BIN.png, SPMCIMG): $(BUILD)/assets/%.png: data/% | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.etc.clut8 $< $(imgWH) $@

$(patsubst %, $(BUILD)/data/MENU/%.BIN, SPMCIMG): $(BUILD)/data/%: $(BUILD)/assets/%.png | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.splat_ext.rgb8 $< $@

$(BUILD)/assets/MENU/ITEMNAME.BIN.vsStringFixed.yaml: data/MENU/ITEMNAME.BIN assets/MENU/ITEMNAME.BIN.yaml | $$(@D)/
	$(ECHO) Extracting $<
	$(VPYTHON) -m tools.etc.vsString_dumpFixedTable $< assets/MENU/ITEMNAME.BIN.yaml $@ 24

$(BUILD)/data/MENU/ITEMNAME.BIN: $(BUILD)/assets/MENU/ITEMNAME.BIN.vsStringFixed.yaml | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.etc.vsString_yamlToDataFixed $< $@ 24

all: $(patsubst %, $(BUILD)/data/MENU/%.BIN, MCMAN SPMCIMG ITEMNAME MENU12)
