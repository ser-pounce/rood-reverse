$(BUILD)/data/BATTLE/BATTLE.PRG.elf: LDFLAGS += \
	--defsym=func_80043D50=0x80043D50 \
	--defsym=func_80043C60=0x80043C60 \
	--defsym=D_80033AF4=0x80030480

$(BUILD)/data/BATTLE/BATTLE.PRG.elf: LDSCRIPT += \
	config/SLUS_010.40/exports.txt

$(BUILD)/src/BATTLE/BATTLE.PRG/%.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/BATTLE/BATTLE.PRG/%.o: CC1VER := 2.8.0-psx

$(addprefix $(BUILD)/src/BATTLE/BATTLE.PRG/, 573B8.o 5BF94.o menuLbas.o gimLbas.o): \
	$(BUILD)/src/include/lbas.h
