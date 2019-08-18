/* ArrayStack.cpp
Author: BSS9395
Update: 2018-06-24T21:53:00 +08
*/

#ifndef ArrayStack_h
#define ArrayStack_h

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
class ArrayStack {
	static ostream *__os;
	class ArrayStackPtr;
public:
	typedef class ArrayStackPtr iterator;
public:
	ArrayStack(long reserved = 1)
		:_top(0) {

		if (1 <= reserved) {
			_capacity = reserved;
			_elements = new T[reserved];
			return;
		}
		throw logic_error("ArrayStack: init capacity should greater than 1.");
	}
	ArrayStack(initializer_list<T> il)
		:_top(0) {

		_capacity = il.size();
		_elements = new T[_capacity];
		for (auto &e : il) {
			_elements[_top] = e;
			_top++;
		}
	}
	ArrayStack(const ArrayStack &stack)
		:_top(0) {
		_capacity = stack._top;
		_elements = new T[_capacity];
		long top = stack._top;
		T *elements = stack._elements;
		while (_top < top) {
			_elements[_top] = elements[_top];
			_top++;
		}
	}
	~ArrayStack() {
		_reset();
	}
public:
	auto begin() -> iterator {
		return iterator(*this, 0);
	}
	auto end() -> iterator {
		return iterator(*this, _top);
	}
public:
	auto empty() const -> bool {
		return (_top == 0);
	}
	auto length() const -> long {
		return _top;
	}
	auto top() const -> T & {
		_checkEmpty();
		return _elements[_top - 1];
	}
	auto pop() -> void {
		_checkEmpty();
		_top--;
	}
	auto push(const T &value) -> void {
		_checkCapacity();
		_elements[_top] = value;
		_top++;
	}
	auto print(ostream &os = cout) -> void {
		__os = &os;

		bool first = true;
		(*__os) << "[top: " << _top << ", capacity: " << _capacity << "]";
		for (long i = 0; i < _top; ++i) {
			(*__os) << (first ? (first = false, "") : "->");
			(*__os) << _elements[i];
		}
		(*__os) << endl;
	}
protected:
	auto _checkEmpty() const -> void {
		if (1 <= _top) {
			return;
		}
		throw out_of_range("_checkEmpty(): empty");
	}
	auto _checkCapacity() -> void {
		if (_top < _capacity) {
			return;
		}
		long capacity = 2 * _capacity;
		T *elements = new T[capacity];
		for (long i = 0; i < _top; ++i) {
			elements[i] = _elements[i];
		}

		_top = _top;
		_capacity = capacity;
		delete[] _elements;
		_elements = elements;
	}
	auto _reset() -> void {
		_top = 0;
		_capacity = 1;
		delete[] _elements;
		_elements = new T[_capacity];
	}
protected:
	long _top;
	long _capacity;
	T *_elements;
};

template<typename T>
ostream *ArrayStack<T>::__os = &cout;

template<typename T>
class ArrayStack<T>::ArrayStackPtr {
	friend auto operator==(const ArrayStackPtr &lhs, const ArrayStackPtr &rhs) -> bool {
		bool ret1 = (&lhs._stack == &rhs._stack);
		bool ret2 = (lhs._ptr == rhs._ptr);

		return (ret1 && ret2);
	}
	friend auto operator!=(const ArrayStackPtr &lhs, const ArrayStackPtr &rhs) -> bool {
		return !operator==(lhs, rhs);
	}
public:
	ArrayStackPtr(ArrayStack &stack, long ptr)
		:_stack(stack), _ptr(ptr) {

	}
public:
	auto operator++() -> ArrayStackPtr {
		_ptr++;
		return *this;
	}
	auto operator++(int) -> ArrayStackPtr {
		auto ret(*this);
		operator++();
		return ret;
	}
	auto operator--() -> ArrayStackPtr {
		_ptr--;
		return *this;
	}
	auto operator--(int) -> ArrayStackPtr {
		auto ret(*this);
		operator--();
		return ret;
	}
	auto operator*() -> T & {
		return _stack._elements[_ptr];
	}
	auto operator->() -> T * {
		return &(operator*());
	}
protected:
	ArrayStack &_stack;
	long _ptr;
};

template class ArrayStack<string>;
#endif // ArrayStack_h

#ifdef Main

int main(int argc, char *argv[]) {
	ArrayStack<string> stack({ "a","b","c" });
	stack.print();

	for (auto &e : stack) {
		cout << e;
	}

	return 0;
}
#endif

