ARCH    := mipsel-linux-gnu-
OBJCOPY := $(ARCH)objcopy
SIZE    := $(ARCH)size
PYTHON  := python3
GIT     := git

OBJCOPYFLAGS := -I binary -O elf32-tradlittlemips

BUILD      := build
DISKCODE   := SLUS-01040
DISKIMAGE  := disks/$(DISKCODE).bin
DISKCONFIG := disks/$(DISKCODE).xml
COMPILERS  := 2.7.2-psx 2.7.2-cdk 2.8.1-psx

SHELL := bash
.SHELLFLAGS := -euc -o pipefail
.DELETE_ON_ERROR:
.ONESHELL:
.SILENT:
.SECONDEXPANSION:
.PHONY: all clean commit-check remake image

SKIPSPLAT += commit-check clean remake clean-all

all: check

check: $$(TARGETS)

commit-check: format
	$(MAKE) remake
	$(MAKE) objdiff

clean:
	$(RM) $(RMFLAGS) $(BUILD) nonmatchings

remake: clean
	$(MAKE)

image: $(BUILD)/$(DISKIMAGE)

BINARIES := SLUS_010.40 $(addsuffix .PRG, TITLE/TITLE BATTLE/BATTLE BATTLE/INITBTL GIM/SCREFF2 ENDING/ENDING)

include $(patsubst %,config/%/Makefile,EFFECT MENU SMALL)

BINTARGETS := $(BINARIES:%=$(BUILD)/data/%)
TARGETS    += $(BINTARGETS)

include $(wildcard $(BINARIES:%=config/%/Makefile))
include $(patsubst %,tools/make/%.mk,shell assemble compile docker kaitai link permuter python vsstring)

ifndef PERMUTER
ifndef __BASH_MAKE_COMPLETION__
include $(patsubst %,tools/make/%.mk,compilers img lint objdiff psxiso splat xdelta)
endif
endif

BINARY_DEPS := $(BINARIES:%=$(BUILD)/config/%/link.d)

$(BUILDDEPS):   | tools/.sysdeps
$(DISKCONFIG):  | $(BUILDDEPS)
$(BINARY_DEPS): | $(DISKCONFIG)

ifeq ($(filter $(SKIPSPLAT),$(MAKECMDGOALS)),)
include $(BINARY_DEPS)
endif
