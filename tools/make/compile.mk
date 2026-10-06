CC1VER    ?= 2.7.2-psx
CC1       ?= tools/old-gcc/$(CC1VER)/cc1
MAS       ?= $(VPYTHON) tools/maspsx/maspsx.py
VSSTRING  ?= $(VPYTHON) -m tools.etc.vsStringTransformer

# Sony's PsyQ library objects were assembled by GNU as in reorder mode (the assembler fills
# j/jr/jal delay slots with the preceding instruction, including the tail of a lui/sw macro),
# not by ASPSX. Feed cc1 output straight to as; only `move` must keep the old addu encoding.
# libsn/SNMAIN is SN Systems hand-written asm and keeps the ASPSX (maspsx) path.
PSQ_PATCH ?= $(SED) -E -e '1i .include "macro.inc"' -e 's/^\tmove\t([^,]+),(.+)$$/\taddu\t\1,\2,$$0/'

CPPFLAGS ?= -nostdinc -I include/psx -I src/include -I ./ -D "__attribute__(x)=" -D_LANGUAGE_C
CC1FLAGS ?= -G0 -O2 -Wall -quiet -fno-builtin -funsigned-char -Wno-unused
MASFLAGS ?= --aspsx-version=2.77 --macro-inc

PREPROCESS.c = $(CPP) $(CPPFLAGS) $<
PREPROCESS.s = $(MAS) $(MASFLAGS)
COMPILE.c    = $(PREPROCESS.c) | $(VSSTRING) | $(CC1) $(CC1FLAGS) | $(PREPROCESS.s) | $(COMPILE.s)

$(BUILD)/%.c.o: %.c
	$(ECHO) Compiling $<
	$(COMPILE.c) $(OUTPUT_OPTION)

$(BUILD)/%.c.d: CPPFLAGS += -M -MF $@ -MT $(@:.d=.o) -MG
$(BUILD)/%.c.d: %.c | $$(@D)/
	$(PREPROCESS.c) $(OUTPUT_OPTION)
