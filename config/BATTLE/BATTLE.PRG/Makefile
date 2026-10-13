battle.prg := BATTLE/BATTLE.PRG
buildDir   := $(BUILD)/src/$(battle.prg)

$(BUILD)/data/$(battle.prg): LDFLAGS += \
	--defsym=vs_scratch=0x1F800000

$(BUILD)/data/BATTLE/BATTLE.PRG.elf: LDFLAGS += \
	--retain-symbols-file=config/BATTLE/BATTLE.PRG/exports.txt

$(buildDir)/%.c.o: CC1VER := 2.8.1-psx
$(buildDir)/%.c.o: ASFLAGS += -no-pad-sections

$(patsubst %,$(buildDir)/%.c.o,30DB0 38C1C 3A1A0 40564 44F14): CC1VER := 2.7.2-cdk
$(patsubst %,$(buildDir)/%.c.o,146C 4A0A8 5BF94):  CC1FLAGS += -Wno-return-type -Wno-uninitialized
$(buildDir)/40564.c.o $(buildDir)/573B8.c.o: CC1FLAGS += -Wno-return-type
$(buildDir)/30DB0.c.o: CC1FLAGS += -Wno-return-type -Wno-sign-compare -Wno-uninitialized
$(patsubst %,$(buildDir)/%.c.o,38C1C 3A1A0 40564 6E644): CC1FLAGS += -Wno-uninitialized

$(BUILD)/config/$(battle.prg)/link.d: \
	config/SLUS_010.40/symbol_addrs.txt \
	config/MENU/MAINMENU.PRG/symbol_addrs.txt

# Patch single byte in string table padding, seems it might actually be used though
$(BUILD)/data/BATTLE/BATTLE.PRG: FIXUP = $(XDELTA) -dfans $@ tools/data/BATTLE/BATTLE.PRG.xdelta $@

$(BUILD)/assets/BATTLE/BATTLE.PRG/keyStrings.vsStringFixed.bin $(BUILD)/assets/BATTLE/BATTLE.PRG/keyStrings.h &: $(BUILD)/assets/BATTLE/BATTLE.PRG/keyStrings.vsStringFixed.yaml | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.etc.vsString_yamlToDataFixed $< $(BUILD)/assets/BATTLE/BATTLE.PRG/keyStrings.vsStringFixed.bin 24 $(BUILD)/assets/BATTLE/BATTLE.PRG/keyStrings.h

$(BUILD)/assets/BATTLE/BATTLE.PRG/keyStrings.vsStringFixed.yaml.o: $(BUILD)/assets/BATTLE/BATTLE.PRG/keyStrings.vsStringFixed.bin
	$(ECHO) Converting $<
	$(OBJCOPY) $(OBJCOPYFLAGS) $< $@
