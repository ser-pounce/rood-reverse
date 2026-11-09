LD        = $(ARCH)ld
LDSCRIPT ?= link.ld undefined_funcs_auto.txt undefined_syms_auto.txt
LDFLAGS   = -nostdlib --build-id=none --noinhibit-exe -L $(BUILD)/config/$* $(LDSCRIPT:%=-T %)

$(BINTARGETS:=.elf): private OUTPUT_OPTION += 3>&1 2>/dev/null
$(BINTARGETS:=.elf): private LDFLAGS += -e 0x0 $(addprefix -R,$(LDLIBS)) --error-handling-script=tools/etc/ldUndefined.sh
$(BINTARGETS:=.elf): $(BUILD)/data/%.elf: $(BUILD)/data/%.sym.elf
	$(ECHO) Linking $@
	$(LD) $(LDFLAGS) $(OUTPUT_OPTION)

$(BINTARGETS): %: %.elf
	$(ECHO) Converting $@
	$(OBJCOPY) -O binary $< $@
	$(FIXUP)

$(BINTARGETS:=.sym.elf): private OUTPUT_OPTION += 2>/dev/null
$(BINTARGETS:=.sym.elf): private LDFLAGS += --unresolved-symbols=ignore-all
$(BINTARGETS:=.sym.elf): $(BUILD)/data/%.sym.elf: | $$(@D)/
	$(ECHO) Linking $@
	$(LD) $(LDFLAGS) $(OUTPUT_OPTION)
