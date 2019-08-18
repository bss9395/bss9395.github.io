/* BalanceTree.cpp
Author: BSS9395
Update: 2018-07-02T19:15:00 +08
*/

#ifndef BalanceTree_h
#define BalanceTree_h

#include "BalanceNode.h"
template<typename T>
class BalanceNode;

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

#include <string>
using std::string;

#include <initializer_list>
using std::initializer_list;

#include <queue>
using std::queue;

#include <utility>
using std::pair;

#include <stdexcept>
using std::logic_error;
using std::out_of_range;

#include <cmath>
using std::min;
using std::max;
using std::exp2;
using std::log2;

/* RightRotate: G
	   G2          P0
	  / \         / \
	 P1  H       H   G0
	/ \          |  / \
   H   H         n H   H
   |
   n
*/
/* LeftRotate, RightRotate: P, G
	   G2          G2          C0
	  / \         / \         / \
	 P-1 H       C2  H       P0  G-1
	/ \         / \         / \ / \
   H   C1      P0  I       H  I I  H
	  / \     / \             |
	 I   I   H   I            n
	 |           |
	 n           n
*/
/* LeftRotate, RightRotate: P, G
	   G2          G2          C0
	  / \         / \         / \
	 P-1 H       C1  H       P1  G0
	/ \         / \         / \ / \
   H   C-1     P1  I       H  I I  H
	  / \     / \  |            |
	 I   I   H   I n            n
		 |
		 n
*/
/* LeftRotate, Rightotate: P, G
	   G2          G2          C0
	  /           /           / \
	 P-1         C1          P0  G0
	  \         /
	   C0      P0
*/
/* LeftRotate: G
	   G-2         P0
	  / \         / \
	 H   P-1     G0  H
		/ \     / \  |
	   H   H   H   H n
		   |
		   n
*/
/* RightRotate, LeftRotate: P, G
	   G-2         G-2          C0
	  / \         / \          / \
	 H   P1      H   C-2      G1  P0
		/ \         / \      / \ / \
	   C-1 H       I   P0   H  I I  H
	  / \             / \        |
	 I   I           I   H       n
		 |           |
		 n           n
*/
/* RightRotate, LeftRotate: P, G
	   G-2         G-2          C0
	  / \         / \          / \
	 H   P1      H   C-1      G0  P-1
		/ \         / \      / \ / \
	   C1  H       I   P-1  H  I I  H
	  / \          |  / \      |
	 I   I         n I   H     n
	 |
	 n
*/
/* RightRotate, LeftRotate: P, G
	   G-2         G-2          C0
		\           \          / \
		 P1          C-1      G0  P0
		/             \
	   C0              P0
*/
/* data: { 13, 24, 37, 90, 53 }
-------------------------------
		   13
-------------------------------
		   13
			\
			 24
-------------------------------
		   13          24
			\         / \
			 24      13  37
			  \
			   37
-------------------------------
		   24
		  / \
		 13  37
			  \
			   90
-------------------------------
		   24          24
		  / \         / \
		 13  37      13  53
			  \         / \
			   90      37  90
			  /
			 53
*/

