SCREFF2_LDLIBS := $(patsubst %,$(BUILD)/data/%.sym.elf,SLUS_010.40 BATTLE/BATTLE.PRG)
$(BUILD)/data/GIM/SCREFF2.PRG.elf: $(SCREFF2_LDLIBS)
$(BUILD)/data/GIM/SCREFF2.PRG.elf: private LDLIBS += $(SCREFF2_LDLIBS)
$(BUILD)/data/GIM/SCREFF2.PRG.elf: private LDFLAGS += \
	--defsym=vs_scratch=0x1F800000

$(BUILD)/data/GIM/SCREFF2.PRG.elf $(BUILD)/data/GIM/SCREFF2.PRG.sym.elf: private LDSCRIPT := link.ld

$(BUILD)/src/GIM/SCREFF2.PRG/0.c.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/GIM/SCREFF2.PRG/0.c.o: CC1VER := 2.8.1-psx
$(BUILD)/src/GIM/SCREFF2.PRG/0.c.o: CC1FLAGS += -Wno-uninitialized
