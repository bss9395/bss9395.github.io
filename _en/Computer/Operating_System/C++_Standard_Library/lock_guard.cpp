#if 0
#include <mutex>
template <class Mutex> class lock_guard;
#endif 

#include <iostream>
#include <exception>
#include <thread>
#include <mutex>

using std::cout;
using std::cerr;
using std::endl;
using std::exception;
using std::thread;
using std::mutex;
using std::lock_guard;

class Singleton {
	static Singleton *_singleton;
	static mutex _mtx;

private:
	Singleton() {
		cout << __FUNCTION__ << endl;
	}

	~Singleton() {
		cout << __FUNCTION__ << endl;
	}

	Singleton(const Singleton&) = delete;
	void operator=(const Singleton&) = delete;
	void operator=(Singleton&&) = delete;

public:
	static Singleton *GetInstace() {
		if (_singleton == nullptr) {
			lock_guard<mutex> lock(_mtx);
			if (_singleton == nullptr) {
				static Singleton singleton;
				_singleton = &singleton;
			}
		}
		return _singleton;
	}
};

Singleton *Singleton::_singleton = nullptr;
mutex Singleton::_mtx;

void func(int i) {
	try {
		Singleton::GetInstace();
	}
	catch (...) {
		cout << "exception..." << endl;
	}
}

int main(int argc, char *argv[]) {
	const int THREAD_NUM = 10;
	thread arr[THREAD_NUM];

	for (int i = 0; i < THREAD_NUM; ++i) {
		arr[i] = thread(func, i);
	}

	for (int i = 0; i < THREAD_NUM; ++i) {
		arr[i].join();
	}

	return 0;
}
