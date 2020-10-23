/* IO.c
Auther: BSS9395
Update: 2020-10-23T19:44:00+08@China-Guangdong-Zhanjiang+08
Design: IO Control
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

long Read_Line(FILE *file, char *line, long size, const char ends[], long num) {
	long len = 0;
	bool loop = false;
	if (0 < size) {
		size -= 1;
		for (int ch = EOF; len < size; len += 1) {
		Loop:
			ch = fgetc(file);
			if (ch == EOF) {
				clearerr(file);
				goto Break;
			}
			for (int i = 0; i < num; i += 1) {
				if (ch == ends[i]) {
					loop = true;
					goto Loop;
				}
			}
			if (loop) {
				ungetc(ch, file);
				goto Break;
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
	// long len = Read_Line(stdin, line, sizeof(line) / sizeof(char), "abc", 3);
	long len = Read_Line(stdin, line, sizeof(line) / sizeof(char), "\t\v\f\r\n", 5);
	fprintf(stdout, "%ld#%s", len, line);

	fprintf(stdout, "\n==========\n");

	char buf[10] = "buf";
	fscanf(stdin, "%[^\n]%*c", buf);
	fprintf(stdout, "%s\n", buf);
}

int main(int argc, char *argv[]) {
	Test_Read_Line();

	return 0;
}
