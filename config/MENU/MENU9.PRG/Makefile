menu9_LDLIBS := $(patsubst %,$(BUILD)/data/%.elf,SLUS_010.40 BATTLE/BATTLE.PRG MENU/MAINMENU.PRG)

$(BUILD)/data/MENU/MENU9.PRG: $(menu9_LDLIBS)
$(BUILD)/data/MENU/MENU9.PRG: LDLIBS += $(menu9_LDLIBS)
$(BUILD)/data/MENU/MENU9.PRG: LDFLAGS += \
	--defsym=D_1F800000=0x1F800000
$(BUILD)/data/MENU/MENU9.PRG $(BUILD)/data/MENU/MENU9.PRG.elf: LDSCRIPT := link.ld

$(BUILD)/data/MENU/MENU9.PRG: LDFLAGS += \
	--defsym=_toVsStringPercentAlias=0x80106D5C

$(BUILD)/src/MENU/MENU9.PRG/%.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/MENU/MENU9.PRG/238.o: CC1FLAGS += -Wno-uninitialized
$(patsubst %,$(BUILD)/src/MENU/MENU9.PRG/%.o,238 592C): CC1VER := 2.8.1-psx
$(BUILD)/src/MENU/MENU9.PRG/57BC.o: CC1VER := 2.7.2-cdk
