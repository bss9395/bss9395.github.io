/* Main.c
Design: Decoupling
Author: BSS9395
Update: 2019-08-09T23:34
*/


#include "LinkedList.h"
#include "Element.h"

int main() {

	Element *e1 = makeElement("key1", "value1");
	Element *e2 = makeElement("key2", "value2");
	Element *e3 = makeElement("key3", "value3");

	LinkedList *list = makeList();

	insertNodeByIndex(list, 0, e1);
	insertNodeByIndex(list, 1, e2);
	insertNodeByIndex(list, 2, e3);

	sortList(list, ASC, compareElement);
	sortListBubble(list, ASC, compareElement);

	printList(list, stdout, printElement);
	destroyList(list);

	return 0;
}