menu5_LDLIBS := $(patsubst %,$(BUILD)/data/%.elf,SLUS_010.40 BATTLE/BATTLE.PRG MENU/MAINMENU.PRG)

$(BUILD)/data/MENU/MENU5.PRG: $(menu5_LDLIBS)
$(BUILD)/data/MENU/MENU5.PRG: LDLIBS += $(menu5_LDLIBS)
$(BUILD)/data/MENU/MENU5.PRG: LDFLAGS += \
	--defsym=D_1F800000=0x1F800000

$(BUILD)/data/MENU/MENU5.PRG.elf: LDFLAGS += \
	--retain-symbols-file=config/MENU/MENU5.PRG/exports.txt

$(BUILD)/data/MENU/MENU5.PRG $(BUILD)/data/MENU/MENU5.PRG.elf: LDSCRIPT := link.ld

$(BUILD)/src/MENU/MENU5.PRG/%.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/MENU/MENU5.PRG/%.o: CC1VER := 2.8.1-psx
