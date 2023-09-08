
#include <iostream>  
#include <windows.h>
#include <tchar.h>
#include "Interview.h"

using namespace std;

int main() {
	typedef int(*pAdd)(int, int);

	HMODULE hMoudle = LoadLibraryA("Interview.dll");
	if (hMoudle == NULL || hMoudle == INVALID_HANDLE_VALUE) {
		FreeLibrary(hMoudle);
		return -1;
	}

	pAdd add = (pAdd)GetProcAddress(hMoudle, "add");
	if (add == NULL) {
		FreeLibrary(hMoudle);
		return -1;
	}
	std::cout << add(1, 2) << std::endl;

	FreeLibrary(hMoudle);

	return 0;
}
