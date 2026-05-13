CPP       = $(ARCH)cpp
DEPCPP    = $(CPP)
CC1VER   ?= 2.7.2-psx
CC1      ?= tools/old-gcc/build-gcc-$(CC1VER)/cc1
MAS       = $(VPYTHON) tools/maspsx/maspsx.py
VSSTRING  = $(VPYTHON) tools/etc/vsStringTransformer.py

CPPFLAGS  = -nostdinc -I include/psx -I src/include -I ./ -D "__attribute__(x)=" -D_LANGUAGE_C
CC1FLAGS ?= -G0 -O2 -Wall -quiet -fno-builtin -funsigned-char -Wno-unused
MASFLAGS ?= --aspsx-version=2.77 --macro-inc

PREPROCESS.c = $(CPP) $(CPPFLAGS) $<
COMPILE.c    = $(PREPROCESS.c) | $(VSSTRING) | $(CC1) $(CC1FLAGS) | $(MAS) $(MASFLAGS) | $(COMPILE.s)

$(BUILD)/%.o: %.c
	$(ECHO) Compiling $<
	$(COMPILE.c) $(OUTPUT_OPTION)

$(BUILD)/%.d: %.c | $$(@D)/
	$(DEPCPP) $(CPPFLAGS) -M -MG -MF $@ -MT $(@:.d=.o) -w $< 2>/dev/null || \
	    : > $@
