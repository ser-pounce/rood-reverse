build/data/SLUS_010.40.elf: LDSCRIPT += \
	config/TITLE/TITLE.PRG/exports.txt \
	config/BATTLE/BATTLE.PRG/exports.txt

build/data/SLUS_010.40.elf: $(addprefix build/assets/SLUS_010.40/, _nowLoading.rgba16.o _soundFileMap.o _skillData.o _animData.o)

build/src/SLUS_010.40/main.o: CC1FLAGS += -Wno-return-type
build/src/SLUS_010.40/main.o build/src/SLUS_010.40/audioLBAs.o: build/src/include/lbas.h

%_soundFileMap.o: %_soundFileMap.bin
	$(call builder,Compiling $<)
	@$(OBJCOPY) $(OBJCOPYFLAGS) \
	--add-symbol _soundFileMap=.data:0 $< $@

%_skillData.o: %_skillData.bin
	$(call builder,Compiling $<)
	@$(OBJCOPY) $(OBJCOPYFLAGS) \
	--add-symbol _skillData=.data:0 $< $@

%_animData.o: %_animData.bin
	$(call builder,Compiling $<)
	@$(OBJCOPY) $(OBJCOPYFLAGS) \
	--set-section-alignment .data=4 \
	--add-symbol _animOffset16=.data:0 \
	--add-symbol _animOffset8=.data:1008 \
	--add-symbol _animOffset4=.data:1512 \
	--add-symbol _animOffset2=.data:1764 $< $@

%_soundFileMap.bin: %_soundFileMap.yaml
	$(call builder,Converting $<)
	@$(VPYTHON) -m tools.splat_ext.vsSoundFileMap $< $@

%_skillData.bin: %_skillData.yaml
	$(call builder,Converting $<)
	@$(VPYTHON) -m tools.splat_ext.vsSkillData $< $@

%_animData.bin: %_animData.yaml
	$(call builder,Converting $<)
	@$(VPYTHON) -m tools.splat_ext.vsAnimData $< $@

$(patsubst %,build/src/SLUS_010.40/%.o, \
	2MBYTE.OBJ overlay 25AC 31724 32154 main \
	$(addprefix libgte/, \
		MTX_005 REG13 REG12 REG11 MTX_12 MTX_09 MTX_004 \
		MTX_06 MTX_05 SMP_05 SMP_04 SMP_02 CMB_02 MTX_07 CMB_00 \
	) \
): ASFLAGS += -no-pad-sections

$(patsubst %,build/src/SLUS_010.40/%.o,2MBYTE.OBJ overlay 25AC main): CC1VER := 2.8.0
