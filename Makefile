# Configure these to your needs
ARCH   := mips-linux-gnu-
CPP    := $(ARCH)cpp
LD     := $(ARCH)ld
AS     := $(ARCH)as
PYTHON := python3
GIT    := git
CMAKE  := cmake
DOCKER := docker
FORMAT := clang-format
DIFF   := diff
CAT    := cat
TOUCH  := touch
ECHO   := echo
WHICH  := which
MKDIR  := mkdir

# Anything below this line should not need editing
CC1VER  := 2.7.2
CC1      = tools/old-gcc/build-gcc-$(CC1VER)-psx/cc1
VPYDIR  := tools/python
VPYTHON := $(VPYDIR)/bin/$(PYTHON)
MAS     := $(VPYTHON) tools/maspsx/maspsx.py
SPLAT   := $(VPYTHON) -m splat split
IMPORT  := $(VPYTHON) tools/decomp-permuter/import.py
PERMUTE := $(VPYTHON) tools/decomp-permuter/permuter.py
RGBA16  := $(VPYTHON) tools/splat_ext/rgba16.py
DUMPISO := tools/mkpsxiso/build/Release/dumpsxiso

BCONFIG = build/config/$*

CPPFLAGS      = -nostdinc -I src/include -I include/psx $(CPP_DEPS)
CC1FLAGS     := -G0 -O2 -Wall -quiet -fno-builtin -Wno-unused
LDFLAGS       = -nostdlib --build-id=none -EL -x \
              	-L $(BCONFIG) $(LDSCRIPT:%=-T %) --dependency-file=$(BCONFIG)/link.d
LDFLAGS_BIN  := --oformat=binary -e 0x0
LDSCRIPT     := link.ld undefined_funcs_auto.txt undefined_syms_auto.txt
ASFLAGS       = -I src/include $(AS_DEPS) -EL
MASFLAGS     := --aspsx-version=2.56 --macro-inc
SPLATFLAGS   := --disassemble-all
PERMUTEFLAGS := -j8
DUMPISOFLAGS  = -x data -s config/$(disk).xml
FORMATFLAGS  := --style="{BasedOnStyle: WebKit, ColumnLimit: 90, SortIncludes: 'Never' }" -i
RMFLAGS      := -Rf
DIFFFLAGS    := -s
WHICHFLAGS   := -s
MKDIRFLAGS   := -p

ifeq ($(PERMUTER),)
CPP_DEPS = -MD -MF $@.d -MT $@
AS_DEPS  = --MD $(@:.o=.d)
endif

disk       := SLUS-01040
binaries   := SLUS_010.40 TITLE/TITLE.PRG BATTLE/BATTLE.PRG
targets    := $(binaries:%=build/data/%)
symfiles   := $(binaries:%=config/%/symbol_addrs.txt) $(binaries:%=config/%/exports.txt)
makefiles  := $(binaries:%=config/%/Makefile)
ifneq ($(wildcard build/src),)
deps != find build/src -type f -name *.d
endif
build_deps := $(DUMPISO) $(VPYTHON) $(patsubst %,tools/old-gcc/build-gcc-%-psx/cc1,2.7.2 2.8.0)
sysdeps    := $(CMAKE) $(CXX) $(PYTHON) $(CPP) $(DOCKER) $(FORMAT)

src_from_target = $(patsubst build/%/,%.c,$(dir $(subst nonmatchings/,,$1)))

.PHONY: all format decompme permute clean remake clean-all

all: $(targets)

format:
	for f in $(symfiles) ; do sort $$f -t = -k 2 -o $$f ; done
	find src/ -type f -name *.h -o -name *.c | xargs \
		$(FORMAT) $(FORMATFLAGS)

decompme: IMPORTFLAGS += --decompme
decompme: $(call src_from_target,$(TARGET)) $(TARGET)
	@$(IMPORT) $(IMPORTFLAGS) $^

