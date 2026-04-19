%.img.o: export OBJCOPY := $(OBJCOPY)
%.img.o: export OBJCOPYFLAGS := $(OBJCOPYFLAGS)
%.img.o: %.img.png | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.splat_ext.$(word 2,$(subst ., ,$(@F))) $< $@

%.img.dat: %.img.png | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.splat_ext.$(word 2,$(subst ., ,$(@F))) $< $@ --dat
