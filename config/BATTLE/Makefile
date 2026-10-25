TARGETS += $(BUILD)/data/BATTLE/SYSTEM.DAT

SYSTEM_DAT_PNGS := $(patsubst %,$(BUILD)/assets/BATTLE/SYSTEM.DAT/%.png,baseEffect clut0 clut1 font0 font1 font2 grid0 grid1 ui_tex0 ui_tex1)

$(BUILD)/data/BATTLE/SYSTEM.DAT: $(SYSTEM_DAT_PNGS) | $$(@D)/
	$(ECHO) Creating $@ 
	$(VPYTHON) -m tools.data.BATTLE.SYSTEM_DAT $(BUILD)/assets/BATTLE/SYSTEM.DAT/ $@

$(SYSTEM_DAT_PNGS) &: data/BATTLE/SYSTEM.DAT | $$(@D)/
	$(ECHO) Unpacking $<
	$(VPYTHON) -m tools.data.BATTLE.SYSTEM_DAT $< $(BUILD)/assets/BATTLE/SYSTEM.DAT/
