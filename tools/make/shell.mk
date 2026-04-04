SHELL_RED    := \033[0;31m
SHELL_GREEN  := \033[0;32m
SHELL_YELLOW := \033[1;33m
SHELL_RESET  := \033[0m

.PHONY: check confirm-reset

check:
ifndef NOCHECK
	echo "Verifying target files..."
	fail=0
	for t in $(^:$(BUILD)/%=%); do
		if ! $(DIFF) $(DIFFFLAGS) "$$t" "$(BUILD)/$$t" >/dev/null 2>&1; then
			printf '$(SHELL_RED)✘ [%s]$(SHELL_RESET)\n' "$(BUILD)/$$t"
			fail=1
		fi
	done
	if [ $$fail -eq 0 ]; then
		printf '$(SHELL_GREEN)✔ All files match$(SHELL_RESET)\n'
	fi
	exit $$fail
endif

confirm-reset:
	$(ECHO) ""
	$(ECHO) "  $(SHELL_YELLOW)⚠️  WARNING: This will delete all untracked files and reset any uncommitted changes.$(SHELL_RESET)"
	$(ECHO) ""
	read -p "  Continue? [y/N] " confirm
	$(ECHO) ""
	{ [ "$$confirm" = "y" ] || [ "$$confirm" = "Y" ]; } || { $(ECHO) "  $(SHELL_RED)Aborted.$(SHELL_RESET)"; exit 1; }
