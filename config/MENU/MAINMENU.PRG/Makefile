$(BUILD)/data/MENU/MAINMENU.PRG: fixup = $(call pad,+1)
$(BUILD)/src/MENU/MAINMENU.PRG/%.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/MENU/MAINMENU.PRG/%.o: CC1VER := 2.8.0-psx

$(BUILD)/config/MENU/MAINMENU.PRG/link.d: \
	config/SLUS_010.40/symbol_addrs.txt \
	config/BATTLE/BATTLE.PRG/symbol_addrs.txt \
	$(patsubst %,config/MENU/MENU%.PRG/symbol_addrs.txt,0 1 2 3 4 5 7 8 9 B C D E F)

$(BUILD)/src/MENU/MAINMENU.PRG/413C.o: $(BUILD)/src/include/lbas.h
$(BUILD)/src/MENU/MAINMENU.PRG/C48.o: $(BUILD)/assets/MENU/ITEMHELP.BIN.h

mainMenu_cdkFiles := $(patsubst %,$(BUILD)/src/MENU/MAINMENU.PRG/%.o,224 278)
$(mainMenu_cdkFiles): CC1VER := 2.7.2-cdk
$(mainMenu_cdkFiles): CC1FLAGS += -msoft-float 
