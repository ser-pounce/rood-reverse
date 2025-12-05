$(BUILD)/src/BATTLE/BATTLE.PRG/%.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/BATTLE/BATTLE.PRG/%.o: CC1VER := 2.8.0-psx
$(BUILD)/src/BATTLE/BATTLE.PRG/30D14.o: CC1VER := 2.7.2-cdk
$(BUILD)/src/BATTLE/BATTLE.PRG/30D14.o: CC1FLAGS += -msoft-float

$(BUILD)/src/BATTLE/BATTLE.PRG/146C.o: CC1FLAGS += -Wno-return-type

$(BUILD)/config/BATTLE/BATTLE.PRG/link.d: \
	config/SLUS_010.40/symbol_addrs.txt \
	config/MENU/MAINMENU.PRG/symbol_addrs.txt

$(BUILD)/data/BATTLE/BATTLE.PRG.elf: $(BUILD)/assets/BATTLE/BATTLE.PRG/menuStrings.vsString.o
$(BUILD)/assets/BATTLE/BATTLE.PRG/menuStrings.vsString.o: OBJCOPYFLAGS += --pad-to 0x1DC

$(addprefix $(BUILD)/src/BATTLE/BATTLE.PRG/, 573B8.o 5BF94.o menuLbas.o gimLbas.o): \
	$(BUILD)/src/include/lbas.h
