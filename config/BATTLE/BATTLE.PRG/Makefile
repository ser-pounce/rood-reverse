battle.prg := BATTLE/BATTLE.PRG
buildDir   := $(BUILD)/src/$(battle.prg)

$(BUILD)/data/$(battle.prg): LDFLAGS += \
	--defsym=_camera=0x1F800000

$(buildDir)/%.o: CC1VER := 2.8.1-psx
$(buildDir)/%.o: ASFLAGS += -no-pad-sections

$(patsubst %,$(buildDir)/%.o,30D14 3A1A0 40564 44F14): CC1VER := 2.7.2-cdk

$(buildDir)/146C.o:  CC1FLAGS += -Wno-return-type -Wno-uninitialized
$(buildDir)/4A0A8.o: CC1FLAGS += -Wno-return-type -Wno-uninitialized
$(buildDir)/573B8.o: CC1FLAGS += -Wno-return-type
$(buildDir)/5BF94.o: CC1FLAGS += -Wno-return-type

$(BUILD)/config/$(battle.prg)/link.d: \
	config/SLUS_010.40/symbol_addrs.txt \
	config/MENU/MAINMENU.PRG/symbol_addrs.txt

$(BUILD)/assets/$(battle.prg)/menuStrings.vsString.o: OBJCOPYFLAGS += --pad-to 0x1DC
