#if 0
#include <mutex>
template <class Mutex> class unique_lock;
#endif

#include <iostream>      
#include <thread>        
#include <mutex>  

using std::cout;
using std::endl;
using std::thread;
using std::mutex;
using std::unique_lock;

mutex mtx;

void print(int n, char c) {
	unique_lock<mutex> lck(mtx);
	// mtx.lock();
	for (int i = 0; i < n; i += 1) {
		cout << c;
	}
	cout << endl;
	// mtx.unlock();
}

int main(int argc, char *argv[]) {
	thread th1(print, 50, '*');
	thread th2(print, 50, '$');

	th1.join();
	th2.join();
	return 0;
}