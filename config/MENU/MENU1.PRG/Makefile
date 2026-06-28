menu1_LDLIBS := $(patsubst %,$(BUILD)/data/%.elf,SLUS_010.40 BATTLE/BATTLE.PRG MENU/MAINMENU.PRG)

$(BUILD)/data/MENU/MENU1.PRG: $(menu1_LDLIBS)
$(BUILD)/data/MENU/MENU1.PRG: LDLIBS += $(menu1_LDLIBS)

$(BUILD)/data/MENU/MENU1.PRG.elf: LDFLAGS += -r \
	--retain-symbols-file=config/MENU/MENU1.PRG/exports.txt

$(BUILD)/data/MENU/MENU1.PRG $(BUILD)/data/MENU/MENU1.PRG.elf: LDSCRIPT := link.ld

$(BUILD)/src/MENU/MENU1.PRG/%.o: ASFLAGS += \
	-no-pad-sections
$(BUILD)/src/MENU/MENU1.PRG/%.o: CC1VER := 2.8.1-psx
