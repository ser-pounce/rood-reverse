FORMAT      ?= clang-format
FORMATFLAGS ?= -i --style=file:tools/.clang-format

SKIPSPLAT += format sortsyms lintsrc

.PHONY: format sortsyms lintsrc

format: sortsyms lintsrc

sortsyms:
	$(ECHO) Sorting symbols
	$(FIND) config -name symbol_addrs.txt -exec sort -t = -k 2 {} -o {} \;

lintsrc:
	$(ECHO) Linting source
	$(FIND) src/ -type f -name *.h -o -name *.c | xargs \
		$(FORMAT) $(FORMATFLAGS)
