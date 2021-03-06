#include <stdarg.h>

typedef struct Biobuf Biobuf;

enum
{
	Bsize		= 8*1024,
	Bungetsize	= UTFmax+1,		/* space for ungetc */
	Bmagic		= 0x314159,
	Beof		= -1,
	Bbad		= -2,

	Binactive	= 0,		/* states */
	Bractive,
	Bwactive,
	Bracteof,

	Bend
};

struct	Biobuf
{
	int	icount;		/* neg num of bytes at eob */
	int	ocount;		/* num of bytes at bob */
	int	rdline;		/* num of bytes after rdline */
	int	runesize;	/* num of bytes of last getrune */
	int	state;		/* r/w/inactive */
	int	fid;		/* open file */
	int	flag;		/* magic if malloc'ed */
	long long	offset;		/* offset of buffer in file */
	int	bsize;		/* size of buffer */
	unsigned char*	bbuf;		/* pointer to beginning of buffer */
	unsigned char*	ebuf;		/* pointer to end of buffer */
	unsigned char*	gbuf;		/* pointer to good data in buf */
	unsigned char	b[Bungetsize+Bsize];
};

/* Dregs, redefined as functions for backwards compatibility */
#define	BGETC(bp)	Bgetc(bp)
#define	BPUTC(bp,c)	Bputc(bp,c)
#define	BOFFSET(bp)	Boffset(bp)
#define	BLINELEN(bp)	Blinelen(bp)
#define	BFILDES(bp)	Bfildes(bp)

int	Bfildes(Biobuf*);
int	Bflush(Biobuf*);
int	Bgetc(Biobuf*);
int	Bgetd(Biobuf*, double*);
long	Bgetrune(Biobuf*);
int	Binit(Biobuf*, int, int);
int	Binits(Biobuf*, int, int, unsigned char*, int);
int	Blinelen(Biobuf*);
long long	Boffset(Biobuf*);
Biobuf*	Bopen(char*, int);
int	Bprint(Biobuf*, char*, ...);
int	Bvprint(Biobuf*, char*, va_list);
int	Bputc(Biobuf*, int);
int	Bputrune(Biobuf*, long);
void*	Brdline(Biobuf*, int);
char*	Brdstr(Biobuf*, int, int);
long	Bread(Biobuf*, void*, long);
long long	Bseek(Biobuf*, long long, int);
int	Bterm(Biobuf*);
int	Bungetc(Biobuf*);
int	Bungetrune(Biobuf*);
long	Bwrite(Biobuf*, void*, long);
