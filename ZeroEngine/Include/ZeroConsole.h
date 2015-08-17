#pragma once

#include <io.h>
#include <fcntl.h>
#include <d3d9.h>
#include <cstdio>

class ZeroConsole {
public:
	ZeroConsole() {
		int hCrt;
		FILE* hf;

		AllocConsole();

		hCrt = _open_osfhandle(long(GetStdHandle(STD_OUTPUT_HANDLE)), _O_TEXT);
		hf = _fdopen(hCrt, "w");

		*stdout = *hf;
		setvbuf(stdout, NULL, _IONBF, 0);
	}

	~ZeroConsole() {
		_fcloseall();
		FreeConsole();
	}
};
