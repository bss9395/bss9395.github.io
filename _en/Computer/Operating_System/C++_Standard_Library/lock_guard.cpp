#if 0
#include <mutex>
template <class Mutex>
class lock_guard;
#endif 

#include <iostream>
#include <exception>
#include <thread>
#include <mutex>

using std::cout;
using std::endl;
using std::exception;
using std::thread;
using std::mutex;
using std::lock_guard;

class Singleton {
	class Garbo {
	public:
		~Garbo() {
			if (Singleton::singleton != nullptr)
			{
				delete Singleton::singleton;
			}
		}
	};
	static Garbo garbo;
	static Singleton *singleton;
	static mutex mtx;

private:
	Singleton() {
		cout << "Singleton constructor" << endl;
	}
	~Singleton() {
		cout << "Singleton destructor" << endl;
	}
	Singleton(const Singleton&) = delete;
	void operator=(const Singleton&) = delete;
	void operator=(Singleton&&) = delete;

public:
	static Singleton *GetInstace() {
		if (singleton == nullptr) {
			lock_guard<mutex> guard(mtx);
			if (singleton == nullptr) {
				singleton = new Singleton;
				throw new exception;
			}
		}
		return singleton;
	}

	void print(int i) {
		cout << i << '#' << endl;
	}
};

Singleton::Garbo Singleton::garbo;
Singleton *Singleton::singleton = nullptr;
mutex Singleton::mtx;

void func(int i) {
	try {
		Singleton::GetInstace()->print(i);
	}
	catch (...) {
		cout << "catch exception" << endl;
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
