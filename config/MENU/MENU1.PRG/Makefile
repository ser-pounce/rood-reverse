$(BUILD)/data/MENU/MENU1.PRG.elf: LDSCRIPT += \
	config/SLUS_010.40/exports.txt \
	config/BATTLE/BATTLE.PRG/exports.txt \
	config/MENU/MAINMENU.PRG/exports.txt
$(BUILD)/data/MENU/MENU1.PRG: fixup = $(call pad,+2)
$(BUILD)/src/MENU/MENU1.PRG/%.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/MENU/MENU1.PRG/%.o: CC1VER := 2.8.0-psx
$(BUILD)/src/MENU/MENU1.PRG/30.o: $(BUILD)/src/BATTLE/BATTLE.PRG/menuStrings.h $(BUILD)/assets/MENU/MENU1.PRG/strings.dat $(BUILD)/src/MENU/MENU1.PRG/strings.h

$(BUILD)/assets/MENU/MENU1.PRG/strings.dat $(BUILD)/src/MENU/MENU1.PRG/strings.h &: assets/MENU/MENU1.PRG/strings.yaml
	$(call builder,Converting $<)
	@$(VPYTHON) -m tools.etc.vsString_yamlToData $< $(BUILD)/assets/MENU/MENU1.PRG/strings.dat $(BUILD)/src/MENU/MENU1.PRG/strings.h
