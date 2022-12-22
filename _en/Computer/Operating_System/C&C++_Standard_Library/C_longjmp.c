/* C_setjmp.c
Author: BSS9395
Update: 2022-12-13T22:31:00+08@China-Shanghai+08
Design: C Standard Library: setjmp(), longjmp()
*/

/*
#include <csetjmp>
int setjmp (jmp_buf env);
void longjmp (jmp_buf env, int val);
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf _jmp;

void _Function() {
	fprintf(stdout, "%s\n", __FUNCTION__);

	longjmp(_jmp, 23);
}

int main(int argc, char* argv[]) {
	fprintf(stdout, "%s\n", __FUNCTION__);

	int val = setjmp(_jmp);
	if (val != 0) {
		fprintf(stderr, "Error %d happened.\n", val);
		exit(val);
	}

	////////////////////////////////////

	_Function();
}
