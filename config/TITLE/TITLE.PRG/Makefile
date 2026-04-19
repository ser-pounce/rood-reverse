$(BUILD)/src/TITLE/TITLE.PRG/22C.o: CPPFLAGS += -D MENUBGSZ=$(strip \
	$(shell $(SIZE) $(BUILD)/assets/TITLE/TITLE.PRG/_titleScreenBg.rgba16Compressed.img.o | cut -f2 | tail -n 1)\
)
$(BUILD)/src/TITLE/TITLE.PRG/22C.o: CC1FLAGS += -Wno-uninitialized
$(addprefix $(BUILD)/src/TITLE/TITLE.PRG/, 22C.o): ASFLAGS += -no-pad-sections
$(addprefix $(BUILD)/src/TITLE/TITLE.PRG/, 22C.o): CC1VER := 2.8.1-psx

$(BUILD)/config/TITLE/TITLE.PRG/link.d: \
	config/SLUS_010.40/symbol_addrs.txt

$(BUILD)/src/TITLE/TITLE.PRG/22C.o: $(BUILD)/src/include/lbas.h $(BUILD)/assets/MENU/MCMAN.BIN.h \
	$(addprefix $(BUILD)/assets/TITLE/TITLE.PRG/, \
		_titleScreenBg.rgba16Compressed.img.o \
		$(addsuffix .img.dat, publisher.rgbClut developer.rgbClut))
