CAT      ?= cat
COMMAND  ?= command
DIFF     ?= diff
ECHO     ?= echo -e
FIND     ?= find
MKDIR    ?= mkdir
MV       ?= mv
SED      ?= sed
TOUCH    ?= touch
TRUNCATE ?= truncate

COMMANDFLAGS ?= -v
DIFFFLAGS    ?= -s
MKDIRFLAGS   ?= -p
RMFLAGS      ?= -Rf

SYSDEPS       = $(CMAKE) $(CXX) $(PYTHON) $(CPP) $(DOCKER) $(FORMAT) $(RUSTUP)

SHELL_RED    := \033[0;31m
SHELL_GREEN  := \033[0;32m
SHELL_YELLOW := \033[1;33m
SHELL_CYAN   := \033[0;36m
SHELL_RESET  := \033[0m

.PHONY: check clean-all confirm-reset

tools/.sysdeps:
	$(ECHO) "$(SHELL_CYAN)Welcome to Rood Reverse!\\nChecking prerequisites and setting up remaining tools, this could take a while.\\n$(SHELL_RESET)"
	missing=0
	for cmd in $(SYSDEPS); do
		command -v "$$cmd" >/dev/null 2>&1 || { echo "Missing: $$cmd"; missing=1; }
	done
	[ $$missing -eq 0 ] || exit 1
	$(GIT) submodule update --init --recursive -q
	$(TOUCH) $@

check:
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

clean-all: confirm-reset
	$(GIT) clean -xfd -e $(DISKIMAGE)
	$(GIT) submodule foreach --recursive $(GIT) clean -xfd
	$(GIT) reset --hard
	$(GIT) submodule foreach --recursive $(GIT) reset --hard

confirm-reset:
	$(ECHO) ""
	$(ECHO) "  $(SHELL_YELLOW)⚠️  WARNING: This will delete all untracked files and reset any uncommitted changes.$(SHELL_RESET)"
	$(ECHO) ""
	read -p "  Continue? [y/N] " confirm
	$(ECHO) ""
	{ [ "$$confirm" = "y" ] || [ "$$confirm" = "Y" ]; } || { $(ECHO) "  $(SHELL_RED)Aborted.$(SHELL_RESET)"; exit 1; }

.PRECIOUS: %/
%/:
	$(MKDIR) $(MKDIRFLAGS) $(@D)

pad = @$(TRUNCATE) -s $1 $@

.SUFFIXES:
%: %,v
%: RCS/%,v
%: RCS/%
%: s.%
%: SCCS/s.%
%.c: %.w %.ch
