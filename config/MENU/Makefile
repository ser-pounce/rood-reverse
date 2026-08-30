$(BUILD)/assets/MENU/GAMEOVER.BIN.png: imgWH := 24 128
$(BUILD)/assets/MENU/MAPBG.BIN.png: imgWH := 320 240

$(BUILD)/assets/MENU/SPMCIMG.BIN.png: | $$(@D)/
	$(ECHO) Converting data/SPMCIMG.BIN
	$(VPYTHON) -m tools.data.MENU.SPMCIMG_BIN data/MENU/SPMCIMG.BIN $@ --clut data/MENU/MCDATA.BIN

$(BUILD)/data/MENU/SPMCIMG.BIN: $(BUILD)/assets/MENU/SPMCIMG.BIN.png | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.data.MENU.SPMCIMG_BIN $< $@

$(BUILD)/assets/MENU/MAPBG.BIN.png: | $$(@D)/
	$(ECHO) Converting data/MENU/MAPBG.BIN
	$(VPYTHON) -m tools.data.MENU.MAPBG_BIN data/MENU/MAPBG.BIN $@

$(BUILD)/data/MENU/MAPBG.BIN: $(BUILD)/assets/MENU/MAPBG.BIN.png | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.data.MENU.MAPBG_BIN $< $@

$(BUILD)/assets/MENU/ITEMNAME.BIN.vsStringFixed.yaml: assets/MENU/ITEMNAME.BIN.yaml | $$(@D)/
	$(ECHO) Extracting data/MENU/ITEMNAME.BIN
	$(VPYTHON) -m tools.etc.vsString_dumpFixedTable data/MENU/ITEMNAME.BIN assets/MENU/ITEMNAME.BIN.yaml $@ 24

$(BUILD)/assets/MENU/ITEMNAME.BIN.vsStringFixed.bin $(BUILD)/assets/MENU/ITEMNAME.BIN.h &: $(BUILD)/assets/MENU/ITEMNAME.BIN.vsStringFixed.yaml | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.etc.vsString_yamlToDataFixed $< $(BUILD)/assets/MENU/ITEMNAME.BIN.vsStringFixed.bin 24 $(BUILD)/assets/MENU/ITEMNAME.BIN.h

$(BUILD)/data/MENU/ITEMNAME.BIN: $(BUILD)/assets/MENU/ITEMNAME.BIN.vsStringFixed.bin | $$(@D)/
	$(ECHO) Converting $<
	cp $< $@

.PRECIOUS: $(BUILD)/assets/MENU/%.SYD.yml

$(BUILD)/assets/MENU/%.SYD.yml: | $$(@D)/
	$(ECHO) Converting data/MENU/$*.SYD
	$(VPYTHON) -m tools.data.MENU.SYD $* data/MENU/$*.SYD $@

$(BUILD)/data/MENU/%.SYD: $(BUILD)/assets/MENU/%.SYD.yml | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.data.MENU.SYD $* $< $@

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

$(BUILD)/data/MENU/MENUA.PRG: | $$(@D)/
	$(ECHO) Touching empty file $@
	$(TOUCH) $@

TARGETS += $(addprefix $(BUILD)/data/MENU/,MENUA.PRG $(addsuffix .BIN, ITEMNAME ITEMHELP GAMEOVER MAPBG MCMAN MENU12 MENUBG SPMCIMG) $(addsuffix .SYD, BLADE ARMOR SHIELD))
