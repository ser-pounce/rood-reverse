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
FORMAT   := clang-format
DIFF     := diff
CAT      := cat
TOUCH    := touch
ECHO     := echo
COMMAND  := command
MKDIR    := mkdir
MV       := mv
CP       := cp
FIND     := find
TRUNCATE := truncate

# Anything below this line should not need editing
CC1VER    := 2.7.2-psx
CC1        = tools/old-gcc/build-gcc-$(CC1VER)/cc1
VPYDIR    := tools/python
VPYTHON   := $(VPYDIR)/bin/$(PYTHON)
MAS       := $(VPYTHON) tools/maspsx/maspsx.py
SPLAT     := $(VPYTHON) -m splat split
IMPORT    := $(VPYTHON) tools/decomp-permuter/import.py
VSSTRING  := $(VPYTHON) tools/etc/vsStringTransformer.py
PERMUTE   := $(VPYTHON) tools/decomp-permuter/permuter.py
DUMPSXISO := tools/mkpsxiso/build/Release/dumpsxiso
MKPSXISO  := tools/mkpsxiso/build/Release/mkpsxiso

BUILD   := build
BCONFIG = $(BUILD)/config/$*

CPPFLAGS 		= -nostdinc -I src/include -I include/psx -I $(BUILD)/src/include $(CPP_DEPS) \
                  -D "__attribute__(x)="
CC1FLAGS       := -G0 -O2 -Wall -quiet -fno-builtin -funsigned-char -Wno-unused
LDFLAGS         = -nostdlib --build-id=none -x \
              	  -L $(BCONFIG) $(LDSCRIPT:%=-T %) --dependency-file=$(BCONFIG)/link.d
LDFLAGS_BIN    := --oformat=binary -e 0x0
LDSCRIPT       := link.ld undefined_funcs_auto.txt undefined_syms_auto.txt
ASFLAGS         = -I include $(AS_DEPS) -G0
OBJCOPYFLAGS   := -I binary -O elf32-tradlittlemips
MASFLAGS       := --aspsx-version=2.77 --macro-inc
SPLATFLAGS     := --disassemble-all
PERMUTEFLAGS   := -j8
DUMPSXISOFLAGS  = -x data -s config/$(disk).xml
FORMATFLAGS    := -i --style=file:tools/.clang-format
RMFLAGS        := -Rf
DIFFFLAGS      := -s
COMMANDFLAGS   := -v
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
targets    = $(binaries:%=$(BUILD)/data/%)
symfiles   := $(binaries:%=config/%/symbol_addrs.txt)
makefiles  := $(binaries:%=config/%/Makefile) config/MENU/Makefile config/SMALL/Makefile
ifneq ($(wildcard $(BUILD)/src),)
deps != $(FIND) $(BUILD)/src -type f -name *.d
endif
compilers  := $(patsubst %,tools/old-gcc/build-gcc-%/cc1,2.7.2-psx 2.7.2-cdk 2.8.0-psx)
build_deps := $(DUMPSXISO) $(VPYTHON) $(compilers)
sysdeps    := $(CMAKE) $(CXX) $(PYTHON) $(CPP) $(DOCKER) $(FORMAT)

src_from_target = $(patsubst $(BUILD)/%/,%.c,$(dir $(subst nonmatchings/,,$1)))

.ONESHELL:
.SILENT:
.SECONDEXPANSION:
.PHONY: all format sortsyms lintsrc decompme permute objdiff clean remake clean-all

all: $(targets)
ifeq ($(NOCHECK),)
	echo "Verifying target files"
	fail=0
	for t in $(^:$(BUILD)/%=%); do
	    if ! $(DIFF) $(DIFFFLAGS) "$$t" "$(BUILD)/$$t" >/dev/null 2>&1; then
	        printf '\033[0;31m✘ [%s]\033[0m\n' "$(BUILD)/$$t"
	        fail=1
	    fi
	done
	if [ $$fail -eq 0 ]; then
	    printf '\033[0;32m✔ All files match\033[0m\n'
	fi
	exit $$fail
endif

format: sortsyms lintsrc

sortsyms:
	$(ECHO) Sorting symbols
	for f in $(symfiles) ; do sort $$f -t = -k 2 -o $$f ; done

lintsrc:
	$(ECHO) Linting source
	$(FIND) src/ -type f -name *.h -o -name *.c | xargs \
		$(FORMAT) $(FORMATFLAGS)

decompme: IMPORTFLAGS += --decompme --preserve-macros="NULL"
decompme: $(call src_from_target,$(TARGET)) $(TARGET)
	$(IMPORT) $(IMPORTFLAGS) $^

permute: $(patsubst %.s,nonmatchings/%/,$(notdir $(TARGET)))
	$(PERMUTE) $(PERMUTEFLAGS) $<

objdiff: all
	$(VPYTHON) tools/dev/objdiff_config.py $(BUILD)/ $(BUILD)/ tools/dev/categories.json
	../.cargo/bin/objdiff-cli report generate > progress.json
	$(VPYTHON) tools/dev/progress.py

clean:
	$(RM) $(RMFLAGS) $(BUILD) nonmatchings

remake: MAKEFLAGS += --no-print-directory
remake: clean
	$(MAKE)

clean-all:
	$(GIT) clean -xfd -e disks/$(disk).bin
	$(GIT) submodule foreach --recursive $(GIT) clean -xfd
	$(GIT) reset --hard
	$(GIT) submodule foreach --recursive $(GIT) reset --hard

