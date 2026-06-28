.PRECIOUS: $(BUILD)/assets/%.vsString.yaml $(BUILD)/assets/%.BIN.vsString.yaml

$(BUILD)/assets/%.BIN.vsString.yaml: assets/%.BIN.yaml | $$(@D)/
	$(ECHO) Extracting data/$*.BIN
	$(VPYTHON) -m tools.etc.vsString_dumpTable data/$*.BIN $< $@

$(BUILD)/%.vsString $(BUILD)/%.h $(BUILD)/%.vsString.bin &: $(BUILD)/%.vsString.yaml | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.etc.vsString_yamlToData $< $(BUILD)/$*.vsString $(BUILD)/$*.h

$(BUILD)/data/%: $(BUILD)/assets/%.vsString.bin | $$(@D)/
	$(ECHO) Converting $<
	cp $< $@

%.vsString.o: %.vsString.bin
	$(ECHO) Assembling $@
	$(OBJCOPY) $(OBJCOPYFLAGS) $< $@
