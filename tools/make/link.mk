LD        = $(ARCH)ld
BCONFIG   = $(patsubst $(BUILD)/data/%,$(BUILD)/config/%,$(@:.elf=))
LDSCRIPT ?= link.ld undefined_funcs_auto.txt undefined_syms_auto.txt
LDFLAGS   = -nostdlib --build-id=none -L $(BCONFIG) $(LDSCRIPT:%=-T %)

$(BINTARGETS) $(BINTARGETS:=.elf):
	$(ECHO) Linking $@
	$(LD) $(LDFLAGS) $(OUTPUT_OPTION)
	$(FIXUP)

$(BINTARGETS): private LDFLAGS += --oformat=binary -e 0x0 $(addprefix -R,$(LDLIBS))
$(BINTARGETS): $(BUILD)/data/%: $(BUILD)/data/%.elf

$(BINTARGETS:=.elf): private LDFLAGS += --unresolved-symbols=ignore-all
$(BINTARGETS:=.elf): | $$(@D)/
