/* Association.c
* Author: BSS9395
* Update: 2020-05-12T13:10:00+08@SChina-Guangdong-Zhanjiang+08
* Design: Association
*/

#include <stdio.h>

typedef const char* Type;
static const struct {
	const Type _Null;
	const Type _Boole;
	const Type _Long;
	const Type _Double;
	const Type _String;
} EType = { "Null", "Boole", "Long", "Double", "String" };
static const Type *AType = (Type *)&EType;

int main(int argc, char* argv[]) {
	Type type = EType._Null;
	fprintf(stderr, "%X: %s""\n", type, type);

	type = EType._Boole;
	fprintf(stderr, "%X: %s""\n", type, type);

	fprintf(stderr, "------------------""\n");

	for (int i = 0; i < sizeof(EType) / sizeof(Type); ++i) {
		printf("%X: %s""\n", AType[i], AType[i]);
	}

	return 0;
}
