#include <stdio.h>
#include "RawMode.h"
#include <windows.h>
#include <stdbool.h>

DWORD originalMode;
HANDLE hIn;

bool enableRawMode() {
	hIn = GetStdHandle(STD_INPUT_HANDLE);

	if (hIn == INVALID_HANDLE_VALUE) {
		return false;
	}

	if (!GetConsoleMode(hIn, &originalMode)) {
		return false;
	}

	DWORD mode = originalMode;

	mode &= ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT | ENABLE_PROCESSED_INPUT);

	if (!SetConsoleMode(hIn, mode)) {
		return false;
	}

	return true;
}

void disableRawMode() {
	SetConsoleMode(hIn, originalMode);
}