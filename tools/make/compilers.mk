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
