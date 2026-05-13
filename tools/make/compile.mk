# Use `=` not `?=`: GNU make has a builtin `CPP = $(CC) -E` that would otherwise win
# over `?=`, silently routing C preprocessing through the host C compiler instead of
# the cross preprocessor — which breaks matching codegen.
CPP       = $(ARCH)cpp
DEPCPP    = $(CPP)
CC1VER   ?= 2.7.2-psx
CC1      ?= tools/old-gcc/build-gcc-$(CC1VER)/cc1
MAS       = $(VPYTHON) tools/maspsx/maspsx.py
VSSTRING  = $(VPYTHON) tools/etc/vsStringTransformer.py

# -D_LANGUAGE_C: the PSY-Q SDK convention is for the gcc *driver* to inject this when
# compiling C TUs, so that include/psx/asm.h skips its MIPS register-name macros
# (fp=$30, s3=$19, etc.). We invoke cpp directly (bypassing the driver), so we have to
# define it ourselves; otherwise cpp expands every occurrence of those names in both
# the SDK headers (e.g. libcd.h `CdSearchFile(CdlFILE *fp, …)`) and the decomp's own
# variables (e.g. 25AC.c `s3 = arg0;`), and cc1 segfaults on the resulting `$NN`.
CPPFLAGS  = -nostdinc -I include/psx -I src/include -I ./ -D "__attribute__(x)=" -D_LANGUAGE_C
CC1FLAGS ?= -G0 -O2 -Wall -quiet -fno-builtin -funsigned-char -Wno-unused
MASFLAGS ?= --aspsx-version=2.77 --macro-inc

PREPROCESS.c = $(CPP) $(CPPFLAGS) $<
COMPILE.c    = $(PREPROCESS.c) | $(VSSTRING) | $(CC1) $(CC1FLAGS) | $(MAS) $(MASFLAGS) | $(COMPILE.s)

$(BUILD)/%.o: %.c
	$(ECHO) Compiling $<
	$(COMPILE.c) $(OUTPUT_OPTION)

# Dependency files via host cpp's -M -MG. -MG treats missing headers (e.g.
# build/assets/*.h, build/src/include/lbas.h, build/.../charInit.h) as generated
# prerequisites instead of failing, so parallel make waits for them. -w silences
# the modern-cpp diagnostics that the SDK headers (e.g. (null) struct warnings)
# trigger; we only care about which files are #include'd.
$(BUILD)/%.d: %.c | $$(@D)/
	$(DEPCPP) $(CPPFLAGS) -M -MG -MF $@ -MT $(@:.d=.o) -w $< 2>/dev/null || \
	    : > $@