permute: $(patsubst %.s,nonmatchings/%/,$(notdir $(TARGET)))
	@$(PERMUTE) $(PERMUTEFLAGS) $<

clean:
	$(RM) $(RMFLAGS) build

remake: MAKEFLAGS += --no-print-directory
remake: clean
	@$(MAKE)

clean-all:
	@$(GIT) clean -xfd -e disks/$(disk).bin
	@$(GIT) submodule foreach --recursive $(GIT) clean -xfd
	@$(GIT) reset --hard
	@$(GIT) submodule foreach --recursive $(GIT) reset --hard

ifeq ($(PERMUTER),)
build/config/%/link.d: config/%/splat.yaml config/%/symbol_addrs.txt data/% Makefile
	@$(SPLAT) $(SPLATFLAGS) $<
	@$(TOUCH) $@
endif

build/data/%: build/data/%.elf	
	$(call builder,Linking $@)
	@$(LD) $(LDFLAGS_BIN) $< -o $@
	@$(DIFF) $(DIFFFLAGS) $@ data/$*

build/data/%.elf:
	$(call builder,Linking $@)
	@$(LD) $(LDFLAGS) -o $@

%.o: %.s
	$(call builder,Assembling $<)
	@$(AS) $(ASFLAGS) -no-pad-sections -o $@ $<

build/%.o: %.s
	$(call builder,Assembling $<)
	@$(AS) $(ASFLAGS) -o $@ $<

build/%.o: %.c
	$(call builder,Compiling $<)
	@$(CPP) $(CPPFLAGS) $< | $(CC1) $(CC1FLAGS) | $(MAS) $(MASFLAGS) | $(AS) $(ASFLAGS) -o $@
	@$(CAT) $@.d >> build/$*.d
	@$(RM) $(RMFLAGS) $@.d

%rgba16.bin: %rgba16.png
	$(call builder,Converting $<)
	@$(RGBA16) $< $@

nonmatchings/%/: $(call src_from_target,$(TARGET)) $(TARGET)
	@$(IMPORT) $(IMPORTFLAGS) $^

ifeq ($(PERMUTER),)
.PRECIOUS: data/%
data/%: | disks/$(disk).bin $(build_deps)
	$(DUMPISO) $(DUMPISOFLAGS) disks/$(disk).bin
endif

disks/$(disk).bin:
	@$(ECHO) $@ not found
	@false

$(build_deps): | tools/.sysdeps

$(DUMPISO):
	@$(CMAKE) -S tools/mkpsxiso -B tools/mkpsxiso/build --preset release --log-level=ERROR
	@$(CMAKE) --build tools/mkpsxiso/build -j --config Release

$(VPYTHON):
	@$(ECHO) Installing virtual python environment to $(VPYDIR)
	@$(PYTHON) -m venv $(VPYDIR)
	@$(VPYTHON) -m pip install splat64[mips] toml pycparser

tools/old-gcc/build-gcc-%/cc1: tools/old-gcc/gcc-%.Dockerfile
	@$(MAKE) -C tools/old-gcc/ VERSION=$*
	@$(TOUCH) $@

tools/.sysdeps:
	@$(GIT) submodule update --init --recursive
	@$(WHICH) $(WHICHFLAGS) $(sysdeps) || ($(ECHO) One or more applications are missing: \\n \
		$(sysdeps); false)
	@$(TOUCH) $@


define builder
@$(ECHO) $1
@$(MKDIR) $(MKDIRFLAGS) $(@D)
endef

# De-crud
.SUFFIXES:
Makefile $(makefiles) $(deps):: ;
%: %,v
%: RCS/%,v
%: RCS/%
%: s.%
%: SCCS/s.%
%.c: %.w %.ch

include $(makefiles)
ifeq ($(filter decompme permute format clean remake clean-all,$(MAKECMDGOALS)),)
-include $(binaries:%=build/config/%/link.d) $(deps)
endif
