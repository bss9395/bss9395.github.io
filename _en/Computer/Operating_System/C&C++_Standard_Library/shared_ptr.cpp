/* Shared_Ptr.cpp
Author: bss9395
Update: 2024-07-24T23:14:41+08@China-Beijing+08
Design: Auto_Ptr, Unique_Ptr, Shared_Ptr, Weak_Ptr
*/

#include <iostream>
#include <mutex>
#include <thread>

template<typename T_>
class Auto_Ptr {
public:
	T_* _ptr = nullptr;

public:
	explicit Auto_Ptr(T_* ptr = nullptr) {
		_ptr = ptr;
	}

	Auto_Ptr(const Auto_Ptr<T_>& auto_ptr) {
		_ptr = auto_ptr._ptr;
		auto_ptr._ptr = nullptr;
	}

	Auto_Ptr<T_>& operator=(const Auto_Ptr<T_>& auto_ptr) {
		if (this != &auto_ptr) {
			if (_ptr != nullptr) {
				delete _ptr;
			}
			_ptr = auto_ptr._ptr;
			auto_ptr._ptr = nullptr;
		}
		return (*this);
	}

	virtual ~Auto_Ptr() {
		if (_ptr != nullptr) {
			delete _ptr;
		}
	}

public:
	T_& operator*() const {
		return (*_ptr);
	}

	T_* operator->() const {
		return _ptr;
	}
};

////////////////////////////////////////////////////////////////////////////////

template<typename T_>
class Unique_Ptr {
public:
	T_* _ptr = nullptr;

public:
	explicit Unique_Ptr(T_* ptr = nullptr) {
		_ptr = ptr;
	}

	Unique_Ptr(const Unique_Ptr<T_>&) = delete;
	Unique_Ptr& operator=(const Unique_Ptr<T_>&) = delete;

	virtual ~Unique_Ptr() {
		if (_ptr != nullptr) {
			delete _ptr;
		}
	}

public:
	T_& operator*() const {
		return *_ptr;
	}

	T_* operator->() const {
		return _ptr;
	}
};

////////////////////////////////////////////////////////////////////////////////

template<typename T_>
class Shared_Ptr {
public:
	T_* _ptr = nullptr;
	int* _count = nullptr;
	std::mutex* _mutex = nullptr;

public:
	explicit Shared_Ptr(T_* ptr = nullptr) {
		_ptr = ptr;
		_count = new int(1);
		_mutex = new std::mutex();
	}

	Shared_Ptr(const Shared_Ptr<T_>& shared_ptr) {
		_ptr = shared_ptr._ptr;
		_count = shared_ptr._count;
		_mutex = shared_ptr._mutex;
		_Increase();
	}

	Shared_Ptr& operator=(const Shared_Ptr<T_>& shared_ptr) {
		if (this != &shared_ptr) {
			_Release();
			_ptr = shared_ptr._ptr;
			_count = shared_ptr._count;
			_mutex = shared_ptr._mutex;
			_Increase();
		}
		return (*this);
	}

	virtual ~Shared_Ptr() {
		_Release();
	}

public:
	T_& operator*() const {
		return (*_ptr);
	}

	T_* operator->() const {
		return _ptr;
	}

public:
	void _Increase() {
		_mutex->lock();
		(*_count) += 1;
		_mutex->unlock();
	}

	void _Release() {
		bool zero = false;
		_mutex->lock();
		(*_count) -= 1;
		if ((*_count) == 0) {
			delete _ptr, _ptr = nullptr;
			delete _count, _count = nullptr;
			zero = true;
		}
		_mutex->unlock();

		if (zero == true) {
			delete _mutex, _mutex = nullptr;
		}
	}

public:
	T_* _Retrieve() const {
		return _ptr;
	}

	int _Count() const {
		return (*_count);
	}
};

template<typename T_>
class Weak_Ptr {
public:
	T_* _ptr = nullptr;

public:
	explicit Weak_Ptr(T_* ptr = nullptr) {
		_ptr = ptr;
	}

	Weak_Ptr(const Shared_Ptr<T_>& shared_ptr) {
		_ptr = shared_ptr._Retrieve();
	}

	Weak_Ptr& operator=(const Shared_Ptr<T_>& shared_ptr) {
		_ptr = shared_ptr._Retrieve();	
		return (*this);
	}

	virtual ~Weak_Ptr() {

	}

public:
	T_& operator*() const {
		return (*_ptr);
	}

