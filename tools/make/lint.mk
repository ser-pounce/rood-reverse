FORMAT      ?= clang-format
FORMATFLAGS ?= -i --style=file:tools/.clang-format

SKIPSPLAT += format sortsyms lintsrc

.PHONY: format sortsyms lintsrc

format: sortsyms lintsrc

sortsyms:
	$(ECHO) Sorting symbols
	$(FIND) config -name symbol_addrs.txt -exec sh -c \
		'sort -c -t = -k 2 "$$1" 2>/dev/null || sort -t = -k 2 "$$1" -o "$$1"' _ {} \;

lintsrc:
	$(ECHO) Linting source
	$(FIND) src/ -type f -name *.h -o -name *.c | xargs \
		$(FORMAT) $(FORMATFLAGS)
