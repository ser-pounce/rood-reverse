.PRECIOUS: %.img.bin %.img.dat %.img.sym

%.img.bin %.img.dat %.img.sym &: %.img.png | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.splat_ext.$(word 2,$(subst ., ,$(@F))) $< $(@D)/$(*F).img.bin

%.img.o: %.img.bin %.img.sym | $$(@D)/
	$(ECHO) Assembling $@
	symbol_args=$$(awk '{ printf "--add-symbol %s=.data:%s ", $$1, $$2 }' $*.img.sym); $(OBJCOPY) $(OBJCOPYFLAGS) $$symbol_args $< $@
