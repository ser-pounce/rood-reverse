COMMAND      ?= command
COMMANDFLAGS ?= -v

SYSDEPS = $(CMAKE) $(CXX) $(PYTHON) $(CPP) $(DOCKER) $(CARGO) $(FORMAT)

.PHONY: sysdeps
sysdeps:
	$(GIT) submodule update --init --recursive
	$(COMMAND) $(COMMANDFLAGS) $(SYSDEPS) >/dev/null 2>&1 || ($(ECHO) One or more applications are missing: \\n \
		$(SYSDEPS); false)
	$(ECHO) Welcome to Rood Reverse!\\nPrerequisites checked.\\nSetting up remaining tools, this could take a while.\\n\\n

clean-all:
	$(GIT) clean -xfd -e $(DISKIMAGE)
	$(GIT) submodule foreach --recursive $(GIT) clean -xfd
	$(GIT) reset --hard
	$(GIT) submodule foreach --recursive $(GIT) reset --hard
