SCREFF2_LDLIBS := $(patsubst %,$(BUILD)/data/%.elf,SLUS_010.40 BATTLE/BATTLE.PRG)
$(BUILD)/data/GIM/SCREFF2.PRG: $(SCREFF2_LDLIBS)
$(BUILD)/data/GIM/SCREFF2.PRG: private LDLIBS += $(SCREFF2_LDLIBS)
$(BUILD)/data/GIM/SCREFF2.PRG: private LDFLAGS += \
	--defsym=vs_scratch=0x1F800000

$(BUILD)/data/GIM/SCREFF2.PRG $(BUILD)/data/GIM/SCREFF2.PRG.elf: private LDSCRIPT := link.ld

$(BUILD)/src/GIM/SCREFF2.PRG/0.c.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/GIM/SCREFF2.PRG/0.c.o: CC1VER := 2.8.1-psx
