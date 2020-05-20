/* Another.c
Author: BSS9395
Update: 2020-05-20T16:34:00+08@China-Guangdong-Zhanjiang+08
Design: Container
*/

#include "List.c"


List *Another() {
	List *list = CreateList(EType._Double);
	double dou = 3.0;
	Node *node3 = NewNode(&dou, sizeof(double));
	list->Attach(node3, 0);

	return list;
}

