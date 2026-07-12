#include "RawMode.h"
#include <windows.h>
#include <winbase.h>
#include <stdbool.h>

#include "ErrorHandling.h"

DWORD originalMode;
HANDLE hIn;
DWORD timeoutBufferSize;
DWORD timeoutMs; // Timeout in ms

bool enableRawMode() {

	COMMTIMEOUTS timeouts = {0};

	timeoutMs = 100;

	timeouts.ReadIntervalTimeout =
	    0; // Tell Windows not to care about how much time gap is between
	       // consequent bytes
	timeouts.ReadTotalTimeoutMultiplier = 0; // Fixed duration of timeout
	timeouts.ReadTotalTimeoutConstant = timeoutMs;

	// Add the die() function for enableRawMode function, check for errors
	// while get getting the console mode.
	if (GetConsoleMode(hIn, &originalMode) == -1) {
		die("GetConsoleMode");
	};
	atexit(disableRawMode);

	hIn = GetStdHandle(STD_INPUT_HANDLE);

	if (hIn == INVALID_HANDLE_VALUE) {
		return false;
	}

	if (!GetConsoleMode(hIn, &originalMode)) {
		return false;
	}

	DWORD mode = originalMode;

	mode &=
	    ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT | ENABLE_PROCESSED_INPUT);

	if (!SetConsoleMode(hIn, mode)) {
		return false;
	}

	if (SetConsoleMode(hIn, mode) == -1) {
		die("SetConsoleMode");
	}

	return true;
}

void disableRawMode() {
	if (SetConsoleMode(hIn, originalMode) == -1) {
		die("SetConsoleMode");
	};
}
