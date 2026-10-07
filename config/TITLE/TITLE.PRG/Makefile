$(BUILD)/data/TITLE/TITLE.PRG: $(BUILD)/data/SLUS_010.40.elf
$(BUILD)/data/TITLE/TITLE.PRG: private LDLIBS += $(BUILD)/data/SLUS_010.40.elf
$(BUILD)/data/TITLE/TITLE.PRG $(BUILD)/data/TITLE/TITLE.PRG.elf: private LDSCRIPT := link.ld

$(BUILD)/src/TITLE/TITLE.PRG/22C.c.o: CPPFLAGS += -D MENUBGSZ=$(strip \
	$(shell $(SIZE) $(BUILD)/assets/TITLE/TITLE.PRG/_titleScreenBg.rleRgb555.img.png.o | cut -f2 | tail -n 1)\
)
$(BUILD)/src/TITLE/TITLE.PRG/22C.c.o: CC1FLAGS += -Wno-uninitialized
$(BUILD)/src/TITLE/TITLE.PRG/22C.c.o $(BUILD)/src/TITLE/TITLE.PRG/titleData.c.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/TITLE/TITLE.PRG/22C.c.o: CC1VER := 2.8.1-psx

$(BUILD)/config/TITLE/TITLE.PRG/link.d: \
	config/SLUS_010.40/symbol_addrs.txt

$(BUILD)/src/TITLE/TITLE.PRG/22C.c.o: $(BUILD)/assets/TITLE/TITLE.PRG/_titleScreenBg.rleRgb555.img.png.o

$(BUILD)/src/TITLE/TITLE.PRG/libpress/%.c.o: PREPROCESS.s = $(PSQ_PATCH)
