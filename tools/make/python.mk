VPYDIR    := tools/python
VPYTHON   := $(VPYDIR)/bin/$(PYTHON)

BUILD_DEPENDENCIES += $(VPYTHON)

$(VPYTHON):
	$(ECHO) Installing virtual python environment to $(VPYDIR)
	$(PYTHON) -m venv $(VPYDIR)
	$(VPYTHON) -m pip install --quiet splat64[mips] toml pandas
