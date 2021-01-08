/* Logger.c
Author: BSS9395
Update: 2019-11-08T01:05:00+08 @ ShenZhen
Design: Encapsulation
*/

#define _CRT_SECURE_NO_WARNINGS
#define _GNU_SOURCE

#include <stdbool.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <time.h>

typedef enum {
	RELEASE = 0,
	DEBUG   = 1,
	INFO    = 2,
	WARN    = 3,
	ERROR   = 4,
	FATAL   = 5
} Level;

typedef struct {
	FILE *(*setup)(FILE *file, char *filename, char *format, char *timestamp);
	long  (*logging)(Level level, char *timeline, ...);
	bool  (*sync)(char *filename);
} Logger;

int checkError(const bool failed, const char *file, const long line, const char *func, const char *msg);
Logger makeLogger(void);

////////////////////////////////////////////////////////////////////////////////

#ifndef Logger_c
#define Logger_c

typedef struct {
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
	int tune;
	int zone;
} Timestamp;

int checkError(const bool failed, const char *file, const long line, const char *func, const char *msg);
Logger makeLogger(void);

////////////////////////////////////////////////////////////////////////////////

static long getTimestamp(char *format, char *timestamp);
static int parseTimestamp(char *str, Timestamp *timestamp);
static FILE *setup(FILE *file, char *filename, char *format, char *timestamp);
static long logging(Level level, char *timeline, ...);
static bool sync(char *filename);


static FILE *LOG_FILE = NULL;
static char  LOG_FILENAME[BUFSIZ]  = "file.log";
static char  LOG_FORMAT[BUFSIZ]    = "==%s==%ld==%s==%s=="; // "filename lineno function message";
static char  LOG_TIMESTAMP[BUFSIZ] = "YYYY-MM-DDThh:mm:ss.tttttt.ZZZzz";

////////////////////////////////////////////////////////////////////////////////

int checkError(const bool failed, const char *file, const long line, const char *func, const char *msg) {
	// __FILE__:__LINE__:__FUNCTION__:msg:[errno]strerror
	if(failed) {
		fprintf(stderr, "\e[33m==%s==%ld==%s==%s==[%d]%s==\e[0m\n", file, line, func, msg, errno, strerror(errno));
		if(errno){
			exit(errno);
		}
	}

	return 0;
}

Logger makeLogger(void) {
	static Logger logger = {
		.setup = setup,
		.logging = logging,
		.sync = sync
	};

	return logger;
}

