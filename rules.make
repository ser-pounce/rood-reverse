# GNU Make 4.3
# Built for x86_64-pc-linux-gnu
# Copyright (C) 1988-2020 Free Software Foundation, Inc.
# License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
# This is free software: you are free to change and redistribute it.
# There is NO WARRANTY, to the extent permitted by law.

# Make data base, printed on Wed Apr  1 07:34:32 2026

# Variables

# default
PREPROCESS.S = $(CC) -E $(CPPFLAGS)
# default
COMPILE.m = $(OBJC) $(OBJCFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c
# default
ARFLAGS = rv
# default
AS = as
# default
AR = ar
# default
OBJC = cc
# default
LINK.S = $(CC) $(ASFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TARGET_MACH)
# default
LINK.s = $(CC) $(ASFLAGS) $(LDFLAGS) $(TARGET_MACH)
# default
MAKE_COMMAND := make
# automatic
@D = $(patsubst %/,%,$(dir $@))
# default
COFLAGS = 
# default
COMPILE.mod = $(M2C) $(M2FLAGS) $(MODFLAGS) $(TARGET_ARCH)
# default
.VARIABLES := 
# automatic
%D = $(patsubst %/,%,$(dir $%))
# default
LINK.o = $(CC) $(LDFLAGS) $(TARGET_ARCH)
# default
TEXI2DVI = texi2dvi
# automatic
^D = $(patsubst %/,%,$(dir $^))
# automatic
%F = $(notdir $%)
# default
LEX.l = $(LEX) $(LFLAGS) -t
# default
.LOADED := 
# default
.INCLUDE_DIRS = /usr/local/include /usr/include /usr/include
# default
COMPILE.c = $(CC) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c
# makefile
MAKEFLAGS = p
# default
LINK.f = $(FC) $(FFLAGS) $(LDFLAGS) $(TARGET_ARCH)
# default
TANGLE = tangle
# makefile
CURDIR := /home/lukea/rood-reverse
# default
PREPROCESS.F = $(FC) $(FFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -F
# automatic
*D = $(patsubst %/,%,$(dir $*))
# environment
MFLAGS = -p
# default
COMPILE.p = $(PC) $(PFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c
# default
.SHELLFLAGS := -c
# default
M2C = m2c
# default
COMPILE.cpp = $(COMPILE.cc)
# default
TEX = tex
# automatic
+D = $(patsubst %/,%,$(dir $+))
# makefile (from '/dev/null', line 1)
MAKEFILE_LIST := /dev/null
# default
F77FLAGS = $(FFLAGS)
# automatic
@F = $(notdir $@)
# automatic
?D = $(patsubst %/,%,$(dir $?))
# default
COMPILE.def = $(M2C) $(M2FLAGS) $(DEFFLAGS) $(TARGET_ARCH)
# default
CTANGLE = ctangle
# automatic
*F = $(notdir $*)
# automatic
<D = $(patsubst %/,%,$(dir $<))
# default
COMPILE.C = $(COMPILE.cc)
# default
YACC.m = $(YACC) $(YFLAGS)
# default
LINK.C = $(LINK.cc)
# default
MAKE_HOST := x86_64-pc-linux-gnu
# default
LINK.c = $(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TARGET_ARCH)
# default
SHELL := /bin/sh
# default
LINK.F = $(FC) $(FFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TARGET_ARCH)
# environment
MAKELEVEL := 0
# default
MAKE = $(MAKE_COMMAND)
# default
FC = f77
# default
LINT = lint
# default
PC = pc
# default
MAKEFILES := 
# automatic
^F = $(notdir $^)
# default
LEX.m = $(LEX) $(LFLAGS) -t
# default
.LIBPATTERNS = lib%.so lib%.a
# default
CPP = $(CC) -E
# default
LINK.cc = $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TARGET_ARCH)
# default
CHECKOUT,v = +$(if $(wildcard $@),,$(CO) $(COFLAGS) $< $@)
# default
COMPILE.f = $(FC) $(FFLAGS) $(TARGET_ARCH) -c
# default
COMPILE.r = $(FC) $(FFLAGS) $(RFLAGS) $(TARGET_ARCH) -c
# default
COMPILE.S = $(CC) $(ASFLAGS) $(CPPFLAGS) $(TARGET_MACH) -c
# automatic
?F = $(notdir $?)
# default
GET = get
# default
LINK.r = $(FC) $(FFLAGS) $(RFLAGS) $(LDFLAGS) $(TARGET_ARCH)
# automatic
+F = $(notdir $+)
# default
MAKEINFO = makeinfo
# 'override' directive
GNUMAKEFLAGS := 
# default
PREPROCESS.r = $(FC) $(FFLAGS) $(RFLAGS) $(TARGET_ARCH) -F
# default
LINK.m = $(OBJC) $(OBJCFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TARGET_ARCH)
# default
LINK.p = $(PC) $(PFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TARGET_ARCH)
# default
YACC = yacc
# makefile
.DEFAULT_GOAL := 
# default
RM = rm -f
# default
WEAVE = weave
# default
MAKE_VERSION := 4.3
# default
F77 = $(FC)
# default
CWEAVE = cweave
# default
YACC.y = $(YACC) $(YFLAGS)
# default
LINK.cpp = $(LINK.cc)
# default
CO = co
# default
OUTPUT_OPTION = -o $@
# default
COMPILE.s = $(AS) $(ASFLAGS) $(TARGET_MACH)
# default
MAKE_TERMERR := /dev/pts/5
# default
LEX = lex
# default
LINT.c = $(LINT) $(LINTFLAGS) $(CPPFLAGS) $(TARGET_ARCH)
# default
COMPILE.F = $(FC) $(FFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c
# default
.RECIPEPREFIX := 
# automatic
<F = $(notdir $<)
# default
SUFFIXES := .out .a .ln .o .c .cc .C .cpp .p .f .F .m .r .y .l .ym .yl .s .S .mod .sym .def .h .info .dvi .tex .texinfo .texi .txinfo .w .ch .web .sh .elc .el
# default
LD = ld
# default
.FEATURES := target-specific order-only second-expansion else-if shortest-stem undefine oneshell nocomment grouped-target extra-prereqs archives jobserver output-sync check-symlink load
# default
CXX = g++
# default
CC = cc
# default
COMPILE.cc = $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c
# variable set hash-table stats:
# Load=98/1024=10%, Rehash=0, Collisions=3/128=2%

# Pattern-specific Variable Values

# No pattern-specific variable values.

# Directories

# RCS: could not be stat'd.
# SCCS: could not be stat'd.
# /dev/RCS: could not be stat'd.
# /dev (device 5, inode 1): 193 files, 19 impossibilities.
# /dev/SCCS: could not be stat'd.

# 193 files, 19 impossibilities in 5 directories.

# Implicit Rules

%.out:

%.a:

%.ln:

%.o:

%: %.o
#  recipe to execute (built-in):
	$(LINK.o) $^ $(LOADLIBES) $(LDLIBS) -o $@

%.c:

%: %.c
#  recipe to execute (built-in):
	$(LINK.c) $^ $(LOADLIBES) $(LDLIBS) -o $@

%.ln: %.c
#  recipe to execute (built-in):
	$(LINT.c) -C$* $<

%.o: %.c
#  recipe to execute (built-in):
	$(COMPILE.c) $(OUTPUT_OPTION) $<

%.cc:

%: %.cc
#  recipe to execute (built-in):
	$(LINK.cc) $^ $(LOADLIBES) $(LDLIBS) -o $@

%.o: %.cc
#  recipe to execute (built-in):
	$(COMPILE.cc) $(OUTPUT_OPTION) $<

%.C:

%: %.C
#  recipe to execute (built-in):
	$(LINK.C) $^ $(LOADLIBES) $(LDLIBS) -o $@

%.o: %.C
#  recipe to execute (built-in):
	$(COMPILE.C) $(OUTPUT_OPTION) $<

%.cpp:

%: %.cpp
#  recipe to execute (built-in):
	$(LINK.cpp) $^ $(LOADLIBES) $(LDLIBS) -o $@

%.o: %.cpp
#  recipe to execute (built-in):
	$(COMPILE.cpp) $(OUTPUT_OPTION) $<

%.p:

%: %.p
#  recipe to execute (built-in):
	$(LINK.p) $^ $(LOADLIBES) $(LDLIBS) -o $@

%.o: %.p
#  recipe to execute (built-in):
	$(COMPILE.p) $(OUTPUT_OPTION) $<

%.f:

%: %.f
#  recipe to execute (built-in):
	$(LINK.f) $^ $(LOADLIBES) $(LDLIBS) -o $@

%.o: %.f
#  recipe to execute (built-in):
	$(COMPILE.f) $(OUTPUT_OPTION) $<

%.F:

%: %.F
#  recipe to execute (built-in):
	$(LINK.F) $^ $(LOADLIBES) $(LDLIBS) -o $@

%.o: %.F
#  recipe to execute (built-in):
	$(COMPILE.F) $(OUTPUT_OPTION) $<

%.f: %.F
#  recipe to execute (built-in):
	$(PREPROCESS.F) $(OUTPUT_OPTION) $<

%.m:

%: %.m
#  recipe to execute (built-in):
	$(LINK.m) $^ $(LOADLIBES) $(LDLIBS) -o $@

%.o: %.m
#  recipe to execute (built-in):
	$(COMPILE.m) $(OUTPUT_OPTION) $<

%.r:

%: %.r
#  recipe to execute (built-in):
	$(LINK.r) $^ $(LOADLIBES) $(LDLIBS) -o $@

%.o: %.r
#  recipe to execute (built-in):
	$(COMPILE.r) $(OUTPUT_OPTION) $<

%.f: %.r
#  recipe to execute (built-in):
	$(PREPROCESS.r) $(OUTPUT_OPTION) $<

%.y:

%.ln: %.y
#  recipe to execute (built-in):
	$(YACC.y) $< 
	 $(LINT.c) -C$* y.tab.c 
	 $(RM) y.tab.c

%.c: %.y
#  recipe to execute (built-in):
	$(YACC.y) $< 
	 mv -f y.tab.c $@

%.l:

%.ln: %.l
#  recipe to execute (built-in):
	@$(RM) $*.c
	 $(LEX.l) $< > $*.c
	$(LINT.c) -i $*.c -o $@
	 $(RM) $*.c

%.c: %.l
#  recipe to execute (built-in):
	@$(RM) $@ 
	 $(LEX.l) $< > $@

%.r: %.l
#  recipe to execute (built-in):
	$(LEX.l) $< > $@ 
	 mv -f lex.yy.r $@

%.ym:

%.m: %.ym
#  recipe to execute (built-in):
	$(YACC.m) $< 
	 mv -f y.tab.c $@

%.yl:

%.s:

%: %.s
#  recipe to execute (built-in):
	$(LINK.s) $^ $(LOADLIBES) $(LDLIBS) -o $@

%.o: %.s
#  recipe to execute (built-in):
	$(COMPILE.s) -o $@ $<

%.S:

%: %.S
#  recipe to execute (built-in):
	$(LINK.S) $^ $(LOADLIBES) $(LDLIBS) -o $@

%.o: %.S
#  recipe to execute (built-in):
	$(COMPILE.S) -o $@ $<

%.s: %.S
#  recipe to execute (built-in):
	$(PREPROCESS.S) $< > $@

%.mod:

%: %.mod
#  recipe to execute (built-in):
	$(COMPILE.mod) -o $@ -e $@ $^

%.o: %.mod
#  recipe to execute (built-in):
	$(COMPILE.mod) -o $@ $<

%.sym:

%.def:

%.sym: %.def
#  recipe to execute (built-in):
	$(COMPILE.def) -o $@ $<

%.h:

%.info:

%.dvi:

%.tex:

%.dvi: %.tex
#  recipe to execute (built-in):
	$(TEX) $<

%.texinfo:

%.info: %.texinfo
#  recipe to execute (built-in):
	$(MAKEINFO) $(MAKEINFO_FLAGS) $< -o $@

%.dvi: %.texinfo
#  recipe to execute (built-in):
	$(TEXI2DVI) $(TEXI2DVI_FLAGS) $<

%.texi:

%.info: %.texi
#  recipe to execute (built-in):
	$(MAKEINFO) $(MAKEINFO_FLAGS) $< -o $@

%.dvi: %.texi
#  recipe to execute (built-in):
	$(TEXI2DVI) $(TEXI2DVI_FLAGS) $<

%.txinfo:

%.info: %.txinfo
#  recipe to execute (built-in):
	$(MAKEINFO) $(MAKEINFO_FLAGS) $< -o $@

%.dvi: %.txinfo
#  recipe to execute (built-in):
	$(TEXI2DVI) $(TEXI2DVI_FLAGS) $<

%.w:

%.c: %.w
#  recipe to execute (built-in):
	$(CTANGLE) $< - $@

%.tex: %.w
#  recipe to execute (built-in):
	$(CWEAVE) $< - $@

%.ch:

%.web:

%.p: %.web
#  recipe to execute (built-in):
	$(TANGLE) $<

%.tex: %.web
#  recipe to execute (built-in):
	$(WEAVE) $<

%.sh:

%: %.sh
#  recipe to execute (built-in):
	cat $< >$@ 
	 chmod a+x $@

%.elc:

%.el:

(%): %
#  recipe to execute (built-in):
	$(AR) $(ARFLAGS) $@ $<

%.out: %
#  recipe to execute (built-in):
	@rm -f $@ 
	 cp $< $@

%.c: %.w %.ch
#  recipe to execute (built-in):
	$(CTANGLE) $^ $@

%.tex: %.w %.ch
#  recipe to execute (built-in):
	$(CWEAVE) $^ $@

%:: %,v
#  recipe to execute (built-in):
	$(CHECKOUT,v)

%:: RCS/%,v
#  recipe to execute (built-in):
	$(CHECKOUT,v)

%:: RCS/%
#  recipe to execute (built-in):
	$(CHECKOUT,v)

%:: s.%
#  recipe to execute (built-in):
	$(GET) $(GFLAGS) $(SCCS_OUTPUT_OPTION) $<

%:: SCCS/s.%
#  recipe to execute (built-in):
	$(GET) $(GFLAGS) $(SCCS_OUTPUT_OPTION) $<

# 92 implicit rules, 5 (5.4%) terminal.
# Files

# Not a target:
.cpp:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(LINK.cpp) $^ $(LOADLIBES) $(LDLIBS) -o $@

# Not a target:
.c.o:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(COMPILE.c) $(OUTPUT_OPTION) $<

# Not a target:
.h:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.

# Not a target:
.sh:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	cat $< >$@ 
	 chmod a+x $@

# Not a target:
.ch:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.

# Not a target:
.r.f:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(PREPROCESS.r) $(OUTPUT_OPTION) $<

# Not a target:
.dvi:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.

# Not a target:
.def.sym:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(COMPILE.def) -o $@ $<

# Not a target:
.m.o:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(COMPILE.m) $(OUTPUT_OPTION) $<

# Not a target:
.lm.m:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	@$(RM) $@ 
	 $(LEX.m) $< > $@

# Not a target:
.p.o:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(COMPILE.p) $(OUTPUT_OPTION) $<

# Not a target:
.texinfo:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.

# Not a target:
.ln:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.

# Not a target:
.C:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(LINK.C) $^ $(LOADLIBES) $(LDLIBS) -o $@

# Not a target:
.web:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.

# Not a target:
.elc:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.

# Not a target:
.y.ln:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(YACC.y) $< 
	 $(LINT.c) -C$* y.tab.c 
	 $(RM) y.tab.c

# Not a target:
.l.c:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	@$(RM) $@ 
	 $(LEX.l) $< > $@

# Not a target:
.sym:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.

# Not a target:
.r.o:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(COMPILE.r) $(OUTPUT_OPTION) $<

# Not a target:
.mod:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(COMPILE.mod) -o $@ -e $@ $^

# Not a target:
.def:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.

# Not a target:
.S:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(LINK.S) $^ $(LOADLIBES) $(LDLIBS) -o $@

# Not a target:
.texi.dvi:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(TEXI2DVI) $(TEXI2DVI_FLAGS) $<

# Not a target:
.txinfo.dvi:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(TEXI2DVI) $(TEXI2DVI_FLAGS) $<

# Not a target:
.y.c:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(YACC.y) $< 
	 mv -f y.tab.c $@

# Not a target:
.cpp.o:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(COMPILE.cpp) $(OUTPUT_OPTION) $<

# Not a target:
.el:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.

# Not a target:
.cc:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(LINK.cc) $^ $(LOADLIBES) $(LDLIBS) -o $@

# Not a target:
.tex:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.

# Not a target:
.m:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(LINK.m) $^ $(LOADLIBES) $(LDLIBS) -o $@

# Not a target:
.F:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(LINK.F) $^ $(LOADLIBES) $(LDLIBS) -o $@

# Not a target:
.web.tex:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(WEAVE) $<

# Not a target:
.texinfo.info:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(MAKEINFO) $(MAKEINFO_FLAGS) $< -o $@

# Not a target:
.ym.m:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(YACC.m) $< 
	 mv -f y.tab.c $@

# Not a target:
.l:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.

# Not a target:
.f:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(LINK.f) $^ $(LOADLIBES) $(LDLIBS) -o $@

# Not a target:
.texi:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.

# Not a target:
.DEFAULT:
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.

# Not a target:
.r:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(LINK.r) $^ $(LOADLIBES) $(LDLIBS) -o $@

# Not a target:
.a:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.

# Not a target:
.w.tex:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(CWEAVE) $< - $@

# Not a target:
.s.o:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(COMPILE.s) -o $@ $<

# Not a target:
.txinfo:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.

# Not a target:
.c.ln:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(LINT.c) -C$* $<

# Not a target:
.tex.dvi:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(TEX) $<

# Not a target:
.info:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.

# Not a target:
.out:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.

# Not a target:
.texinfo.dvi:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(TEXI2DVI) $(TEXI2DVI_FLAGS) $<

# Not a target:
.F.o:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(COMPILE.F) $(OUTPUT_OPTION) $<

# Not a target:
.yl:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.

# Not a target:
.s:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(LINK.s) $^ $(LOADLIBES) $(LDLIBS) -o $@

# Not a target:
.S.o:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(COMPILE.S) -o $@ $<

# Not a target:
.o:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(LINK.o) $^ $(LOADLIBES) $(LDLIBS) -o $@

# Not a target:
.C.o:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(COMPILE.C) $(OUTPUT_OPTION) $<

# Not a target:
.c:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(LINK.c) $^ $(LOADLIBES) $(LDLIBS) -o $@

# Not a target:
.txinfo.info:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(MAKEINFO) $(MAKEINFO_FLAGS) $< -o $@

# Not a target:
.texi.info:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(MAKEINFO) $(MAKEINFO_FLAGS) $< -o $@

# Not a target:
.y:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.

# Not a target:
.l.r:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(LEX.l) $< > $@ 
	 mv -f lex.yy.r $@

# Not a target:
.p:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(LINK.p) $^ $(LOADLIBES) $(LDLIBS) -o $@

# Not a target:
.l.ln:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	@$(RM) $*.c
	 $(LEX.l) $< > $*.c
	$(LINT.c) -i $*.c -o $@
	 $(RM) $*.c

# Not a target:
/dev/null:
#  Implicit rule search has been done.
#  Last modified 2026-04-01 07:17:44.930280404
#  File has been updated.
#  Successfully updated.

# Not a target:
.w:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.

# Not a target:
.SUFFIXES: .out .a .ln .o .c .cc .C .cpp .p .f .F .m .r .y .l .ym .yl .s .S .mod .sym .def .h .info .dvi .tex .texinfo .texi .txinfo .w .ch .web .sh .elc .el
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.

# Not a target:
.mod.o:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(COMPILE.mod) -o $@ $<

# Not a target:
.web.p:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(TANGLE) $<

# Not a target:
.S.s:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(PREPROCESS.S) $< > $@

# Not a target:
.f.o:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(COMPILE.f) $(OUTPUT_OPTION) $<

# Not a target:
.ym:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.

# Not a target:
.cc.o:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(COMPILE.cc) $(OUTPUT_OPTION) $<

# Not a target:
.F.f:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(PREPROCESS.F) $(OUTPUT_OPTION) $<

# Not a target:
.w.c:
#  Builtin rule
#  Implicit rule search has not been done.
#  Modification time never checked.
#  File has not been updated.
#  recipe to execute (built-in):
	$(CTANGLE) $< - $@

# files hash-table stats:
# Load=73/1024=7%, Rehash=0, Collisions=99/1476=7%
# VPATH Search Paths

# No 'vpath' search paths.

# No general ('VPATH' variable) search path.

# strcache buffers: 1 (0) / strings = 452 / storage = 3880 B / avg = 8 B
# current buf: size = 8162 B / used = 3880 B / count = 452 / avg = 8 B

# strcache performance: lookups = 621 / hit rate = 27%
# hash-table stats:
# Load=452/8192=6%, Rehash=0, Collisions=18/621=3%
# Finished Make data base on Wed Apr  1 07:34:32 2026

