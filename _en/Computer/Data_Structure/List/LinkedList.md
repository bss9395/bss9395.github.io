---
layout:    en_post
Topic:     Data Structure
Title:     LinkedList
Revised:   2018-06-24 22:16:00 +08 @ China-Guangdong-ShenZhen +08
Authors:   BSS9395
Resources:
---

``` c++
#ifndef LinkedList_h
#define LinkedList_h

#include "ListNode.h"
template<typename T>
class ListNode;

#include <iostream>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

#include <fstream>
using std::ofstream;

#include <stdexcept>
using std::out_of_range;
using std::logic_error;

#include <initializer_list>
using std::initializer_list;


template<typename T>
class LinkedList :public ListNode<T> {
	static ostream *__os;
	class LinkedListPtr;

public:
	typedef class ListNode<T> ListNode;
	typedef class LinkedListPtr iterator;
public:
	LinkedList();
	LinkedList(initializer_list<T> il);
	LinkedList(const LinkedList &list);
	~LinkedList();
public:
	auto begin()->iterator;
	auto end()->iterator;
public:
	auto empty() const -> bool;
	auto size() const -> long;
	auto get(long index) const->T &;
	auto find(const T &value) const->long;
	auto insert(long index, const T &value)->void;
	auto erase(long index)->void;
	auto append(LinkedList &list)->void;
	auto print(ostream &os = cout) const->void;

protected:
	auto _reset()->void;
	auto _checkIndex(long index, long bound) const->void;

protected:
	long _size;
	ListNode **_tail;
};

////////////////////
template<typename T>
ostream *LinkedList<T>::__os = &cout;

template<typename T>
class LinkedList<T>::LinkedListPtr {
	friend auto operator==(const LinkedListPtr &lhs, const LinkedListPtr &rhs) -> bool {
		return (lhs._ptr == rhs._ptr);
	}
	friend auto operator!=(const LinkedListPtr &lhs, const LinkedListPtr &rhs) -> bool {
		return !operator==(lhs, rhs);
	}
public:
	LinkedListPtr(ListNode *ptr = nullptr)
		:_ptr(ptr) {

	}
public:
	auto operator++() -> LinkedListPtr & {
		_ptr = _ptr->_next;
		return *this;
	}
	auto operator++(int) -> LinkedListPtr {
		auto ret(*this);
		operator++();
		return ret;
	}
	auto operator*() const -> T & {
		return _ptr->_element;
	}
	auto operator->() const -> T * {
		return &(operator*());
	}
protected:
	ListNode *_ptr;
};

template<typename T>
LinkedList<T>::LinkedList()
	:_size(0) {
	this->_next = nullptr;
	_tail = &(this->_next);
}

template<typename T>
LinkedList<T>::LinkedList(initializer_list<T> il)
	: _size(0) {
	ListNode *tail = this;
	for (auto &e : il) {
		tail->_next = new ListNode(e, nullptr);
		tail = tail->_next;
		_size++;
	}
	_tail = &(tail->_next);
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList &list)
try :_size(0) {

	ListNode *tail = this;
	for (const ListNode *curr = list._next; curr != nullptr; curr = curr->_next) {
		tail->_next = new ListNode(curr->_element, nullptr);
		tail = tail->_next;
		_size++;
	}
	_tail = &(tail->_next);

	if (_size != list._size) {
		throw out_of_range("LinkedList(const LinkedList &): size not consistent!");
	}
}
catch (out_of_range &e) {
	(*__os) << e.what() << endl;
	exit(EXIT_FAILURE);
}

template<typename T>
LinkedList<T>::~LinkedList() {
	bool first = true;

	(*__os) << "~LinkedList(): ";

	ListNode *head = this->_next;
	ListNode *curr = head;
	while (head) {
		head = head->_next;
		(*__os) << (first ? (first = false, "") : "->");
		(*__os) << *curr;
		delete curr;
		curr = head;
	}
	(*__os) << endl;

	_reset();
}

template<typename T>
auto LinkedList<T>::begin() -> iterator {
	return iterator(this->_next);
}

template<typename T>
auto LinkedList<T>::end() -> iterator {
	if (*_tail != nullptr) {
		throw logic_error("end(): LList abnormal!");
	}

	//return iterator(*_tail);
	return iterator(nullptr);
}

template<typename T>
auto LinkedList<T>::empty() const -> bool {
	bool ret1 = (_size == 0);
	bool ret2 = (this->_next == nullptr);

	if (ret1 != ret2) {
		throw logic_error("empty(): abnormal!");
	}
	return ret1 && ret2;
}

template<typename T>
auto LinkedList<T>::size() const -> long {
	return _size;
}

template<typename T>
auto LinkedList<T>::_reset()->void {
	this->_element.~T();
	this->_next = nullptr;
	_tail = &(this->_next);
	_size = 0;
}

template<typename T>
auto LinkedList<T>::get(long index) const -> T & {
	_checkIndex(index, _size);

	ListNode *curr = this->_next;
	for (long i = 0; i < index; ++i) {
		curr = curr->_next;
	}
	return curr->_element;
}

template<typename T>
auto LinkedList<T>::find(const T &value) const -> long {
	ListNode *curr = this->_next;
	for (long i = 0; i < _size; ++i) {
		if (curr->_element == value) {
			return i;
		}
		curr = curr->_next;
	}
	return -1;
}

template<typename T>
auto LinkedList<T>::insert(long index, const T &value) -> void {
	_checkIndex(index, _size + 1);
	ListNode *node = new ListNode(value, nullptr);

	if (index != _size) {
		ListNode *curr = this;
		for (long i = 0; i < index; ++i) {
			curr = curr->_next;
		}
		node->_next = curr->_next;
		curr->_next = node;
	}
	else {
		*_tail = node;
		_tail = &(node->_next);
	}
	_size++;
}

template<typename T>
auto LinkedList<T>::erase(long index)->void {
	_checkIndex(index, _size);

	ListNode *curr = this;
	for (long i = 0; i < index; ++i) {
		curr = curr->_next;
	}
	ListNode *node = curr->_next;
	curr->_next = curr->_next->_next;

	if (_tail == &(node->_next)) {
		_tail = &(curr->_next);
	}

	delete node;
	node = nullptr;
	_size--;
}

template<typename T>
auto LinkedList<T>::append(LinkedList &list)->void {
	*_tail = list._next;
	_tail = list._tail;
	_size += list._size;

	list._reset();
}

template<typename T>
auto LinkedList<T>::print(ostream &os) const ->void {
	__os = &os;
	bool first = true;

	(*__os) << "[size: " << _size << "]";
	for (const ListNode *curr = this->_next; curr != nullptr; curr = curr->_next) {
		(*__os) << (first ? (first = false, "") : "->");
		(*__os) << *curr;
	}
	(*__os) << endl;
}

template<typename T>
auto LinkedList<T>::_checkIndex(long index, long bound) const -> void {
	if (0 <= index && index < bound) {
		return;
	}
	(*__os) << "index out of range!" << endl;
	throw out_of_range("index out of range!");
}

template class LinkedList<string>;
#endif // LinkedList_h

#ifdef Main
int main(int argc, char *argv[]) {
	typedef class ListNode<string> ListNode;
	typedef class LinkedList<string> LinkedList;

	LinkedList li1 = { "0","1","2","3","4","5","6","7","8","9" };
	//li1.insert(0, "n1");
	//li1.insert(1, "n2");
	//li1.insert(0, "n0");
	li1.erase(li1.size() - 1);
	li1.erase(1);

	li1.insert(li1.size(), "0");
	li1.print();

	//LList li2;

	for (auto it = li1.begin(); it != li1.end(); ++it) {
		cout << it->size() << " ";
	}
	cout << endl;

	for (auto &e : li1) {
		cout << e << " ";
	}
	cout << endl;

	return 0;
}

#endif
```