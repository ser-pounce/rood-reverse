KSC      ?= ksc
KSCFLAGS ?= -t python -I tools/kaitai/ksy/lib

KAITAI_KSY     != $(FIND) tools/kaitai/ksy -type f -name *.ksy
KAITAI_PARSERS := $(KAITAI_KSY:tools/kaitai/ksy/%.ksy=tools/kaitai/parsers/%.py)

.PHONY: kaitai

SKIPSPLAT += kaitai

kaitai: $(KAITAI_PARSERS)

$(KAITAI_PARSERS): tools/kaitai/parsers/%.py: tools/kaitai/ksy/%.ksy | $$(@D)/
	$(ECHO) Generating parser for $*
	$(KSC) $(KSCFLAGS) --python-package $(subst /,.,$(@D:%.py=%)) $< --outdir $(@D)
