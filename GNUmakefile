CFLAGS=-g -O2 -Wall -Wextra -Wpedantic -Werror -fstack-protector-strong -g -I. -include sys.h
CPPFLAGS='-D_FORTIFY_SOURCE='2
LDFLAGS=-L.

TARG=mk

OFILES=\
	arc.o\
	archive.o\
	bufblock.o\
	env.o\
	file.o\
	graph.o\
	job.o\
	lex.o\
	main.o\
	match.o\
	mk.o\
	parse.o\
	recipe.o\
	rc.o\
	rule.o\
	run.o\
	sh.o\
	shell.o\
	shprint.o\
	symtab.o\
	var.o\
	varsub.o\
	word.o\
	unix.o\

BIOFILES=\
	bio/bflush.o\
	bio/bgetc.o\
	bio/bgetrune.o\
	bio/binit.o\
	bio/bprint.o\
	bio/bputc.o\
	bio/bputrune.o\
	bio/bread.o\
	bio/bvprint.o\
	bio/bwrite.o\

FMTFILES=\
	fmt/charstod.o\
	fmt/dofmt.o\
	fmt/dorfmt.o\
	fmt/errfmt.o\
	fmt/fltfmt.o\
	fmt/fmt.o\
	fmt/fmtfd.o\
	fmt/fmtfdflush.o\
	fmt/fmtlocale.o\
	fmt/fmtlock.o\
	fmt/fmtnull.o\
	fmt/fmtprint.o\
	fmt/fmtquote.o\
	fmt/fmtrune.o\
	fmt/fmtstr.o\
	fmt/fmtvprint.o\
	fmt/fprint.o\
	fmt/nan64.o\
	fmt/pow10.o\
	fmt/print.o\
	fmt/runefmtstr.o\
	fmt/runeseprint.o\
	fmt/runesmprint.o\
	fmt/runesnprint.o\
	fmt/runesprint.o\
	fmt/runevseprint.o\
	fmt/runevsmprint.o\
	fmt/runevsnprint.o\
	fmt/seprint.o\
	fmt/smprint.o\
	fmt/snprint.o\
	fmt/sprint.o\
	fmt/strtod.o\
	fmt/vfprint.o\
	fmt/vseprint.o\
	fmt/vsmprint.o\
	fmt/vsnprint.o\

UTFFILES=\
	utf/rune.o\
	utf/runestrcat.o\
	utf/runestrchr.o\
	utf/runestrcmp.o\
	utf/runestrcpy.o\
	utf/runestrdup.o\
	utf/runestrecpy.o\
	utf/runestrlen.o\
	utf/runestrncat.o\
	utf/runestrncmp.o\
	utf/runestrncpy.o\
	utf/runestrrchr.o\
	utf/runestrstr.o\
	utf/runetype.o\
	utf/utfecpy.o\
	utf/utflen.o\
	utf/utfnlen.o\
	utf/utfrrune.o\
	utf/utfrune.o\
	utf/utfutf.o\

REGEXFILES=\
	regexp9/regaux.o\
	regexp9/regcomp.o\
	regexp9/regerror.o\
	regexp9/regexec.o\
	regexp9/regsub.o\
	regexp9/rregexec.o\
	regexp9/rregsub.o\

HFILES=\
	mk.h\
	fns.h\

all: libbio.a libfmt.a libutf.a libregexp9.a o.${TARG}

clean:
	rm -f ${OFILES} ${BIOFILES} ${FMTFILES} ${UTFFILES} ${REGEXFILES}

nuke: clean
	rm -f libbio.a libfmt.a libutf.a libregexp9.a o.${TARG}

.PHONY: all clean nuke

o.${TARG}: ${OFILES}
	${CC} -o $@ $^ ${LDFLAGS} -lbio -lfmt -lutf -lregexp9

libbio.a: ${BIOFILES}
libfmt.a: ${FMTFILES}
libutf.a: ${UTFFILES}
libregexp9.a: ${REGEXFILES}

%.a:
	ar rc $@ $^
	ranlib $@

%.o: %.c
	${CC} ${CFLAGS} ${CPPFLAGS} -c $^ -o $@
