/* Distribution.cpp
Author: BSS9395
Update: 2023-06-19T00:19:00+08@China-Beijing+08
Design: Linear Congruential Generator
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<functional>
using namespace std;

/*
Even * Even = Even;    Even + Even = Even;    Even - Even = Even;    Even % Even = Even;
Even * Odd  = Even;    Even + Odd  = Odd ;    Even - Odd  = Odd ;    Even % Odd  = ?   ;
Odd  * Even = Even;    Odd  + Even = Odd ;    Odd  - Even = Odd ;    Odd  % Even = Odd ;
Odd  * Odd  = Odd ;    Odd  + Odd  = Even;    Odd  - Odd  = Even;    Odd  % Odd  = ?   ;
*/
class Distribution {
	typedef      signed __int32    in05;
	typedef    unsigned __int32    ui05;
	typedef      signed __int64    in06;
	typedef    unsigned __int64    ui06;

public:
	static auto _Confirm_Prime(ui06 prime) -> bool {
		if (prime <= 0) {
			return false;
		}
		else if (prime <= 2) {
			return true;
		}
		else if ((prime & 0x01) == 0x00) {  // note: even number
			return false;
		}

		auto root = (ui06)sqrt(prime);
		for (auto fact = (ui06)3; fact <= root; fact += 2) {
			if ((prime % fact) == 0) {
				return false;
			}
		}
		return true;
	}

	static auto _Generate_Primes(ui06 range, const string& filename = "primes.txt") -> void {
		static ui06 _primes_256[] = {
			1, 2, 3, 5, 7, 11, 13,
			17, 19, 23, 29, 31,
			37, 41, 43, 47, 53, 59, 61,
			67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127,
			131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251
		};

		auto file  = fopen(&filename[0], "wt+");
		fwprintf(file, L"  %llu", (ui06)1);
		fwprintf(file, L", %llu", (ui06)2);
		for (auto prime = (ui06)3; prime <= range; prime += 2) {
			if ((prime & 0x01) == 0x01 && _Confirm_Prime(prime) == true) {
				fwprintf(file, L", %llu", prime);
			}
		}
		fclose(file);
	}

public:
	static auto _Generator_Cyclic_Permuted_32bits_Prototype(ui06 seed, in06 steps = 3) -> function<ui05()> {
		static ui06         _module = ((~(ui06)0x00) >> (64 - 32));
		static vector<ui06> _primes = vector<ui06>();
		struct Generator_Cyclic_Permuted_32bits_Prototype {
			ui06 _seed  = 0;
			in06 _steps = 0;
			Generator_Cyclic_Permuted_32bits_Prototype(ui06 seed, in06 steps) {
				static auto _Generate_Primes = [](in06 steps, double prefer = 3.0 / 5.0) -> void {
					(1 <= steps) ? steps : (steps = 1);
					(steps <= 7) ? steps : (steps = 7);
					if (false == ((in06)_primes.size() < steps)) {
						return ;
					}

					auto prime = (1 <= _primes.size()) ? _primes[(in06)_primes.size() - 1] : (ui06)(_module * prefer);
					while ((in06)_primes.size() < steps) {
						prime += 1;
						if ((prime & 0x01) == 0x01 && _Confirm_Prime(prime) == true) {
							_primes.push_back(prime);
						}
					}
				};
				
				_Generate_Primes(steps);
				_seed = seed;
				_steps = steps;
			}

			auto operator()() -> ui05 {
				_seed = (_seed + 1) % _module;
				auto permute = _seed;
				for (auto step = (in06)0; step < _steps; step += 1) {
					permute = ((permute + 1) * _primes[step]) % _module;
				}
				return (ui05)permute;
			}
		};
		return Generator_Cyclic_Permuted_32bits_Prototype(seed, steps);
	}

