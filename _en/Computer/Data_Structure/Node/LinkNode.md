---
layout:    en_post
Topic:     Data Structure
Title:     LinkNode
Revised:   2018-06-24 22:08:00 +08 @ China-Guangdong-ShenZhen +08
Authors:   BSS9395
Resources:
---

``` c++
#ifndef LinkNode_h
#define LinkNode_h

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

#include <string>
using std::string;

template<typename T>
class LinkNode {
	friend auto operator<<(ostream &os, const LinkNode &node) -> ostream & {
		os << node._element;
		return os;
	}
public:
	LinkNode(const T &element = T(), LinkNode *prev = nullptr, LinkNode *next = nullptr)
		:_element(element), _prev(prev), _next(next) {

	}
	LinkNode(const LinkNode &node)
		:_element(node._element), _prev(node._prev), _next(node._next) {

	}
	auto operator=(const LinkNode &node) -> LinkNode & {
		if (this != &node) {
			_clear();
			_element = node._element;
			_prev = node._prev;
			_next = node._next;
		}
		return *this;
	}
protected:
	auto _clear() -> void {
		_element.~T();
	}
public:
	T _element;
	LinkNode *_prev;
	LinkNode *_next;
};

template class LinkNode<string>;
#endif // LinkNode
```