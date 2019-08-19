/* Main.c
Design: decoupling
Author: BSS9395
Update: 2019-08-10T21:13 +08
*/

#include "BinaryTree.h"
#include "Element.h"

int main() {
	BinaryTree *tree = makeTree();

	Element *e1 = makeElement("key1", "value1");
	Element *e2 = makeElement("key2", "value2");
	Element *e3 = makeElement("key3", "vlaue3");

	insertElement(tree, e2, compareElement);
	insertElement(tree, e1, compareElement);
	insertElement(tree, e3, compareElement);

	printTree(tree, stdout);
	destruct(tree);

	return 0;
}