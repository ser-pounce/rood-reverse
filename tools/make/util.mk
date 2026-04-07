SED      := sed
DIFF     := diff
CAT      := cat
TOUCH    := touch
ECHO     := echo
MKDIR    := mkdir
MV       := mv
FIND     := find
TRUNCATE := truncate

RMFLAGS    := -Rf
DIFFFLAGS  := -s
MKDIRFLAGS := -p

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
