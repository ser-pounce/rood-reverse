COMMAND      := command
COMMANDFLAGS := -v

SYSDEPS := $(CMAKE) $(CXX) $(PYTHON) $(CPP) $(DOCKER) $(FORMAT)

.PHONY: sysdeps
sysdeps:
	$(GIT) submodule update --init --recursive
	$(COMMAND) $(COMMANDFLAGS) $(SYSDEPS) >/dev/null 2>&1 || ($(ECHO) One or more applications are missing: \\n \
		$(SYSDEPS); false)
	$(ECHO) Welcome to Rood Reverse!\\nPrerequisites checked.\\nSetting up remaining tools, this could take a while.\\n\\n
