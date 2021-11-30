/* _findclose.c
Author: BSS9395
Update: 2021-11-30T23:44:00+08@China-Guangdong-Shenzhen+08
Design: Windows C Library: _findclose
Credit: https://docs.microsoft.com/en-us/cpp/c-runtime-library/filename-search-functions?view=msvc-170
*/

/* Windows C Library
#include <io.h>

#define _A_NORMAL 0x00 // Normal file - No read/write restrictions
#define _A_RDONLY 0x01 // Read only file
#define _A_HIDDEN 0x02 // Hidden file
#define _A_SYSTEM 0x04 // System file
#define _A_SUBDIR 0x10 // Subdirectory
#define _A_ARCH   0x20 // Archive file

struct __finddata64_t {
    unsigned    attrib;
    __time64_t  time_create;    // -1 for FAT file systems
    __time64_t  time_access;    // -1 for FAT file systems
    __time64_t  time_write;
    __int64     size;
    char        name[260];
};

intptr_t _findfirst(const char *filespec, struct _finddata_t *fileinfo);
int _findnext(intptr_t handle, struct _finddata_t *fileinfo);
int _findclose(intptr_t handle);
*/

#define _CRT_SECURE_NO_WARNINGS
#include <io.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef intptr_t iptr;
typedef struct {
    iptr _numb;
    iptr _size;
    char **_filenames;
} Filenames;

void Get_Filenames(Filenames *data, char *directory, const char *format) {
    const char sepa = '/';
    iptr dire_leng = strlen(directory) + 1;
    directory[dire_leng - 1] = sepa;
    strcpy(&directory[dire_leng], format);

    struct _finddata_t find_data = { 0 };
    iptr handle = _findfirst(directory, &find_data);
    if (handle != -1) {
        do {
            if (find_data.attrib & _A_SUBDIR) {
                if (0 == strcmp(find_data.name, ".") || 0 == strcmp(find_data.name, "..")) {
                    continue;
                }
                strcpy(&directory[dire_leng], find_data.name);
                Get_Filenames(data, directory, format);
            } else {
                if (data->_size <= data->_numb) {
                    data->_size = data->_size * 2;
                    data->_filenames = (char **)realloc(data->_filenames, data->_size * sizeof(char*));
                }
                iptr leng = strlen(find_data.name);
                data->_filenames[data->_numb] = (char *)calloc(1, (dire_leng + leng + 1) * sizeof(char)); // including the terminated '\0'
                memcpy(&data->_filenames[data->_numb][0], directory, dire_leng);
                strcpy(&data->_filenames[data->_numb][dire_leng], find_data.name);
                data->_numb += 1;
            }
        } while (0 == _findnext(handle, &find_data));
        _findclose(handle);
    }
}


int main(int argc, char *argv[]) {
    Filenames data = { 0 };
    data._numb = 0;
    data._size = 4;
    data._filenames = (char**)calloc(1, data._size * sizeof(char*));

    char buffer[1024] = "C:/Users/bss9395/Pictures";
    Get_Filenames(&data, buffer, "*.*");
    Get_Filenames(&data, buffer, "*.png*");

    fprintf(stdout, "data->_numb = %td""\n", data._numb);
    for (iptr i = 0; i < data._numb; i += 1) {
        fprintf(stdout, "%s""\n", data._filenames[i]);
    }

    for (iptr i = 0; i < data._numb; i += 1) {
        free(data._filenames[i]);
    }
    free(data._filenames);
    return 0;
}