	static auto _Generator_Cyclic_Permuted_32bits(ui06 seed) -> function<ui05()> {
		static ui06 _modulo[33] = {};
		static ui06 _primes[33] = {};
		struct Generator_Cyclic_Permuted_32bits {
			ui06 _seeds[33] = {};
			Generator_Cyclic_Permuted_32bits(ui06 seed) {
				static auto _Generate_Modulo_Primes = [](double prefer = 3.0 / 5.0) -> bool {
					_modulo[0] = 32;
					for (auto i = (ui06)1, size = sizeof(_modulo) / sizeof(_modulo[0]); i < size; i += 1) {
						_modulo[i] = ((~(ui06)0x00) >> (64 - i));
					}

					_primes[0] = 17;
					for (auto i = (ui06)1, size = sizeof(_primes) / sizeof(_primes[0]); i < size; i += 1) {
						auto prime = (ui06)(_modulo[i] * prefer);
						while (false == ((prime & 0x01) == 0x01 && _Confirm_Prime(prime))) {
							prime += 1;
						}
						_primes[i] = prime;
					}

					return true;
				};
				static auto _static = _Generate_Modulo_Primes();


				_seeds[0] = seed;
				for (in06 i = 1, size = sizeof(_seeds) / sizeof(_seeds[0]); i < size; i += 1) {
					_seeds[0] = (_seeds[0] + 1) % _modulo[0];
					_seeds[i] = ((_seeds[0] * _primes[0]) % _modulo[0]);
				}
			}

			auto operator()() -> ui05 {
				_seeds[0] = (_seeds[0] + 1) % _modulo[0];
				auto bits = ((_seeds[0] * _primes[0]) % _modulo[0]) + 1;
				_seeds[bits] = (_seeds[bits] + 1) % _modulo[bits];
				auto permute = (_seeds[bits] * _primes[bits]) % _modulo[bits];
				return (ui05)permute;
			}
		};
		return Generator_Cyclic_Permuted_32bits(seed);
	}

	static auto _Generator_Uniform_Distribution_Two_rand(ui06 seed) -> function<ui06()> {
		struct Generator_Uniform_Distribution_Two_rand {
			function<ui05()> _generator = rand;
			Generator_Uniform_Distribution_Two_rand(ui06 seed) {
				srand((ui05)seed);
			}

			auto operator()() -> ui06 {
				while (true) {
					ui06 yield0 = _generator() & 0x01;
					ui06 yield1 = _generator() & 0x01;
					if (yield0 == 0 && yield1 == 1) {
						return 0;
					}
					else if (yield0 == 1 && yield1 == 0) {
						return 1;
					}
				}
			}
		};
		return Generator_Uniform_Distribution_Two_rand(seed);
	}

	static auto _Generator_Uniform_Distribution_Two(ui06 seed) -> function<ui06()> {
		struct Generator_Uniform_Distribution_Two {
			function<ui05()> _generator = function<ui05()>();
			Generator_Uniform_Distribution_Two(ui06 seed) {
				_generator = _Generator_Cyclic_Permuted_32bits(seed);
			}

			auto operator()() -> ui06 {
				while (true) {
					ui06 yield0 = _generator() & 0x01;
					ui06 yield1 = _generator() & 0x01;
					if (yield0 == 0 && yield1 == 1) {
						return 0;
					}
					else if (yield0 == 1 && yield1 == 0) {
						return 1;
					}
				}
			}
		};
		return Generator_Uniform_Distribution_Two(seed);
	}

	static auto _Generator_Uniform_Distribution_rand(ui06 seed, ui06 range = (~(ui05)0x00)) -> function<ui06()> {
		struct Generator_Uniform_Distribution_rand {
			function<ui06()> _generator = function<ui06()>();
			ui06             _range = 0;
			ui06             _bits = 0;
			Generator_Uniform_Distribution_rand(ui06 seed, ui06 range) {
				_generator = _Generator_Uniform_Distribution_Two_rand(seed);

				_range = range;
				while (range != 0) {
					_bits += 1;
					range >>= 1;
				}
				fwprintf(stdout, L"_bits=%llu\n", _bits);
			}

			auto operator()() -> ui06 {
				while (true) {
					auto uniform = (ui06)0;
					for (auto bit = (ui06)0; bit < _bits; bit += 1) {
						uniform <<= 1;
						uniform |= _generator();
					}
					if (uniform <= _range) {
						return uniform;
					}
				}
			}
		};
		return Generator_Uniform_Distribution_rand(seed, range);
	}

	static auto _Generator_Uniform_Distribution(ui06 seed, ui06 range = (~(ui05)0x00)) -> function<ui06()> {
		struct Generator_Uniform_Distribution {
			function<ui06()> _generator = function<ui06()>();
			ui06             _range     = 0;
			ui06             _bits      = 0;
			Generator_Uniform_Distribution(ui06 seed, ui06 range) {
				_generator = _Generator_Uniform_Distribution_Two(seed);

				_range = range;
				while (range != 0) {
					_bits += 1;
					range >>= 1;
				}
				fwprintf(stdout, L"_bits=%llu\n", _bits);
			}

			auto operator()() -> ui06 {
				while (true) {
					auto uniform = (ui06)0;
					for (auto bit = (ui06)0; bit < _bits; bit += 1) {
						uniform <<= 1;
						uniform |= _generator();
					}
					if (uniform <= _range) {
						return uniform;
					}
				}
			}
		};
		return Generator_Uniform_Distribution(seed, range);
	}

public:
	static auto _Test_Generator_Cyclic_Permuted_32bits_Prototype(in05 sample = 50) -> void {
		auto generator = _Generator_Cyclic_Permuted_32bits_Prototype((ui05)time(NULL));
		fwprintf(stdout, L"[");
		for (auto i = (in05)0; i < sample; i += 1) {
			auto yield = generator();
			if (i == 0) {
				fwprintf(stdout, L"%u", yield);
			}
			else {
				fwprintf(stdout, L", %u", yield);
			}
		}
		fwprintf(stdout, L"]\n\n");
	}

