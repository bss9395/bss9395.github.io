/* rmdir.c
Author: BSS9395
Update: 2023-09-16T10:02:00+08@China-Guangdong-Zhanjiang+08
Design: Linux Standard Library: rmdir
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdbool.h>

int rm(const char *path) {
    struct stat stat_path;
    stat(path, &stat_path);
    if(S_ISDIR(stat_path.st_mode) == false) {
        unlink(path);
        return 0;
    }

    DIR *dir = opendir(path);
    if(dir == NULL) {
        perror("open");
        return -1;
    }

    char buffer[1024];
    struct dirent *entry = NULL;
    while(entry = readdir(dir), entry != NULL) {
        sprintf(buffer, "%s/%s", path, entry->d_name);
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        rm(buffer);       
     }

    closedir(dir);
    rmdir(path);
    return 0;
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        fprintf(stdout, "%s path", argv[0]);
    }
    rm(argv[1]);

    return 0;
}
