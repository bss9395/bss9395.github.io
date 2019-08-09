/* LinkedList.h
Design: Decoupling
Author: BSS9395
Update: 2019-08-09T23:34
*/

#ifndef LinkedList_h
#define LinkedList_h

#include "Helper.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct LinkedNode {
	void(*destroy)(struct LinkedNode *self);

	struct LinkedNode *next;
	void *element;
} LinkedNode;

typedef struct LinkedList {
	void(*destroy)(struct LinkedList *self);

	struct LinkedNode head;
	long size;
	FILE *out;
} LinkedList;

inline void _checkIndex(long index, long bound) {
	if (0 <= index && index < bound) {
		return;
	}
	fprintf(stderr, "void _checkIndex(long, long): index out of bound.\n");
	exit(EXIT_FAILURE);
}

inline void _checkNode(void *element) {
	if (element) {
		return;
	}
	fprintf(stderr, "void _checkNode(void *): abnormal element.\n");
	exit(EXIT_FAILURE);
}

inline void destroyNode(LinkedNode *node) {
	typedef struct {
		void(*destroy)(void *);
	} Class;

	Class *ele = (Class *)(node->element);
	ele->destroy(ele);

	free(node);
}

inline LinkedNode *makeNode(void *element, LinkedNode *next) {
	LinkedNode *node = (LinkedNode *)malloc(sizeof(LinkedNode));
	node->destroy = destroyNode;
	node->element = element;
	node->next = next;
	return node;
}

inline void destroyList(LinkedList *list) {
	LinkedNode *head = list->head.next;
	LinkedNode *node = head;

	while (head != NULL) {
		head = head->next;

		node->destroy(node);
		node = head;

		list->size--;
	}

	if (0 != list->size) {
		fprintf(stderr, "void destroyList(LinkedList **): abnormal list.\n");
		exit(EXIT_FAILURE);
	}

	free(list);
}

inline LinkedList *makeList() {
	LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
	list->destroy = destroyList;

	list->head.next = NULL;
	list->head.element = NULL;
	list->size = 0;
	list->out = stdout;

	return list;
}

inline void insertNodeByIndex(LinkedList *self, long index, void *element) {
	_checkIndex(index, self->size + 1);
	_checkNode(element);

	LinkedNode *curr = &(self->head);
	for (long i = 0; i < index; ++i) {
		curr = curr->next;
	}

	LinkedNode *node = makeNode(element, curr->next);
	curr->next = node;
	self->size++;
}

inline void removeNodeByIndex(LinkedList *self, long index) {
	_checkIndex(index, self->size);

	LinkedNode *curr = &(self->head);
	for (long i = 0; i < index; ++i) {
		curr = curr->next;
	}

	LinkedNode *node = curr->next;
	curr->next = node->next;
	node->destroy(node);
}

inline void printList(LinkedList *self, FILE *out, void(*print)(FILE *out, void *element, ...)) {
	if (out) {
		self->out = out;
	}

	long i = 0;
	LinkedNode *head = self->head.next;

	print(self->out, NULL, "[size = %d]: ", self->size);
	while (head != NULL) {
		print(self->out, NULL, (i == 0 ? " " : " -> "));
		print(self->out, head->element);
		head = head->next;
		i++;
	}
	print(self->out, NULL, "\n");

	if (i != self->size) {
		fprintf(stderr, "void printList(LinkedList *, FILE *, void(*)(FILE *, void *, const char *, ...)): abnormal list.\n");
		exit(EXIT_FAILURE);
	}
}

inline void sortList(LinkedList *self, CP asc, CP(*compare)(void *lhs, void *rhs)) {
	LinkedNode tmp;
	for (LinkedNode *it = self->head.next; it != NULL; it = it->next) {
		for (LinkedNode *jt = it->next; jt != NULL; jt = jt->next) {
			if (asc == compare(jt->element, it->element)) {
				tmp = *it;
				*it = *jt;
				*jt = tmp;

				tmp.next = it->next;
				it->next = jt->next;
				jt->next = tmp.next;
			}
		}
	}
}

inline void sortListBubble(LinkedList *self, CP asc, CP(*compare)(void *lhs, void *rhs)) {
	LinkedNode *head = NULL;
	LinkedNode *end = NULL;
	LinkedNode *it = NULL;
	LinkedNode *jt = NULL;

	while (head = &(self->head), head->next != end) {
		while (it = head->next, jt = it->next, jt != end) {
			if (ASC == compare(jt->element, it->element)) {
				it->next = jt->next;
				jt->next = it;
				head->next = jt;
			}
			head = head->next;
		}
		end = head->next;
	}
}

#endif // LinkedList_h
