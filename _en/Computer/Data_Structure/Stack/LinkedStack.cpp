/* LinkedStack.cpp
Author: BSS9395
Update: 2018-06-24T22:07:00 +08
*/

#ifndef LinkedStack_h
#define LinkedStack_h

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
class LinkedStack {
	static ostream *__os;
public:
	typedef class ListNode<T> ListNode;
public:
	LinkedStack()
		:_size(0), _head(T(), nullptr) {

	}
	LinkedStack(initializer_list<T> il)
		:_size(0), _head(T(), nullptr) {

		ListNode *back = &_head;
		for (auto &e : il) {
			back->_next = new ListNode(e, nullptr);
			back = back->_next;
			_size++;
		}
	}
	LinkedStack(const LinkedStack &stack)
		:_size(0), _head(T(), nullptr) {

		ListNode *back = &_head;
		for (ListNode *curr = stack._head._next; curr != nullptr; curr = curr->_next) {
			back->_next = new ListNode(curr->_element, nullptr);
			back = back->_next;
			_size++;
		}
		if (_size != stack._size) {
			throw logic_error("LinkedStack(const LinkedStack &): LinkedStack abnormal!");
		}
	}
	~LinkedStack() {
		bool first = true;

		(*__os) << "~LinkedStack(): ";
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
			(*__os) << "~LinkedStack(): LinkedStack abnormal!" << endl;
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
	auto top() const -> T & {
		_checkEmpty();
		return _head._next->_element;
	}
	auto pop() -> void {
		_checkEmpty();
		ListNode *node = _head._next;
		_head._next = _head._next->_next;
		delete node;
		_size--;
	}
	auto push(const T &value) -> void {
		_head._next = new ListNode(value, _head._next);
		_size++;
	}
	auto print(ostream &os = cout) -> void {
		__os = &os;

		bool first = true;
		(*__os) << "[size: " << _size << ", top->base]";
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
		throw out_of_range("_checkEmpty(): empty");
	}
	auto _reset() -> void {
		_size = 0;
	}
protected:
	long _size;
	ListNode _head;
};

template<typename T>
ostream *LinkedStack<T>::__os = &cout;

template class LinkedStack<string>;
#endif // LinkedStack_h

#ifdef Main
int main(int argc, char *argv[]) {
	LinkedStack<string> stack({ "a","b","c" });
	stack.push("d");
	cout << stack.top();
	stack.pop();
	stack.print();


	return 0;
}
#endif
