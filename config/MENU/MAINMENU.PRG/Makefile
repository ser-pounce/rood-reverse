mainmenu_LDLIBS := $(patsubst %,$(BUILD)/data/MENU/MENU%.PRG.elf,0 1 2 3 4 5 7 8 9 B C D E F)

# Patch junk in .bss section
$(BUILD)/data/MENU/MAINMENU.PRG: FIXUP = $(XDELTA) -dfans $@ tools/data/MENU/MAINMENU.PRG.xdelta $@

$(BUILD)/data/MENU/MAINMENU.PRG: $(mainmenu_LDLIBS)
$(BUILD)/data/MENU/MAINMENU.PRG: LDLIBS += $(mainmenu_LDLIBS)

$(patsubst %,$(BUILD)/src/MENU/MAINMENU.PRG/%.o,224 278): CC1VER := 2.7.2-cdk
$(patsubst %,$(BUILD)/src/MENU/MAINMENU.PRG/%.o,2D10 C48): CC1FLAGS += -Wno-uninitialized
