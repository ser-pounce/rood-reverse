# Configure these to your needs
ARCH     := mipsel-linux-gnu-
CPP      := $(ARCH)cpp
LD       := $(ARCH)ld
AS       := $(ARCH)as
OBJCOPY  := $(ARCH)objcopy
SIZE     := $(ARCH)size
PYTHON   := python3
GIT      := git
CMAKE    := cmake
DOCKER   := docker
CARGO    := cargo
SED      := sed
DIFF     := diff
CAT      := cat
TOUCH    := touch
ECHO     := echo
MKDIR    := mkdir
MV       := mv
CP       := cp
FIND     := find
TRUNCATE := truncate

# Anything below this line should not need editing
CC1VER    := 2.7.2-psx
CC1        = tools/old-gcc/build-gcc-$(CC1VER)/cc1
MAS        = $(VPYTHON) tools/maspsx/maspsx.py

BUILD   := build

CPPFLAGS 		= -nostdinc -I src/include -I include/psx -I $(BUILD)/src/include \
                  -MD -MF $@.d -MT $@ -D "__attribute__(x)="
CC1FLAGS       := -G0 -O2 -Wall -quiet -fno-builtin -funsigned-char -Wno-unused
LDFLAGS         = -nostdlib --build-id=none -L $(BCONFIG) $(LDSCRIPT:%=-T %)
LDSCRIPT       := link.ld undefined_funcs_auto.txt undefined_syms_auto.txt
ASFLAGS         = -I include --MD $(@:.o=.d) -G0
OBJCOPYFLAGS   := -I binary -O elf32-tradlittlemips
MASFLAGS       := --aspsx-version=2.77 --macro-inc
RMFLAGS        := -Rf
DIFFFLAGS      := -s
MKDIRFLAGS     := -p

BINARIES     := SLUS_010.40 $(addsuffix .PRG, \
				TITLE/TITLE BATTLE/BATTLE BATTLE/INITBTL GIM/SCREFF2 ENDING/ENDING \
				$(addprefix MENU/, MAINMENU $(addprefix MENU, 0 1 2 3 4 5 7 8 9 B C D E F)))
BINTARGETS   := $(BINARIES:%=$(BUILD)/data/%)
TARGETS      := $(BINTARGETS)
INCMAKEFILES := $(BINARIES:%=config/%/Makefile) config/MENU/Makefile config/SMALL/Makefile \
				$(patsubst %,tools/make/%.mk,compilers lint objdiff permuter psxiso python shell splat sysdeps vsstring)
DISKCODE  := SLUS-01040
COMPILERS := 2.7.2-psx 2.7.2-cdk 2.8.1-psx

O_DEPS := $(SED) -En 's/(.*).o:$$/-include \1.d/p'

.ONESHELL:
.SILENT:
.SECONDEXPANSION:
.PHONY: all clean remake clean-all

SKIPSPLAT += clean remake clean-all

all: check
check: $$(TARGETS)

clean:
	$(RM) $(RMFLAGS) $(BUILD) nonmatchings

remake: MAKEFLAGS += --no-print-directory
remake: clean
	$(MAKE)

clean-all: confirm-reset
	$(GIT) clean -xfd -e $(DISKIMAGE)
	$(GIT) submodule foreach --recursive $(GIT) clean -xfd
	$(GIT) reset --hard
	$(GIT) submodule foreach --recursive $(GIT) reset --hard

$(BINTARGETS): private LDFLAGS := --oformat=binary -e 0x0
$(BINTARGETS): $(BUILD)/data/%: $(BUILD)/data/%.linked.elf
	$(ECHO) Linking $@
	$(LD) $(LDFLAGS) $(OUTPUT_OPTION) $<
	$(fixup)

$(BUILD)/data/%.elf: private BCONFIG = $(BUILD)/config/$(*:%.linked=%)
$(BUILD)/data/%.elf:
	$(ECHO) Linking $@
	$(LD) $(LDFLAGS) $(OUTPUT_OPTION)
	$(UPDATE_DEPS)

$(BINTARGETS:=.linked.elf): private LDFLAGS += $(addprefix -R ,$(LDLIBS))
$(BINTARGETS:=.linked.elf): $(BUILD)/data/%.linked.elf: $(BUILD)/data/%.elf

$(BINTARGETS:=.elf): private LDFLAGS += --unresolved-symbols=ignore-all --dependency-file=$(BCONFIG)/link.d
$(BINTARGETS:=.elf): private UPDATE_DEPS = $(O_DEPS) $(BCONFIG)/link.d >> $(BCONFIG)/link.d
$(BINTARGETS:=.elf): | $$(@D)/

%.o: %.s | $$(@D)/
	$(ECHO) Assembling $<
	$(AS) $(ASFLAGS) -no-pad-sections $(OUTPUT_OPTION) $<

$(BUILD)/%.o: %.s | $$(@D)/
	$(ECHO) Assembling $<
	$(AS) $(ASFLAGS) $(OUTPUT_OPTION) $<

$(BUILD)/%.o: %.c | $$(@D)/
	$(ECHO) Compiling $<
	$(CPP) $(CPPFLAGS) $< | $(VSSTRING) | $(CC1) $(CC1FLAGS) | $(MAS) $(MASFLAGS) | $(AS) $(ASFLAGS) $(OUTPUT_OPTION)
	$(CAT) $@.d >> $(BUILD)/$*.d
	$(RM) $(RMFLAGS) $@.d

%.img.o: OBJCOPYFLAGS += --add-symbol $(filename)=.data:0
%.img.o: filename = $(word 1,$(subst ., ,$(@F)))
%.img.o: %.img.bin | $$(@D)/
	$(ECHO) Converting $<
	$(OBJCOPY) $(OBJCOPYFLAGS) $< $@

.PRECIOUS: %.img.bin
%.img.bin: %.img.png | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.splat_ext.$(word 2,$(subst ., ,$(@F))) $< $@

%.rgba16Header.img.o: OBJCOPYFLAGS += \
	--add-symbol $(filename)_header=.data:0 \
	--add-symbol $(filename)_data=.data:4

.PRECIOUS: %/
%/:
	$(MKDIR) $(MKDIRFLAGS) $(@D)

pad = @$(TRUNCATE) -s $1 $@

.SUFFIXES:
%: %,v
%: RCS/%,v
%: RCS/%
%: s.%
%: SCCS/s.%
%.c: %.w %.ch

include $(INCMAKEFILES)

ifeq ($(filter $(SKIPSPLAT),$(MAKECMDGOALS)),)
-include $(BINARIES:%=$(BUILD)/config/%/link.d)
endif

$(BUILDDEPS): | sysdeps
