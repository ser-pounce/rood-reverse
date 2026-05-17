$(BUILD)/assets/MENU/GAMEOVER.BIN.png: imgWH := 24 128
$(BUILD)/assets/MENU/MAPBG.BIN.png: imgWH := 320 240

$(BUILD)/assets/MENU/SPMCIMG.BIN.png: | $$(@D)/
	$(ECHO) Converting data/SPMCIMG.BIN
	$(VPYTHON) -m tools.data.MENU.SPMCIMG_BIN decode data/MENU/SPMCIMG.BIN data/MENU/MCDATA.BIN $@

$(BUILD)/data/MENU/SPMCIMG.BIN: $(BUILD)/assets/MENU/SPMCIMG.BIN.png | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.data.MENU.SPMCIMG_BIN encode $< $@

$(BUILD)/assets/MENU/MAPBG.BIN.png: | $$(@D)/
	$(ECHO) Converting data/MENU/MAPBG.BIN
	$(VPYTHON) -m tools.data.MENU.MAPBG_BIN decode data/MENU/MAPBG.BIN $@

$(BUILD)/data/MENU/MAPBG.BIN: $(BUILD)/assets/MENU/MAPBG.BIN.png | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.data.MENU.MAPBG_BIN encode $< $@

$(BUILD)/assets/MENU/ITEMNAME.BIN.vsStringFixed.yaml: assets/MENU/ITEMNAME.BIN.yaml | $$(@D)/
	$(ECHO) Extracting data/MENU/ITEMNAME.BIN
	$(VPYTHON) -m tools.etc.vsString_dumpFixedTable data/MENU/ITEMNAME.BIN assets/MENU/ITEMNAME.BIN.yaml $@ 24

$(BUILD)/assets/MENU/ITEMNAME.BIN.vsStringFixed.bin $(BUILD)/assets/MENU/ITEMNAME.BIN.h &: $(BUILD)/assets/MENU/ITEMNAME.BIN.vsStringFixed.yaml | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.etc.vsString_yamlToDataFixed $< $(BUILD)/assets/MENU/ITEMNAME.BIN.vsStringFixed.bin 24 $(BUILD)/assets/MENU/ITEMNAME.BIN.h

$(BUILD)/data/MENU/ITEMNAME.BIN: $(BUILD)/assets/MENU/ITEMNAME.BIN.vsStringFixed.bin | $$(@D)/
	$(ECHO) Converting $<
	cp $< $@

$(BUILD)/assets/MENU/%.SYD.yaml: | $$(@D)/
	$(ECHO) Converting data/MENU/$*.SYD
	$(VPYTHON) -m tools.data.MENU.$*_SYD_dump data/MENU/$*.SYD $@

$(BUILD)/data/MENU/%.SYD: $(BUILD)/assets/MENU/%.SYD.yaml | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.data.MENU.$*_SYD_encode $< $@

$(BUILD)/assets/MENU/MENUBG.BIN.png: data/MENU/MENUBG.BIN
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.data.MENU.MENUBG_BIN $< $@

$(BUILD)/data/MENU/MENUBG.BIN: $(BUILD)/assets/MENU/MENUBG.BIN.png
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.data.MENU.MENUBG_BIN $< $@

$(BUILD)/assets/MENU/GAMEOVER.BIN.png: data/MENU/GAMEOVER.BIN
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.data.MENU.GAMEOVER_BIN $< $@

$(BUILD)/data/MENU/GAMEOVER.BIN: $(BUILD)/assets/MENU/GAMEOVER.BIN.png
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.data.MENU.GAMEOVER_BIN $< $@

TARGETS += $(addprefix $(BUILD)/data/MENU/, $(addsuffix .BIN, ITEMNAME ITEMHELP GAMEOVER MAPBG MCMAN MENU12 MENUBG SPMCIMG) $(addsuffix .SYD, BLADE ARMOR SHIELD))
