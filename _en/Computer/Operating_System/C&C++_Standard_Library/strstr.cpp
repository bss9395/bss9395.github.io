/* strstr.cpp
Author: BSS9395
Update: 2022-06-19T00:16:00+08@China-Shanghai+08
Design: C++ Standard Library: strstr()
*/

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
typedef intptr_t iptr;

void _strstr(string liter = "11abcd111122abcd333abcd3322abcd3333322qqq") {
	iptr count = 0;
	char* iter = &liter[0];
	char* end = &liter[liter.length()];
	while (iter < end && (iter = strstr(iter, "abcd")) != NULL) {
		count += 1;
		iter = iter + strlen("abcd");
	}
	fprintf(stdout, "count = %td\n", count);
}

int main(int argc, char* argv[]) {
	_strstr();

	return 0;
}
