# Configure these to your needs
ARCH     := mips-linux-gnu-
CPP      := $(ARCH)cpp
LD       := $(ARCH)ld
AS       := $(ARCH)as
OBJCOPY  := $(ARCH)objcopy
PYTHON   := python3
GIT      := git
CMAKE    := cmake
DOCKER   := docker
FORMAT   := clang-format
DIFF     := diff
CAT      := cat
TOUCH    := touch
ECHO     := echo
WHICH    := which
MKDIR    := mkdir
MV       := mv
FIND     := find
TRUNCATE := truncate

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
DUMPSXISO := tools/mkpsxiso/build/Release/dumpsxiso
MKPSXISO := tools/mkpsxiso/build/Release/mkpsxiso

BCONFIG = build/config/$*

CPPFLAGS        = -nostdinc -I src/include -I include/psx -I build/src/include $(CPP_DEPS)
CC1FLAGS       := -G0 -O2 -Wall -quiet -fno-builtin -fsigned-char -Wno-unused
LDFLAGS         = -nostdlib --build-id=none -EL -x \
              	  -L $(BCONFIG) $(LDSCRIPT:%=-T %) --dependency-file=$(BCONFIG)/link.d
LDFLAGS_BIN    := --oformat=binary -e 0x0
LDSCRIPT       := link.ld undefined_funcs_auto.txt undefined_syms_auto.txt
ASFLAGS         = -I src/include $(AS_DEPS) -EL -G0
OBJCOPYFLAGS   := -I binary -O elf32-tradlittlemips
MASFLAGS       := --aspsx-version=2.56 --macro-inc
SPLATFLAGS     := --disassemble-all
PERMUTEFLAGS   := -j8
DUMPSXISOFLAGS  = -x data -s config/$(disk).xml
FORMATFLAGS    := --style="{BasedOnStyle: WebKit, ColumnLimit: 90, SortIncludes: 'Never' }" -i
RMFLAGS        := -Rf
DIFFFLAGS      := -s
WHICHFLAGS     := -s
MKDIRFLAGS     := -p

ifeq ($(PERMUTER),)
CPP_DEPS = -MD -MF $@.d -MT $@
AS_DEPS  = --MD $(@:.o=.d)
endif

disk       := SLUS-01040
binaries   := SLUS_010.40 $(addsuffix .PRG, \
				TITLE/TITLE BATTLE/BATTLE BATTLE/INITBTL GIM/SCREFF2 ENDING/ENDING \
				$(addprefix MENU/, MAINMENU $(addprefix MENU, 0 1 2 3 4 5 7 8 9 B C D E F)))
sourcedata := $(binaries:%=data/%)
targets    := $(binaries:%=build/data/%)
symfiles   := $(binaries:%=config/%/symbol_addrs.txt) $(binaries:%=config/%/exports.txt)
makefiles  := $(binaries:%=config/%/Makefile)
ifneq ($(wildcard build/src),)
deps != $(FIND) build/src -type f -name *.d
endif
build_deps := $(DUMPSXISO) $(VPYTHON) $(patsubst %,tools/old-gcc/build-gcc-%-psx/cc1,2.7.2 2.8.0)
sysdeps    := $(CMAKE) $(CXX) $(PYTHON) $(CPP) $(DOCKER) $(FORMAT)

src_from_target = $(patsubst build/%/,%.c,$(dir $(subst nonmatchings/,,$1)))

.PHONY: all format sortsyms lintsrc decompme permute clean remake clean-all

all: $(targets)

format: sortsyms lintsrc

sortsyms:
	@$(ECHO) Sorting symbols
	@for f in $(symfiles) ; do sort $$f -t = -k 2 -o $$f ; done

lintsrc:
	@$(ECHO) Linting source
	@$(FIND) src/ -type f -name *.h -o -name *.c | xargs \
		$(FORMAT) $(FORMATFLAGS)

decompme: IMPORTFLAGS += --decompme --preserve-macros "setRECT|vs_.*"
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
build/config/%/link.d: config/%/splat.yaml config/%/symbol_addrs.txt config/%/exports.txt \
						config/%/Makefile Makefile data/%
	@$(call builder, Splitting $*)
	@$(SPLAT) $(SPLATFLAGS) $< $(if $(DEBUG),,> build/config/$*/splat.log 2> /dev/null)
	@$(TOUCH) $@
endif

build/data/%: build/data/%.elf	
	$(call builder,Linking $@)
	@$(LD) $(LDFLAGS_BIN) $< -o $@
	$(fixup)
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

%rgba16.o: filename = $(@F:%.rgba16.o=%)
%rgba16.o: %rgba16.bin
	$(call builder,Compiling $<)
	@$(OBJCOPY) $(OBJCOPYFLAGS) \
	--add-symbol $(filename)_header=.data:0 \
	--add-symbol $(filename)_data=.data:4 $< $@

%rgba16.bin: %rgba16.png
	$(call builder,Converting $<)
	@$(RGBA16) $< $@

%.o: %.yaml.bin
	$(call builder,Compiling $<)
	@$(OBJCOPY) $(OBJCOPYFLAGS) --set-section-alignment .data=4 \
	$(shell $(VPYTHON) -m tools.splat_ext.symbolBuilder tools.splat_ext.$(*F)) $< $@

%.yaml.bin: %.yaml
	$(call builder,Converting $<)
	@$(VPYTHON) -m tools.splat_ext.$(*F) $< $@

nonmatchings/%/: $(call src_from_target,$(TARGET)) $(TARGET)
	@$(IMPORT) $(IMPORTFLAGS) $^

ifeq ($(PERMUTER),)
.PRECIOUS: data/%
$(sourcedata) &: | disks/$(disk).bin $(build_deps)
	@$(ECHO) Dumping files from disk
	@$(DUMPSXISO) $(DUMPSXISOFLAGS) disks/$(disk).bin $(if $(DEBUG),,> /dev/null)
endif

build/config/$(disk)_LBA.txt: $(sourcedata)
	$(call builder,Generating $@)
	@$(MKPSXISO) -q -lba -noisogen config/$(disk).xml
	@$(MV) $(disk)_LBA.txt build/config/

build/src/include/lbas.h: build/config/$(disk)_LBA.txt
	$(call builder,Generating $@)
	@$(VPYTHON) tools/etc/make_lba_import.py $< $@

disks/$(disk).bin:
	@$(ECHO) $@ not found
	@false

$(build_deps): | tools/.sysdeps

$(DUMPSXISO):
	@$(ECHO) Building mkpsxiso
	@$(CMAKE) -S tools/mkpsxiso -B tools/mkpsxiso/build --preset release --log-level=ERROR \
		$(if $(DEBUG),,> /dev/null)
	@$(CMAKE) --build tools/mkpsxiso/build -j --config Release $(if $(DEBUG),,> /dev/null)

$(VPYTHON):
	@$(ECHO) Installing virtual python environment to $(VPYDIR)
	@$(PYTHON) -m venv $(VPYDIR)
	@$(VPYTHON) -m pip install --quiet splat64[mips] toml pycparser pandas

tools/old-gcc/build-gcc-%/cc1: tools/old-gcc/gcc-%.Dockerfile
	@$(ECHO) Building GCC $*
	@$(DOCKER) build -f $< --target export \
		--output tools/old-gcc/build-gcc-$* tools/old-gcc/ $(if $(DEBUG),,2> /dev/null)
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

define pad
@$(TRUNCATE) -s $1 $@
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
ifeq ($(filter decompme permute format sortsyms lintsrc clean remake clean-all,$(MAKECMDGOALS)),)
-include $(binaries:%=build/config/%/link.d) $(deps)
endif
