/* String_Matcher.c
Author: BSS9395
Update: 2020-11-21T22:37:00+08@China-Guangdong-Zhanjiang+08
Design: Pattern Matcher
*/

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int8_t    in08;
typedef int16_t   in16;
typedef int32_t   in32;
typedef int64_t   in64;
typedef intptr_t  iptr;
typedef uint8_t   ui08;
typedef uint16_t  ui16;
typedef uint32_t  ui32;
typedef uint64_t  ui64;
typedef uintptr_t uptr;

typedef const ui08 *Level;
struct {
	const Level _Info;
	const Level _ToDo;
	const Level _Warn;
	const Level _Error;
	const Level _Fatal;
} ELevel;

bool Check(bool failed, Level level, const ui08 *function, const ui08 *record, const ui08 *extra) {
	if (failed) {
		(extra == NULL) ? extra = (const ui08 *)"" : extra;
		fprintf(stderr, "[%s] %s: %s%s; ""\n", level, function, record, extra);
	}

	errno = 0;
	return failed;
}

long Length(char *stri) {
	long len = -1;
	if (stri != NULL) {
		while (len += 1, stri[len] != '\0');
	}
	return len;
}

////////////////////////////////////////////////////////////////////////////////

char *Match_SubString_Classic(char *str, long len_str, char *sub, long len_sub) {
	if (Check(str == NULL || len_str < 0 || sub == NULL || len_sub < 0, ELevel._Error, __FUNCTION__, "str == NULL || len_str < 0 || sub == NULL || len_sub < 0", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (len_str < len_sub) {
		return NULL;
	}

	long idx = 0;
	char *end_str = str + len_str - len_sub + 1;
	while (str < end_str && idx < len_sub) {
		(str[idx] == sub[idx]) ? (idx += 1) : (str += 1, idx = 0);
	}
	return (idx >= len_sub) ? str : NULL;
}

char *Match_SubString_Hash_Classic(char *str, long len_str, char *sub, long len_sub) {
	if (Check(str == NULL || len_str < 0 || sub == NULL || len_sub < 0, ELevel._Error, __FUNCTION__, "str == NULL || len_str < 0 || sub == NULL || len_sub < 0", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (len_str < len_sub) {
		return NULL;
	}

	if (sizeof(ui64) <= len_sub) {
		typedef ui64 Hash;
		len_sub -= sizeof(Hash);
		char *end_str = str + len_str - sizeof(Hash) + 1;
		for (Hash hash = *(Hash *)sub; str < end_str; str += 1) {
			if (*(Hash *)str == hash) {
				long idx = 1;
				for (; idx < len_sub && *(Hash *)(str + idx) == *(Hash *)(sub + idx); idx += 1);
				if (idx >= len_sub) {
					return str;
				}
			}
		}
	}
	else if (sizeof(ui32) <= len_sub) {
		typedef ui32 Hash;
		len_sub -= sizeof(Hash);
		char *end_str = str + len_str - sizeof(Hash) + 1;
		for (Hash hash = *(Hash *)sub; str < end_str; str += 1) {
			if (*(Hash *)str == hash) {
				long idx = 1;
				for (; idx < len_sub && *(Hash *)(str + idx) == *(Hash *)(sub + idx); idx += 1);
				if (idx >= len_sub) {
					return str;
				}
			}
		}
	}
	else {
		char *end_str = str + len_str - len_sub + 1;
		for (; str < end_str; str += 1) {
			if (str[0] == sub[0]) {
				long idx = 1;
				for (; idx < len_sub && str[idx] == sub[idx]; idx += 1);
				if (idx >= len_sub) {
					return str;
				}
			}
		}
	}
	return NULL;
}

/* ! ^ ? ^ ? = !
0 ^ 0 = 0, 0 ^ 0 = 0, 0 ^ 0 ^ 0 = 0
0 ^ 1 = 1, 1 ^ 1 = 0, 0 ^ 1 ^ 1 = 0
1 ^ 0 = 1, 1 ^ 0 = 1, 1 ^ 0 ^ 0 = 1
1 ^ 1 = 0, 0 ^ 1 = 1, 1 ^ 1 ^ 1 = 1
*/
char *Match_SubString_Hash(char *str, long len_str, char *sub, long len_sub) {
	if (Check(str == NULL || len_str < 0 || sub == NULL || len_sub < 0, ELevel._Error, __FUNCTION__, "str == NULL || len_str < 0 || sub == NULL || len_sub < 0", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (len_str < len_sub) {
		return NULL;
	}

	ui64 hash_str = 0; char *ptr_str = (char *)&hash_str;
	ui64 hash_sub = 0; char *ptr_sub = (char *)&hash_sub;
	for (long i = 0; i < len_sub; i += 1) {
		ptr_str[0B0111 & i] ^= str[i];
		ptr_sub[0B0111 & i] ^= sub[i];
	}

	long idx = 0B0111 & (len_sub - 1);
	long off = sizeof(ui64) * 8 - 8;
	for (char *end_str = str + len_str - len_sub + 1; str < end_str; str += 1) {
		if (hash_str == hash_sub) {
			long i = 0;
			for (; i < len_sub && str[i] == sub[i]; i += 1);
			if (i >= len_sub) {
				return str;
			}
		}
		ptr_str[0] ^= str[0];
		hash_str = (hash_str >> 8) | (hash_str << off);
		ptr_str[idx] ^= str[len_sub];
	}
	return NULL;
}

////////////////////////////////////////////////////////////////////////////////

/* String moves forward all the way up, but Pattern will rollback once unmatch.
Si+0,Si+1,...,Si+n-1
P0  ,P1  ,...,Pn-1

Si+0,...,...,Si+j,Si+j+1
P0  ,...,...,Pj  ,Pj+1
	 P0 ,...,Pk  ,Pk+1


Case 1: Pattern Match
P0,P1,...,Pn-1 == Si+0,Si+1,...,Si+n-1

Case 2: Pattern UnMatch
P0,P1,...,Pj == Si+0,Si+1,...,Si+j  and  Pj+1 ¡Ù Si+j+1

Case 3: Pattern Rollback
P0,P1,...,Pk == Pj-k+0,Pj-k+1,...,Pj   # 0 < k < j < n
relation=> back[j+1] = k+1
optimaze=> if Pj+1 == Pk+1 then back[j+1] = back[k+1]
*/
/*
index: 0  1  2  3  4  5  6  7  8  9
sub:   b  i  g  b  i  g  g  i  r  l
back: -1  0  0  0  1  2  3  0  0  0
back: -1  0  0 -1  0  0  3  0  0  0   # Optimized
*/
long *Generate_Rollback_Index_Classical(char *sub, long back[], long len) {
	if (Check(sub == NULL || len < 0, ELevel._Error, __FUNCTION__, "str == NULL || len < 0", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (back == NULL) {
		back = (long *)calloc(len, sizeof(long));
	}

	long idx_str = 0;
	long idx_sub = -1;
	back[idx_str] = idx_sub;
	for (len -= 1; idx_str < len;) {
		if (idx_sub == -1 || sub[idx_str] == sub[idx_sub]) {
			idx_str += 1;
			idx_sub += 1;
			back[idx_str] = idx_sub;
		}
		else {
			idx_sub = back[idx_sub];
		}
	}
	return back;
}

/*
index: 0  1  2  3  4  5  6  7  8  9
sub:   b  i  g  b  i  g  g  i  r  l
back: -1  0  0  0  1  2  3  0  0  0
back: -1  0  0 -1  0  0  3  0  0  0   # Optimized
*/
long *Generate_Rollback_Index_Classic(char *sub, long back[], long len) {
	if (Check(sub == NULL || len < 0, ELevel._Error, __FUNCTION__, "str == NULL || len < 0", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (back == NULL) {
		back = (long *)calloc(len, sizeof(long));
	}

	long idx_str = 0;
	long idx_sub = -1;
	back[idx_str] = idx_sub;
	for (len -= 1; idx_str < len;) {
		while (0 <= idx_sub && sub[idx_str] != sub[idx_sub]) {
			idx_sub = back[idx_sub];
		}
		idx_str += 1;
		idx_sub += 1;
		back[idx_str] = idx_sub;
	}
	return back;
}

/*
index: 0  1  2  3  4  5  6  7  8  9
sub:   b  i  g  b  i  g  g  i  r  l
back: -1  0  0  0  1  2  3  0  0  0
back: -1  0  0 -1  0  0  3  0  0  0   # Optimized
*/
long *Generate_Rollback_Index(char *sub, long back[], long len) {
	if (Check(sub == NULL || len < 0, ELevel._Error, __FUNCTION__, "str == NULL || len < 0", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (back == NULL) {
		back = (long *)calloc(len, sizeof(long));
	}

	long idx_str = 0;
	long idx_sub = -1;
	back[idx_str] = idx_sub;
	for (len -= 1; idx_str < len;) {
		while (0 <= idx_sub && sub[idx_str] != sub[idx_sub]) {
			idx_sub = back[idx_sub];
		}
		idx_str += 1;
		idx_sub += 1;
		back[idx_str] = (sub[idx_str] == sub[idx_sub]) ? back[idx_sub] : idx_sub;
	}
	return back;
}

char *Match_SubString(char *str, long len_str, char *sub, long back[], long len_sub) {
	if (Check(str == NULL || len_str < 0 || sub == NULL || back == NULL || len_sub < 0, ELevel._Error, __FUNCTION__, "str == NULL || len_str < 0 || sub == NULL || back == NULL || len_sub < 0", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (len_str < len_sub) {
		return NULL;
	}

	char *end_str = str + len_str;
	long idx_sub = 0;
	while (str < end_str && idx_sub < len_sub) {
		while (0 <= idx_sub && str[0] != sub[idx_sub]) {
			idx_sub = back[idx_sub];
		}
		str += 1;
		idx_sub += 1;
	}
	return (idx_sub >= len_sub) ? (str - len_sub) : NULL;
}

////////////////////////////////////////////////////////////////////////////////

/* shift index: (n - 1 - m)
...,Si+0,...,...,Si+n,...              # Si+n ¡Ù Pn
	P0  ,...,...,Pn

...,Si+0,...,...,Si+n,...,Si+2n-m,...  # Si+n ¡Ô Pm
		 P0 ,...,Pm  ,...,Pn
*/
long *Generate_Shift_Index(char *sub, long shift[], long len) {
	if (Check(sub == NULL || len < 0, ELevel._Error, __FUNCTION__, "sub == NULL || len < 0", NULL)) {
		exit(EXIT_FAILURE);
	}

	long alpha = (1U << (sizeof(char) * 8));
	if (shift == NULL) {
		shift = (long *)calloc(alpha, sizeof(long));
	}

	for (long i = 0; i < alpha; i += 1) {
		shift[i] = len;
	}
	for (long i = 0; i < len; i += 1) {
		shift[sub[i]] = len - 1 - i;
	}
	return shift;
}

/*
Rollback Index
index:  0  1  2  3  4  5  6  7  8  9
sub:    b  i  g  b  i  g  g  i  r  l
back:  -1  0  0  0  1  2  3  0  0  0
back:  -1  0  0 -1  0  0  3  0  0  0   # Optimized

Reverse Index
index:  0  1  2  3  4  5  6  7  8  9
sub:    l  r  i  g  g  i  b  g  i  b
rever:  1  2  3  4  5  6  3  4  5  ?
rever:  1  2  3  4  5  6  3  8  9  ?   # Optimized
*/
long *Generate_Reverse_Index_Classic(char *sub, long rever[], long len) {
	if (Check(sub == NULL || len < 0, ELevel._Error, __FUNCTION__, "sub == NULL || len < 0", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (rever == NULL) {
		rever = (long *)calloc(len, sizeof(long));
	}

	long idx_str = len - 1;
	rever[idx_str] = -1;
	long idx_sub = idx_str - 1;
	while (0 < idx_str) {
		if (idx_sub < 0) {
			idx_str -= 1;
			rever[idx_str] = -1;
			idx_sub = idx_str - 1;
		}
		else if (sub[idx_str] == sub[idx_sub]) {
			idx_str -= 1;
			idx_sub -= 1;
			rever[idx_str] = idx_sub;
		}
		else {
			idx_sub -= 1;
		}
	}
	for (long idx = 0; idx < len; idx += 1) {
		rever[idx] = idx - rever[idx];
	}
	return rever;
}

/*
Rollback Index
index:  0  1  2  3  4  5  6  7  8  9
sub:    b  i  g  b  i  g  g  i  r  l
back:  -1  0  0  0  1  2  3  0  0  0
back:  -1  0  0 -1  0  0  3  0  0  0   # Optimized

Reverse Index
index:  0  1  2  3  4  5  6  7  8  9
sub:    l  r  i  g  g  i  b  g  i  b
rever:  1  2  3  4  5  6  3  4  5  ?
rever:  1  2  3  4  5  6  3  8  9  ?   # Optimized
*/
long *Generate_Reverse_Index(char *sub, long rever[], long len) {
	if (Check(sub == NULL || len < 0, ELevel._Error, __FUNCTION__, "sub == NULL || len < 0", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (rever == NULL) {
		rever = (long *)calloc(len, sizeof(long));
	}

	long idx_str = len - 1;
	long idx_sub = idx_str - 1;
	rever[idx_str] = len;
	while (0 <= idx_sub && sub[idx_str] != sub[idx_sub]) {
		idx_sub -= 1;
	}
	while (0 <= idx_sub) {
		idx_str -= 1;
		idx_sub -= 1;
		if (sub[idx_str] == sub[idx_sub]) {
			rever[idx_str] = idx_str + 1;
		}
		else {
			rever[idx_str] = idx_sub;
			break;
		}
	}
	while (idx_str -= 1, 0 <= idx_str) {
		rever[idx_str] = idx_str + 1;
	}
	return rever;
}

char *Match_SubString_Reverse(char *str, long len_str, char *sub, long shift[], long rever[], long len_sub) {
	if (Check(str == NULL || len_str < 0 || sub == NULL || rever == NULL || len_sub < 0, ELevel._Error, __FUNCTION__, "str == NULL || len_str < 0 || sub == NULL || back == NULL || len_sub < 0", NULL)) {
		exit(EXIT_FAILURE);
	}
	if (len_str < len_sub) {
		return NULL;
	}

	char *end_str = str + len_str - len_sub + 1;
	while (str < end_str) {
		long idx_sub = len_sub - 1;
		if (str[idx_sub] != sub[idx_sub]) {
			str += shift[str[idx_sub]];
			continue;
		}

		while (0 <= idx_sub && str[idx_sub] == sub[idx_sub]) {
			idx_sub -= 1;
		}
		if (idx_sub < 0) {
			return str;
		}
		str += rever[idx_sub];
	}
	return NULL;
}

////////////////////////////////////////////////////////////////////////////////

void Test_Match_SubString_Classic() {
	char str[] = "Thereisnoonelikeyou.";
	char sub[] = "noon";
	long len_str = Length(str);
	long len_sub = Length(sub);

	char *match = Match_SubString_Classic(str, len_str, sub, len_sub);
	fprintf(stdout, "%d, %s\n", match - str, match);
}

void Test_Match_SubString_Hash_Classic() {
	char *str = "Iamabigbiggirl,inabigbigworld.";
	char *sub = "bigbiggirl";
	long len_str = Length(str);
	long len_sub = Length(sub);
	char *match = Match_SubString_Hash_Classic(str, len_str, sub, len_sub);
	fprintf(stdout, "%s\n", match);
}

void Test_Match_SubString_Hash() {
	char *str = "Iamabigbiggirl,inabigbigworld.";
	char *sub = "bigbiggirl";
	long len_str = Length(str);
	long len_sub = Length(sub);

	char *match = Match_SubString_Hash(str, len_str, sub, len_sub);
	fprintf(stdout, "%ld, %s\n", match - str, match);
}

void Test_Rollback_Index() {
	char *sub = "bigbiggirl";
	long len = Length(sub);
	long back[100];

	// Generate_Rollback_Index_Classical(sub, back, len);
	Generate_Rollback_Index_Classic(sub, back, len);
	// Generate_Rollback_Index(sub, back, len);
	for (long i = 0; i < len; i += 1) {
		fprintf(stdout, "%ld, ", back[i]);
	}
	fprintf(stdout, "\n");
}

void Test_Match_SubString() {
	char *str = "Iamabigbiggirl,inabigbigworld.";
	char *sub = "bigbiggirl";
	long len_str = Length(str);
	long len_sub = Length(sub);
	long *back = Generate_Rollback_Index(sub, NULL, len_sub);
	char *match = Match_SubString(str, len_str, sub, back, len_sub);
	fprintf(stdout, "%ld, %s\n", match - str, match);
	free(back);
}

void Test_Generate_Reverse_Index() {
	char *str = ".dlrowgibgibani,lriggibgibamaI";
	char *sub = "lriggibgib";
	long len_str = Length(str);
	long len_sub = Length(sub);
	// long *rever = Generate_Reverse_Index_Classic(sub, NULL, len_sub);
	long *rever = Generate_Reverse_Index(sub, NULL, len_sub);
	for (long i = 0; i < len_sub; i += 1) {
		fprintf(stdout, "%ld, ", rever[i]);
	}
	fprintf(stdout, "\n");
}

void Test_Match_SubString_Reverse() {
	// char *str = "Iamabigbiggirl,inabigbigworld.";
	// char *sub = "bigbiggirl";
	char *str = ".lrowgibgibani,lriggibgibamaI";
	char *sub = "lriggibgib";
	long len_str = Length(str);
	long len_sub = Length(sub);
	long *shift = Generate_Shift_Index(sub, NULL, len_sub);
	// long *rever = Generate_Reverse_Index_Classic(sub, NULL, len_sub);
	long *rever = Generate_Reverse_Index(sub, NULL, len_sub);
	char *match = Match_SubString_Reverse(str, len_str, sub, shift, rever, len_sub);
	fprintf(stdout, "%ld, %s\n", match - str, match);
}

int main(int argc, char *argv[]) {
	// Test_Match_SubString_Classic();
	// Test_Match_SubString_Hash_Classic
	// Test_Match_SubString_Hash();
	// Test_Rollback_Index();
	// Test_Match_SubString();

	Test_Generate_Reverse_Index();
	Test_Match_SubString();

	return 0;
}
