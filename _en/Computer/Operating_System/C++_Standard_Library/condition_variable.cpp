#if 0
#include <condition_variable>
class condition_variable;
#endif

#include <iostream>           
#include <thread>            
#include <mutex>              
#include <condition_variable> 

using std::cout;
using std::endl;
using std::unique_lock;
using std::thread;
using std::mutex;
using std::condition_variable;

mutex mtx;
condition_variable cv;

void print(int id) {
	unique_lock<mutex> lck(mtx);
	cv.wait(lck);
	cout << "thread " << id << endl;
}

void go() {
	unique_lock<mutex> lck(mtx);
	cv.notify_all();
}

int main(int argc, char *argv[]) {
	thread threads[10];
	for (int i = 0; i < 10; i += 1) {
		threads[i] = thread(print, i);
	}

	cout << "10 threads ready to race...\n";
	go();

	for (auto& th : threads) {
		th.join();
	}

	return 0;
}