OLDGCC         ?= tools/old-gcc
COMPILER_PATHS ?= $(COMPILERS:%=$(OLDGCC)/build-gcc-%/cc1)

BUILDDEPS += $(COMPILER_PATHS)

$(COMPILER_PATHS): $(OLDGCC)/build-gcc-%/cc1:
	$(ECHO) Building GCC $*
	$(DOCKER) build -f $(OLDGCC)/gcc-$*.Dockerfile --target export \
		--output $(OLDGCC)/build-gcc-$* $(OLDGCC)/ $(if $(DEBUG),,2> /dev/null)
	$(TOUCH) $@
