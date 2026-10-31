battle.prg := BATTLE/BATTLE.PRG
buildDir   := $(BUILD)/src/$(battle.prg)

$(BUILD)/data/$(battle.prg): LDFLAGS += \
	--defsym=vs_scratch=0x1F800000

$(BUILD)/data/BATTLE/BATTLE.PRG.elf: LDFLAGS += \
	--retain-symbols-file=config/BATTLE/BATTLE.PRG/exports.txt

$(buildDir)/%.c.o: CC1VER := 2.8.1-psx
$(buildDir)/%.c.o: ASFLAGS += -no-pad-sections
$(patsubst %,$(buildDir)/%.s.o,2EA3C 48C7C 4B16C 579C0 6FA0C 70D4C 72B70 7399C 7B3C8 7DDDC): ASFLAGS += -no-pad-sections

$(patsubst %,$(buildDir)/%.c.o,30DB0 38C1C 3A1A0 40564 44F14 49268 49EB8): CC1VER := 2.7.2-cdk
$(patsubst %,$(buildDir)/%.c.o,146C 4DEA8 5BF94):  CC1FLAGS += -Wno-return-type -Wno-uninitialized
$(patsubst %,$(buildDir)/%.c.o,3A1A0 40564 573B8 57B1C): CC1FLAGS += -Wno-return-type
$(buildDir)/30DB0.c.o: CC1FLAGS += -Wno-return-type -Wno-sign-compare -Wno-uninitialized
$(patsubst %,$(buildDir)/%.c.o,38C1C 3A1A0 40564 44F14 49268 6E4CC 6FC00 71618 73700 74088 7CD68 7EE98): CC1FLAGS += -Wno-uninitialized

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

BATTLE_LDLIBS := $(BUILD)/data/GIM/SCREFF2.PRG.elf
$(BUILD)/data/$(battle.prg): $(BATTLE_LDLIBS)
$(BUILD)/data/$(battle.prg): private LDLIBS += $(BATTLE_LDLIBS)
