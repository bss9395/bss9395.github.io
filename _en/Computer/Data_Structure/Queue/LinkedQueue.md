---
layout:    en_post
Topic:     Data Structure
Title:     LinkedQueue
Revised:   2018-06-24 21:57:00 +08 @ China-Guangdong-ShenZhen +08
Authors:   BSS9395
Resources:
---

``` c++
#ifndef LinkedQueue_h
#define LinkedQueue_h

#include "ListNode.h"
template<typename T>
class ListNode;

#include <iostream>
using std::cin;
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

template<typename T>
class LinkedQueue {
	static ostream *__os;
public:
	typedef class ListNode<T> ListNode;
public:
	LinkedQueue()
		:_size(0) {
		_back = &_head;
	}
	LinkedQueue(initializer_list<T> il)
		:_size(0) {
		_back = &_head;

		for (auto &e : il) {
			_back->_next = new ListNode(e, _back->_next);
			_back = _back->_next;
			_size++;
		}
	}
	LinkedQueue(const LinkedQueue & queue)
		:_size(0) {
		_back = &_head;

		for (ListNode *curr = queue._head._next; curr != nullptr; curr = curr->_next) {
			_back->_next = new ListNode(curr->_element, nullptr);
			_back = _back->_next;
			_size++;
		}
		if (_size != queue._size) {
			throw logic_error("LinkedQueue(const LinkedQueue &): LinkedQueue abnormal!");
		}
	}
	~LinkedQueue() {
		bool first = true;

		(*__os) << "~LinkedQueue(): ";
		ListNode *head = _head._next;
		ListNode *node = head;
		while (head != nullptr) {
			head = head->_next;

			(*__os) << (first ? (first = false, "") : "<-");
			(*__os) << *node;
			delete node;
			node = head;
			_size--;
		}
		(*__os) << endl;
		if (_size != 0) {
			(*__os) << "~LinkedQueue(): LinkedQueue abnormal!" << endl;
			exit(EXIT_FAILURE);
		}
		_reset();
	}
public:
	auto empty() const -> bool {
		bool ret1 = (_size == 0);
		bool ret2 = (_head._next == nullptr);
		if (!(ret1 == ret2)) {
			throw logic_error("empty(): LinkedQueue abnormal!");
		}
		return (ret1 && ret2);
	}
	auto length() const -> long {
		return _size;
	}
	auto front() const -> T & {
		_checkEmpty();
		return (_head._next)->_element;
	}
	auto back() const -> T & {
		_checkEmpty();
		return _back->_element;
	}
	auto pop() -> void {
		_checkEmpty();
		ListNode *node = (_head._next);
		_head._next = (_head._next)->_next;
		if (_back == node) {
			_back = &_head;
		}

		delete node;
		_size--;
	}
	auto push(const T &value) -> void {
		_back->_next = new ListNode(value, nullptr);
		_back = _back->_next;
		_size++;
	}
	auto print(ostream &os = cout) -> void {
		__os = &os;

		bool first = true;
		(*__os) << "[size: " << _size << "]";
		for (ListNode *curr = _head._next; curr != nullptr; curr = curr->_next) {
			(*__os) << (first ? (first = false, "") : "->");
			(*__os) << *curr;
		}
		(*__os) << endl;
	}
protected:
	auto _checkEmpty() const -> void {
		if (1 <= _size) {
			return;
		}
		throw out_of_range("_checkEmpty(): empty!");
	}
	auto _reset() -> void {
		_size = 0;
		_back = &_head;
	}
protected:
	long _size;
	ListNode _head;
	ListNode *_back;
};

template<typename T>
ostream *LinkedQueue<T>::__os = &cout;

template class LinkedQueue<string>;
#endif // LinkedQueue_h
```