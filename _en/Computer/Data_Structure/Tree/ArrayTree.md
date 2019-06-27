---
layout:    en_post
Topic:     Data Structure
Title:     ArrayTree
Revised:   2018-06-24 21:45:00 +08 @ China-Guangdong-ShenZhen +08
Authors:   BSS9395
Resources:
---

``` c++
#ifndef ArrayTree_h
#define ArrayTree_h

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

#include <string>
using std::string;

#include <initializer_list>
using std::initializer_list;

#include <stdexcept>
using std::logic_error;
using std::out_of_range;

#include <queue>
using std::queue;

#include <cmath>
using std::exp2;
using std::log2;

#include <memory>
using std::uninitialized_fill_n;

/*
0:      0
		|
1:	    1
	   / \
2:	  2   3
	 / \ / \
3:  4  5 6  7
*/

template<typename T>
class ArrayTree {
	static ostream *__os;
public:
	// 1 <= depth
	// 2^(depth-1) <= size < 2^depth
	ArrayTree(long depth = 0) {
		if (0 <= depth) {
			_depth = depth;
			_capacity = long(exp2(_depth));
			_elements = new T[_capacity]();
			return;
		}
		throw logic_error("ArrayTree(long): depth should >= 0.");
	}
	// { Null, "1", "2", "3", Null, "5", "6", Null }
	ArrayTree(initializer_list<T> il) {
		long size = il.size() - 1;
		_depth = long((size <= 0) ? 0 : log2(size) + 1);
		_capacity = long(exp2(_depth));
		_elements = new T[_capacity]();

		long i = 0;
		for (auto &e : il) {
			_elements[i] = e;
			++i;
		}
	}
	ArrayTree(const ArrayTree &tree) {
		_depth = tree._depth;
		_capacity = tree._capacity;
		_elements = new T[_capacity]();
		T *elements = tree._elements;
		for (long i = 0; i < _capacity; ++i) {
			_elements[i] = elements[i];
		}
	}
	~ArrayTree() {
		_reset();
	}
public:
	auto operator[](long index) -> T & {
		return _elements[index];
	}
public:
	auto empty() const -> bool {
		return (_depth == 0);
	}
	auto depth() const ->long {
		return _depth;
	}
	auto preOrder() -> void {
		_first = true;

		(*__os) << "[depth: " << _depth << ", capacity: " << _capacity << ", preOrder()]";
		_preOrder(1);
		(*__os) << endl;
	}
	auto inOrder() -> void {
		_first = true;

		(*__os) << "[depth: " << _depth << ", capacity: " << _capacity << ", inOrder()]";
		_inOrder(1);
		(*__os) << endl;
	}
	auto postOrder() -> void {
		_first = true;

		(*__os) << "[depth: " << _depth << ", capacity: " << _capacity << ", postOrder()]";
		_postOrder(1);
		(*__os) << endl;
	}
	auto levelOrder() -> void {
		_first = true;

		(*__os) << "[depth: " << _depth << ", capacity: " << _capacity << ", levelOrder()]";
		_levelOrder(1);
		(*__os) << endl;
	}
	auto print(ostream &os = cout) -> void {
		__os = &os;

		_first = true;
		(*__os) << "[depth: " << _depth << ", capacity: " << _capacity << "]";
		for (long i = 0; i < _capacity; ++i) {
			(*__os) << (_first ? (_first = false, "") : "->");
			(*__os) << _elements[i];
		}
		(*__os) << endl;
	}
protected:
	auto _left(long parent) const -> long {
		return 2 * parent;
	}
	auto _right(long parent) const -> long {
		return 2 * parent + 1;
	}
	auto _visit(long node)  -> void {
		(*__os) << (_first ? (_first = false, "") : "->");
		(*__os) << _elements[node];
	}
	auto _preOrder(long node) -> void {
		if (node < _capacity && _elements[node] != _elements[0]) {
			_visit(node);
			_preOrder(_left(node));
			_preOrder(_right(node));
		}
	}
	auto _inOrder(long node) -> void {
		if (node < _capacity && _elements[node] != _elements[0]) {
			_inOrder(_left(node));
			_visit(node);
			_inOrder(_right(node));
		}
	}
	auto _postOrder(long node) -> void {
		if (node < _capacity && _elements[node] != _elements[0]) {
			_postOrder(_left(node));
			_postOrder(_right(node));
			_visit(node);
		}
	}
	auto _levelOrder(long node) -> void {
		const T Null = _elements[0];
		if (node < _capacity && _elements[node] != Null) {
			queue<long> level;
			level.push(node);

			while (!level.empty()) {
				node = level.front();
				level.pop();

				_visit(node);
				if (_left(node) < _capacity && _elements[_left(node)] != Null) {
					level.push(_left(node));
				}
				if (_right(node) < _capacity && _elements[_right(node)] != Null) {
					level.push(_right(node));
				}
			}
		}
	}
	auto _reset() -> void {
		_depth = 0;
		_capacity = long(exp2(_depth));
		delete[] _elements;
		_elements = new T[_capacity]();
	}
protected:
	bool _first;
protected:
	long _depth;
	long _capacity;
	T *_elements;
};

template<typename T>
ostream *ArrayTree<T>::__os = &cout;

template class ArrayTree<string>;

#endif // ArrayTree_h

#ifdef Main

int main(int argc, char *argv[]) {
	const string Null = string("$");
	ArrayTree<string> tree({ Null, "1", "2", "3", Null, "5", "6", Null });
	if (tree.empty()) {
		cout << "empty" << endl;
	}
	tree.print();
	tree.preOrder();
	tree.inOrder();
	tree.postOrder();
	tree.levelOrder();
	return 0;
}
#endif
```
