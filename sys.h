#include <stdint.h>

#include "utf.h"
#include "fmt.h"
#include "bio.h"

/*
 * compiler directive on Plan 9
 */
#define USED(x)	if(x){}else{}

#define OREAD		O_RDONLY
#define OWRITE	O_WRONLY
#define ORDWR	O_RDWR
#define nil 0
#define nelem(x) (sizeof(x)/sizeof((x)[0]))
#define seek lseek
#define remove unlink
#define exits(x)	exit(x && *(char*)x ? 1 : 0)

/*
 * easiest way to make sure these are defined
 */
#define uchar _mk_uchar
#define uchar	_mk_uchar
#define ushort	_mk_ushort
#define uint	_mk_uint
#define ulong	_mk_ulong
#define uintptr	_mk_uintptr
#define uvlong	_mk_uvlong
#define vlong	_mk_vlong
typedef long long	vlong;
typedef unsigned long long	uvlong;
typedef unsigned char		uchar;
typedef unsigned short		ushort;
typedef unsigned int		uint;
typedef unsigned long		ulong;
typedef unsigned char uchar;
typedef uintptr_t uintptr;
