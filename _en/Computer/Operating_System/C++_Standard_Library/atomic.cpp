#if 0
#include <atomic>
template <class T> struct atomic;
#endif

#include <iostream>    
#include <vector>  
#include <atomic>    
#include <thread>    

using std::cout;
using std::endl;
using std::vector;
using std::atomic;
using std::atomic_flag;
using std::thread;
namespace this_thread = std::this_thread;


atomic<bool> ready(false);
atomic_flag winner = ATOMIC_FLAG_INIT;

void count(int id) {
	while (!ready) {
		this_thread::yield();
	}

	for (volatile int i = 0; i < 1000000; ++i) {

	}

	if (!winner.test_and_set()) {
		cout << "thread #" << id << " won!\n";
	}
};

int main(int argc, char *argv[]) {
	vector<thread> threads;
	cout << "spawning 10 threads that count to 1 million...\n";

	for (int i = 1; i <= 10; ++i) {
		threads.push_back(thread(count, i));
	}

	ready = true;
	for (auto& th : threads) {
		th.join();
	}

	return 0;
}