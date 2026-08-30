CPP       = $(ARCH)cpp
CC1VER   ?= 2.7.2-psx
CC1      ?= tools/old-gcc/$(CC1VER)/cc1
MAS       = $(VPYTHON) tools/maspsx/maspsx.py
VSSTRING  = $(VPYTHON) -m tools.etc.vsStringTransformer

CPPFLAGS  = -nostdinc -I include/psx -I src/include -I ./ -D "__attribute__(x)="
CC1FLAGS ?= -G0 -O2 -Wall -quiet -fno-builtin -funsigned-char -Wno-unused
MASFLAGS ?= --aspsx-version=2.77 --macro-inc

PREPROCESS.c = $(CPP) $(CPPFLAGS) $<
COMPILE.c    = $(PREPROCESS.c) | $(VSSTRING) | $(CC1) $(CC1FLAGS) | $(MAS) $(MASFLAGS) | $(COMPILE.s)

$(BUILD)/%.o: %.c
	$(ECHO) Compiling $<
	$(COMPILE.c) $(OUTPUT_OPTION)

$(BUILD)/%.d: CPPFLAGS += -M -MF $@ -MT $(@:.d=.o) -MG
$(BUILD)/%.d: %.c | $$(@D)/
	$(PREPROCESS.c) $(OUTPUT_OPTION)
