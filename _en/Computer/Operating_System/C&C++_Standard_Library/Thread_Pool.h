
#ifndef ThreadPool_h
#define ThreadPool_h

#include <mutex>
#include <queue>
#include <functional>
#include <future>
#include <thread>
#include <utility>
#include <vector>
#include <random>

template<typename Type_>
class Queue_Safe {
private:
	std::queue<Type_> _queue;
	std::mutex _mutex;

public:
	Queue_Safe() {

	}

public:
	bool _Empty() {
		std::unique_lock<std::mutex> lock(_mutex);
		return _queue.empty();
	}

	int _Size() {
		std::unique_lock<std::mutex> lock(_mutex);
		return _queue.size();
	}

	void _Enqueue(Type_& type) {
		std::unique_lock<std::mutex> lock(_mutex);
		_queue.emplace(type);
	}

	bool _Dequeue(Type_& type) {
		std::unique_lock<std::mutex> lock(_mutex);
		if (_queue.empty()) {
			return false;
		}
		type = _queue.front();
		_queue.pop();
		return true;
	}
};

class Thread_Pool {
	class ThreadWorker {
	private:
		Thread_Pool* _pool;
		int _id;

	public:
		ThreadWorker(Thread_Pool* pool, const int id) {
			_pool = pool;
			_id = id;
		}

		void operator()() {
			std::function<void()> func;
			bool dequeued;
			while (_pool->_shutdown == false) {
				{
					std::unique_lock<std::mutex> lock(_pool->_mutex);
					if (_pool->_queue._Empty()) {
						_pool->_condition.wait(lock);
					}
					dequeued = _pool->_queue._Dequeue(func);
				}
				if (dequeued) {
					func();
				}
			}
		}
	};

private:
	bool _shutdown;
	Queue_Safe<std::function<void()>> _queue;
	std::vector<std::thread> _threads;
	std::mutex _mutex;
	std::condition_variable _condition;

public:
	Thread_Pool(const int threads = 4) {
		_shutdown = false;
		_threads = std::vector<std::thread>(threads);
		
		for (int i = 0; i < _threads.size(); i += 1) {
			_threads[i] = std::thread(ThreadWorker(this, i));
		}
	}

	Thread_Pool(const Thread_Pool&) = delete;
	Thread_Pool(Thread_Pool&&) = delete;
	Thread_Pool& operator=(const Thread_Pool&) = delete;
	Thread_Pool& operator=(Thread_Pool&&) = delete;

public:
	void _Shutdown() {
		_shutdown = true;
		_condition.notify_all();
		for (int i = 0; i < _threads.size(); i += 1) {
			if (_threads[i].joinable()) {
				_threads[i].join();
			}
		}
	}

	template<typename F, typename... Args> 
	auto _Submit(F&& func, Args &&...args) -> std::future<decltype(func(args...))> {
		std::function<decltype(func(args...))()> func_void = std::bind(std::forward<F>(func), std::forward<Args>(args)...);
		auto func_task = std::make_shared<std::packaged_task<decltype(func(args...))()>>(func_void);
		std::function<void()> func_wrapper = [func_task]() {
			(*func_task)();
		};
	
		_queue._Enqueue(func_wrapper);
		_condition.notify_one();
		return func_task->get_future();
	}
};

////////////////////////////////////////////////////////////////////////////////

void _Simulate_Hard_Computation() {
	std::this_thread::sleep_for(std::chrono::milliseconds(200 + rand() % 1000));
}

void _Multiply(const int lhs, const int rhs) {
	_Simulate_Hard_Computation();
	const int output = lhs * rhs;
	fprintf(stdout, "%d * %d = %d\n", lhs, rhs, output);
}

void _Multiply_Output(int& output, const int lhs, const int rhs) {
	_Simulate_Hard_Computation();
	output = lhs * rhs;
	fprintf(stdout, "%d * %d = %d\n", lhs, rhs, output);
}

int _Multiply_Return(const int lhs, const int rhs) {
	_Simulate_Hard_Computation();
	const int output = lhs * rhs;
	fprintf(stdout, "%d * %d = %d\n", lhs, rhs, output);
	return output;
}

int main() {
	Thread_Pool pool(3);

	for (int i = 1; i <= 3; i += 1) {
		for (int j = 1; j <= 2; j += 1) {
			pool._Submit(_Multiply, i, j);
		}
	}

	int output_ref;
	auto future1 = pool._Submit(_Multiply_Output, std::ref(output_ref), 5, 6);
	future1.get();
	std::cout << "Last operation result is equals to " << output_ref << std::endl;

	auto future2 = pool._Submit(_Multiply_Return, 5, 3);
	int res = future2.get();
	std::cout << "Last operation result is equals to " << res << std::endl;

	pool._Shutdown();

	return 0;
}

#endif