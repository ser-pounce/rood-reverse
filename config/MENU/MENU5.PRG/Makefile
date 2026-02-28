$(BUILD)/data/MENU/MENU5.PRG.elf: LDFLAGS += \
	--retain-symbols-file=config/MENU/MENU5.PRG/exports.txt
$(BUILD)/data/MENU/MENU5.PRG.linked.elf: LDFLAGS += \
	--defsym=D_1F800000=0x1F800000
$(BUILD)/src/MENU/MENU5.PRG/%.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/MENU/MENU5.PRG/%.o: CC1VER := 2.8.0-psx

MENU5_stringTables := $(patsubst %,assets/MENU/MENU5.PRG/%,mapNames mapNames connectingMaps doors paling)

$(BUILD)/config/MENU/MENU5.PRG/link.d: \
	config/SLUS_010.40/symbol_addrs.txt \
	config/BATTLE/BATTLE.PRG/symbol_addrs.txt \
	config/MENU/MAINMENU.PRG/symbol_addrs.txt \
	$(wildcard $(MENU5_stringTables:%=%.yaml))

$(BUILD)/src/MENU/MENU5.PRG/4D8.o: $(BUILD)/src/include/lbas.h $(MENU5_stringTables:%=$(BUILD)/%.vsString)
