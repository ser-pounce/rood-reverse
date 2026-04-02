PERMUTE         := $(VPYTHON) tools/decomp-permuter/permuter.py
IMPORT          := $(VPYTHON) tools/decomp-permuter/import.py
PERMUTEFLAGS    := -j8
PERMUTER_SOURCE := $(patsubst $(BUILD)/%/,%.c,$(dir $(subst nonmatchings/,,$(TARGET))))

.PHONY: permute decompme

permute: $(patsubst %.s,nonmatchings/%/,$(notdir $(TARGET)))
	$(PERMUTE) $(PERMUTEFLAGS) $<

decompme: IMPORTFLAGS += --decompme --preserve-macros="NULL"
decompme: $(PERMUTER_SOURCE) $(TARGET)
	$(IMPORT) $(IMPORTFLAGS) $^

nonmatchings/%/: $(PERMUTER_SOURCE) $(TARGET)
	$(IMPORT) $(IMPORTFLAGS) $^
