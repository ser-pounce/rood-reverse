$(BUILD)/assets/MENU/GAMEOVER.BIN.png: imgWH := 24 128
$(BUILD)/assets/MENU/SPMCIMG.BIN.png: imgWH := 448 256

$(patsubst %, $(BUILD)/assets/MENU/%.BIN.png, SPMCIMG): $(BUILD)/assets/%.png: data/% | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.etc.clut8 $< $(imgWH) $@

$(patsubst %, $(BUILD)/data/MENU/%.BIN, SPMCIMG): $(BUILD)/data/%: $(BUILD)/assets/%.png | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.splat_ext.rgb8 $< $@

$(BUILD)/assets/MENU/MCMAN.BIN.vsString.yaml $(BUILD)/assets/MENU/MCMAN.BIN.h &: data/MENU/MCMAN.BIN assets/MENU/MCMAN.BIN.yaml | $$(@D)/
	$(ECHO) Extracting $<
	$(VPYTHON) -m tools.etc.vsString_dumpTable $< assets/MENU/MCMAN.BIN.yaml $@

$(BUILD)/data/MENU/MCMAN.BIN: $(BUILD)/assets/MENU/MCMAN.BIN.vsString | $$(@D)/
	$(ECHO) Converting $<
	cp $(BUILD)/assets/MENU/MCMAN.BIN.vsString.bin $@

$(BUILD)/assets/MENU/MENU12.BIN.vsString.yaml $(BUILD)/assets/MENU/MENU12.BIN.h &: data/MENU/MENU12.BIN assets/MENU/MENU12.BIN.yaml | $$(@D)/
	$(ECHO) Extracting $<
	$(VPYTHON) -m tools.etc.vsString_dumpTable $< assets/MENU/MENU12.BIN.yaml $@

$(BUILD)/data/MENU/MENU12.BIN: $(BUILD)/assets/MENU/MENU12.BIN.vsString | $$(@D)/
	$(ECHO) Converting $<
	cp $(BUILD)/assets/MENU/MENU12.BIN.vsString.bin $@

$(BUILD)/assets/MENU/ITEMNAME.BIN.vsStringNoHeader.yaml: data/MENU/ITEMNAME.BIN assets/MENU/ITEMNAME.BIN.yaml | $$(@D)/
	$(ECHO) Extracting $<
	$(VPYTHON) -m tools.etc.vsString_dumpFixedTable $< assets/MENU/ITEMNAME.BIN.yaml $@ 24

$(BUILD)/data/MENU/ITEMNAME.BIN: $(BUILD)/assets/MENU/ITEMNAME.BIN.vsStringNoHeader.yaml | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.etc.vsString_yamlToDataNoHeader $< $@ 24

all: $(patsubst %, $(BUILD)/data/MENU/%.BIN, MCMAN SPMCIMG ITEMNAME MENU12)
