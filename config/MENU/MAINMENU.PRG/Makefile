build/src/MENU/MAINMENU.PRG/%.o: ASFLAGS += -no-pad-sections
build/src/MENU/MAINMENU.PRG/%.o: CC1VER := 2.8.0

build/data/MENU/MAINMENU.PRG: build/data/MENU/MAINMENU.PRG.elf	
	$(call builder,Linking $@)
	@$(LD) $(LDFLAGS_BIN) $< -o $@
	@$(TRUNCATE) -s +1 $@
	@$(DIFF) $(DIFFFLAGS) $@ data/MENU/MAINMENU.PRG