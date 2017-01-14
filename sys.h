#include <utf.h>
#include <fmt.h>
#include <bio.h>
#include <regexp9.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdint.h>

#define OREAD		O_RDONLY
#define OWRITE	O_WRONLY
#define ORDWR	O_RDWR
#define nil 0
#define nelem(x) (sizeof(x)/sizeof((x)[0]))
#define seek lseek
#define remove unlink
#define exits(x)	exit(x && *(char*)x ? 1 : 0)
#define USED(x)	if(x){}else{}
#define create(name, mode, perm)	open(name, mode|O_CREAT, perm)
#define ERRMAX	256

typedef uintptr_t uintptr;
#define uchar mk_uchar
typedef unsigned char uchar;

#define timespecclear(tsp)              (tsp)->tv_sec = (tsp)->tv_nsec = 0
#define timespecisset(tsp)              ((tsp)->tv_sec || (tsp)->tv_nsec)
#define timespeccmp(tsp, usp, cmp)                                      \
        (((tsp)->tv_sec == (usp)->tv_sec) ?                             \
            ((tsp)->tv_nsec cmp (usp)->tv_nsec) :                       \
            ((tsp)->tv_sec cmp (usp)->tv_sec))

#ifdef __has_include
  #if __has_include(<stdnoreturn.h>)
    #include <stdnoreturn.h>
  #else
    #define noreturn /**/
  #endif
#else
  #define noreturn /**/
#endif
