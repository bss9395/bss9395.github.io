---
layout:    en_post
Topic:     Data Structure
Title:     ArrayQueue
Revised:   2018-06-24 21:49:00 +08 @ China-Guangdong-ShenZhen +08
Authors:   BSS9395
Resources:
---

``` c++
#ifndef ArrayQueue_h
#define ArrayQueue_h

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
class ArrayQueue {
	static ostream *__os;
	class ArrayQueuePtr;
public:
	typedef class ArrayQueuePtr iterator;
public:
	ArrayQueue(long reserved = 1)
		:_front(0), _size(0) {
		if (1 <= reserved) {
			_capacity = reserved;
			_elements = new T[_capacity];
			return;
		}
		throw logic_error("ArrayQueue(long): init capacity should greater than 1.");
	}
	ArrayQueue(initializer_list<T> il)
		:_front(0), _size(0) {

		_capacity = il.size();
		_elements = new T[_capacity];
		for (auto &e : il) {
			_elements[_size] = e;
			_size++;
		}
	}
	ArrayQueue(const ArrayQueue &queue)
		:_front(0), _size(0) {

		_capacity = queue._size;
		_elements = new T[_capacity];
		long front = queue._front;
		long size = queue._size;
		long capacity = queue._capacity;
		T *elements = queue._elements;
		while (_size < size) {
			_elements[_size] = elements[(front + _size) % capacity];
			_size++;
		}
	}
	~ArrayQueue() {
		_reset();
	}
public:
	auto begin() -> iterator {
		return iterator(*this, _front, 0);
	}
	auto end() -> iterator {
		return iterator(*this, _front, _size);
	}
	auto operator[](long index)->T & {
		return _elements[(_front + index) % _capacity];
	}
public:
	auto empty() const -> bool {
		return (_size == 0);
	}
	auto length() const -> long {
		return _size;
	}
	auto front() const -> T & {
		_checkEmpty();
		return _elements[_front];
	}
	auto back() const -> T & {
		_checkEmpty();
		return _elements[(_front + _size - 1) % _capacity];
	}
	auto pop() -> void {
		_checkEmpty();
		_front++;
		_front = (_front + _capacity) % _capacity;
		_size--;
	}
	auto push(const T &value) -> void {
		_checkCapacity();
		_elements[(_front + _size) % _capacity] = value;
		_size++;
	}
	auto print(ostream &os = cout) const -> void {
		__os = &os;

		bool first = true;
		(*__os) << "[front: " << _front << ", size: " << _size << ", capacity: " << _capacity << "]";
		for (long i = 0; i < _size; ++i) {
			(*__os) << (first ? (first = false, "") : "<-");
			(*__os) << _elements[(_front + i) % _capacity];
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
	auto _checkCapacity() -> void {
		if (_size < _capacity) {
			return;
		}
		long capacity = 2 * _capacity;
		T *elements = new T[capacity];
		for (long i = 0; i < _size; i++) {
			elements[i] = _elements[(_front + i) % _capacity];
		}

		_front = 0;
		_size = _size;
		_capacity = capacity;
		delete[] _elements;
		_elements = elements;
	}

	auto _reset() -> void {
		_front = 0;
		_size = 0;
		_capacity = 1;
		delete[] _elements;
		_elements = new T[_capacity];
	}
protected:
	long _front;
	long _size;
	long _capacity;
	T *_elements;
};

template<typename T>
ostream *ArrayQueue<T>::__os = &cout;

template<typename T>
class ArrayQueue<T>::ArrayQueuePtr {
	friend auto operator==(const ArrayQueuePtr &lhs, const ArrayQueuePtr &rhs) -> bool {
		bool ret1 = (&(lhs._queue) == &(rhs._queue));
		bool ret2 = (lhs._ptr == rhs._ptr);
		bool ret3 = (lhs._index == rhs._index);
		return ret1 && ret2 && ret3;
	}
	friend auto operator!=(const ArrayQueuePtr &lhs, const ArrayQueuePtr &rhs) -> bool {
		return !operator==(lhs, rhs);
	}
public:
	ArrayQueuePtr(ArrayQueue &queue, long ptr, long index)
		:_queue(queue), _ptr(ptr), _index(index) {

	}
public:
	auto operator++() -> ArrayQueuePtr & {
		_ptr++;
		_ptr %= _queue._capacity;
		_index++;
		return *this;
	}
	auto operator++(int) -> ArrayQueuePtr {
		auto ret(*this);
		operator++();
		return ret;
	}
	auto operator--() -> ArrayQueuePtr {
		_ptr--;
		_ptr = (_ptr + _queue._capacity) % _queue._capacity;
		_index--;
		return *this;
	}
	auto operator--(int) -> ArrayQueuePtr {
		auto ret(*this);
		operator--();
		return ret;
	}
	auto operator*() -> T & {
		return _queue._elements[_ptr];
	}
	auto operator->() -> T * {
		return &(operator*());
	}
protected:
	ArrayQueue &_queue;
	long _ptr;
	long _index;
};
#endif // ArrayQueue_h

#ifdef Main
int main(int argc, char *argv[]) {

	ArrayQueue<string> que({ "a","b","c" });
	que.pop();
	que.push("d");
	cout << que.back() << endl;
	cout << que.front() << endl;
	que.print();

	return 0;
}
#endif
```