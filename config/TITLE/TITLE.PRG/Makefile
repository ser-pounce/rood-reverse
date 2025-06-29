$(BUILD)/data/TITLE/TITLE.PRG.elf: LDSCRIPT += \
	config/SLUS_010.40/exports.txt

$(BUILD)/src/TITLE/TITLE.PRG/22C.o: CPPFLAGS += -D MENUBGSZ=$(strip \
	$(shell $(SIZE) $(BUILD)/assets/TITLE/TITLE.PRG/_titleScreenBg.rgba16Compressed.segment.o | cut -f2 | tail -n 1)\
)
$(BUILD)/src/TITLE/TITLE.PRG/22C.o: CC1FLAGS += -Wno-uninitialized
$(addprefix $(BUILD)/src/TITLE/TITLE.PRG/, 22C.o sfx.o libpress/LIBPRESS.o): ASFLAGS += -no-pad-sections
$(addprefix $(BUILD)/src/TITLE/TITLE.PRG/, 22C.o sfx.o): CC1VER := 2.8.0
$(BUILD)/src/TITLE/TITLE.PRG/22C.o: $(BUILD)/src/include/lbas.h $(BUILD)/src/include/mcman.h \
	$(BUILD)/assets/TITLE/TITLE.PRG/_titleScreenBg.rgba16Compressed.segment.o

