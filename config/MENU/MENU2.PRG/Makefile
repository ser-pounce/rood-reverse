menu2_LDLIBS := $(patsubst %,$(BUILD)/data/%.elf,SLUS_010.40 BATTLE/BATTLE.PRG MENU/MAINMENU.PRG)

$(BUILD)/data/MENU/MENU2.PRG: $(menu2_LDLIBS)
$(BUILD)/data/MENU/MENU2.PRG: LDLIBS += $(menu2_LDLIBS)

$(BUILD)/data/MENU/MENU2.PRG: LDFLAGS += \
	--defsym=D_1F800000=0x1F800000

$(BUILD)/data/MENU/MENU2.PRG.elf: LDFLAGS += -r \
	--retain-symbols-file=config/MENU/MENU2.PRG/exports.txt

$(BUILD)/data/MENU/MENU2.PRG $(BUILD)/data/MENU/MENU2.PRG.elf: LDSCRIPT := link.ld

$(BUILD)/src/MENU/MENU2.PRG/%.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/MENU/MENU2.PRG/%.o: CC1VER := 2.8.1-psx
