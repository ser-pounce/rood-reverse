$(BUILD)/src/BATTLE/INITBTL.PRG/%.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/BATTLE/INITBTL.PRG/%.o: CC1VER := 2.8.1-psx
$(BUILD)/src/BATTLE/INITBTL.PRG/18.o: $(BUILD)/src/include/lbas.h

$(BUILD)/src/BATTLE/INITBTL.PRG/FB0.o: CC1VER := 2.7.2-cdk

$(BUILD)/data/BATTLE/INITBTL.PRG.linked.elf: LDFLAGS += \
	--defsym=_camera=0x1F800000

$(BUILD)/config/BATTLE/INITBTL.PRG/link.d: \
	config/SLUS_010.40/symbol_addrs.txt \
	config/BATTLE/BATTLE.PRG/symbol_addrs.txt
