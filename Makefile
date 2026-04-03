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
MAS        = $(VPYTHON) tools/maspsx/maspsx.py
SPLAT      = $(VPYTHON) -m splat
VSSTRING   = $(VPYTHON) tools/etc/vsStringTransformer.py

BUILD   := build
BCONFIG  = $(BUILD)/config/$*

CPPFLAGS 		= -nostdinc -I src/include -I include/psx -I $(BUILD)/src/include \
                  -MD -MF $@.d -MT $@ -D "__attribute__(x)="
CC1FLAGS       := -G0 -O2 -Wall -quiet -fno-builtin -funsigned-char -Wno-unused
LDFLAGS         = -nostdlib --build-id=none -L $(BCONFIG) \
				   $(LDSCRIPT:%=-T %) --dependency-file=$(BCONFIG)/link.d
LDSCRIPT       := link.ld undefined_funcs_auto.txt undefined_syms_auto.txt
ASFLAGS         = -I include --MD $(@:.o=.d) -G0
OBJCOPYFLAGS   := -I binary -O elf32-tradlittlemips
MASFLAGS       := --aspsx-version=2.77 --macro-inc
SPLATFLAGS     := split --disassemble-all
FORMATFLAGS    := -i --style=file:tools/.clang-format
RMFLAGS        := -Rf
DIFFFLAGS      := -s
COMMANDFLAGS   := -v
MKDIRFLAGS     := -p

binaries   := SLUS_010.40 $(addsuffix .PRG, \
				TITLE/TITLE BATTLE/BATTLE BATTLE/INITBTL GIM/SCREFF2 ENDING/ENDING \
				$(addprefix MENU/, MAINMENU $(addprefix MENU, 0 1 2 3 4 5 7 8 9 B C D E F)))
targets     = $(binaries:%=$(BUILD)/data/%)
symfiles   := $(binaries:%=config/%/symbol_addrs.txt)
makefiles  := $(binaries:%=config/%/Makefile) config/MENU/Makefile config/SMALL/Makefile
SYSDEPS    := $(CMAKE) $(CXX) $(PYTHON) $(CPP) $(DOCKER) $(FORMAT)

.ONESHELL:
.SILENT:
.SECONDEXPANSION:
.PHONY: all format sortsyms lintsrc objdiff clean remake clean-all

all: $(targets)
ifndef NOCHECK
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
	$(GIT) clean -xfd -e $(DISKIMAGE)
	$(GIT) submodule foreach --recursive $(GIT) clean -xfd
	$(GIT) reset --hard
	$(GIT) submodule foreach --recursive $(GIT) reset --hard

ifndef PERMUTER
ifndef __BASH_MAKE_COMPLETION__
$(BUILD)/config/%/link.d: config/%/splat.yaml config/%/symbol_addrs.txt config/%/Makefile | $$(if $$(wildcard $$(DISKCONFIG)),,$$(DISKCONFIG)) $$(@D)/
	$(ECHO) Splitting $*
	$(SPLAT) $(SPLATFLAGS) config/splat.config.yaml $< $(if $(DEBUG),,> $(BUILD)/config/$*/splat.log 2> /dev/null)
	$(TOUCH) $@
endif
endif

$(targets): private LDFLAGS := --oformat=binary -e 0x0
$(targets): $(BUILD)/data/%: $(BUILD)/data/%.linked.elf
	$(ECHO) Linking $@
	$(LD) $(LDFLAGS) $(OUTPUT_OPTION) $<
	$(fixup)
	$(file >>$(BUILD)/config/$*/link.d,include $(wildcard $(patsubst %.o,%.d,$(filter %.o,$(file <$(BUILD)/config/$*/link.d)))))

$(targets:=.linked.elf): private LDFLAGS += $(addprefix -R ,$(LDLIBS))
$(targets:=.linked.elf): $(BUILD)/data/%.linked.elf: $(BUILD)/data/%.elf
	$(ECHO) Linking $@
	$(LD) $(LDFLAGS) $(OUTPUT_OPTION)

$(targets:=.elf): private LDFLAGS += --unresolved-symbols=ignore-all
$(targets:=.elf): $(BUILD)/data/%.elf: | $$(@D)/
	$(ECHO) Linking $@
	$(LD) $(LDFLAGS) $(OUTPUT_OPTION)

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

.PRECIOUS: $(BUILD)/assets/%.vsString.yaml
$(BUILD)/assets/%.vsString.yaml: assets/%.yaml | $$(@D)/
	$(ECHO) Extracting data/$*
	$(VPYTHON) -m tools.etc.vsString_dumpTable data/$* assets/$*.yaml $@

$(BUILD)/%.vsString $(BUILD)/%.h $(BUILD)/%.vsString.bin &: $(BUILD)/%.vsString.yaml | $$(@D)/
	$(ECHO) Converting $<
	$(VPYTHON) -m tools.etc.vsString_yamlToData $< $(BUILD)/$*.vsString $(BUILD)/$*.h

$(BUILD)/data/%: $(BUILD)/assets/%.vsString.bin | $$(@D)/
	$(ECHO) Converting $<
	cp $< $@

%.vsString.o: %.vsString.bin
	$(ECHO) Assembling $@
	$(OBJCOPY) $(OBJCOPYFLAGS) $< $@

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

include tools/make/permuter.mk tools/make/psxiso.mk tools/make/python.mk tools/make/compilers.mk

$(BUILD_DEPENDENCIES): | sysdeps

.PHONY: sysdeps
sysdeps:
	$(GIT) submodule update --init --recursive
	$(COMMAND) $(COMMANDFLAGS) $(SYSDEPS) >/dev/null 2>&1 || ($(ECHO) One or more applications are missing: \\n \
		$(SYSDEPS); false)
	$(ECHO) Welcome to Rood Reverse!\\nPrerequisites checked.\\nSetting up remaining tools, this could take a while.\\n\\n

include $(makefiles)
ifeq ($(filter decompme permute format sortsyms lintsrc clean remake clean-all,$(MAKECMDGOALS)),)
-include $(binaries:%=$(BUILD)/config/%/link.d)
endif
