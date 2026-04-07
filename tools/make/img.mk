%.img.o: filename = $(word 1,$(subst ., ,$(@F)))
%.img.o: OBJCOPYFLAGS += --add-symbol $(filename)=.data:0
%.img.o: %.img.bin | $$(@D)/
	$(ECHO) Converting $<
	$(OBJCOPY) $(OBJCOPYFLAGS) $< $@

.PRECIOUS: %.img.bin
%.img.bin: %.img.png | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.splat_ext.$(word 2,$(subst ., ,$(@F))) $< $@

%.rgba16Header.img.o: OBJCOPYFLAGS += \
	--add-symbol $(filename)_header=.data:0 \
	--add-symbol $(filename)_data=.data:4
