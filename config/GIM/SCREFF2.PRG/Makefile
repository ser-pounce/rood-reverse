$(BUILD)/data/GIM/SCREFF2.PRG: LDFLAGS += \
	--defsym=vs_scratch=0x1F800000

# 0.c / 5E8.c (C) and 3D8.s (split hasm) all keep the module-wide settings.
$(BUILD)/src/GIM/SCREFF2.PRG/%.c.o $(BUILD)/src/GIM/SCREFF2.PRG/%.s.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/GIM/SCREFF2.PRG/%.c.o: CC1VER := 2.8.1-psx

$(BUILD)/config/GIM/SCREFF2.PRG/link.d: \
	config/SLUS_010.40/symbol_addrs.txt \
	config/BATTLE/BATTLE.PRG/symbol_addrs.txt
