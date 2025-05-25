build/data/BATTLE/BATTLE.PRG.elf: LDFLAGS += \
	--defsym=func_80043D50=0x80043D50 \
	--defsym=func_80043C60=0x80043C60 \
	--defsym=D_80033AF4=0x80030480

build/data/BATTLE/BATTLE.PRG.elf: LDSCRIPT += \
	config/SLUS_010.40/exports.txt

build/src/BATTLE/BATTLE.PRG/%.o: ASFLAGS += -no-pad-sections
build/src/BATTLE/BATTLE.PRG/%.o: CC1VER := 2.8.0

$(addprefix build/src/BATTLE/BATTLE.PRG/, 573B8.o 5BF94.o): build/src/include/lbas.h
