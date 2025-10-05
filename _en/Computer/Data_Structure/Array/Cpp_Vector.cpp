/* Cpp_Vector.cpp
Author: bss9395
Update: 2025/10/04T21:50:00+08@China-GuangDong-ZhanJiang+08
Keepin: bss9395@yeah.net
*/

#include<iostream>
#include<string>
#include<vector>
#include<functional>
using namespace std;

template<typename Datum_>
struct Vector {
	static long _Compare(const Datum_ &lhs, const Datum_ &rhs) {
		if (lhs < rhs) {
			return -1;
		} else if (lhs > rhs) {
			return +1;
		}
		return 0;
	}

	function<long(const Datum_ &, const Datum_ &)> _compare = _Compare;
	Datum_ *_head = nullptr;
	long _capacity = 0;
	long _size = 0;

	Vector() {
		_Init(10);
	}
	Vector(const function<long(const Datum_ &, const Datum_ &)> &compare) {
		_compare = compare;
		_Init(10);
	}
	Vector(long capacity) {
		_Init(capacity);
	}
	Vector(const vector<Datum_> &data) {
		_Init((long)data.size());

		for (long i = 0; i < (long)data.size(); i += 1) {
			_head[i] = data[i];
		}
		_size = (long)data.size();
	}
	void _Init(long capacity) {
		if ((0 < capacity) == false) {
			capacity = 10;
		}
		_head = new Datum_[capacity];
		_capacity = capacity;
		_size = 0;
	}

	virtual ~Vector() {
		_Clear();
	}
	void _Clear() {
		delete[] _head;
		_capacity = 0;
		_size = 0;
	}

	Vector(const Vector &that) {
		_Init(that._size);
		_Copy(that);
	}
	Vector &operator=(const Vector &that) {
		if (this != &that) {
			_Ensure(that._size);
			_Copy(that);
		}
	}
	void _Ensure(long capacity) {
		if ((capacity <= _capacity) == false) {
			delete[] _head;
			_head = new Datum_[capacity];
			_capacity = capacity;
			_size = 0;
		}
	}
	void _Copy(const Vector &that) {
		for (int i = 0; i < that._size; i += 1) {
			_head[i] = that._head[i];
		}
		_size = that._size;
	}

	void _Next(ostream &os) {
		for (int i = 0; i < _size; i += 1) {
			os << _head[i];
		}
	}
	void _Prev(ostream &os) {
		for (int i = _size - 1; 0 <= i; i -= 1) {
			os << _head[i];
		}
	}

	long _Search(const Datum_ &datum) {
		long index = 0;
		for (; index < _size && _compare(_head[index], datum) != 0; index += 1);
		return index;
	}
	long _Search_Lower(const Datum_ &datum) {
		long index = 0;
		for (; index < _size && _compare(_head[index], datum) < 0; index += 1);
		return index;
	}
	long _Search_Upper(const Datum_ &datum) {
		long index = 0;
		for (; index < _size && _compare(_head[index], datum) <= 0; index += 1);
		return index;
	}

	long _Search_Bianry_Circulation(const Datum_ &datum) {
		long fore = 0;
		long back = _size;
		while (fore < back) {
			long midd = (fore + back) / 2;
			if (_compare(datum, _head[midd]) < 0) {
				back = midd;
			} else if (_compare(_head[midd], datum) < 0) {
				fore = midd + 1;
			} else {
				return midd;
			}
		}
		return _size;
	}

	long _Search_Bianry_Recursion(const Datum_ &datum) {
		return __Search_Bianry_Recursion(datum, 0, _size);
	}
	long __Search_Bianry_Recursion(const Datum_ &datum, long fore, long back) {
		if (fore < back) {
			long midd = (fore + back) / 2;
			if (_compare(datum, _head[midd]) < 0) {
				return __Search_Bianry_Recursion(datum, fore, midd);
			} else if (_compare(_head[midd], datum) < 0) {
				return __Search_Bianry_Recursion(datum, midd + 1, back);
			} else {
				return midd;
			}
		}
		return _size;
	}
};

void _Test_Copy() {
	Vector<double> array = vector<double>{
		0, 1, 2, 3, 4, 5
	};
	std::cout << array._size << ", " << array._capacity << std::endl;
	array._Next(std::cout);
	std::cout << std::endl;
	array._Prev(std::cout);
	std::cout << std::endl;

	Vector<double> copy = array;
	std::cout << copy._size << ", " << copy._capacity << std::endl;
	copy._Next(std::cout);
	std::cout << std::endl;
	array._Prev(std::cout);
	std::cout << std::endl;
}

void _Test_Search() {
	Vector<double> array = vector<double>{
		0, 1, 2, 3, 3, 4, 5
	};
	long index = array._Search(2.5);
	std::cout << index << std::endl;
}

void _Test_Search_Lower() {
	Vector<double> array = vector<double>{
		0, 1, 2, 3, 3, 4, 5
	};
	long index = array._Search_Lower(2.5);
	std::cout << index << std::endl;
}

void _Test_Search_Upper() {
	Vector<double> array = vector<double>{
		0, 1, 2, 3, 3, 4, 5
	};
	long index = array._Search_Upper(3);
	std::cout << index << std::endl;
}

void _Test_Search_Bianry_Circulation() {
	Vector<double> array = vector<double>{
		0, 1, 2, 3, 4, 5
	};
	long index = array._Search_Bianry_Circulation(2.5);
	std::cout << index << std::endl;
}

void _Test_Search_Bianry_Recursion() {
	Vector<double> array = vector<double>{
		0, 1, 2, 3, 4, 5
	};
	long index = array._Search_Bianry_Recursion(2.5);
	std::cout << index << std::endl;
}

int main() {
	// _Test_Copy();

	// _Test_Search();
	// _Test_Search_Lower();
	// _Test_Search_Upper();

	// _Test_Search_Bianry_Circulation();
	_Test_Search_Bianry_Recursion();

	return 0;
}
