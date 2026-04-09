ARCH     := mipsel-linux-gnu-
OBJCOPY  := $(ARCH)objcopy
SIZE     := $(ARCH)size
PYTHON   := python3
GIT      := git
CMAKE    := cmake
DOCKER   := docker
CARGO    := cargo

OBJCOPYFLAGS := -I binary -O elf32-tradlittlemips

BUILD        := build
BINARIES     := SLUS_010.40 $(addsuffix .PRG, \
				TITLE/TITLE BATTLE/BATTLE BATTLE/INITBTL GIM/SCREFF2 ENDING/ENDING \
				$(addprefix MENU/, MAINMENU $(addprefix MENU, 0 1 2 3 4 5 7 8 9 B C D E F)))
BINTARGETS   := $(BINARIES:%=$(BUILD)/data/%)
TARGETS      := $(BINTARGETS)
INCMAKEFILES := $(BINARIES:%=config/%/Makefile) config/MENU/Makefile config/SMALL/Makefile \
				$(patsubst %,tools/make/%.mk,assemble compile compilers img link lint objdiff permuter psxiso python shell splat sysdeps util vsstring)

DISKCODE  := SLUS-01040
DISKIMAGE := disks/$(DISKCODE).bin
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

commit-check remake: MAKEFLAGS += --no-print-directory

include $(INCMAKEFILES)

ifeq ($(filter $(SKIPSPLAT),$(MAKECMDGOALS)),)
-include $(BINARIES:%=$(BUILD)/config/%/link.d)
endif

$(BUILDDEPS): | sysdeps
