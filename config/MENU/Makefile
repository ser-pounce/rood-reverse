$(BUILD)/assets/MENU/GAMEOVER.BIN.png: imgWH := 24 128
$(BUILD)/assets/MENU/MAPBG.BIN.png: imgWH := 320 240

$(BUILD)/assets/MENU/SPMCIMG.BIN.png: | $$(@D)/
	$(ECHO) Converting data/SPMCIMG.BIN
	$(VPYTHON) -m tools.etc.spmcimg to-png data/MENU/SPMCIMG.BIN data/MENU/MCDATA.BIN $@

$(BUILD)/data/MENU/SPMCIMG.BIN: $(BUILD)/assets/MENU/SPMCIMG.BIN.png | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.etc.spmcimg to-bin $< $@

$(patsubst %, $(BUILD)/assets/MENU/%.BIN.png, MAPBG): $(BUILD)/assets/%.png: | $$(@D)/
	$(ECHO) Converting data/$*
	$(VPYTHON) -m tools.data.MENU.export8bppWithClut data/$* $@ $(imgWH)

$(patsubst %, $(BUILD)/data/MENU/%.BIN, MAPBG): $(BUILD)/data/%: $(BUILD)/assets/%.png | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.data.MENU.import8bppWithClut $< $@

$(BUILD)/assets/MENU/ITEMNAME.BIN.vsStringFixed.yaml: assets/MENU/ITEMNAME.BIN.yaml | $$(@D)/
	$(ECHO) Extracting data/MENU/ITEMNAME.BIN
	$(VPYTHON) -m tools.etc.vsString_dumpFixedTable data/MENU/ITEMNAME.BIN assets/MENU/ITEMNAME.BIN.yaml $@ 24

$(BUILD)/assets/MENU/ITEMNAME.BIN.vsStringFixed.bin $(BUILD)/assets/MENU/ITEMNAME.BIN.h &: $(BUILD)/assets/MENU/ITEMNAME.BIN.vsStringFixed.yaml | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.etc.vsString_yamlToDataFixed $< $(BUILD)/assets/MENU/ITEMNAME.BIN.vsStringFixed.bin 24 $(BUILD)/assets/MENU/ITEMNAME.BIN.h

$(BUILD)/data/MENU/ITEMNAME.BIN: $(BUILD)/assets/MENU/ITEMNAME.BIN.vsStringFixed.bin | $$(@D)/
	$(ECHO) Converting $<
	cp $< $@

$(BUILD)/assets/MENU/BLADE.SYD.yaml: | $$(@D)/
	$(ECHO) Converting data/MENU/BLADE.SYD
	$(VPYTHON) -m tools.data.MENU.BLADE_SYD_dump data/MENU/BLADE.SYD $@

$(BUILD)/data/MENU/BLADE.SYD: $(BUILD)/assets/MENU/BLADE.SYD.yaml | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.data.MENU.BLADE_SYD_encode $< $@

$(BUILD)/assets/MENU/ARMOR.SYD.yaml: | $$(@D)/
	$(ECHO) Converting data/MENU/ARMOR.SYD
	$(VPYTHON) -m tools.data.MENU.ARMOR_SYD_dump data/MENU/ARMOR.SYD $@

$(BUILD)/data/MENU/ARMOR.SYD: $(BUILD)/assets/MENU/ARMOR.SYD.yaml | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.data.MENU.ARMOR_SYD_encode $< $@

$(BUILD)/assets/MENU/SHIELD.SYD.yaml: | $$(@D)/
	$(ECHO) Converting data/MENU/SHIELD.SYD
	$(VPYTHON) -m tools.data.MENU.SHIELD_SYD_dump data/MENU/SHIELD.SYD $@

$(BUILD)/data/MENU/SHIELD.SYD: $(BUILD)/assets/MENU/SHIELD.SYD.yaml | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.data.MENU.SHIELD_SYD_encode $< $@

TARGETS += $(addprefix $(BUILD)/data/MENU/, $(addsuffix .BIN, MCMAN SPMCIMG MAPBG ITEMNAME ITEMHELP MENU12) $(addsuffix .SYD, BLADE ARMOR SHIELD))
