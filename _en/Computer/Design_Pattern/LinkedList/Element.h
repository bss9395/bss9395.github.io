/* Element.h
Design: Decoupling
Author: BSS9395
Update: 2019-08-09T23:34
*/

#ifndef Element_h
#define Element_h

#include "Helper.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

typedef struct Element {
	void(*destroy)(struct Element *self);

	char *key;
	char *value;
} Element;

inline CP compareElement(void *lhs, void *rhs) {
	int cp = strcmp(((Element *)lhs)->key, ((Element *)rhs)->key);
	if (0 < cp) {
		return GT;
	}
	else if (0 == cp) {
		return EQ;
	}
	return LT;
}

inline void destroyElement(Element *element) {
	free(element->key);
	free(element->value);
	free(element);
}

inline Element *makeElement(char *key, char *value) {
	Element *element = (Element *)malloc(sizeof(Element));
	element->key = (char *)malloc((strlen(key) + 1) * sizeof(char));
	element->value = (char *)malloc((strlen(value) + 1) * sizeof(char));

	element->destroy = destroyElement;
	strcpy(element->key, key);
	strcpy(element->value, value);

	return element;
}

inline void printElement(FILE *out, void *ele, ...) {
	if (ele) {
		Element *element = (Element *)ele;
		fprintf(out, "<%0.6s, %0.6s>", element->key, element->value);
		return;
	}

	va_list args;
	va_start(args, ele);
	vfprintf(out, va_arg(args, const char *), args);
	va_end(args);
}

#endif // Element_h
