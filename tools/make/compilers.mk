OLDGCC    := tools/old-gcc
COMPILERS := $(COMPILERS:%=$(OLDGCC)/build-gcc-%/cc1)

BUILDDEPS += $(COMPILERS)

$(COMPILERS): $(OLDGCC)/build-gcc-%/cc1: $(OLDGCC)/gcc-%.Dockerfile
	$(ECHO) Building GCC $*
	$(DOCKER) build -f $< --target export \
		--output $(OLDGCC)/build-gcc-$* $(OLDGCC)/ $(if $(DEBUG),,2> /dev/null)
	$(TOUCH) $@
