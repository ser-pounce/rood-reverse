$(BUILD)/assets/MENU/GAMEOVER.BIN.png: imgWH := 24 128
$(BUILD)/assets/MENU/SPMCIMG.BIN.png: imgWH := 448 256

$(patsubst %, $(BUILD)/assets/MENU/%.BIN.png, SPMCIMG): $(BUILD)/assets/%.png: data/% | $$(@D)/
	@$(ECHO) Converting $<
	@$(VPYTHON) -m tools.etc.clut8 $< $(imgWH) $@

$(patsubst %, $(BUILD)/data/MENU/%.BIN, SPMCIMG): $(BUILD)/data/%: $(BUILD)/assets/%.png | $$(@D)/
	@$(ECHO) Converting $<
	@$(VPYTHON) -m tools.splat_ext.rgb8 $< $@
	@$(DIFF) $(DIFFFLAGS) $@ $(@:build/%=%)

$(BUILD)/data/MENU/MCMAN.BIN $(BUILD)/assets/MENU/MCMAN.vsString $(BUILD)/src/include/mcman.h &: assets/MENU/MCMAN.yaml | $$(@D)/
	@$(ECHO) Converting $<
	@$(VPYTHON) -m tools.etc.vsString_yamlToData $< $(BUILD)/assets/MENU/MCMAN.vsString $(BUILD)/src/include/mcman.h
	@cp $(BUILD)/assets/MENU/MCMAN.vsString.bin $@
	@$(DIFF) $(DIFFFLAGS) $(BUILD)/data/MENU/MCMAN.BIN data/MENU/MCMAN.BIN

all: $(patsubst %, $(BUILD)/data/MENU/%.BIN, MCMAN SPMCIMG) 
