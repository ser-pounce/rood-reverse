menu4_LDLIBS := $(patsubst %,$(BUILD)/data/%.elf,SLUS_010.40 BATTLE/BATTLE.PRG MENU/MAINMENU.PRG)

$(BUILD)/data/MENU/MENU4.PRG: $(menu4_LDLIBS)
$(BUILD)/data/MENU/MENU4.PRG: LDLIBS += $(menu4_LDLIBS)
$(BUILD)/data/MENU/MENU4.PRG: LDFLAGS += \
	--defsym=D_1F800000=0x1F800000
$(BUILD)/data/MENU/MENU4.PRG $(BUILD)/data/MENU/MENU4.PRG.elf: LDSCRIPT := link.ld

$(BUILD)/data/MENU/MENU4.PRG.elf: LDFLAGS += \
	--retain-symbols-file=config/MENU/MENU4.PRG/exports.txt

$(BUILD)/src/MENU/MENU4.PRG/%.o: ASFLAGS += \
	-no-pad-sections
$(BUILD)/src/MENU/MENU4.PRG/%.o: CC1VER := 2.8.1-psx
$(BUILD)/src/MENU/MENU4.PRG/%.o: CC1FLAGS += -Wno-uninitialized
