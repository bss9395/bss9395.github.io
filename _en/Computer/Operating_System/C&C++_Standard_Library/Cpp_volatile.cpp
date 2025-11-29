/* Cpp_volatile.cpp
Author: bss9395
Update: 2025/11/05T00:55:00+08@China-BeiJing+08
Keepin: bss9395@yeah.net
*/

#include <iostream>
#include <thread>
#include <vector>
#include <atomic>

class SpinLock {
public:
	volatile bool _locked = false;
	std::atomic<bool> _atomic = false;

	void _Lock() {
		while (_locked == true) {
			;
		}
		_locked = true;
	}
	void _Unlock() {
		_locked = false;
	}

	void _LockAtomic() {
		// 比较和交换操作是原子操作。
		// 若原子对象当前值与期望值相等，则将原子对象当前值更新为新的值，并返回true。
		// 若原子对象当前值与期望值不等，则将期望值更新为原子对象当前值，并返回false。
		// compare_exchange_weak可能会在原子对象当前值与期望值相等的情况下，仍然返回false。
		bool expected = false;
		while (_atomic.compare_exchange_weak(expected, true) == false) {
			expected = false;
		}
		// std::cout << "[expected] " << std::boolalpha << expected << std::endl;
	}
	void _UnlockAtomic() {
		_atomic.store(false);
	}
};

class Critical {
public:
	SpinLock _spinlock;
	int _raced = 0;
	int _shared = 0;

	void _Worker() {
		for (int i = 0; i < 100000; i += 1) {
			_spinlock._Lock();
			_raced += 1;
			_spinlock._Unlock();
		}
	}

	void _WorkerAtomic() {
		for (int i = 0; i < 100000; ++i) {
			_spinlock._LockAtomic();
			_shared += 1;
			_spinlock._UnlockAtomic();
		}
	}
};

int main(int argc, char *argv[]) {
	Critical critical;
	std::vector<std::thread> threads;
	for (int i = 0; i < 4; ++i) {
		threads.emplace_back(&Critical::_Worker, &critical);
		threads.emplace_back(&Critical::_WorkerAtomic, &critical);
	}
	for (auto& thread : threads) {
		thread.join();
	}
	std::cout << "[critical._raced ] " << critical._raced  << std::endl;
	std::cout << "[critical._shared] " << critical._shared << std::endl;
	return 0;
}