$(shell $(FIND) config src -type f -regex ".*\.\(yaml\|txt\|h\|c\|s\|inc\)\$$"): ;
$(compilers:tools/old-gcc/build-%/cc1=tools/old-gcc/%.Dockerfile): ;

ifeq ($(PERMUTER),)
$(BUILD)/config/%/link.d: config/%/splat.yaml config/%/symbol_addrs.txt config/%/Makefile data/% | $$(@D)/
	$(ECHO) Splitting $*
	$(SPLAT) $(SPLATFLAGS) config/splat.config.yaml $< $(if $(DEBUG),,> $(BUILD)/config/$*/splat.log 2> /dev/null)
	$(TOUCH) $@
endif

$(targets): $(BUILD)/data/%: $(BUILD)/data/%.elf | $$(@D)/
	$(ECHO) Linking $@
	$(LD) $(LDFLAGS_BIN) $< -o $@
	$(fixup)

$(targets:=.elf): $(BUILD)/data/%.elf: | $$(@D)/
	$(ECHO) Linking $@
	$(LD) $(LDFLAGS) -o $@

%.o: %.s | $$(@D)/
	$(ECHO) Assembling $<
	$(AS) $(ASFLAGS) -no-pad-sections -o $@ $<

$(BUILD)/%.o: %.s | $$(@D)/
	$(ECHO) Assembling $<
	$(AS) $(ASFLAGS) -o $@ $<

$(BUILD)/%.o: %.c | $$(@D)/
	$(ECHO) Compiling $<
	$(CPP) $(CPPFLAGS) $< | $(CC1) $(CC1FLAGS) | $(MAS) $(MASFLAGS) | $(AS) $(ASFLAGS) -o $@
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

.PRECIOUS: $(BUILD)/assets/%.vsString.yaml
$(BUILD)/assets/%.vsString.yaml: data/% assets/%.yaml | $$(@D)/
	$(ECHO) Extracting $<
	$(VPYTHON) -m tools.etc.vsString_dumpTable $< assets/$*.yaml $@

$(BUILD)/%.vsString $(BUILD)/%.h $(BUILD)/%.vsString.bin &: $(BUILD)/%.vsString.yaml | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.etc.vsString_yamlToData $< $(BUILD)/$*.vsString $(BUILD)/$*.h

$(BUILD)/data/%: $(BUILD)/assets/%.vsString.bin | $$(@D)/
	$(ECHO) Converting $<
	cp $< $@

%.vsString.o: %.vsString.bin
	$(ECHO) Assembling $@
	$(OBJCOPY) $(OBJCOPYFLAGS) $< $@

nonmatchings/%/: $(call src_from_target,$(TARGET)) $(TARGET)
	$(IMPORT) $(IMPORTFLAGS) $^

ifeq ($(PERMUTER),)
.PRECIOUS: data/%
$(sourcedata) &: | disks/$(disk).bin $(build_deps)
	$(ECHO) Dumping files from disk
	$(DUMPSXISO) $(DUMPSXISOFLAGS) disks/$(disk).bin $(if $(DEBUG),,> /dev/null)
endif

$(BUILD)/config/$(disk)_LBA.txt: $(sourcedata) | $$(@D)/
	$(ECHO) Generating $@
	$(MKPSXISO) -q -lba -noisogen config/$(disk).xml
	$(MV) $(disk)_LBA.txt $(BUILD)/config/

$(BUILD)/src/include/lbas.h: $(BUILD)/config/$(disk)_LBA.txt | $$(@D)/
	$(ECHO) Generating $@
	$(VPYTHON) tools/etc/make_lba_import.py $< $@

disks/$(disk).bin:
	$(ECHO) $@ not found
	false

$(build_deps): | tools/.sysdeps

$(DUMPSXISO):
	$(ECHO) Building mkpsxiso
	$(CMAKE) -S tools/mkpsxiso -B tools/mkpsxiso/build --preset release --log-level=ERROR \
		$(if $(DEBUG),,> /dev/null)
	$(CMAKE) --build tools/mkpsxiso/build -j --config Release $(if $(DEBUG),,> /dev/null)

$(VPYTHON):
	$(ECHO) Installing virtual python environment to $(VPYDIR)
	$(PYTHON) -m venv $(VPYDIR)
	$(VPYTHON) -m pip install --quiet splat64[mips] toml pycparser==2.23 pandas

$(compilers): tools/old-gcc/build-gcc-%/cc1: tools/old-gcc/gcc-%.Dockerfile
	$(ECHO) Building GCC $*
	$(DOCKER) build -f $< --target export \
		--output tools/old-gcc/build-gcc-$* tools/old-gcc/ $(if $(DEBUG),,2> /dev/null)
	$(TOUCH) $@

tools/.sysdeps:
	$(GIT) submodule update --init --recursive
	$(COMMAND) $(COMMANDFLAGS) $(sysdeps) >/dev/null 2>&1 || ($(ECHO) One or more applications are missing: \\n \
		$(sysdeps); false)
	$(TOUCH) $@
	$(ECHO) Welcome to Rood Reverse!\\nPrerequisites checked.\\nSetting up remaining tools, this could take a while.\\n\\n

.PRECIOUS: %/
%/:
	$(MKDIR) $(MKDIRFLAGS) $(@D)

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
-include $(binaries:%=$(BUILD)/config/%/link.d) $(deps)
endif
