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
BINARY_DEPS  := $(BINARIES:%=$(BUILD)/config/%/link.d)
BINTARGETS   := $(BINARIES:%=$(BUILD)/data/%)
TARGETS      := $(BINTARGETS)
INCMAKEFILES := $(BINARIES:%=config/%/Makefile) config/MENU/Makefile config/SMALL/Makefile \
				$(patsubst %,tools/make/%.mk,assemble compile link permuter python util vsstring)

ifndef PERMUTER
ifndef __BASH_MAKE_COMPLETION__
INCMAKEFILES += $(patsubst %,tools/make/%.mk,compilers img lint objdiff psxiso shell splat)
endif
endif

DISKCODE   := SLUS-01040
DISKIMAGE  := disks/$(DISKCODE).bin
DISKCONFIG := config/$(DISKCODE).xml
COMPILERS  := 2.7.2-psx 2.7.2-cdk 2.8.1-psx

SHELL := bash
.SHELLFLAGS := -euc -o pipefail
.DELETE_ON_ERROR:
.ONESHELL:
.SILENT:
.SECONDEXPANSION:
.PHONY: all clean commit-check remake

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

commit-check remake: MAKEFLAGS += --no-print-directory

include $(INCMAKEFILES)

$(BUILDDEPS): | tools/.sysdeps
$(DISKCONFIG): | $(BUILDDEPS)
$(BINARY_DEPS): | $(DISKCONFIG)

ifeq ($(filter $(SKIPSPLAT),$(MAKECMDGOALS)),)
include $(BINARY_DEPS)
endif
