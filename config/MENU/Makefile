$(BUILD)/assets/MENU/SPMCIMG.BIN.png: data/MENU/SPMCIMG.BIN
	$(call builder,Converting $<)
	@$(VPYTHON) -m tools.etc.rgba16 $< 224 256 $@

build/data/MENU/SPMCIMG.BIN: $(BUILD)/assets/MENU/SPMCIMG.BIN.png
	$(call builder,Converting $<)
	@$(RGBA16) $< $@ noheader
	@$(DIFF) $(DIFFFLAGS) build/data/MENU/SPMCIMG.BIN data/MENU/SPMCIMG.BIN


all: build/data/MENU/SPMCIMG.BIN
$(BUILD)/assets/MENU/SPMCIMG.png: data/MENU/SPMCIMG.BIN
