---
layout:    en_post
Topic:     Data Structure
Title:     BinaryNode
Revised:   2018-06-27 20:41:00 +08 @ China-Guangdong-ShenZhen +08
Authors:   BSS9395
Resources:
---

``` c++
#ifndef BinaryNode_h
#define BinaryNode_h

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

#include <string>
using std::string;

#include <stdexcept>
using std::logic_error;
using std::out_of_range;

template<typename T>
class BinaryNode {
	friend auto operator<<(ostream &os, const BinaryNode &node) -> ostream & {
		os << node._element;
		return os;
	}
	friend auto operator<(const BinaryNode &lhs, const BinaryNode &rhs) -> bool {
		return (lhs._element < rhs._element);
	}
public:
	BinaryNode(const T &element = T(), BinaryNode *left = nullptr, BinaryNode *right = nullptr)
		:_element(element), _left(left), _right(right) {

	}
	BinaryNode(const BinaryNode &node)
		:_element(node._element), _left(node._left), _right(node._right) {

	}
	auto operator=(const BinaryNode &node) -> BinaryNode & {
		if (this != &node) {
			_clear();
			_element = node._element;
			_left = node._left;
			_right = node._right;
		}
		return *this;
	}
	virtual ~BinaryNode() {
		_clear();
	}
protected:
	auto _clear() -> void {
		_element.~T();
	}
public:
	T _element;
	BinaryNode *_left;
	BinaryNode *_right;
};

template class BinaryNode<string>;

#endif // BinaryNode_h
```
