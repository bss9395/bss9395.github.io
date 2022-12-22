/* DLL_LoadLibrary.c
Author: BSS9395
Update: 2022-12-10T21:20:00+08@China-Shanghai+08
Design: Windows Standary Library: LoadLibrary(), GetProcAddress(), FreeLibrary()
*/


/* Usage:
cl.exe            Math.lib Source.c    // char*    Version.
cl.exe /D UNICODE Math.lib Source.c    // wchar_t* Version.
*/

#include <Windows.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	HINSTANCE hinstance = LoadLibrary(L"Math.dll");
	if (hinstance == NULL) {
		fprintf(stderr, "Error: unable to load DLL.\n");
		return 1;
	}

	typedef double (*Func)(double, double);
	Func function = (Func)GetProcAddress(hinstance, "Add");
	if (function == NULL) {
		fprintf(stderr, "Error: unable to find DLL function.\n");
		FreeLibrary(hinstance);
		return 1;
	}

	double result = function(1.0, 2.0);
	FreeLibrary(hinstance);
	fprintf(stderr, "result = %f\n", result);

	return 0;
}
