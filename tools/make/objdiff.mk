OBJDIFF      := ~/.cargo/bin/objdiff-cli
OBJDIFFFLAGS := report generate

.PHONY: objdiff objdiff.json

BUILDDEPS += $(OBJDIFF)
SKIPSPLAT += objdiff

objdiff: progress.json
	$(VPYTHON) tools/dev/progress.py

progress.json: objdiff.json
	$(OBJDIFF) $(OBJDIFFFLAGS) > progress.json

objdiff.json:
	$(VPYTHON) tools/dev/objdiff_config.py $(BUILD)/ $(BUILD)/ tools/dev/categories.json

$(OBJDIFF):
	cargo install --locked --git https://github.com/encounter/objdiff.git objdiff-cli