static long getTimestamp(char *format, char *timestamp) {
//	char *ret = timestamp;
	Timestamp ts;
	// ts.year = 1993;
	// ts.month = 9;
	// ts.day = 5;
	// ts.hour = 19;
	// ts.minute = 30;
	// ts.second = 12;
	// ts.tune = 123456;
	// ts.zone = -812;

	char datetime[64] = "0123456789";
	time_t now = time(NULL);
	strftime(datetime, sizeof(datetime), "%Y-%m-%dT%H:%M:%S.000000%z", localtime(&now));
	sscanf(datetime, "%4u-%2u-%2uT%2u:%2u:%2u.%10u%5d", &ts.year, &ts.month, &ts.day, &ts.hour, &ts.minute, &ts.second, &ts.tune, &ts.zone);
	char *ret = timestamp;
//	printf("datetime  = %s\n", datetime);
//	printf("timestamp = %d-%d-%dT%d:%d:%d.%d%+d\n", ts.year, ts.month, ts.day, ts.hour, ts.minute, ts.second, ts.tune, ts.zone);

	int len = 0;
	for(char ch = '\0'; format[0] != '\0'; ch = format[0], format += 1) {
		timestamp[0] = format[0];
		timestamp += 1;
		if(ch == format[0]) {
			len += 1;
			if(format[0] == 'Y' && len == 4) {
				snprintf(timestamp - len, len + 1, "%.*u", len, ts.year);
				len = 0;
			}
			else if(format[0] == 'M' && len == 2) {
				snprintf(timestamp - len, len + 1, "%.*u", len, ts.month);
				len = 0;
			}
			else if(format[0] == 'D' && len == 2) {
				snprintf(timestamp - len, len + 1, "%.*u", len, ts.day);
				len = 0;
			}
			else if(format[0] == 'h' && len == 2) {
				snprintf(timestamp - len, len + 1, "%.*u", len, ts.hour);
				len = 0;
			}
			else if(format[0] == 'm' && len == 2) {
				snprintf(timestamp - len, len + 1, "%.*u", len, ts.minute);
				len = 0;
			}
			else if(format[0] == 's' && len == 2) {
				snprintf(timestamp - len, len + 1, "%.*u", len, ts.second);
				len = 0;
			}
			else if(format[0] == 't' && len == 3) {
				if(0 == strncmp(format + 1 - 6, "ttt", 3)) {
					len = 6;
				}
				snprintf(timestamp - len, len + 1, "%.*u", len, ts.tune);
				len = 0;
			}
			else if(format[0] == 'Z' && len == 3) {
				snprintf(timestamp - len, len + 1, "%+.*d", len - 1, ts.zone);
				len = 0;
			}
			else if(format[0] == 'z' && len == 2) {
				if(0 == strncmp(format + 1 - 5, "ZZZ", 3)) {
					len = 5;
					snprintf(timestamp - len, len + 1, "%+.*d", len - 1, ts.zone);
					len = 0;
				}
			}
		}
		else {
			len = 1;
		}
	}
	timestamp[0] = '\0';

//	printf("len = %d, timestamp = %s#\n", len, ret);
	return (timestamp - ret);
}

static int parseTimestamp(char *str, Timestamp *timestamp) {
	Timestamp ts = { 0 };
	static const char timestamp_set[] = "0123456789"; // "-" "T" ":" "." "+" "-";
	static const char timestamp_fmt[] = "%4u-%2u-%2uT%2u:%2u:%2u.%10u%5d";
	// static const char datetime_fmt[] = "%4u-%2u-%2uT%2u:%2u:%2u";
	// static const char date_fmt[] = "%4u-%2u-%2u";
	// static const char time_fmt[] = "%2u:%2u:%2u.%10u%5d";
	static const char timetune_fmt[] = "%2u:%2u:%2u.%10u%5d";

	char *ptr = NULL;
	long cnt = 0;
	for (ptr = str; ptr = strpbrk(ptr + cnt, timestamp_set), ptr != NULL; cnt = (1 <= cnt) ? cnt : 1) {
		memset(&ts, 0, sizeof(Timestamp));
		cnt = sscanf(ptr, timestamp_fmt, &ts.year, &ts.month, &ts.day, &ts.hour, &ts.minute, &ts.second, &ts.tune, &ts.zone);
		if (cnt == 8 || cnt == 7 || cnt == 6 || cnt == 3) {
			break;
		}

		memset(&ts, 0, sizeof(Timestamp));
		cnt = sscanf(ptr, timetune_fmt, &ts.hour, &ts.minute, &ts.second, &ts.tune, &ts.zone);
		if(cnt == 5 || cnt == 4 || cnt == 3) {
			break;
		}
	}
	// printf("cnt = %ld, %.4d-%.2d-%.2dT%.2d:%.2d:%.2d.%.6d%+.4d# \n", cnt, ts.year, ts.month, ts.day, ts.hour, ts.minute, ts.second, ts.tune, ts.zone);

	if(timestamp) {
		*timestamp = ts;
	}
	return (ptr == NULL) ? cnt : 0;
}

