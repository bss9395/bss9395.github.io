/* BinaryTree.h
Design: decoupling
Author: BSS9395
Update: 2019-08-10T21:13
*/

#ifndef BinaryTree_h
#define BinaryTree_h

#include "Helper.h"
#include <stdbool.h>
#include <stdlib.h>

typedef struct BinaryNode {
	Class cls;

	void *element;
	struct BinaryNode *left;
	struct BinaryNode *right;
} BinaryNode;

typedef struct BinaryTree {
	Class cls;

	struct BinaryNode head;
	long size;
	long height;

	FILE *out;
	CP(*compare)(void *lhs, void *rhs);
	void(*visit)(struct BinaryTree *self, struct BinaryNode *node);
} BinaryTree;


inline void destructNode(BinaryNode *node) {
	destruct(node->element);
	free(node);
}

inline const char *representNode(BinaryNode *node) {
	static char buf[BUFSIZ] = { '\0' };
	sprintf(buf, "%p", node);
	return buf;
}

inline BinaryNode *makeNode(void *element, BinaryNode *left, BinaryNode *right) {
	BinaryNode *node = (BinaryNode *)malloc(sizeof(BinaryNode));
	node->cls.destruct = destructNode;
	node->cls.represent = representNode;

	node->element = element;
	node->left = left;
	node->right = right;

	return node;
}

inline void inOrderTraverse(BinaryTree *tree, void(*visit)(BinaryTree *tree, BinaryNode *node));
inline void preOrderTraverse(BinaryTree *tree, void(*visit)(BinaryTree *tree, BinaryNode *node));
inline void postOrderTraverse(BinaryTree *tree, void(*visit)(BinaryTree *tree, BinaryNode *node));

inline void _deleteNode(BinaryTree *tree, BinaryNode *node) {
	destruct(node);
	tree->size--;
}

inline void destructTree(BinaryTree *tree) {
	inOrderTraverse(tree, _deleteNode);

	bool con1 = (tree->size == 0);
	bool con2 = (tree->height == 0);
	if (!(con1 &&con2)) {
		print(stderr, NULL, "void destructTree(BinaryTree *): abnormal tree.\n");
		exit(EXIT_FAILURE);
	}

	free(tree);
}

inline const char *representTree(BinaryTree *tree) {
	static char buf[BUFSIZ] = { '\0' };
	sprintf(buf, "%p", tree);
	return buf;
}

inline BinaryTree *makeTree() {
	BinaryTree *tree = (BinaryTree *)malloc(sizeof(BinaryTree));
	tree->cls.destruct = destructTree;
	tree->cls.represent = representTree;

	tree->head.element = NULL;
	tree->head.left = NULL;
	tree->head.right = NULL;
	tree->size = 0;
	tree->height = 0;

	tree->out = stdout;
	tree->compare = compare;
	tree->visit = NULL;

	return tree;
}

inline void _insertElement(BinaryTree *tree, void *element, BinaryNode **node) {
	if (*node == NULL) {
		(*node) = makeNode(element, NULL, NULL);
		tree->size++;
		return;
	}

	CP cp = tree->compare(element, (*node)->element);
	if (cp == LT) {
		_insertElement(tree, element, &((*node)->left));
	}
	else if (cp == GT) {
		_insertElement(tree, element, &((*node)->right));
	}
}

inline void insertElement(BinaryTree *tree, void *element, CP(*compare)(void *lhs, void *rhs)) {
	if (compare != NULL) {
		tree->compare = compare;
	}

	_insertElement(tree, element, &(tree->head.right));
}

inline void _inOrderTraverse(BinaryTree *tree, BinaryNode *node) {
	if (node == NULL) {
		return;
	}

	BinaryNode *left = node->left;
	BinaryNode *right = node->right;

	_inOrderTraverse(tree, left);
	tree->visit(tree, node);
	_inOrderTraverse(tree, right);
}

inline void inOrderTraverse(BinaryTree *tree, void(*visit)(BinaryTree *tree, BinaryNode *node)) {
	if (visit != NULL) {
		tree->visit = visit;
	}

	_inOrderTraverse(tree, tree->head.right);
}

inline void _preOrderTraverse(BinaryTree *tree, BinaryNode *node) {
	if (node == NULL) {
		return;
	}

	BinaryNode *left = node->left;
	BinaryNode *right = node->right;

	tree->visit(tree, node);
	_preOrderTraverse(tree, left);
	_preOrderTraverse(tree, right);
}

inline void preOrderTraverse(BinaryTree *tree, void(*visit)(BinaryTree *tree, BinaryNode *node)) {
	if (visit != NULL) {
		tree->visit = visit;
	}

	_preOrderTraverse(tree, tree->head.right);
}

inline void _postOrderTraverse(BinaryTree *tree, BinaryNode *node) {
	if (node == NULL) {
		return;
	}

	BinaryNode *left = node->left;
	BinaryNode *right = node->right;

	_postOrderTraverse(tree, left);
	_postOrderTraverse(tree, right);
	tree->visit(tree, node);
}

inline void postOrderTraverse(BinaryTree *tree, void(*visit)(BinaryTree *tree, BinaryNode *node)) {
	if (visit != NULL) {
		tree->visit = visit;
	}

	_postOrderTraverse(tree, tree->head.right);
}

inline void _printNode(BinaryTree *tree, BinaryNode *node) {
	print(tree->out, node->element);
}

inline void printTree(BinaryTree *tree, FILE *out) {
	if (out != NULL) {
		tree->out = out;
	}

	print(tree->out, NULL, "[size = %ld]: ", tree->size);
	inOrderTraverse(tree, _printNode);
	//preOrderTraverse(tree, _printNode);
	//postOrderTraverse(tree, _printNode);
	print(tree->out, NULL, "\n");
}

#endif // BinaryTree_h
