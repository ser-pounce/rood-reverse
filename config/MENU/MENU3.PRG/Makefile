menu3_LDLIBS := $(patsubst %,$(BUILD)/data/%.elf,SLUS_010.40 BATTLE/BATTLE.PRG MENU/MAINMENU.PRG)

$(BUILD)/data/MENU/MENU3.PRG: $(menu3_LDLIBS)
$(BUILD)/data/MENU/MENU3.PRG: LDLIBS += $(menu3_LDLIBS)

$(BUILD)/data/MENU/MENU3.PRG: LDFLAGS += \
	--defsym=D_1F800000=0x1F800000

$(BUILD)/data/MENU/MENU3.PRG.elf: LDFLAGS += -r \
	--retain-symbols-file=config/MENU/MENU3.PRG/exports.txt

$(BUILD)/data/MENU/MENU3.PRG $(BUILD)/data/MENU/MENU3.PRG.elf: LDSCRIPT := link.ld

$(BUILD)/src/MENU/MENU3.PRG/%.o: ASFLAGS += \
	-no-pad-sections
$(BUILD)/src/MENU/MENU3.PRG/16C.o:  CC1VER := 2.8.1-psx
$(BUILD)/src/MENU/MENU3.PRG/68C4.o: CC1VER := 2.7.2-cdk
