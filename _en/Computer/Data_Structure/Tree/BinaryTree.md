---
layout:    en_post
Topic:     Data Structure
Title:     ArrayTree
Revised:   2018-06-28 21:15:00 +08 @ China-Guangdong-ShenZhen +08
Authors:   BSS9395
Resources:
---

``` c++
#ifndef BinaryTree_h
#define BinaryTree_h

#include "BinaryNode.h"
template<typename T>
class BinaryNode;

#include "ArrayTree.h"
template<typename T>
class ArrayTree;

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

#include <string>
using std::string;

#include <initializer_list>
using std::initializer_list;

#include <vector>
using std::vector;

#include <queue>
using std::queue;

#include <tuple>
using std::tuple;

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

/*
0:    0
	   \
1:      1
	   / \
2:    2   3
	 / \ / \
3:  4  5 6  7
*/

template<typename T>
class BinaryTree {
	static ostream *__os;

public:
	typedef class BinaryNode<T> BinaryNode;
public:
	BinaryTree()
		:_depth(0), _size(0), _head(T(), nullptr, nullptr) {

	}
	// { Null, "1", "2", "3", Null, "5", "6", Null }
	BinaryTree(initializer_list<T> il)
		:_depth(0), _size(0), _head(T(), nullptr, nullptr) {

		if (il.size() < 1) {
			throw logic_error("BinaryTree(initializer_list<T>): shouldn't be NULL!");
		}

		vector<T> nodes(il);
		while (1 < nodes.size() && nodes.back() == nodes[0]) {
			nodes.pop_back();
		}

		vector<BinaryNode *> tree;
		for (auto &e : nodes) {
			tree.push_back(new BinaryNode(e, nullptr, nullptr));
		}

		long size = tree.size() - 1;
		_depth = long((size <= 0) ? 0 : log2(size) + 1);
		const T Null = tree[0]->_element;
		for (long node = 0, end = size / 2; node <= end; ++node) {
			if (_left(node) <= size && (tree[_left(node)])->_element != Null) {
				(tree[node])->_left = tree[_left(node)];
				_size++;
			}
			if (_right(node) <= size && (tree[_right(node)])->_element != Null) {
				(tree[node])->_right = tree[_right(node)];
				_size++;
			}
		}

		_head._element = Null;
		_head._left = nullptr;
		_head._right = (tree[0])->_right;
		delete tree[0];
	}
	BinaryTree(const BinaryTree &tree)
		: _depth(tree._depth), _size(tree._size), _head(tree._head._element, nullptr, nullptr) {

		queue<pair<const BinaryNode *, BinaryNode *>> level;
		level.push({ &tree._head, &_head });

		pair<const BinaryNode *, BinaryNode *> node;
		while (!level.empty()) {
			node = level.front();
			level.pop();

			if (node.first->_left != nullptr) {
				node.second->_left = new BinaryNode(node.first->_left->_element, nullptr, nullptr);
				level.push({ node.first->_left, node.second->_left });
			}
			if (node.first->_right != nullptr) {
				node.second->_right = new BinaryNode(node.first->_right->_element, nullptr, nullptr);
				level.push({ node.first->_right, node.second->_right });
			}
		}
	}
	~BinaryTree() {
		_clear();
		_reset();
	}
	auto clearNode(BinaryNode *(&node)) -> void {
		_first = true;
		_visit = &BinaryTree::_delete;

		(*__os) << "clearTree(BinaryNode *): ";
		_levelOrder(node);
		node = nullptr;
		(*__os) << endl;

		height();
		count();
	}
public:
	auto empty() -> bool {
		bool ret1 = (_depth == 0);
		bool ret2 = (_size == 0);
		bool ret3 = (_head._left == nullptr);
		bool ret4 = (_head._right == nullptr);

		if (!(ret1 == ret2 && ret2 == ret3 && ret3 == ret4)) {
			throw logic_error("empty(): BinaryTree abnormal!");
		}
		return (ret1 && ret2 && ret3 && ret4);
	}
	auto height() -> long {
		_depth = _height(_head._right);
		return _depth;
	}
	auto count() -> long {
		_visit = &BinaryTree::_count;

		_size = 0;
		//_preOrder(_head._right);
		//_inOrder(_head._right);
		//_postOrder(_head._right);
		_levelOrder(_head._right);

		return _size;
	}
	auto root() -> BinaryNode *& {
		return _head._right;
	}
	auto preOrder() -> void {
		_first = true;
		_visit = &BinaryTree::_print;

		(*__os) << "[depth: " << _depth << ", size: " << _size << ", preOrder()] ";
		_preOrder(_head._right);
		(*__os) << endl;
	}
	auto inOrder() -> void {
		_first = true;
		_visit = &BinaryTree::_print;

		(*__os) << "[depth: " << _depth << ", size: " << _size << ", inOrder()] ";
		_inOrder(_head._right);
		(*__os) << endl;
	}
	auto postOrder() -> void {
		_first = true;
		_visit = &BinaryTree::_print;

		(*__os) << "[depth: " << _depth << ", size: " << _size << ", postOrder()] ";
		_postOrder(_head._right);
		(*__os) << endl;
	}
	auto levelOrder() -> void {
		_first = true;
		_visit = &BinaryTree::_print;

		(*__os) << "[depth: " << _depth << ", size: " << _size << ", levelOrder()] ";
		_levelOrder(_head._right);
		(*__os) << endl;
	}
protected:
	auto _left(long parent) const -> long {
		return 2 * parent;
	}
	auto _right(long parent) const -> long {
		return 2 * parent + 1;
	}
	auto _print(BinaryNode *node) -> void {
		(*__os) << (_first ? (_first = false, "") : "->");
		(*__os) << node->_element;
	}
	auto _count(BinaryNode *node) -> void {
		_size++;
	}
	auto _delete(BinaryNode *node) -> void {
		(*__os) << (_first ? (_first = false, "") : "<-");
		(*__os) << node->_element;
		delete node;
	}
	auto _height(BinaryNode *node) -> long {
		if (node == nullptr) {
			return 0;
		}
		long lhs = _height(node->_left);
		long rhs = _height(node->_right);

		return max(lhs, rhs) + 1;
	}
	auto _preOrder(BinaryNode *node) -> void {
		if (node != nullptr) {
			BinaryNode *left = node->_left;
			BinaryNode *right = node->_right;
			(this->*_visit)(node);
			_preOrder(left);
			_preOrder(right);
		}
	}
	auto _inOrder(BinaryNode *node) -> void {
		if (node != nullptr) {
			BinaryNode *left = node->_left;
			BinaryNode *right = node->_right;
			_inOrder(left);
			(this->*_visit)(node);
			_inOrder(right);
		}
	}
	auto _postOrder(BinaryNode *node) -> void {
		if (node != nullptr) {
			BinaryNode *left = node->_left;
			BinaryNode *right = node->_right;
			_postOrder(left);
			_postOrder(right);
			(this->*_visit)(node);
		}
	}
	auto _levelOrder(BinaryNode *node) -> void {
		if (node != nullptr) {
			queue<BinaryNode *> level;
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
		long depth = _depth;
		if (!(_depth == depth)) {
			throw logic_error("depth(): BinaryTree abnormal!");
		}

		long size = _size;
		if (!(_size == size)) {
			throw logic_error("count(): binarytree abnormal!");
		}
	}
	auto _clear() -> void {
		_first = true;
		_visit = &BinaryTree::_delete;

		(*__os) << "[depth: " << _depth << ", size: " << _size << ", ~BinaryTree()] ";
		// _preOrder(_head._right);
		// _inOrder(_head._right);
		// _postOrder(_head._right);
		_levelOrder(_head._right);
		(*__os) << endl;
	}
	auto _reset() -> void {
		_depth = 0;
		_size = 0;
		_head = BinaryNode(T(), nullptr, nullptr);
	}
protected:
	bool _first;
	auto (BinaryTree::*_visit)(BinaryNode *) -> void;
protected:
	long _depth;
	long _size;
	BinaryNode _head;
};

template<typename T>
ostream *BinaryTree<T>::__os = &cout;

template class BinaryTree<string>;
#endif // BinaryTree_h

#ifdef Main
int main(int argv, char *arv[]) {
	const string Null = "0";
	BinaryTree<string> tree = { Null, "1", "2", "3", Null, "5", "6", Null };
	tree.preOrder();
	tree.inOrder();
	tree.postOrder();
	tree.levelOrder();

	tree.clearNode(tree.root()->_left);

	BinaryTree<string> tree2(tree);
	tree2.preOrder();

	BinaryTree<string> tree3;
	cout << tree3.empty() << endl;

	return 0;
}
#endif
```
