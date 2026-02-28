$(BUILD)/data/MENU/MENU0.PRG.elf: LDFLAGS += \
	--retain-symbols-file=config/MENU/MENU0.PRG/exports.txt
$(BUILD)/data/MENU/MENU0.PRG.linked.elf: LDFLAGS += \
	--defsym=D_1F800000=0x1F800000
$(BUILD)/src/MENU/MENU0.PRG/%.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/MENU/MENU0.PRG/%.o: CC1VER := 2.8.0-psx
$(BUILD)/src/MENU/MENU0.PRG/%.o: CC1FLAGS += -Wno-uninitialized

$(BUILD)/config/MENU/MENU0.PRG/link.d: \
	config/SLUS_010.40/symbol_addrs.txt \
	config/BATTLE/BATTLE.PRG/symbol_addrs.txt \
	config/MENU/MAINMENU.PRG/symbol_addrs.txt

$(BUILD)/src/MENU/MENU0.PRG/84.o: $(BUILD)/assets/MENU/MENU0.PRG/base.vsString $(BUILD)/assets/MENU/MENU0.PRG/teleportation.vsString
