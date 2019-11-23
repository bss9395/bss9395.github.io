/* Association.c
* Author: BSS9395
* Update: 2019-11-23T20:32:00+08@ShenZhen
* Design: Association
*/

#include <stdio.h>

typedef void* EType;

static const struct {
	void* Null;
	void* Long;
	void* Double;
	void* String;
} TYPE = { "Null", "Long", "Double", "String" };
#define Null TYPE.Null 
#define Long TYPE.Long
#define Double TYPE.Double
#define String TYPE.String

int main(int argc, char* argv[]) {
	EType type = String;

	printf("%ld\n", (long)type);
	printf("%s\n", (char*)type);

	return 0;
}