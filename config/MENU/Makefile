$(BUILD)/assets/MENU/GAMEOVER.BIN.png: imgWH := 24 128
$(BUILD)/assets/MENU/SPMCIMG.BIN.png: imgWH := 448 256
$(BUILD)/assets/MENU/MAPBG.BIN.png: imgWH := 320 240

$(patsubst %, $(BUILD)/assets/MENU/%.BIN.png, SPMCIMG): $(BUILD)/assets/%.png: data/% | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.etc.clut8 $< $(imgWH) $@

$(patsubst %, $(BUILD)/data/MENU/%.BIN, SPMCIMG): $(BUILD)/data/%: $(BUILD)/assets/%.png | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.splat_ext.rgb8 $< $@

$(patsubst %, $(BUILD)/assets/MENU/%.BIN.png, MAPBG): $(BUILD)/assets/%.png: data/% | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.data.MENU.export8bppWithClut $< $@ $(imgWH)

$(patsubst %, $(BUILD)/data/MENU/%.BIN, MAPBG): $(BUILD)/data/%: $(BUILD)/assets/%.png | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.data.MENU.import8bppWithClut $< $@

$(BUILD)/assets/MENU/ITEMNAME.BIN.vsStringFixed.yaml: data/MENU/ITEMNAME.BIN assets/MENU/ITEMNAME.BIN.yaml | $$(@D)/
	$(ECHO) Extracting $<
	$(VPYTHON) -m tools.etc.vsString_dumpFixedTable $< assets/MENU/ITEMNAME.BIN.yaml $@ 24

$(BUILD)/assets/MENU/ITEMNAME.BIN.vsStringFixed.bin $(BUILD)/assets/MENU/ITEMNAME.BIN.h &: $(BUILD)/assets/MENU/ITEMNAME.BIN.vsStringFixed.yaml | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.etc.vsString_yamlToDataFixed $< $(BUILD)/assets/MENU/ITEMNAME.BIN.vsStringFixed.bin 24 $(BUILD)/assets/MENU/ITEMNAME.BIN.h

$(BUILD)/data/MENU/ITEMNAME.BIN: $(BUILD)/assets/MENU/ITEMNAME.BIN.vsStringFixed.bin | $$(@D)/
	$(ECHO) Converting $<
	cp $< $@

all: $(patsubst %, $(BUILD)/data/MENU/%.BIN, MCMAN SPMCIMG MAPBG ITEMNAME ITEMHELP MENU12)
