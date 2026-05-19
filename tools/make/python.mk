VPYDIR  ?= tools/python
VPYTHON ?= $(VPYDIR)/bin/$(PYTHON)
VPYSTAMP ?= $(VPYDIR)/.requirements.stamp

BUILDDEPS += $(VPYSTAMP)

$(VPYSTAMP): requirements.txt
	$(ECHO) Installing virtual python environment to $(VPYDIR)
	$(PYTHON) -m venv $(VPYDIR)
	$(VPYTHON) -m pip install --quiet -r requirements.txt
	$(TOUCH) $@
