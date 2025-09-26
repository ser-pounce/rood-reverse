$(BUILD)/assets/MENU/GAMEOVER.BIN.png: imgWH := 24 128
$(BUILD)/assets/MENU/SPMCIMG.BIN.png: imgWH := 448 256

$(patsubst %, $(BUILD)/assets/MENU/%.BIN.png, SPMCIMG): $(BUILD)/assets/%.png: data/% | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.etc.clut8 $< $(imgWH) $@

$(patsubst %, $(BUILD)/data/MENU/%.BIN, SPMCIMG): $(BUILD)/data/%: $(BUILD)/assets/%.png | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.splat_ext.rgb8 $< $@

$(BUILD)/assets/MENU/MCMAN.vsString.yaml $(BUILD)/assets/MENU/MCMAN.h &: data/MENU/MCMAN.BIN assets/MENU/MCMAN.yaml | $$(@D)/
	$(ECHO) Extracting $<
	$(VPYTHON) -m tools.etc.vsString_dumpTable $< assets/MENU/MCMAN.yaml $@

$(BUILD)/data/MENU/MCMAN.BIN: $(BUILD)/assets/MENU/MCMAN.vsString | $$(@D)/
	$(ECHO) Converting $<
	cp $(BUILD)/assets/MENU/MCMAN.vsString.bin $@

all: $(patsubst %, $(BUILD)/data/MENU/%.BIN, MCMAN SPMCIMG) 
