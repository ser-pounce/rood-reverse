build/data/SLUS_010.40.elf: LDSCRIPT += \
	config/TITLE/TITLE.PRG/exports.txt \
	config/BATTLE/BATTLE.PRG/exports.txt

build/data/SLUS_010.40.elf: build/assets/SLUS_010.40/_nowLoading.rgba16.bin

build/src/SLUS_010.40/main.o: CC1FLAGS += -Wno-return-type
build/src/SLUS_010.40/main.o: build/src/include/lbas.h

$(patsubst %,build/src/SLUS_010.40/%.o, \
	2MBYTE.OBJ overlay 25AC 31724 32154 main \
	$(addprefix libgte/, \
		MTX_005 REG13 REG12 REG11 MTX_12 MTX_09 MTX_004 \
		MTX_06 MTX_05 SMP_05 SMP_04 SMP_02 CMB_02 MTX_07 CMB_00 \
	) \
): ASFLAGS += -no-pad-sections

$(patsubst %,build/src/SLUS_010.40/%.o,2MBYTE.OBJ overlay 25AC main): CC1VER := 2.8.0
