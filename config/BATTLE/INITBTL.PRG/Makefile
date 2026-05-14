$(BUILD)/src/BATTLE/INITBTL.PRG/%.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/BATTLE/INITBTL.PRG/%.o: CC1VER := 2.8.1-psx

$(BUILD)/src/BATTLE/INITBTL.PRG/18.o: CC1FLAGS += -Wno-uninitialized
$(BUILD)/src/BATTLE/INITBTL.PRG/FB0.o: CC1VER := 2.7.2-cdk

$(BUILD)/data/BATTLE/INITBTL.PRG: LDFLAGS += \
	--defsym=_camera=0x1F800000

$(BUILD)/config/BATTLE/INITBTL.PRG/link.d: \
	config/SLUS_010.40/symbol_addrs.txt \
	config/BATTLE/BATTLE.PRG/symbol_addrs.txt

$(BUILD)/assets/BATTLE/INITBTL.PRG/charInit.h: $(BUILD)/assets/BATTLE/INITBTL.PRG/charInit.yaml | $$(@D)/
	$(ECHO) Encoding struct $@
	$(VPYTHON) -m tools.dev.encodeStruct $< $@ \
		--header src/BATTLE/BATTLE.PRG/146C.h \
		--compiler mipsel-linux-gnu-gcc \
		--include include/psx/ \
		--struct vs_battle_charInitData

$(BUILD)/assets/BATTLE/INITBTL.PRG/charInit.yaml: | $$(@D)/
	$(ECHO) Dumping struct $@
	$(VPYTHON) -m tools.dev.dumpStruct data/BATTLE/INITBTL.PRG 0x1318 $@ \
		--header src/BATTLE/BATTLE.PRG/146C.h \
		--compiler mipsel-linux-gnu-gcc \
		--include include/psx/ \
		--struct vs_battle_charInitData

PYTHONDEPS += cffi
