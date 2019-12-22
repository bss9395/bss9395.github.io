#if 0
#include <random>
class default_random_engine;
#endif

#include <iostream>
#include <string>
#include <chrono>
#include <random>

using namespace std;

int main(int argc, char *argv[]) {
	long seed1 = (long)chrono::system_clock::now().time_since_epoch().count();
	default_random_engine engine1(seed1);
	cout << "random number 1: " << engine1() << endl;

	string str = "seed2";
	seed_seq seed2(str.begin(), str.end());
	default_random_engine engine2(seed2);
	cout << "random number 2: " << engine2() << endl;

	seed_seq seed3 = { 11, 12, 13 };
	default_random_engine engine3(seed3);
	cout << "random number 3: " << engine3() << endl;

	return 0;
}