/* IO.c
Auther: BSS9395
Update: 2020-10-23T19:44:00+08@China-Guangdong-Zhanjiang+08
Design: IO Control
*/

#include <stdio.h>

long Read_Line(FILE *file, char *line, long size, const char ends[], long num) {
	long len = 0;
	if (0 < size) {
		size -= 1;
		for (int ch = EOF; len < size; len += 1) {
			ch = fgetc(file);
			if (ch == EOF) {
				clearerr(file);
				goto Break;
			}
			for (int i = 0; i < num; i += 1) {
				if (ch == ends[i]) {
					goto Break;
				}
			}
			line[len] = ch;
		}
	Break:
		line[len] = '\0';
	}
	return len;
}

void Test_Read_Line() {
	char line[10];
	long len = Read_Line(stdin, line, sizeof(line) / sizeof(char), "\r\n", 2);
	fprintf(stdout, "%ld#%s", len, line);
}

int main(int argc, char *argv[]) {
	Test_Read_Line();

	return 0;
}
