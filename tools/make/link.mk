LD        = $(ARCH)ld
LDSCRIPT ?= link.ld undefined_funcs_auto.txt undefined_syms_auto.txt
LDFLAGS   = -nostdlib --build-id=none --noinhibit-exe --error-handling-script=tools/etc/ldUndefined.sh -L $(BUILD)/config/$* $(LDSCRIPT:%=-T %)

$(BINTARGETS:=.sym.elf) $(BINTARGETS:=.elf): private OUTPUT_OPTION += 3>&1 2>/dev/null

$(BINTARGETS:=.sym.elf): private LDFLAGS += --unresolved-symbols=ignore-all
$(BINTARGETS:=.sym.elf): private OBJCOPYFLAGS = --localize-hidden
$(BINTARGETS:=.sym.elf): $(BUILD)/data/%.sym.elf: | $$(@D)/
	$(ECHO) Linking $@
	$(LD) $(LDFLAGS) $(OUTPUT_OPTION)
	$(OBJCOPY) $(OBJCOPYFLAGS) $@
	$(OBJCOPY) --discard-all $@

$(BINTARGETS:=.elf): private LDFLAGS += -e 0x0 $(addprefix -R,$(LDLIBS))
$(BINTARGETS:=.elf): $(BUILD)/data/%.elf: $(BUILD)/data/%.sym.elf
	$(ECHO) Linking $@
	$(LD) $(LDFLAGS) $(OUTPUT_OPTION)

$(BINTARGETS): private OBJCOPYFLAGS = -O binary
$(BINTARGETS): %: %.elf
	$(ECHO) Converting $@
	$(OBJCOPY) $(OBJCOPYFLAGS) $< $@
	$(FIXUP)