template<typename T>
class BalanceTree {
	static ostream *__os;
public:
	typedef class BalanceNode<T> BalanceNode;
public:
	BalanceTree()
		: _size(0), _head(T(), 0, nullptr, nullptr) {

	}
	BalanceTree(initializer_list<T> il)
		: _size(0), _head(T(), 0, nullptr, nullptr) {

		for (auto &e : il) {
			BalanceNode *node = new BalanceNode(e, 0, nullptr, nullptr);
			insert(e);
		}
	}
	BalanceTree(const BalanceTree &tree)
		: _size(tree._size), _head(tree._head) {
		queue<pair<const BalanceNode *, BalanceNode *>> level;
		level.push({ &tree._head, &_head });

		pair<const BalanceNode *, BalanceNode *> node;
		while (!level.empty()) {
			node = level.front();
			level.pop();

			if (node.first->_left != nullptr) {
				node.second->_left = new BalanceNode(node.first->_left->_element, 0, nullptr, nullptr);
				level.push({ node.first->_left, node.second->_left });
			}
			if (node.first->_right != nullptr) {
				node.second->_right = new BalanceNode(node.first->_right->_element, 0, nullptr, nullptr);
				level.push({ node.first->_right, node.second->_right });
			}
		}
	}
	~BalanceTree() {
		_clear();
		_reset();
	}
public:
	auto search(const T &element) -> BalanceNode *& {
		return _search(_head._right, element);
	}
	auto insert(const T &element) -> void {
		_insert(_head._right, element);
	}
	auto preOrder() -> void {
		_first = true;
		_visit = &BalanceTree::_print;

		(*__os) << "[size: " << _size << ", preOrder()] ";
		_preOrder(_head._right);
		(*__os) << endl;
	}
	auto inOrder() -> void {
		_first = true;
		_visit = &BalanceTree::_print;

		(*__os) << "[size: " << _size << ", inOrder()] ";
		_inOrder(_head._right);
		(*__os) << endl;
	}
	auto postOrder() -> void {
		_first = true;
		_visit = &BalanceTree::_print;

		(*__os) << "[size: " << _size << ", postOrder()] ";
		_postOrder(_head._right);
		(*__os) << endl;
	}
	auto levelOrder() -> void {
		_first = true;
		_visit = &BalanceTree::_print;

		(*__os) << "[size: " << _size << ", levelOrder()] ";
		_levelOrder(_head._right);
		(*__os) << endl;
	}
protected:
	auto _search(BalanceNode *(&tree), const T &element) -> BalanceNode *& {
		if (tree == nullptr) {
			return tree;
		}
		else if (element < tree->_element) {
			return _search(tree->_left, element);
		}
		else if (tree->_element < element) {
			return _search(tree->_right, element);
		}
		return tree; // tree->_element == element;
	}
	auto _insert(BalanceNode *(&tree), const T &element) -> bool {
		if (tree == nullptr) {
			tree = new BalanceNode(element, 0, nullptr, nullptr);
			_size++;
			return true;
		}
		else if (element < tree->_element) {
			if (_insert(tree->_left, element)) {
				tree->_balance += 1;
				if (2 == tree->_balance) {
					switch (tree->_left->_balance) {
					case 1:
						_rightRotate(tree);
						tree->_balance = 0;
						tree->_right->_balance = 0;
						break;
					case -1:
						_leftRotate(tree->_left);
						_rightRotate(tree);
						switch (tree->_balance) {
						case 1:
							tree->_balance = 0;
							tree->_left->_balance = 0;
							tree->_right->_balance = -1;
							break;
						case 0:
							tree->_balance = 0;
							tree->_left->_balance = 0;
							tree->_right->_balance = 0;
							break;
						case -1:
							tree->_balance = 0;
							tree->_left->_balance = 1;
							tree->_right->_balance = 0;
							break;
						default:
							throw logic_error("_insert(BalanceNode *&, const T &): switch(tree->_balance).");
						}
						break;
					default:
						throw logic_error("_insert(BalanceNode *&, const T &): switch(tree->_left->_balance).");
					}
					return false;
				}
				return (tree->_balance > 0);
			}
		}
		else if (tree->_element < element) {
			if (_insert(tree->_right, element)) {
				tree->_balance -= 1;
				if (-2 == tree->_balance) {
					switch (tree->_right->_balance) {
					case -1:
						_leftRotate(tree);
						tree->_balance = 0;
						tree->_left->_balance = 0;
						break;
					case 1:
						_rightRotate(tree->_right);
						_leftRotate(tree);
						switch (tree->_balance) {
						case -1:
							tree->_balance = 0;
							tree->_left->_balance = 1;
							tree->_right->_balance = 0;
							break;
						case 0:
							tree->_balance = 0;
							tree->_left->_balance = 0;
							tree->_right->_balance = 0;
							break;
						case 1:
							tree->_balance = 0;
							tree->_left->_balance = 0;
							tree->_right->_balance = -1;
							break;
						default:
							throw logic_error("_insert(BalanceNode *&, const T &): switch(tree->_balance).");
						}
						break;
					default:
						throw logic_error("_insert(BalanceNode *&, const T &): switch(tree->_right->_balance).");
					}
					return false;
				}
				return (tree->_balance < 0);
			}
		}
		return false; // tree->_element == node->_element;
	}
	auto _leftRotate(BalanceNode *(&tree)) -> void {
		BalanceNode *node = tree->_right;
		tree->_right = node->_left;
		node->_left = tree;
		tree = node;
	}
	auto _rightRotate(BalanceNode *(&tree)) {
		BalanceNode *node = tree->_left;
		tree->_left = node->_right;
		node->_right = tree;
		tree = node;
	}
	auto _print(BalanceNode *node) -> void {
		(*__os) << (_first ? (_first = false, "") : "->");
		(*__os) << "(" << node->_balance << ", " << node->_element << ")";
	}
	auto _count(BalanceNode *node) -> void {
		_size++;
	}
	auto _delete(BalanceNode *node) -> void {
		(*__os) << (_first ? (_first = false, "") : "<-");
		(*__os) << node->_element;
		delete node;
	}
	auto _height(BalanceNode *node) -> long {
		if (node == nullptr) {
			return 0;
		}
		long lhs = _height(node->_left);
		long rhs = _height(node->_right);

		return max(lhs, rhs) + 1;
	}
	auto _preOrder(BalanceNode *node) -> void {
		if (node != nullptr) {
			BalanceNode *left = node->_left;
			BalanceNode *right = node->_right;
			(this->*_visit)(node);
			_preOrder(left);
			_preOrder(right);
		}
	}
	auto _inOrder(BalanceNode *node) -> void {
		if (node != nullptr) {
			BalanceNode *left = node->_left;
			BalanceNode *right = node->_right;
			_inOrder(left);
			(this->*_visit)(node);
			_inOrder(right);
		}
	}
	auto _postOrder(BalanceNode *node) -> void {
		if (node != nullptr) {
			BalanceNode *left = node->_left;
			BalanceNode *right = node->_right;
			_postOrder(left);
			_postOrder(right);
			(this->*_visit)(node);
		}
	}
	auto _levelOrder(BalanceNode *node) -> void {
		if (node != nullptr) {
			queue<BalanceNode *> level;
			level.push(node);

			while (!level.empty()) {
				node = level.front();
				level.pop();

				if (node->_left != nullptr) {
					level.push(node->_left);
				}
				if (node->_right != nullptr) {
					level.push(node->_right);
				}
				(this->*_visit)(node);
			}
		}
	}
protected:
	auto _checkStatus() -> void {
		long size = _size;
		_size = 0;
		_visit = &BalanceTree::_count;
		//_preOrder(_head._right);
		//_inOrder(_head._right);
		//_postOrder(_head._right);
		_levelOrder(_head._right);

		if (!(_size == size)) {
			throw logic_error("_checkStatus(): BalanceTree abnormal!");
		}
	}
	auto _clear() -> void {
		_first = true;
		_visit = &BalanceTree::_delete;

		(*__os) << "[size: " << _size << ", ~BalanceTree()] ";
		// _preOrder(_head._right);
		// _inOrder(_head._right);
		// _postOrder(_head._right);
		_levelOrder(_head._right);
		(*__os) << endl;
	}
	auto _reset() -> void {
		_size = 0;
		_head = BalanceNode(T(), 0, nullptr, nullptr);
	}
protected:
	bool _first;
	auto (BalanceTree::*_visit) (BalanceNode *) -> void;
protected:
	long _size;
	BalanceNode _head;
};

template<typename T>
ostream *BalanceTree<T>::__os = &cout;

template class BalanceTree<string>;

#endif // BalanceTree_h
