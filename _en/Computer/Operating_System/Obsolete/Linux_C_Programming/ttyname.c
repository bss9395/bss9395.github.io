/* ttyname.c
Author: BSS9395
Update: 2023-09-18T15:52:00+08@China-Guangdong-Zhanjiang+08
Design: Linux Standard Library: ttyname
*/

#include <stdio.h>
#include <unistd.h>

/*
#include <unistd.h>
char *ttyname(int fd);
int ttyname_r(int fd, char *buf, size_t buflen);
*/

int main(int argc, char *argv[]) {
	for(int i = 0; i < 10; ++i) {
		printf("fd %d: %s\n", i, ttyname(i));
	}

	return 0;
}