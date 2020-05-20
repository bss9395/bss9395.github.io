/* Another.c
Author: BSS9395
Update: 2020-05-20T15:21:00+08@China-Guangdong-Zhanjiang+08
Design: Container
*/

#define List_c
#include "List.c"


List *Another() {
	List *list = CreateList();
	Node *node2 = NewNode("node2_in_Another");
	list->Attach(node2, 0);
	// list->Traverse();

	return list;
}