	static auto _Test_Generator_Cyclic_Permuted_32bits(in05 sample = 50) -> void {
		auto generator = _Generator_Cyclic_Permuted_32bits((ui05)time(NULL));
		fwprintf(stdout, L"[");
		for (in05 i = 0; i < sample; i += 1) {
			auto yield = generator();
			if (i == 0) {
				fwprintf(stdout, L"%u", yield);
			}
			else {
				fwprintf(stdout, L", %u", yield);
			}
		}
		fwprintf(stdout, L"]\n\n");
	}

	static auto _Test_Generator_Uniform_Distribution_Two_rand(in05 sample = 50) -> void {
		auto generator = _Generator_Uniform_Distribution_Two_rand((ui05)time(NULL));
		fwprintf(stdout, L"[");
		for (in05 i = 0; i < sample; i += 1) {
			auto yield = generator();
			if (i == 0) {
				fwprintf(stdout, L"%llu", yield);
			}
			else {
				fwprintf(stdout, L", %llu", yield);
			}
		}
		fwprintf(stdout, L"]\n\n");
	}

	static auto _Test_Generator_Uniform_Distribution_Two(in05 sample = 50) -> void {
		auto generator = _Generator_Uniform_Distribution_Two((ui05)time(NULL));
		fwprintf(stdout, L"[");
		for (in05 i = 0; i < sample; i += 1) {
			auto yield = generator();
			if (i == 0) {
				fwprintf(stdout, L"%llu", yield);
			}
			else {
				fwprintf(stdout, L", %llu", yield);
			}
		}
		fwprintf(stdout, L"]\n\n");
	}

	static auto _Test_rand(in05 sample = 50) -> void {
		fwprintf(stdout, L"RAND_MAX=%u\n", RAND_MAX);
		srand((unsigned int)time(NULL));
		auto generator = rand;
		fwprintf(stdout, L"[");
		for (in05 i = 0; i < sample; i += 1) {
			auto yield = generator();
			if (i == 0) {
				fwprintf(stdout, L"%u", yield);
			}
			else {
				fwprintf(stdout, L", %u", yield);
			}
		}
		fwprintf(stdout, L"]\n\n");
	}

	static auto _Test_Generator_Uniform_Distribution_rand(in05 sample = 50) -> void {
		auto generator = _Generator_Uniform_Distribution_rand((ui05)time(NULL));
		fwprintf(stdout, L"[");
		for (in05 i = 0; i < sample; i += 1) {
			auto yield = generator();
			if (i == 0) {
				fwprintf(stdout, L"%llu", yield);
			}
			else {
				fwprintf(stdout, L", %llu", yield);
			}
		}
		fwprintf(stdout, L"]\n\n");
	}

	static auto _Test_Generator_Uniform_Distribution(in05 sample = 50) -> void {
		auto generator = _Generator_Uniform_Distribution((ui05)time(NULL));
		fwprintf(stdout, L"[");
		for (in05 i = 0; i < sample; i += 1) {
			auto yield = generator();
			if (i == 0) {
				fwprintf(stdout, L"%llu", yield);
			}
			else {
				fwprintf(stdout, L", %llu", yield);
			}
		}
		fwprintf(stdout, L"]\n\n");
	}
};


int main(int argc, char* argv[]) {
	// Distribution::_Test_Generator_Cyclic_Permuted_32bits_Prototype();
	// Distribution::_Test_Generator_Cyclic_Permuted_32bits();
	// Distribution::_Test_Generator_Uniform_Distribution_Two_rand();
	// Distribution::_Test_Generator_Uniform_Distribution_Two();
	Distribution::_Test_rand();
	// Distribution::_Test_Generator_Uniform_Distribution_rand();
	// Distribution::_Test_Generator_Uniform_Distribution();

	return 0;
}
