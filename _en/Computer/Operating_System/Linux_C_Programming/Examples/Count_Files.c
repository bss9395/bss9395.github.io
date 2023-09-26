/* Count_Files.c
Author: BSS9395
Update: 2023-09-17T15:16:00+08@China-Guangdong-Zhanjiang+08
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdbool.h>
#include <dirent.h>

int _Count_Files(char *path) {
    int total = 0;
    struct stat stat_path;
    stat(path, &stat_path);
    if(S_ISDIR(stat_path.st_mode) == false) {
        total = 1;
        return total;
    }

    char buffer[1024];
    DIR *dir = opendir(path);
    struct dirent *entry = NULL;
    while(entry = readdir(dir), entry != NULL) {
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;            
        }
        sprintf(buffer, "%s/%s", path, entry->d_name);
        total += _Count_Files(buffer);
    }
    closedir(dir);
    return total;
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        fprintf(stdout, "usage: %s path", argv[0]);
        exit(EXIT_FAILURE);
    }

    int total = _Count_Files(argv[1]);
    fprintf(stdout, "total = %d\n", total);
    return 0;
}
