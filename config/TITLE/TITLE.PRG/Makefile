$(BUILD)/data/TITLE/TITLE.PRG.elf: LDSCRIPT += \
	config/SLUS_010.40/exports.txt

$(BUILD)/src/TITLE/TITLE.PRG/22C.o: CPPFLAGS += -D MENUBGSZ=$(strip \
	$(shell $(SIZE) $(BUILD)/assets/TITLE/TITLE.PRG/menuBg.rgba16Compressed.o | cut -f2 | tail -n 1)\
)
$(BUILD)/src/TITLE/TITLE.PRG/22C.o: CC1FLAGS += -Wno-uninitialized
$(BUILD)/src/TITLE/TITLE.PRG/22C.o: ASFLAGS += -no-pad-sections
$(BUILD)/src/TITLE/TITLE.PRG/22C.o: CC1VER := 2.8.0
$(BUILD)/src/TITLE/TITLE.PRG/22C.o: $(BUILD)/src/include/lbas.h \
	$(BUILD)/assets/TITLE/TITLE.PRG/menuBg.rgba16Compressed.o

%.rgba16Compressed.bin: %.rgba16Compressed.png
	$(call builder,Converting $<)
	@$(VPYTHON) -m tools.splat_ext.rgba16Compressed $< $@
%.rgba16Compressed.o: %.rgba16Compressed.bin
	$(call builder,Converting $<)
	@$(OBJCOPY) $(OBJCOPYFLAGS) \
	--add-symbol _menuBg=.data:0 $< $@
	
%.rgb4.bin: %.rgb4.png
	$(call builder,Converting $<)
	@$(VPYTHON) -m tools.splat_ext.rgb4 $< $@
%.rgb4.o: %.rgb4.bin
	$(call builder,Converting $<)
	@$(OBJCOPY) $(OBJCOPYFLAGS) $< $@

$(BUILD)/assets/TITLE/TITLE.PRG/%.rgba16.bin: rgbflags += noheader
