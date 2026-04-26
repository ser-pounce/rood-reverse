AS       = $(ARCH)as
ASFLAGS  = -I include -G0

# Splitted asm
%.o: %.s | $$(@D)/
	$(ECHO) Assembling $<
	$(COMPILE.s) -no-pad-sections --MD $(@:.o=.d) $(OUTPUT_OPTION) $<

# Hasm in src folder
$(BUILD)/%.o: %.s | $$(@D)/
	$(ECHO) Assembling $<
	$(COMPILE.s) --MD $(@:.o=.d) $(OUTPUT_OPTION) $<
