CPP       = $(ARCH)cpp
CC1VER   := 2.7.2-psx
CC1       = tools/old-gcc/build-gcc-$(CC1VER)/cc1
MAS       = $(VPYTHON) tools/maspsx/maspsx.py
VSSTRING  = $(VPYTHON) tools/etc/vsStringTransformer.py

CPPFLAGS  = -nostdinc -I include/psx -I src/include -I $(BUILD)/src/include \
            -MD -MF $@.d -MT $@ -D "__attribute__(x)="
CC1FLAGS := -G0 -O2 -Wall -quiet -fno-builtin -funsigned-char -Wno-unused
MASFLAGS := --aspsx-version=2.77 --macro-inc

COMPILE.c = $(CPP) $(CPPFLAGS) $< | $(VSSTRING) | $(CC1) $(CC1FLAGS) | $(MAS) $(MASFLAGS) | $(COMPILE.s)

$(BUILD)/%.o: %.c | $$(@D)/
	$(ECHO) Compiling $<
	$(COMPILE.c) $(OUTPUT_OPTION)
	$(CAT) $@.d >> $(BUILD)/$*.d
	$(RM) $(RMFLAGS) $@.d
