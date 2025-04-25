build/data/SLUS_010.40.elf: LDSCRIPT += \
	config/TITLE/TITLE.PRG/exports.txt \
	config/BATTLE/BATTLE.PRG/exports.txt

build/data/SLUS_010.40.elf: build/assets/SLUS_010.40/_nowLoading.rgba16.bin

build/src/SLUS_010.40/3264C.o: CC1FLAGS += -Wno-return-type
build/src/SLUS_010.40/3264C.o: build/src/include/lbas.h

$(patsubst %,build/src/SLUS_010.40/%.o, \
	overlay 25AC 31724 32154 3264C \
	$(addprefix libgte/, \
		MTX_005 REG13 REG12 REG11 MTX_12 MTX_09 MTX_004 \
		MTX_06 MTX_05 SMP_05 SMP_04 SMP_02 CMB_02 MTX_07 CMB_00 \
	) \
): ASFLAGS += -no-pad-sections

$(patsubst %,build/src/SLUS_010.40/%.o,overlay 25AC 3264C): CC1VER := 2.8.0
