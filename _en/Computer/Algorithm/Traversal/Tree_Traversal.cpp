/* Tree_Traversal_by_Stack.cpp
Author: BSS9395
Update: 2020-03-10T18:54:00+08@China-Guangdong-Zhanjiang
Algorithm: Tree Traversal
*/

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <string>
#include <queue>
#include <stack>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::queue;
using std::stack;

typedef string Node;

class Tree {
public:
	Tree(const Node &value = Node(), Tree *left = nullptr, Tree *right = nullptr)
		: _value(value), _left(left), _right(right) {
		// cerr << __FUNCTION__ << endl;
	}

	~Tree() {
		// cerr << __FUNCTION__ << endl;
	}

public:
	void _visit(Tree *tree) {
		cerr << tree->_value << " ";
	}

	void _preOrder(Tree *tree) {
		if (tree != nullptr) {
			_visit(tree);
			_preOrder(tree->_left);
			_preOrder(tree->_right);
		}
	}

	void _preOrder_by_stack(Tree *tree) {
		stack<Tree *> order;
		while (true) {
			if (tree != nullptr) {
				tree->_visit(tree);
				order.push(tree->_right);
				tree = tree->_left;
			}
			else if (!order.empty()) {
				tree = order.top();
				order.pop();
			}
			else {
				break;
			}
		}
	}

	void _inOrder(Tree *tree) {
		if (tree != nullptr) {
			_inOrder(tree->_left);
			_visit(tree);
			_inOrder(tree->_right);
		}
	}

	void _inOrder_by_stack(Tree *tree) {
		stack<Tree *> order;
		while (true) {
			if (tree != nullptr) {
				order.push(tree);
				tree = tree->_left;
			}
			else if (!order.empty()) {
				tree = order.top();
				order.pop();
				tree->_visit(tree);
				tree = tree->_right;
			}
			else {
				break;
			}
		}
	}

	void _postOrder(Tree *tree) {
		if (tree != nullptr) {
			_postOrder(tree->_left);
			_postOrder(tree->_right);
			_visit(tree);
		}
	}

	void _postOrder_by_stack(Tree *tree) {
		stack<Tree *> order;
		Tree *right = tree;
		while (true) {
			if (tree != nullptr) {
				order.push(tree);
				tree = tree->_left;
			}
			else if (!order.empty()) {
				tree = order.top();
				if (tree->_right != nullptr) {
					tree = tree->_right;
					continue;
				}
				do {
					order.pop();
					tree->_visit(tree);
					if (!order.empty()) {
						right = tree;
						tree = order.top();
					}
					else {
						break;
					}
				} while (tree->_right == right);
				tree = nullptr;
			}
			else {
				break;
			}
		}
	}

	void _levelOrder(Tree *tree) {
		queue<Tree *> level;
		level.push(tree);
		while (!level.empty()) {
			Tree *node = level.front();
			level.pop();
			if (node != nullptr) {
				node->visit();
				level.push(node->_left);
				level.push(node->_right);
			}
		}
	}

public:
	void visit() {
		cerr << _value << " ";
	}

	void preOrder() {
		visit();
		if (_left != nullptr) {
			_left->preOrder();
		}
		if (_right != nullptr) {
			_right->preOrder();
		}
	}

	void preOrder_by_stack() {
		Tree *tree = this;
		// tree->preOrder_by_stack(tree);

		stack<Tree *> order;
		while (true) {
			tree->visit();
			if (tree->_right != nullptr) {
				order.push(tree->_right);
			}

			if (tree->_left != nullptr) {
				tree = tree->_left;
			}
			else if (!order.empty()) {
				tree = order.top();
				order.pop();
			}
			else {
				break;
			}
		}
	}

	void inOrder() {
		if (_left != nullptr) {
			_left->inOrder();
		}
		visit();
		if (_right != nullptr) {
			_right->inOrder();
		}
	}

	void inOrder_by_stack() {
		Tree *tree = this;
		// tree->inOrder_by_stack(tree);

		stack<Tree *> order;
		bool goon = true;
		while (goon) {
			order.push(tree);
			if (tree->_left != nullptr) {
				tree = tree->_left;
			}
			else if (!order.empty()) {
				goon = false;
				do {
					tree = order.top();
					order.pop();
					tree->visit();
					if (tree->_right != nullptr) {
						tree = tree->_right;
						goon = true;
						break;
					}
				} while (!order.empty());
			}
			else {
				break;
			}
		}
	}

	void postOrder() {
		if (_left != nullptr) {
			_left->postOrder();
		}
		if (_right != nullptr) {
			_right->postOrder();
		}
		visit();
	}

	void postOrder_by_stack() {
		Tree *tree = this;
		// tree->postOrder_by_stack(tree);

		stack<Tree *> order;
		Tree *right = tree;
		bool goon = true;
		while (goon) {
			order.push(tree);
			if (tree->_left != nullptr) {
				tree = tree->_left;
			}
			else if (!order.empty()) {
				do {
					tree = order.top();
					if (tree->_right != nullptr) {
						tree = tree->_right;
						break;
					}
					do {
						order.pop();
						tree->visit();
						if (!order.empty()) {
							right = tree;
							tree = order.top();
						}
						else {
							goon = false;
							break;
						}
					} while (tree->_right == right);
				} while (goon);
			}
			else {
				break;
			}
		}
	}

	void levelOrder() {
		queue<Tree *> level;
		level.push(this);
		while (!level.empty()) {
			Tree *node = level.front();
			level.pop();
			node->visit();
			if (node->_left != nullptr) {
				level.push(node->_left);
			}
			if (node->_right != nullptr) {
				level.push(node->_right);
			}
		}
	}

public:
	Node _value;
	Tree *_left;
	Tree *_right;
};

#define Main
#ifdef Main
int main(int argc, char *argv[]) {
	Tree tree;
	Tree node0("+");
	Tree node1("A");
	Tree node2("¡Á");
	Tree node3("B");
	Tree node4("+");
	Tree node5("C");
	Tree node6("D");

	node0._left = &node1;
	node0._right = &node2;
	node2._left = &node3;
	node2._right = &node4;
	node4._left = &node5;
	node4._right = &node6;

	node0.postOrder();
	node0.postOrder_by_stack();

	return 0;
}
#endif // Main
