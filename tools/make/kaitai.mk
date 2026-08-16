KSC      ?= ksc
KSCFLAGS ?= -t python -I tools/kaitai/ksy/lib --python-package tools.kaitai.parsers.lib

KAITAI_DATA_KSY     != $(FIND) tools/kaitai/ksy/data -type f -name *.ksy
KAITAI_LIB_KSY      != $(FIND) tools/kaitai/ksy/lib -type f -name *.ksy
KAITAI_DATA_PARSERS := $(KAITAI_DATA_KSY:tools/kaitai/ksy/%.ksy=tools/kaitai/parsers/%.py)
KAITAI_LIB_PARSERS  := $(KAITAI_LIB_KSY:tools/kaitai/ksy/%.ksy=tools/kaitai/parsers/%.py)
KAITAI_LIB_NAMES    := $(notdir $(KAITAI_LIB_PARSERS))
KAITAI_STALE_LIB    := $(foreach d,$(sort $(dir $(KAITAI_DATA_PARSERS))),$(addprefix $(d),$(KAITAI_LIB_NAMES)))

.PHONY: kaitai

SKIPSPLAT += kaitai

kaitai: $(KAITAI_DATA_PARSERS)
	$(RM) $(KAITAI_STALE_LIB)

$(KAITAI_DATA_PARSERS): $(KAITAI_LIB_PARSERS)

tools/kaitai/parsers/%.py: tools/kaitai/ksy/%.ksy | $$(@D)/
	$(ECHO) Generating parser for $*
	$(KSC) $(KSCFLAGS) $< --outdir $(@D)
