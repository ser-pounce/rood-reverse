mainmenu_LDLIBS := $(patsubst %,$(BUILD)/data/MENU/MENU%.PRG.elf,0 1 2 3 4 5 7 8 9 B C D E F) \
	$(BUILD)/data/SLUS_010.40.elf $(BUILD)/data/BATTLE/BATTLE.PRG.elf

$(BUILD)/data/MENU/MAINMENU.PRG: FIXUP = $(VPYTHON) -m tools.data.MENU.MAINMENU_PRG $@
$(BUILD)/data/MENU/MAINMENU.PRG: $(mainmenu_LDLIBS)
$(BUILD)/data/MENU/MAINMENU.PRG: LDLIBS += $(mainmenu_LDLIBS)
$(BUILD)/data/MENU/MAINMENU.PRG: LDFLAGS += \
	--defsym=D_1F800000=0x1F800000
$(BUILD)/data/MENU/MAINMENU.PRG $(BUILD)/data/MENU/MAINMENU.PRG.elf: LDSCRIPT := link.ld

$(BUILD)/src/MENU/MAINMENU.PRG/%.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/MENU/MAINMENU.PRG/%.o: CC1VER := 2.8.1-psx
$(patsubst %,$(BUILD)/src/MENU/MAINMENU.PRG/%.o,224 278): CC1VER := 2.7.2-cdk
$(patsubst %,$(BUILD)/src/MENU/MAINMENU.PRG/%.o,2D10 C48): CC1FLAGS += -Wno-uninitialized
