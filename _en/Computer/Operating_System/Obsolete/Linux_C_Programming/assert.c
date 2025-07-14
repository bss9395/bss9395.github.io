// #define NDEBUG

#include <stdio.h>
#include <assert.h>
#include <errno.h>

#if 0
void assert(scalar expression);
#endif // 0

int main(int argc, char *argv[]) {
	int lhs = 12;
	int rhs = 0;
	
	assert(0 == rhs);

	int ret = lhs / rhs;
	printf("lhs / rhs = %d\n", ret);

	return 0;
}
