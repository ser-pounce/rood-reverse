menuE_LDLIBS := $(patsubst %,$(BUILD)/data/%.elf,SLUS_010.40 BATTLE/BATTLE.PRG MENU/MAINMENU.PRG)

$(BUILD)/data/MENU/MENUE.PRG: $(menuE_LDLIBS)
$(BUILD)/data/MENU/MENUE.PRG: LDLIBS += $(menuE_LDLIBS)
$(BUILD)/data/MENU/MENUE.PRG: LDFLAGS += \
	--defsym=D_1F800000=0x1F800000
$(BUILD)/data/MENU/MENUE.PRG $(BUILD)/data/MENU/MENUE.PRG.elf: LDSCRIPT := link.ld

$(BUILD)/data/MENU/MENUE.PRG.elf: LDFLAGS += \
	--retain-symbols-file=config/MENU/MENUE.PRG/exports.txt

$(BUILD)/src/MENU/MENUE.PRG/494.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/MENU/MENUE.PRG/494.o: CC1VER := 2.8.1-psx
