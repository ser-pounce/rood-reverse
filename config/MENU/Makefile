$(BUILD)/assets/MENU/SPMCIMG.BIN.png: data/MENU/SPMCIMG.BIN
	$(call builder,Converting $<)
	@$(VPYTHON) -m tools.etc.clut8 $< 448 256 $@

$(BUILD)/data/MENU/SPMCIMG.BIN: $(BUILD)/assets/MENU/SPMCIMG.BIN.png
	$(call builder,Converting $<)
	@$(VPYTHON) -m tools.splat_ext.rgb8 $< $@
	@$(DIFF) $(DIFFFLAGS) $@ $(@:build/%=%)

all: build/data/MENU/SPMCIMG.BIN
