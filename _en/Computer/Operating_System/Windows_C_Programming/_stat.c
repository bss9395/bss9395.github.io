/* _stat.c
Author: BSS9395
Update: 2021-11-01T20:33:00+08@China-Guangdong-Shenzhen+08
Design: Windows C Library: _stat
*/

/*
// Windows C API
#include <sys/stat.h>
int _stat(const char *path, struct _stat *buffer);

struct stat {
    _dev_t         st_dev;    // Drive number of the disk containing the file (same as st_rdev).
    _ino_t         st_ino;    // Number of the information node (the inode) for the file (UNIX-specific). On UNIX file systems, the inode describes the file date and time stamps, permissions, and content. When files are hard-linked to one another, they share the same inode. The inode, and therefore st_ino, has no meaning in the FAT, HPFS, or NTFS file systems.
    unsigned short st_mode;   // Bit mask for file-mode information. The _S_IFDIR bit is set if path specifies a directory; the _S_IFREG bit is set if path specifies an ordinary file or a device. User read/write bits are set according to the file's permission mode; user execute bits are set according to the filename extension.
    short          st_nlink;  // Always 1 on non-NTFS file systems.
    short          st_uid;    // Numeric identifier of user who owns file (UNIX-specific). This field will always be zero on Windows systems. A redirected file is classified as a Windows file.
    short          st_gid;    // Numeric identifier of group that owns the file (UNIX-specific) This field will always be zero on Windows systems. A redirected file is classified as a Windows file.
    _dev_t         st_rdev;   // Drive number of the disk containing the file (same as st_dev).
    _off_t         st_size;   // Size of the file in bytes; a 64-bit integer for variations with the i64 suffix.
    time_t         st_atime;  // Time of last access of file. Valid on NTFS but not on FAT formatted disk drives.
    time_t         st_mtime;  // Time of last modification of file.
    time_t         st_ctime;  // Time of creation of file. Valid on NTFS but not on FAT formatted disk drives.
};
*/

#define _CRT_SECURE_NO_WARNINGS
#include <sys/stat.h>  // Windows C API
#include <direct.h>    // Windows C API
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long iptr;

iptr Make_Dir(const char *path) {
    iptr leng = (iptr)strlen(path);
    char *full = (char *)calloc(1, (leng + 1) * sizeof(char));
    if (full == NULL) {
        exit(EXIT_FAILURE);
    }

    iptr level = 0;
    iptr idx = 0;
    struct stat info = { 0 };
    for (iptr i = 0; i < leng; ) {
        if (path[i] == '/' && 0 < i && path[i - 1] != ':') {
            if (path[i - 1] == path[i]) {
                i += 1;
                continue;
            }
            full[idx] = '\0';
            if (!((stat(full, &info) == 0) && (info.st_mode & S_IFDIR))) {
                int ok = _mkdir(full);
                if (ok != 0) {
                    fprintf(stderr, "[%d] %s""\n", errno, strerror(errno));
                    level = -1;
                    goto END;
                }
            }
            level += 1;
        }
        full[idx] = path[i];
        idx += 1, i += 1;
    }
    if ((0 < leng) && (path[leng - 1] != '/')) {
        full[idx] = '\0';
        if (!((stat(full, &info) == 0) && (info.st_mode & S_IFDIR))) {
            int ok = _mkdir(full);
            if (ok != 0) {
                fprintf(stderr, "[%d] %s""\n", errno, strerror(errno));
                level = -1;
                goto END;
            }
        }
        level += 1;
    }

END:
    free(full);
    return level;
}

iptr Make_Directory(const char *path) {
    iptr leng = (iptr)strlen(path);
    char *full = (char *)calloc(1, (leng + 2) * sizeof(char));
    if (full == NULL) {
        exit(EXIT_FAILURE);
    }

    iptr idx = 0;
    for (iptr i = 0; i < leng; ) {
        if (path[i] == '/' && 0 < i && path[i - 1] == path[i]) {
            i += 1;
            continue;
        }
        full[idx] = path[i];
        idx += 1, i += 1;
    }
    full[idx] = '/';
    full[idx + 1] = '\0';
    leng = idx + 1;

    iptr level = 0;
    struct stat info = { 0 };
    for (idx = 0; idx < leng; idx += 1) {
        if (full[idx] == '/' && 0 < idx && full[idx - 1] != ':') {
            full[idx] = '\0';
            if (!((stat(full, &info) == 0) && (info.st_mode & S_IFDIR))) {
                int ok = _mkdir(full);
                if (ok != 0) {
                    fprintf(stderr, "[%d] %s""\n", errno, strerror(errno));
                    level = -1;
                    goto END;
                }
            }
            full[idx] = '/';
            level += 1;
        }
    }

END:
    free(full);
    return level;
}

int main(int argc, char *argv[]) {
    const char *path = "E:/tmp/temp/";
    iptr level = Make_Directory(path);
    fprintf(stderr, "%d", level);

    return 0;
}
