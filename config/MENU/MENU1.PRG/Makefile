build/src/MENU/MENU1.PRG/%.o: ASFLAGS += -no-pad-sections
build/src/MENU/MENU1.PRG/%.o: CC1VER := 2.8.0

build/data/MENU/MENU1.PRG: build/data/MENU/MENU1.PRG.elf	
	$(call builder,Linking $@)
	@$(LD) $(LDFLAGS_BIN) $< -o $@
	@$(TRUNCATE) -s +2 $@
	@$(DIFF) $(DIFFFLAGS) $@ data/MENU/MENU1.PRG