AS       = $(ARCH)as
ASFLAGS  = -I include --MD $(@:.o=.d) -G0

# Splitted asm
%.o: %.s | $$(@D)/
	$(ECHO) Assembling $<
	$(COMPILE.s) -no-pad-sections $(OUTPUT_OPTION) $<

# Hasm in src folder
$(BUILD)/%.o: %.s | $$(@D)/
	$(ECHO) Assembling $<
	$(COMPILE.s) $(OUTPUT_OPTION) $<
