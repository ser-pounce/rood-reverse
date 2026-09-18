SPLAT      ?= $(VPYTHON) -m splat
SPLATFLAGS ?= split --disassemble-all

PYTHONDEPS += splat64[mips]

$(BUILD)/config/%/link.d: $$(wildcard $(addprefix config/%/,splat.yaml Makefile symbol_addrs.txt)) | $$(@D)/
	$(ECHO) Splitting $*
	$(SPLAT) $(SPLATFLAGS) config/splat.config.yaml $< $(if $(DEBUG),,> $(BUILD)/config/$*/splat.log 2> /dev/null)
