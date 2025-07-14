/* readdir.c
Author: BSS9395
Update: 2023-09-15T15:25:00+08@China-Guangdong-Zhanjiang+08
Design: Linux Standard Library: readdir
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>

/*
#include <dirent.h>
struct dirent *readdir(DIR *dirp);
*/

int main(int argc, char *argv[]) {
	DIR *dir = opendir("/home/");
	if (NULL == dir) {
		perror("opendir");
	}

	struct dirent *ent = NULL;
	while (ent = readdir(dir), NULL != ent) {
		printf("__ino64_t          d_ino;       = %ld\n", ent->d_ino);
		printf("__off64_t          d_off;       = %ld\n", ent->d_off);
		printf("unsigned short int d_reclen;    = %hu\n", ent->d_reclen);
		printf("unsigned char      d_type;      = %hhu\n", ent->d_type);
		printf("char               d_name[256]; = %s\n", ent->d_name);

		switch (ent->d_type) {
		case DT_UNKNOWN:
			printf("δ֪�ļ�\n");
			break;
		case DT_FIFO:
			printf("�ܵ��ļ�\n");
			break;
		case DT_CHR:
			printf("�ַ��ļ�\n");
			break;
		case DT_DIR:
			printf("Ŀ¼�ļ�\n");
			break;
		case DT_BLK:
			printf("���ļ�\n");
			break;
		case DT_REG:
			printf("��ͨ�ļ�\n");
			break;
		case DT_LNK:
			printf("��������\n");
			break;
		case DT_SOCK:
			printf("�׽����ļ�\n");
			break;
		case DT_WHT:
			printf("DT_WHT\n");
			break;
		}

		printf("-----------------------------------------------------------\n");
	}

	closedir(dir);
	return 0;
}
