build/src/MENU/MENU0.PRG/%.o: ASFLAGS += -no-pad-sections
build/src/MENU/MENU0.PRG/%.o: CC1VER := 2.8.0

build/data/MENU/MENU0.PRG: build/data/MENU/MENU0.PRG.elf	
	$(call builder,Linking $@)
	@$(LD) $(LDFLAGS_BIN) $< -o $@
	@$(TRUNCATE) -s +1 $@
	@$(DIFF) $(DIFFFLAGS) $@ data/MENU/MENU0.PRG