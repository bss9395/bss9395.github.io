/*normal_distribution.cpp
*/

#if 0
#include <random>
template <class RealType = double> class normal_distribution;
#endif

#include <iostream>
#include <random>
using std::cout;
using std::cerr;
using std::endl;
using std::default_random_engine;
using std::normal_distribution;

void NormalDistribution() {
	default_random_engine engine;
	normal_distribution<double> distribution(5.0, 2.0);

	const int trials = 10000;
	int bucket[10] = { 0 };

	for (int i = 0; i < trials; i += 1) {
		double num = distribution(engine);
		if (0.0 <= num && num < 10.0) {
			bucket[(int)num] += 1;
		}
	}

	char stars[100] = { '\0' };
	for (int i = 0; i < sizeof(stars); i += 1) {
		stars[i] = '*';
	}

	for (int i = 0; i < sizeof(bucket) / sizeof(bucket[0]); i += 1) {
		int cnt = sizeof(stars) * bucket[i] / trials;
		fprintf(stderr, "%02d-%02d: ", i, i + 1);
		fprintf(stderr, "%*.*s\n", cnt, cnt, stars);
	}
}

int main(int argc, char *argv[]) {
	NormalDistribution();

	return 0;
}
