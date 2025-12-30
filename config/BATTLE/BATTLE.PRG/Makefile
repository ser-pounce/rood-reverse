battle.prg := BATTLE/BATTLE.PRG
buildDir := $(BUILD)/src/$(battle.prg)
configDir := $(BUILD)/config/$(battle.prg)
assetsDir := $(BUILD)/assets/$(battle.prg)

$(buildDir)/%.o: CC1VER := 2.8.0-psx
$(buildDir)/%.o: ASFLAGS += -no-pad-sections
$(buildDir)/30D14.o: CC1VER := 2.7.2-cdk
$(buildDir)/30D14.o: CC1FLAGS += -msoft-float
$(buildDir)/3A1A0.o: CC1VER := 2.7.2-cdk
$(buildDir)/3A1A0.o: CC1FLAGS += -msoft-float

$(buildDir)/146C.o: CC1FLAGS += -Wno-return-type -Wno-uninitialized

$(configDir)/link.d: \
	config/SLUS_010.40/symbol_addrs.txt \
	config/MENU/MAINMENU.PRG/symbol_addrs.txt

$(BUILD)/data/$(battle.prg).elf: LDFLAGS += --defsym=func_8008574C_alias=0x8008574C
$(BUILD)/data/$(battle.prg).elf: $(assetsDir)/menuStrings.vsString.o
$(assetsDir)/menuStrings.vsString.o: OBJCOPYFLAGS += --pad-to 0x1DC

$(addprefix $(buildDir)/, 573B8.o 5BF94.o menuLbas.o gimLbas.o): $(BUILD)/src/include/lbas.h
