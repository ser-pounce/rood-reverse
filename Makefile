# Configure these to your needs
ARCH     := mipsel-linux-gnu-
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

BUILD   := build

OBJCOPYFLAGS   := -I binary -O elf32-tradlittlemips
RMFLAGS        := -Rf
DIFFFLAGS      := -s
MKDIRFLAGS     := -p

BINARIES     := SLUS_010.40 $(addsuffix .PRG, \
				TITLE/TITLE BATTLE/BATTLE BATTLE/INITBTL GIM/SCREFF2 ENDING/ENDING \
				$(addprefix MENU/, MAINMENU $(addprefix MENU, 0 1 2 3 4 5 7 8 9 B C D E F)))
BINTARGETS   := $(BINARIES:%=$(BUILD)/data/%)
TARGETS      := $(BINTARGETS)
INCMAKEFILES := $(BINARIES:%=config/%/Makefile) config/MENU/Makefile config/SMALL/Makefile \
				$(patsubst %,tools/make/%.mk,assemble compile compilers link lint objdiff permuter psxiso python shell splat sysdeps vsstring)
DISKCODE  := SLUS-01040
COMPILERS := 2.7.2-psx 2.7.2-cdk 2.8.1-psx

.ONESHELL:
.SILENT:
.SECONDEXPANSION:
.PHONY: all clean commit-check remake clean-all

SKIPSPLAT += clean remake clean-all

all: check

check: $$(TARGETS)

commit-check: format
	$(MAKE) remake
	$(MAKE) objdiff

clean:
	$(RM) $(RMFLAGS) $(BUILD) nonmatchings

remake: clean
	$(MAKE)

clean-all: confirm-reset
	$(GIT) clean -xfd -e $(DISKIMAGE)
	$(GIT) submodule foreach --recursive $(GIT) clean -xfd
	$(GIT) reset --hard
	$(GIT) submodule foreach --recursive $(GIT) reset --hard
	
commit-check remake: MAKEFLAGS += --no-print-directory

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
