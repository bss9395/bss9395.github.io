/* Reverse_List.c
Author: BSS9395
Update: 2020-08-25T09:31:00+08@China-Guangdong-Zhanjiang+08
Design: Reverse Linked List
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int _data;
    struct _Node *_next;
} Node;

void Reverse_List(Node *list) {
    Node *prev = NULL;
    Node *curr = list->_next;
    Node *next = NULL;

    while (curr != NULL) {
        next = curr->_next;
        curr->_next = prev;
        prev = curr;
        curr = next;
    }
    list->_next = prev;
}

int main(int argc, char *argv[]) {
    Node list;
    Node node0 = { 9, NULL };
    Node node1 = { 0, NULL };
    Node node2 = { 8, NULL };
    Node node3 = { 2, NULL };
    Node node4 = { 6, NULL };
    Node node5 = { 1, NULL };
    Node node6 = { 3, NULL };
    Node node7 = { 4, NULL };
    Node node8 = { 5, NULL };
    Node node9 = { 7,NULL };

    list._next = &node0;
    node0._next = &node1;
    node1._next = &node2;
    node2._next = &node3;
    node3._next = &node4;
    node4._next = &node5;
    node5._next = &node6;
    node6._next = &node7;
    node7._next = &node8;
    node8._next = &node9;
    node9._next = NULL;

    for (Node *head = list._next; head != NULL; head = head->_next) {
        fprintf(stdout, " => %d", head->_data);
    }
    fprintf(stdout, "\n");

    ////////////////////////////////////

    Reverse_List(&list);

    for (Node *head = list._next; head != NULL; head = head->_next) {
        fprintf(stdout, " => %d", head->_data);
    }
    fprintf(stdout, "\n");
    return 0;
}
