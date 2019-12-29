#if 0
#include <future>
template <class T>  future;
template <class R&> future<R&>;     // specialization : T is a reference type (R&)
template <>         future<void>;   // specialization : T is void
#endif

#include <iostream>     
#include <chrono> 
#include <future>        

using std::cout;
using std::endl;
using std::flush;
using std::future;
using std::future_status;
using std::async;
namespace chrono = std::chrono;

bool is_prime(int x) {
	for (int i = 2; i < x; i += 1) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

int main(int argc, char *argv[]) {
	future<bool> fut = async(is_prime, 444444443);

	cout << "checking, please wait";
	chrono::milliseconds span(100);
	while (fut.wait_for(span) == future_status::timeout) {
		cout << '.' << flush;
	}

	bool x = fut.get();
	cout << endl << "444444443 " << (x ? "is" : "is not") << " prime." << endl;

	return 0;
}