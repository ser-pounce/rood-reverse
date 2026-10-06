AS       = $(ARCH)as
ASFLAGS  ?= -I include -G0

# Splitted asm
%.s.o: %.s | $$(@D)/
	$(ECHO) Assembling $<
	$(COMPILE.s) -no-pad-sections --MD $(@:.o=.d) $(OUTPUT_OPTION) $<

# Hasm in src folder
$(BUILD)/%.s.o: %.s | $$(@D)/
	$(ECHO) Assembling $<
	$(COMPILE.s) --MD $(@:.o=.d) $(OUTPUT_OPTION) $<
