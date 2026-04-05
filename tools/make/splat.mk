SPLAT       = $(VPYTHON) -m splat
SPLATFLAGS := split --disassemble-all



PYTHONDEPS += splat64[mips]

ifndef PERMUTER
ifndef __BASH_MAKE_COMPLETION__
$(BUILD)/config/%/link.d: config/%/splat.yaml config/%/symbol_addrs.txt config/%/Makefile | $$(if $$(wildcard $$(DISKCONFIG)),,$$(DISKCONFIG)) $$(@D)/
	$(ECHO) Splitting $*
	$(SPLAT) $(SPLATFLAGS) config/splat.config.yaml $< $(if $(DEBUG),,> $(BUILD)/config/$*/splat.log 2> /dev/null)
	$(O_DEPS) $@ >> $@
endif
endif
