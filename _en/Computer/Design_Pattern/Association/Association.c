/* Association.c
* Author: BSS9395
* Update: 2019-11-23T20:32:00+08@ShenZhen
* Design: Association
*/

#include <stdio.h>

typedef void* EType;
static const struct {
	EType Null;
	EType Bool;
	EType Long;
	EType Double;
	EType Array;
	EType String;
	EType EType;
	EType AType;
} ETYPE = { (EType)"Null", (EType)"Bool", (EType)"Long", (EType)"Double", (EType)"Array", (EType)"String", (EType)"EType", (EType)"AType" };
static EType* ATYPE = (EType*)&ETYPE;

int main(int argc, char* argv[]) {
	EType type1 = ETYPE.String;
	printf("%ld, %s\n", (long)type1, (char*)type1);

	EType type2 = "String";
	printf("%ld, %s\n", (long)type2, (char*)type2);

	for (int i = 0; i < sizeof(ETYPE) / sizeof(EType); ++i) {
		printf("%ld, %s\n", (long)ATYPE[i], (char*)ATYPE[i]);
	}

	return 0;
}