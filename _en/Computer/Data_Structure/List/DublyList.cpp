/* DublyList.cpp
Author: BSS9395
Update: 2018-06-24T22:13:00 +08
*/

#ifndef DublyList_h
#define DublyList_h

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
class DublyList {
	static ostream *__os;
	class DublyListPtr;
public:
	typedef class LinkNode<T> LinkNode;
	typedef class DublyListPtr iterator;
public:
	DublyList()
		:_size(0), _head(T(), nullptr, nullptr) {

		_head._next = &_head;
		_head._prev = &_head;
	}
	DublyList(initializer_list<T> il)
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
	DublyList(const DublyList &list)
		:_size(0), _head(list._head._element, nullptr, nullptr) {

		LinkNode *tail = &_head;
		for (LinkNode *curr = list._head._next; curr != &(list._head); curr = curr->_next) {
			tail->_next = new LinkNode(curr->_element, tail, nullptr);
			tail = tail->_next;
			_size++;
		}
		tail->_next = &_head;
		_head._prev = tail;

		if (_size != list._size) {
			throw logic_error("DublyList(const DublyList &): DublyList abnormal");
		}
	}
	~DublyList() {
		bool first = true;

		(*__os) << "~DublyList(): ";
		LinkNode *tail = _head._prev;
		LinkNode *node = tail;
		while (tail != &_head) {
			tail = tail->_prev;

			(*__os) << (first ? (first = false, "") : "<-");
			(*__os) << *node;
			delete node;
			node = tail;

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
	auto empty() -> bool {
		bool ret1 = (_size == 0);
		bool ret2 = (_head._prev == &_head);
		bool ret3 = (_head._next == &_head);
		if (!(ret1 == ret2 && ret2 == ret3)) {
			throw logic_error("empty(): DublyList abnormal!");
		}
		return (ret1 && ret2 && ret3);
	}
	auto length() -> long {
		return _size;
	}
	auto get(long index) -> T & {
		_checkIndex(index, _size);
		LinkNode *curr = _head._next;
		for (long i = 0; i < index; ++i) {
			curr = curr->_next;
		}
		return curr->_element;
	}
	auto find(const T &value) -> long {

		LinkNode *curr = _head._next;
		for (long i = 0; i < _size; ++i) {
			if (curr->_element == value) {
				return i;
			}
		}
		return -1;
	}
	auto insert(long index, const T &value) -> void {
		_checkIndex(index, _size + 1);

		LinkNode *curr = _head._next;
		for (long i = 0; i < index; ++i) {
			curr = curr->_next;
		}
		LinkNode *node = new LinkNode(value, curr->_prev, curr);
		curr->_prev->_next = node;
		curr->_prev = node;

		_size++;
	}
	auto erase(long index) -> void {
		_checkIndex(index, _size);

		LinkNode *curr = _head._next;
		for (long i = 0; i < index; ++i) {
			curr = curr->_next;
		}
		LinkNode *node = curr;
		curr->_prev->_next = curr->_next;
		curr->_next->_prev = curr->_prev;

		delete node;
		_size--;
	}
	auto print(ostream &os = cout) -> void {
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
	auto _checkIndex(long index, long bound) -> void {
		if (0 <= index && index < bound) {
			return;
		}
		throw out_of_range("_checkIndex(long, long): index out of range!");
	}
	auto _reset() -> void {
		_size = 0;
		_head._prev = &_head;
		_head._next = &_head;
	}
protected:
	long _size;
	LinkNode _head;
};

template<typename T>
ostream *DublyList<T>::__os = &cout;

template<typename T>
class DublyList<T>::DublyListPtr {
	friend auto operator==(const DublyListPtr &lhs, const DublyListPtr &rhs) -> bool {
		return (lhs._ptr == rhs._ptr);
	}
	friend auto operator!=(const DublyListPtr &lhs, const DublyListPtr &rhs) -> bool {
		return !operator==(lhs, rhs);
	}
public:
	DublyListPtr(LinkNode *ptr = nullptr)
		:_ptr(ptr) {

	}
public:
	auto operator++() -> DublyListPtr & {
		_ptr = _ptr->_next;
		return *this;
	}
	auto operator++(int) -> DublyListPtr {
		auto ret = *this;
		_ptr = _ptr->_next;
		return ret;
	}
	auto operator--() -> DublyListPtr & {
		_ptr = _ptr->_prev;
		return *this;
	}
	auto operator--(int) -> DublyListPtr {
		auto ret = *this;
		_ptr = _ptr->_prev;
		return ret;
	}
	auto operator*() const -> T & {
		return _ptr->_element;
	}
	auto operator->() const -> T * {
		return &(operator*());
	}
protected:
	LinkNode *_ptr;
};

template class DublyList<string>;
#endif // DublyList_h

#ifdef Main
int main(int argc, char *argv[]) {
	DublyList<string> list({ "a","b","c" });
	list.print();

	DublyList<string> li2(list);
	li2.print();

	DublyList<string> li;
	cout << li.empty() << endl;

	li.insert(0, "q");
	li.erase(0);
	li.print();

	for (auto &e : list) {
		cout << e;
	}

	return 0;
}
#endif