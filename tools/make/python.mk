VPYDIR  ?= tools/python
VPYTHON ?= $(VPYDIR)/bin/$(PYTHON)

BUILDDEPS += $(VPYTHON)

$(VPYTHON):
	$(ECHO) Installing virtual python environment to $(VPYDIR)
	$(PYTHON) -m venv $(VPYDIR)
	$(VPYTHON) -m pip install --quiet $(PYTHONDEPS)
