/* Huffman_Coding.c
Author: BSS9395
Update: 2021-09-14T19:25:00+08@China-Guangdong-Zhanjiang+08
Design: Huffman Coding
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
    int _parent;
    int _left;
    int _right;
    double _weight;
} Node;

typedef struct _HTree {
    int _numb;
    Node *_tree;
    char **_code;
} HTree;

HTree Huffman_Conding(double weight[], int numb) {
    int size = 2 * numb - 1;
    Node *tree = (Node *)malloc(size * sizeof(Node));
    char **code = (char **)malloc(numb * sizeof(char *));

    for (int i = 0; i < numb; i += 1) {
        tree[i]._parent = -1;
        tree[i]._weight = weight[i];
    }
    for (int i = numb; i < size; i += 1) {
        tree[i]._parent = -1;
    }


    for (int parent = numb; parent < size; parent += 1) {
        int left = -1;
        int right = -1;
        for (int i = 0; i < parent; i += 1) {
            if (tree[i]._parent == -1) {
                if (left == -1) {
                    left = i;
                }
                else if (right == -1) {
                    right = i;
                    // left weight <= right weight
                    if (tree[left]._weight > tree[right]._weight) {
                        right = left;
                        left = i;
                    }
                }
                else if (tree[i]._weight < tree[right]._weight) {
                    if (tree[i]._weight < tree[left]._weight) {
                        right = left;
                        left = i;
                    }
                    else {
                        right = i;
                    }
                }
            }
        }

        tree[left]._parent = parent;
        tree[right]._parent = parent;
        tree[parent]._left = left;
        tree[parent]._right = right;
        tree[parent]._weight = tree[left]._weight + tree[right]._weight;
    }

    char *buff = (char *)malloc((numb + 1) * sizeof(char));
    buff[numb] = '\0';

    for (int i = 0; i < numb; i += 1) {
        int fore = numb;
        for (int child = i, parent = tree[child]._parent; parent != -1; child = parent, parent = tree[parent]._parent) {
            fore -= 1;
            if (tree[parent]._left == child) {
                buff[fore] = '0';
            }
            else if (tree[parent]._right == child) {
                buff[fore] = '1';
            }
        }
        code[i] = (char *)malloc((numb - fore) * sizeof(char));
        strcpy(code[i], &buff[fore]);
    }

    free(buff);
    return (HTree) { ._numb = numb, ._tree = tree, ._code = code };
}

int main(int argc, char *argv[]) {
    int numb = 5;
    double weight[5] = { 3, 5, 2, 4, 1 };
    char alpha[5] = { 'A', 'B', 'C', 'D', 'E' };

    HTree htree = Huffman_Conding(weight, numb);
    for (int i = 0; i < numb; i += 1) {
        fprintf(stdout, "%c: %s""\n", alpha[i], htree._code[i]);
    }

    return 0;
}
