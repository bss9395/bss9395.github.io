/* asctime.c
Author: BSS9395
Update: 2023-09-15T15:54:00+08@China-Guangdong-Zhanjiang+08
Design: Linux Standard Library: asctime
*/


#include <stdio.h>
#include <time.h>

/*
#include <time.h>
char *asctime(const struct tm *tm);
char *asctime_r(const struct tm *tm, char *buf);

char *ctime(const time_t *timep);
char *ctime_r(const time_t *timep, char *buf);

struct tm *gmtime(const time_t *timep);
struct tm *gmtime_r(const time_t *timep, struct tm *result);

struct tm *localtime(const time_t *timep);
struct tm *localtime_r(const time_t *timep, struct tm *result);

time_t mktime(struct tm *tm);
*/

int main(int argc, char *argv[]) {
    struct tm time;
    time.tm_year = 123;  // note: 从1900年到现在的年数
    time.tm_mon = 9;
    time.tm_mday = 15;
    time.tm_hour = 15;
    time.tm_min = 41;
    time.tm_sec = 0;
    time.tm_wday = 5;    // note: 一个星期中的第几天
    char *represent = asctime(&time);
    fprintf(stdout, "%s\n", represent);

    return 0;
}

