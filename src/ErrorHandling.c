#include <stdio.h>
#include <stdlib.h>

#include "ErrorHandling.h"

void die(const char *s) {
	perror(1);
	exit(1);
}