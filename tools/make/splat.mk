SPLAT       = $(VPYTHON) -m splat
SPLATFLAGS ?= split --disassemble-all

PYTHONDEPS += splat64[mips]

$(BUILD)/config/%/link.d: config/%/splat.yaml config/%/symbol_addrs.txt config/%/Makefile | $$(@D)/
	$(ECHO) Splitting $*
	$(SPLAT) $(SPLATFLAGS) config/splat.config.yaml $< $(if $(DEBUG),,> $(BUILD)/config/$*/splat.log 2> /dev/null)
	$(TOUCH) $@

