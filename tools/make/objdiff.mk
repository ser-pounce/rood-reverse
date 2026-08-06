OBJDIFF         ?= tools/objdiff/objdiff-cli
OBJDIFF_VERSION ?= v3.8.0
OBJDIFFFLAGS    ?= report generate

.PHONY: objdiff objdiff.json

SKIPSPLAT += objdiff

objdiff: progress.json
	$(VPYTHON) tools/dev/progress.py

progress.json: $(OBJDIFF) objdiff.json
	$(OBJDIFF) $(OBJDIFFFLAGS) $(OUTPUT_OPTION)

.INTERMEDIATE: objdiff.json
objdiff.json:
	$(VPYTHON) tools/dev/objdiff_config.py $(BUILD)/ $(BUILD)/ tools/dev/categories.json

$(OBJDIFF): | $$(@D)/
	$(ECHO) Dowloading objdiff-cli
	$(WGET) $(WGETFLAGS) https://github.com/encounter/objdiff/releases/download/$(OBJDIFF_VERSION)/objdiff-cli-linux-x86_64 -O $@
	chmod +x $@
