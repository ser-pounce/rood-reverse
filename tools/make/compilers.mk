OLDGCC         ?= tools/old-gcc
OLDGCC_VERSION ?= 0.17
COMPILER_PATHS ?= $(COMPILERS:%=$(OLDGCC)/%/cc1)

BUILDDEPS += $(COMPILER_PATHS)

$(COMPILER_PATHS): TARFLAGS += -C $(@D) -xf
$(COMPILER_PATHS): tools/old-gcc/%/cc1: | $$(@D)/
	$(ECHO) Downloading old-gcc $*
	$(WGET) $(WGETFLAGS) https://github.com/decompals/old-gcc/releases/download/$(OLDGCC_VERSION)/gcc-$*.tar.gz -P $(@D)
	$(TAR) $(TARFLAGS) $(@D)/gcc-$*.tar.gz 
	$(RM) $(RMFLAGS) $(@D)/gcc-$*.tar.gz

# The PsyQ library compiler: the stock 2.7.2-psx cc1 with GCC 2.8-style changes (tools/etc/patch_cc1.py).
PSYQ_CC1 ?= $(OLDGCC)/2.7.2-psyq/cc1
BUILDDEPS += $(PSYQ_CC1)
$(PSYQ_CC1): $(OLDGCC)/2.7.2-psx/cc1 tools/etc/patch_cc1.py | $$(@D)/
	$(ECHO) Patching cc1 for the PsyQ libraries
	$(PYTHON) tools/etc/patch_cc1.py $< $@
