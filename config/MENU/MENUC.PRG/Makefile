menuC_LDLIBS := $(patsubst %,$(BUILD)/data/%.elf,SLUS_010.40 BATTLE/BATTLE.PRG MENU/MAINMENU.PRG)

$(BUILD)/data/MENU/MENUC.PRG: $(menuC_LDLIBS)
$(BUILD)/data/MENU/MENUC.PRG: LDLIBS += $(menuC_LDLIBS)
$(BUILD)/data/MENU/MENUC.PRG: LDFLAGS += \
	--defsym=D_1F800000=0x1F800000
$(BUILD)/data/MENU/MENUC.PRG $(BUILD)/data/MENU/MENUC.PRG.elf: LDSCRIPT := link.ld

$(BUILD)/src/MENU/MENUC.PRG/%.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/MENU/MENUC.PRG/%.o: CC1VER := 2.8.1-psx

$(BUILD)/src/MENU/MENUC.PRG/168.o: CC1FLAGS += -Wno-uninitialized
$(BUILD)/src/MENU/MENUC.PRG/9258.o: CC1VER := 2.7.2-cdk
