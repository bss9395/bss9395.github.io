---
layout:    en_post
Topic:     Data Structure
Title:     DublyQueue
Revised:   2018-06-24 21:55:00 +08 @ China-Guangdong-ShenZhen +08
Authors:   BSS9395
Resources:
---

``` c++
#ifndef DublyQueue_h
#define DublyQueue_h

#include "LinkNode.h"
template<typename T>
class LinkNode;

#include <iostream>
using std::cin;
using std::cout;
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
class DublyQueue {
	static ostream *__os;
	class DublyQueuePtr;
public:
	typedef class LinkNode<T> LinkNode;
	typedef class DublyQueuePtr iterator;
public:
	DublyQueue()
		:_size(0), _head(T(), nullptr, nullptr) {
		_head._next = &_head;
		_head._prev = &_head;
	}
	DublyQueue(initializer_list<T> il)
		:_size(0), _head(T(), nullptr, nullptr) {

		LinkNode *tail = &_head;
		for (auto &e : il) {
			tail->_next = new LinkNode(e, tail, nullptr);
			tail = tail->_next;
			_size++;
		}
		tail->_next = &_head;
		_head._prev = tail;
	}
	DublyQueue(const DublyQueue &queue)
		:_size(0), _head(queue._head._element, nullptr, nullptr) {
		LinkNode *tail = &_head;
		for (LinkNode *curr = queue._head._next; curr != &_head; curr = curr->_next) {
			tail->_next = new LinkNode(curr->_element, tail, nullptr);
			tail = tail->_next;
			_size++;
		}
		tail->_next = &_head;
		_head._prev = tail;

		if (_size != queue._size) {
			throw logic_error("DublyQueue(const DublyQueue &): DublyQueue abnormal!");
		}
	}
	~DublyQueue() {
		bool first = true;

		(*__os) << "~DublyQueue(): ";
		LinkNode * back = _head._prev;
		LinkNode *node = back;
		while (back != &_head) {
			back = back->_prev;

			(*__os) << (first ? (first = false, "") : "<-");
			(*__os) << *node;
			delete node;
			node = back;
			_size--;
		}
		(*__os) << endl;

		if (_size != 0) {
			(*__os) << "~DublyList(): DublyList abnormal!" << endl;
			exit(EXIT_FAILURE);
		}

		_reset();
	}
public:
	auto begin() -> iterator {
		return iterator(_head._next);
	}
	auto end() -> iterator {
		return iterator(&_head);
	}
public:
	auto empty() const -> bool {
		bool ret1 = (_size == 0);
		bool ret2 = (_head._next == &_head);
		bool ret3 = (_head._prev == &_head);
		if (!(ret1 == ret2 && ret2 == ret3)) {
			throw logic_error("empty(): DublyQueue abnormal!");
		}
		return (ret1 && ret2 && ret3);
	}
	auto length() const -> long {
		return _size;
	}
	auto front() const -> T & {
		_checkEmpty();
		return _head._next->_element;
	}
	auto back() const -> T & {
		_checkEmpty();
		return _head._prev->_element;
	}
	auto pop() -> void {
		_checkEmpty();
		LinkNode *front = _head._next;
		front->_prev->_next = front->_next;
		front->_next->_prev = front->_prev;
		delete front;
		_size--;
	}
	auto push(const T &value) -> void {
		LinkNode *back = new LinkNode(value, _head._prev, &_head);
		_head._prev->_next = back;
		_head._prev = back;
		_size++;
	}
	auto print(ostream &os = cout)->void {
		__os = &os;

		bool first = true;
		(*__os) << "[size: " << _size << "]";
		for (LinkNode *curr = _head._next; curr != &_head; curr = curr->_next) {
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
		_head._next = &_head;
		_head._prev = &_head;
	}
protected:
	long _size;
	LinkNode _head;
};

template<typename T>
ostream *DublyQueue<T>::__os = &cout;

template<typename T>
class DublyQueue<T>::DublyQueuePtr {
	friend auto operator==(const DublyQueuePtr &lhs, const DublyQueuePtr &rhs) -> bool {
		return (lhs._ptr == rhs._ptr);
	}
	friend auto operator!=(const DublyQueuePtr &lhs, const DublyQueuePtr &rhs) -> bool {
		return !operator==(lhs, rhs);
	}
public:
	DublyQueuePtr(LinkNode *ptr = nullptr)
		:_ptr(ptr) {

	}
public:
	auto operator++() -> DublyQueuePtr {
		_ptr = _ptr->_next;
		return *this;
	}
	auto operator++(int) -> DublyQueuePtr {
		auto ret(*this);
		operator++();
		return ret;
	}
	auto operator--() -> DublyQueuePtr {
		_ptr = _ptr->_prev;
		return *this;
	}
	auto operator--(int) -> DublyQueuePtr {
		auto ret(*this);
		operator--();
		return ret;
	}
	auto operator*() -> T & {
		return _ptr->_element;
	}
	auto operator->() -> T * {
		return &(operator*());
	}
protected:
	LinkNode *_ptr;
};

template class DublyQueue<string>;

#endif // DublyQueue_h

#ifdef Main

int main(int argc, char *argv[]) {
	DublyQueue<string> queue({ "a","b","c" });
	queue.push("d");
	queue.pop();
	queue.print();

	return 0;
}
#endif
```