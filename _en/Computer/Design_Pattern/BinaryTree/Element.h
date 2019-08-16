/* Element.h
Design: decoupling
Author: BSS9395
Update: 2019-08-10T21:13
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
	void(*destruct)(struct Element *self);
	const char *(*represent)(struct Element *self);

	char *key;
	char *value;
} Element;

inline void destructElement(Element *element) {
	free(element->key);
	free(element->value);
	free(element);
}

inline const char *representElement(Element *element) {
	static char rep[BUFSIZ] = { '\0' };
	sprintf(rep, "<%p, %0.6s, %0.6s>", element, element->key, element->value);
	return rep;
}

inline Element *makeElement(char *key, char *value) {
	Element *element = (Element *)malloc(sizeof(Element));
	element->key = (char *)malloc((strlen(key) + 1) * sizeof(char));
	element->value = (char *)malloc((strlen(value) + 1) * sizeof(char));

	element->destruct = destructElement;
	element->represent = representElement;
	strcpy(element->key, key);
	strcpy(element->value, value);

	return element;
}

inline CP compareElement(void *lhs, void *rhs) {
	int cp = strcmp(((Element *)lhs)->key, ((Element *)rhs)->key);
	if (cp < 0) {
		return LT;
	}
	else if (cp > 0) {
		return GT;
	}
	return EQ;
}

#endif // Element_h
