VPYDIR  ?= tools/python
VPYTHON ?= $(VPYDIR)/bin/$(PYTHON)

BUILDDEPS += $(VPYTHON)

$(VPYTHON): requirements.txt
	$(ECHO) Installing virtual python environment to $(VPYDIR)
	$(PYTHON) -m venv $(VPYDIR)
	$(VPYTHON) -m pip install --quiet -r requirements.txt $(PYTHONDEPS)
