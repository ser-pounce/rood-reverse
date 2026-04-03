COMPILERS := 2.7.2-psx 2.7.2-cdk 2.8.1-psx
OLDGCC    := tools/old-gcc
COMPILERS := $(COMPILERS:%=$(OLDGCC)/build-gcc-%/cc1)

BUILD_DEPENDENCIES += $(COMPILERS)

$(COMPILERS): $(OLDGCC)/build-gcc-%/cc1: $(OLDGCC)/gcc-%.Dockerfile
	$(ECHO) Building GCC $*
	$(DOCKER) build -f $< --target export \
		--output $(OLDGCC)/build-gcc-$* $(OLDGCC)/ $(if $(DEBUG),,2> /dev/null)
	$(TOUCH) $@
