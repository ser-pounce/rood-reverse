menu9_LDLIBS := $(patsubst %,$(BUILD)/data/%.elf,SLUS_010.40 BATTLE/BATTLE.PRG MENU/MAINMENU.PRG)

$(BUILD)/data/MENU/MENUB.PRG: $(menu9_LDLIBS)
$(BUILD)/data/MENU/MENUB.PRG: LDLIBS += $(menu9_LDLIBS)
$(BUILD)/data/MENU/MENUB.PRG: LDFLAGS += \
	--defsym=D_1F800000=0x1F800000

$(BUILD)/data/MENU/MENUB.PRG.elf: LDFLAGS += \
	--retain-symbols-file=config/MENU/MENUB.PRG/exports.txt

$(BUILD)/src/MENU/MENUB.PRG/%.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/MENU/MENUB.PRG/%.o: CC1VER := 2.8.1-psx
$(BUILD)/src/MENU/MENUB.PRG/260.o: CC1FLAGS += -Wno-char-subscripts
