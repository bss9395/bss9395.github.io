
#include <iostream>
#include "Library.h"

int main(int argc, char* argv[]) {
	Library library;
	int result = library._Add(3, 4);
	fprintf(stdout, "%d\n", result);
	return 0;
}