static FILE *setup(FILE *file, char *filename, char *format, char *timestamp) {
	char buf[BUFSIZ] = "01234567890";
	FILE *log_file = NULL;

	if(file) {
		log_file = freopen(LOG_FILENAME, "a+", file);
		checkError(log_file == NULL, __FILE__, __LINE__, __FUNCTION__, "freopen");
	}
	else if(filename == NULL) {
		log_file = fopen(LOG_FILENAME, "a+");
		checkError(log_file == NULL, __FILE__, __LINE__, __FUNCTION__, "fopen:filename == NULL");
	}
	else if(filename != NULL) {
		log_file = fopen(filename, "a+");
		checkError(log_file == NULL, __FILE__, __LINE__, __FUNCTION__, "fopen:filename != NULL");
		if(log_file) {
			strcpy(buf, LOG_FILENAME);
			strcpy(LOG_FILENAME, filename);
			strcpy(filename, buf);
		}
	}
	else if(filename[0] == '\0') {
		strcpy(filename, LOG_FILENAME);
	}

	if(format) {
		strcpy(buf, LOG_FORMAT);
		strcpy(LOG_FORMAT, format);
		strcpy(format, buf);
	}
	else if(format[0] == '\0') {
		strcpy(format, LOG_FORMAT);
	}

	if(timestamp) {
		strcpy(buf, LOG_TIMESTAMP);
		strcpy(LOG_TIMESTAMP, timestamp);
		strcpy(timestamp, buf);
	}
	else if(timestamp[0] == '\0') {
		strcpy(timestamp, LOG_TIMESTAMP);
	}

    LOG_FILE = log_file;
    return LOG_FILE;
}

static long logging(Level level, char *timeline, ...) {
	if(LOG_FILE == NULL) {
		setup(NULL, NULL, NULL, NULL);
	}
printf("ok\n");

	static const char *LEVEL[] = {
		"\e[32mRELEASE\e[0m",
		"\e[36mDEBUG\e[0m",
		"\e[34mINFO\e[0m",
		"\e[33mWARN\e[0m",
		"\e[31mERROR\e[0m",
		"\e[35mFATAL\e[0m",
		NULL
	};
	char timestamp[64] = "0123456789";
	long log_len = 0;

	log_len += fprintf(LOG_FILE, "[%s]", LEVEL[level]);
	if(timeline == NULL) {
		va_list args;
		va_start(args, timeline);
		log_len += vfprintf(LOG_FILE, LOG_FORMAT, args);
		va_end(args);
	}
	else if(strpbrk(timeline, "%")) {
		va_list args;
		va_start(args, timeline);
		log_len += vfprintf(LOG_FILE, timeline, args);
		va_end(args);
	}
	else if(timeline[0] == '\0') {
		getTimestamp(LOG_TIMESTAMP, timestamp);
		log_len += fprintf(LOG_FILE, "%s", timeline);

		va_list args;
		va_start(args, timeline);
		log_len += vfprintf(LOG_FILE, LOG_FORMAT, args);
		va_end(args);
	}
	else {
		int cnt = parseTimestamp(timeline, NULL);
		checkError(cnt == 0, __FILE__, __LINE__, __FUNCTION__, "parseTimestamp");
		if(cnt) {
			log_len += fprintf(LOG_FILE, "%s", timeline);

			va_list args;
			va_start(args, timeline);
			log_len += vfprintf(LOG_FILE, LOG_FORMAT, args);
			va_end(args);
		}
		else {
			getTimestamp(timeline, timestamp);
			log_len += fprintf(LOG_FILE, "%s", timeline);

			va_list args;
			va_start(args, timeline);
			log_len += vfprintf(LOG_FILE, LOG_FORMAT, args);
			va_end(args);
		}
	}

	log_len += fprintf(LOG_FILE, "\n");
	return log_len;
}

static bool sync(char *filename) {
	checkError(true, __FILE__, __LINE__, __FUNCTION__, "sync");
	return false;
}

#endif // Logger_c

////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[]) {
	Logger logger = makeLogger();
	logger.logging(INFO, "%s==%s==%ld==%s==%s==", "2019-11-08T01:05:00+08", __FILE__, __LINE__, __FUNCTION__, "Logger.c");

	return 0;
}
