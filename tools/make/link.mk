LD        = $(ARCH)ld
BCONFIG   = $(patsubst $(BUILD)/data/%,$(BUILD)/config/%,$(@:.elf=))
LDSCRIPT ?= link.ld undefined_funcs_auto.txt undefined_syms_auto.txt
LDFLAGS   = -nostdlib --build-id=none -L $(BCONFIG) $(LDSCRIPT:%=-T %)

$(BINTARGETS): private LDFLAGS += --oformat=binary -e 0x0 $(addprefix -R,$(LDLIBS))
$(BINTARGETS): $(BUILD)/data/%: $(BUILD)/data/%.elf

$(BINTARGETS):
	$(ECHO) Linking $@
	$(LD) $(LDFLAGS) $(OUTPUT_OPTION)
	$(FIXUP)

$(BINTARGETS:=.elf): private OUTPUT_OPTION += 2>/dev/null
$(BINTARGETS:=.elf): private LDFLAGS += --unresolved-symbols=ignore-all --noinhibit-exe
$(BINTARGETS:=.elf): | $$(@D)/

$(BINTARGETS:=.elf):
	$(ECHO) Linking $@
	$(LD) $(LDFLAGS) $(OUTPUT_OPTION)
	$(OBJCOPY) --strip-symbol=__romPos $@
