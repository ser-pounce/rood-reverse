PERMUTE      := $(VPYTHON) tools/decomp-permuter/permuter.py
IMPORT       := $(VPYTHON) tools/decomp-permuter/import.py
PERMUTEFLAGS := -j8

src_from_target = $(patsubst $(BUILD)/%/,%.c,$(dir $(subst nonmatchings/,,$1)))

.PHONY: permute decompme

permute: $(patsubst %.s,nonmatchings/%/,$(notdir $(TARGET)))
	$(PERMUTE) $(PERMUTEFLAGS) $<

decompme: IMPORTFLAGS += --decompme --preserve-macros="NULL"
decompme: $(call src_from_target,$(TARGET)) $(TARGET)
	$(IMPORT) $(IMPORTFLAGS) $^

nonmatchings/%/: $(call src_from_target,$(TARGET)) $(TARGET)
	$(IMPORT) $(IMPORTFLAGS) $^
