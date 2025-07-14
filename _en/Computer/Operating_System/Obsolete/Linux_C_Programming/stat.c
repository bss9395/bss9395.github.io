#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>     
#include <sys/stat.h>

/*
int stat(const char *pathname, struct stat *statbuf);
int fstat(int fd, struct stat *statbuf);
int lstat(const char *pathname, struct stat *statbuf);
int fstatat(int dirfd, const char *pathname, struct stat *statbuf, int flags);
*/

struct stat {
		dev_t     st_dev;         /* ID of device containing file */
		ino_t     st_ino;         /* Inode number */
		mode_t    st_mode;        /* File type and mode */
		nlink_t   st_nlink;       /* Number of hard links */
		uid_t     st_uid;         /* User ID of owner */
		gid_t     st_gid;         /* Group ID of owner */
		dev_t     st_rdev;        /* Device ID (if special file) */
		off_t     st_size;        /* Total size, in bytes */
		blksize_t st_blksize;     /* Block size for filesystem I/O */
		blkcnt_t  st_blocks;      /* Number of 512B blocks allocated */

		/* Since Linux 2.6, the kernel supports nanosecond
		   precision for the following timestamp fields.
		   For the details before Linux 2.6, see NOTES. */

		struct timespec st_atim;  /* Time of last access */
		struct timespec st_mtim;  /* Time of last modification */
		struct timespec st_ctim;  /* Time of last status change */

#define st_atime st_atim.tv_sec      /* Backward compatibility */
#define st_mtime st_mtim.tv_sec
#define st_ctime st_ctim.tv_sec
};
#endif // 0

#include <stdio.h>
#include <stdlib.h>

int ls_file(mode_t mode) {
	char buf[10 + 1] = { '\0' };

	const mode_t rwx_mask[] = { 0, S_IRUSR, S_IWUSR, S_IXUSR, S_IRGRP, S_IWGRP, S_IXGRP, S_IROTH, S_IWOTH, S_IXOTH };
	const char rwx[] = { '-', 'r', 'w', 'x', 'r', 'w', 'x', 'r', 'w', 'x' };
	for(int i = 0; i < sizeof(rwx) / sizeof(*rwx); ++i) {
		if((mode_t)(mode & rwx_mask[i])) {
			buf[i] = rwx[i];
		}
		else {
			buf[i] = rwx[0];
		}
	}

	const mode_t type_mask[] = { S_IFSOCK, S_IFLNK, S_IFREG, S_IFBLK, S_IFDIR, S_IFCHR, S_IFIFO };
	const char type[] = { 's', 'l', '-', 'b', 'd', 'c', 'p' };
	for(int i = 0; i < sizeof(type) / sizeof(*type); ++i) {
		if((mode_t)(mode & S_IFMT) == type_mask[i]) {
			buf[0] = type[i];
		}
	}

	buf[10] = '\0';

	printf("%s\n", buf);
	fflush(stdout);

	return 0;
}

int main(int argc, char *argv[]) {
	if(argc != 2) {
		printf("usage: %s filename \n", argv[0]);
		exit(1);
	}

	struct stat st;
	stat(argv[1], &st);

	printf("dev_t     st_dev     = %ld \n", st.st_dev);
	printf("ino_t     st_ino     = %lu \n", st.st_ino);
	printf("mode_t    st_mode    = %u \n", st.st_mode);
	printf("nlink_t   st_nlink   = %ld \n", st.st_nlink);
	printf("uid_t     st_uid     = %u \n", st.st_uid);
	printf("gid_t     st_gid     = %u \n", st.st_gid);
	printf("dev_t     st_rdev    = %ld \n", st.st_rdev);
	printf("off_t     st_size    = %ld \n", st.st_size);
	printf("blksize_t st_blksize = %ld \n", st.st_blksize);
	printf("blkcnt_t  st_blocks  = %ld \n", st.st_blocks);

	printf("\n");
	ls_file(st.st_mode);

	return 0;
}
