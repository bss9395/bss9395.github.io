/* Cpp_Coroutine.cpp
Author: BSS9395
Update: 2024-10-20T22:03:00+08@China-Guangdong-Zhanjiang+08
Credit: https://zplutor.github.io/2022/03/25/cpp-coroutine-beginner/
*/

#include <coroutine>
#include <iostream>
#include <thread>

class IntReader {
public:
	bool await_ready() {
		fprintf(stdout, "%s\n", __FUNCTION__);
		return false;
	}

	void await_suspend(std::coroutine_handle<> handle) {
		fprintf(stdout, "%s\n", __FUNCTION__);
		std::thread thread([this, handle]() {
			static int seed = 0;
			seed += 1;
			_value = seed;
			handle.resume();
			});
		thread.detach();
	}

	int await_resume() {
		fprintf(stdout, "%s\n", __FUNCTION__);
		return _value;
	}

private:
	int _value = 0;
};

class Task {
public:
	class promise_type {
	public:
		Task get_return_object() {
			fprintf(stdout, "%s\n", __FUNCTION__);
			return Task(std::coroutine_handle<promise_type>::from_promise(*this));
		}

		std::suspend_never initial_suspend() {
			fprintf(stdout, "%s\n", __FUNCTION__);
			return std::suspend_never();
		}

		std::suspend_always yield_value(int value) {
			fprintf(stdout, "%s\n", __FUNCTION__);
			_value = value;
			return std::suspend_always();
		}

		void unhandled_exception() {
			fprintf(stdout, "%s\n", __FUNCTION__);
		}

		std::suspend_never final_suspend() noexcept {
			fprintf(stdout, "%s\n", __FUNCTION__);
			return std::suspend_never();
		}

		int GetValue() const {
			fprintf(stdout, "%s\n", __FUNCTION__);
			return _value;
		}

	private:
		int _value = 0;
	};

public:
	Task(std::coroutine_handle<promise_type> handle)
		: _handle(handle) {
		fprintf(stdout, "%s\n", __FUNCTION__);
	}

	void Next() {
		fprintf(stdout, "%s\n", __FUNCTION__);
		_handle.resume();
	}

	int GetValue() const {
		fprintf(stdout, "%s\n", __FUNCTION__);
		return _handle.promise().GetValue();
	}

private:
	std::coroutine_handle<promise_type> _handle;
};

Task GetInt() {
	fprintf(stdout, "%s\n", __FUNCTION__);
	while (true) {
		IntReader reader;
		int value = co_await reader;
		co_yield value;
	}
}

int main(int argc, char* argv[]) {
	fprintf(stdout, "%s\n", __FUNCTION__);

	auto task = GetInt();
	std::string line;
	while (std::cin >> line) {
		int value = task.GetValue();
		std::cout << value << std::endl;
		task.Next();
	}

	return 0;
}
