/* BSearch.c
Author: BSS9395
Update: 2022-07-07T13:42:00+08@China-Shanghai+08
Design: BSearch
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef intptr_t iptr;

const char* BSearch(const char* key, const char* base, iptr numb, iptr size, iptr(*Compare)(const char*, const char*)) {
	if (key == NULL || base == NULL || numb <= 0 || size <= 0) {
		return NULL;
	}

	iptr head = 0;
	iptr tail = numb;    // note: tail is the one after the last one in the array.
	while (head < tail) {
		iptr mid = (head + tail) / 2;
		const char* iter = &base[size * mid];
		if (Compare(key, iter) < 0) {
			tail = mid;
		}
		else if (Compare(key, iter) > 0) {
			head = mid + 1;
		}
		else {
			return iter;
		}
	}
	return NULL;
}

iptr Compare_int(const char* lhs, const char* rhs) {
	if (*(int*)lhs < *(int*)rhs) {
		return -1;
	}
	else if (*(int*)lhs > *(int*)rhs) {
		return +1;
	}
	else {
		return 0;
	}
}

iptr Compare_cstring(const char* lhs, const char* rhs) {
	return strcmp(*(const char **)lhs, *(const char **)rhs);
}


void Test_Compare_int() {
	int inte[] = {
		-2, 0, 1, 3, 4, 5, 5, 8, 9, 10
	};
	iptr numb = sizeof(inte) / sizeof(inte[0]);

	int key = 5;
	int* found = (int *)BSearch((char *)&key, (char *)inte, numb, sizeof(inte[0]), Compare_int);
	if (found != NULL) {
		fprintf(stdout, "found = %d""\n", *found);
	}
}

void Test_Compare_cstring() {
	const char* cstr[] = {
		"chenwei", "dmr", "skyline", "wel", "what"
	};
	iptr numb = sizeof(cstr) / sizeof(cstr[0]);

	const char* key = "chenwei";
	char** found = (char**)BSearch((char *)&key, (char *)cstr, numb, sizeof(cstr[0]), Compare_cstring);
	if (found != NULL) {
		fprintf(stdout, "found = %s""\n", *found);
	}
}

int main(int argc, char* argv[]) {
	// Test_Compare_int();
	Test_Compare_cstring();

	return 0;
}
