$(BUILD)/data/BATTLE/INITBTL.PRG: $(patsubst %,$(BUILD)/data/%.elf,SLUS_010.40 BATTLE/BATTLE.PRG)
$(BUILD)/data/BATTLE/INITBTL.PRG: LDLIBS += $(patsubst %,$(BUILD)/data/%.elf,SLUS_010.40 BATTLE/BATTLE.PRG)
$(BUILD)/data/BATTLE/INITBTL.PRG: LDFLAGS += \
	--defsym=vs_scratch=0x1F800000

$(BUILD)/data/BATTLE/INITBTL.PRG $(BUILD)/data/BATTLE/INITBTL.PRG.elf: LDSCRIPT := link.ld

$(BUILD)/src/BATTLE/INITBTL.PRG/%.c.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/BATTLE/INITBTL.PRG/%.c.o: CC1VER := 2.8.1-psx

$(BUILD)/src/BATTLE/INITBTL.PRG/18.c.o: CC1FLAGS += -Wno-uninitialized
$(BUILD)/src/BATTLE/INITBTL.PRG/FB0.c.o: CC1VER := 2.7.2-cdk