	T_* operator->() const {
		return _ptr;
	}
};

////////////////////////////////////////////////////////////////////////////////

class Date {
public:
	int _year;
	int _month;
	int _day;

public:
	Date(int year = 2024, int month = 7, int day = 24) {
		std::cout << "Date(int year = 2024, int month = 7, int day = 24) {" << std::endl;
		_year = year;
		_month = month;
		_day = day;
	}

	~Date() {
		std::cout << "~Date() {" << std::endl;
	}
};

void _Test_Auto_Ptr() {
	Auto_Ptr<Date> date0 = new Date(2024, 7, 24);
	Auto_Ptr<Date> date1 = date0;

	std::cout << ((nullptr == date0._ptr) ? "true" : "false") << std::endl;
}

void _Test_Unique_Ptr() {
	Unique_Ptr<Date> date0 = new Date(2024, 7, 24);
	// Unique_Ptr<Date> date1 = date0;
}

void _Func(Shared_Ptr<Date>& shared_ptr, int numb) {
	std::cout << "shared_ptr._Retrieve() = " << shared_ptr._Retrieve() << std::endl;
	for (int i = 0; i < numb; i += 1) {
		Shared_Ptr<Date> copy(shared_ptr);
		shared_ptr->_year += 1;
		shared_ptr->_month += 1;
		shared_ptr->_day += 1;
	}
}

void _Test_Shared_Ptr() {
	Shared_Ptr<Date> date0(new Date(2024, 7, 24));
	Shared_Ptr<Date> date1(date0);
	Shared_Ptr<Date> date2 = date0;
	std::cout << "date0._Count() = " << date0._Count() << std::endl;
	std::cout << "date1._Count() = " << date1._Count() << std::endl;
	std::cout << "date2._Count() = " << date2._Count() << std::endl;

	////////////////////////////////////

	Shared_Ptr<Date> date3(new Date(0, 0, 0));
	std::cout << "date3._Retrieve() = " << date3._Retrieve() << std::endl;
	std::cout << "date3._Count()    = " << date3._Count() << std::endl;
	std::thread thread0(_Func, std::ref(date3), 100000);
	std::thread thread1(_Func, std::ref(date3), 100000);
	thread0.join();
	thread1.join();
	std::cout << "date3._Count() = " << date3._Count() << std::endl;
	std::cout << "date3->_year   = " << date3->_year << std::endl;
	std::cout << "date3->_month  = " << date3->_month << std::endl;
	std::cout << "date3->_day    = " << date3->_day << std::endl;
}

void _Test_Shared_Ptr_Circular() {
	struct Node {
	public:
		int _value = 0;
		Shared_Ptr<Node> _next;

	public:
		Node(int value = 0) {
			std::cout << "Node() {" << std::endl;
			_value = value;
		}

		~Node() {
			std::cout << "~Node() {" << std::endl;
		}
	};

	Shared_Ptr<Node> node0(new Node(0));
	Shared_Ptr<Node> node1(new Node(1));
	std::cout << "node0._Count() = " << node0._Count() << std::endl;
	std::cout << "node1._Count() = " << node1._Count() << std::endl;
	node0->_next = node1;
	node1->_next = node0;
	std::cout << "node0._Count() = " << node0._Count() << std::endl;
	std::cout << "node1._Count() = " << node1._Count() << std::endl;
}

void _Test_Weak_Ptr() {
	struct Node {
	public:
		int _value = 0;
		Weak_Ptr<Node> _next;

	public:
		Node(int value = 0) {
			std::cout << "Node() {" << std::endl;
			_value = value;
		}

		~Node() {
			std::cout << "~Node() {" << std::endl;
		}
	};

	Shared_Ptr<Node> node0(new Node(0));
	Shared_Ptr<Node> node1(new Node(1));
	std::cout << "node0._Count() = " << node0._Count() << std::endl;
	std::cout << "node1._Count() = " << node1._Count() << std::endl;
	node0->_next = node1;
	node1->_next = node0;
	std::cout << "node0._Count() = " << node0._Count() << std::endl;
	std::cout << "node1._Count() = " << node1._Count() << std::endl;
}

////////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[]) {
	// _Test_Auto_Ptr();
	// _Test_Unique_Ptr();
	// _Test_Shared_Ptr();
	// _Test_Shared_Ptr_Circular();
	_Test_Weak_Ptr();

	return 0;
}
