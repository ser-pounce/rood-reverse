menuF_LDLIBS := $(patsubst %,$(BUILD)/data/%.elf,SLUS_010.40 BATTLE/BATTLE.PRG MENU/MAINMENU.PRG)

$(BUILD)/data/MENU/MENUF.PRG: $(menuF_LDLIBS)
$(BUILD)/data/MENU/MENUF.PRG: LDLIBS += $(menuF_LDLIBS)
$(BUILD)/data/MENU/MENUF.PRG: LDFLAGS += \
	--defsym=D_1F800000=0x1F800000
$(BUILD)/data/MENU/MENUF.PRG $(BUILD)/data/MENU/MENUF.PRG.elf: LDSCRIPT := link.ld

$(BUILD)/data/MENU/MENUF.PRG.elf: LDFLAGS += \
	--retain-symbols-file=config/MENU/MENUF.PRG/exports.txt

$(BUILD)/src/MENU/MENUF.PRG/%.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/MENU/MENUF.PRG/%.o: CC1VER := 2.8.1-psx
$(BUILD)/src/MENU/MENUF.PRG/%.o: CC1FLAGS += -Wno-uninitialized

