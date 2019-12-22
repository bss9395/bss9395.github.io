/* Lock.cpp
* Author: BSS9395
* Update: 2019-12-02T15:28:00+08@ShenZhen
* Design: Automation
*/

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

class Lock {
public:
	Lock(mutex &mtx)
		: _mutex(mtx) {
		_mutex.lock();
	}

	Lock(const Lock &lock) = delete;
	Lock(Lock &&lock) = delete;
	Lock &operator=(const Lock &lock) = delete;
	Lock &operator=(Lock &&lock) = delete;

	~Lock() {
		_mutex.unlock();
	}
private:
	mutex& _mutex;
};

class Singleton {
public:
	class Garbo {
	public:
		~Garbo() {
			if (Singleton::_instance != nullptr) {
				delete Singleton::_instance;
			}
		}
	};

	static Singleton *_instance;
	static Garbo _garbo;
	static mutex _mutex;

public:
	Singleton() {
		cerr << __FUNCTION__ << endl;
	}

	~Singleton() {
		cerr << __FUNCTION__ << endl;
	}

	Singleton(const Singleton&) = delete;
	Singleton operator=(const Singleton&) = delete;

public:
	static Singleton &GetInstace() {
		if (_instance == nullptr) {
			Lock lock(_mutex);
			if (_instance == nullptr) {
				_instance = new Singleton();
				throw 1;
			}
		}
		return *_instance;
	}
};

Singleton *Singleton::_instance = nullptr;
Singleton::Garbo Singleton::_garbo;
mutex Singleton::_mutex;

void func(int i) {
	try {
		Singleton::GetInstace();
	}
	catch (...) {
		cerr << "exception..." << endl;
	}
}

int main(int argc, char *argv[]) {
	const int THREAD_NUM = 10;
	thread *ths[THREAD_NUM];

	for (int i = 0; i < THREAD_NUM; ++i) {
		ths[i] = new thread(func, i);
	}

	for (int i = 0; i < THREAD_NUM; ++i) {
		ths[i]->join();
		delete ths[i];
	}

	return 0;
}
