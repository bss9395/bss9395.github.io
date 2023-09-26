/* getpwuid.c
Author: BSS9395
Update: 2023-09-15T17:14:00+08@China-Guangdong-Zhanjiang+08
Design: Linux Standard Library: getpwuid
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>
#include <fcntl.h>     
#include <sys/stat.h>

/*
#include <sys/types.h>
#include <grp.h>
struct group *getgrnam(const char *name);
struct group *getgrgid(gid_t gid);
int getgrnam_r(const char *name, struct group *grp, char *buf, size_t buflen, struct group **result);
int getgrgid_r(gid_t gid, struct group *grp, char *buf, size_t buflen, struct group **result);
*/

int main(int argc, char *argv[]) {
    if(argc < 2) {
        fprintf(stdout, "usage: ./a.out filename\n");
        exit(EXIT_FAILURE);
    }

    char perms[10 + 1] = { '\0' };
    struct stat stat_arg;
    stat(argv[1], &stat_arg);
	const mode_t rwx_mask[] = { 0, S_IRUSR, S_IWUSR, S_IXUSR, S_IRGRP, S_IWGRP, S_IXGRP, S_IROTH, S_IWOTH, S_IXOTH };
	const char rwx[] = { '-', 'r', 'w', 'x', 'r', 'w', 'x', 'r', 'w', 'x' };
	for(int i = 0; i < sizeof(rwx) / sizeof(*rwx); ++i) {
		if((mode_t)(stat_arg.st_mode & rwx_mask[i])) {
			perms[i] = rwx[i];
		}
		else {
			perms[i] = rwx[0];
		}
	}

	const mode_t type_mask[] = { S_IFSOCK, S_IFLNK, S_IFREG, S_IFBLK, S_IFDIR, S_IFCHR, S_IFIFO };
	const char type[] = { 's', 'l', '-', 'b', 'd', 'c', 'p' };
	for(int i = 0; i < sizeof(type) / sizeof(*type); ++i) {
		if((mode_t)(stat_arg.st_mode & S_IFMT) == type_mask[i]) {
			perms[0] = type[i];
		}
	}
	perms[10] = '\0';

    int link_count = stat_arg.st_nlink;
    char *owner = getpwuid(stat_arg.st_uid)->pw_name;
    char *group = getgrgid(stat_arg.st_gid)->gr_name;
    int file_size = (int)stat_arg.st_size;
    char *time = ctime(&stat_arg.st_mtime);
    
    char time_change[512];
    strncpy(time_change, time, strlen(time) - 1);
    char buffer[1024];
    sprintf(buffer, "%s %d %s %s %d %s %s", perms, link_count, owner, group, file_size, time_change, argv[1]);
    fprintf(stdout, "%s\n", buffer);
    return 0;
}
