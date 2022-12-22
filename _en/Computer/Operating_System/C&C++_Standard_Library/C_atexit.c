/* C_atexit.c
Author: BSS9395
Update: 2022-12-11T20:37:00+08@China-Shanghai+08
Design: C Standard Library: atexit()
*/


#include <stdio.h>
#include <stdlib.h>

void _Func_0(void) {
	fprintf(stdout, "%s\n", __FUNCTION__);
}

void _Func_1(void) {
	fprintf(stdout, "%s\n", __FUNCTION__);
}

int main(int argc, char* argv[]) {
	fprintf(stdout, "%s\n", __FUNCTION__);
	atexit(_Func_0);
	atexit(_Func_1);
	fprintf(stdout, "%s\n", "return 0");
	return 0;
}
