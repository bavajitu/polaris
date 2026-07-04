#include <stdio.h>
#include <stdlib.h>
#include "RawMode.h"
#include <windows.h>
#include <unistd.h>

#define MAXLENGTH 10000

int main() {

	enableRawMode();

	char c;
	while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q')
		;

	return 0;
}
