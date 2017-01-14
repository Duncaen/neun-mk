#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "regexp9.h"

void
regerror9(char *s)
{
	fprint(2, "regerror: %s\n", s);
	exit(1);
}
