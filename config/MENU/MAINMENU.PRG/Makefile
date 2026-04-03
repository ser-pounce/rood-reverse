$(BUILD)/data/MENU/MAINMENU.PRG: fixup = $(call pad,+1)

mainmenu_LDLIBS := $(patsubst %,$(BUILD)/data/MENU/MENU%.PRG.elf,0 1 2 3 4 5 7 8 9 E)
$(BUILD)/data/MENU/MAINMENU.PRG.linked.elf: $(mainmenu_LDLIBS)
$(BUILD)/data/MENU/MAINMENU.PRG.linked.elf: LDLIBS += $(mainmenu_LDLIBS)

$(BUILD)/src/MENU/MAINMENU.PRG/%.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/MENU/MAINMENU.PRG/%.o: CC1VER := 2.8.1-psx
$(patsubst %,$(BUILD)/src/MENU/MAINMENU.PRG/%.o, 2D10 C48): CC1FLAGS += -Wno-uninitialized

$(BUILD)/config/MENU/MAINMENU.PRG/link.d: \
	config/SLUS_010.40/symbol_addrs.txt \
	config/BATTLE/BATTLE.PRG/symbol_addrs.txt \
	$(patsubst %,config/MENU/MENU%.PRG/symbol_addrs.txt,0 1 2 3 4 5 7 8 9 B C D E F)

$(BUILD)/src/MENU/MAINMENU.PRG/2D10.o: $(BUILD)/src/include/lbas.h $(BUILD)/assets/MENU/ITEMHELP.BIN.h $(BUILD)/assets/MENU/ITEMNAME.BIN.h

mainMenu_cdkFiles := $(patsubst %,$(BUILD)/src/MENU/MAINMENU.PRG/%.o,224 278)
$(mainMenu_cdkFiles): CC1VER := 2.7.2-cdk
