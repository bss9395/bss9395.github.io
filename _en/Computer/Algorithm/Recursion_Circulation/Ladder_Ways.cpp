/* Ladder_Ways.cpp
Author: BSS9395
Update: 2023-06-25T23:13:00+08@China-Beijing+08
Design: Ways of Ladder
*/

#include <iostream>
#include <string>
#include <vector>
#include <functional>
using namespace std;

/*
stairs(6)
|- stairs(5)
|  |- stairs(4)
|  |  |- stairs(3)
|  |  |  |- stairs(2)
|  |  |  |  |- stairs(1)
|  |  |  |  |  |- stairs(0), 6
|  |  |  |  |- stairs(0)   , 5
|  |  |  |- stairs(1)
|  |  |     |- stairs(0)   , 5
|  |  |- stairs(2)
|  |     |- stairs(1)
|  |     |  |- stairs(0)   , 5
|  |     |- stairs(0)      , 4
|  |- stairs(3)
|     |- stairs(2)
|     |  |- stairs(1)
|     |  |  |- stairs(0)   , 5
|     |  |- stairs(0)      , 4
|     |- stairs(1)
|        |- stairs(0)      , 4
|- stairs(4)
   |- stairs(3)
   |  |- stairs(2)
   |  |  |- stairs(1)
   |  |  |  |- stairs(0)   , 5
   |  |  |- stairs(0)      , 4
   |  |- stairs(1)
   |     |- stairs(0)      , 4
   |- stairs(2)
	  |- stairs(1)
	  |  |- stairs(0)      , 4
	  |- stairs(0)         , 3
						   . 13, [7, 6]
*/
class Ladder_Ways {
	typedef      signed __int64    in06;

public:
	/*
	问题：假设有stairs个台阶，每跨一步可以上1阶或者2阶直到n阶，则走完stairs个台阶，总共有多少种走法？
	分析：
		ways(stairs) = ways(stairs-1) + ways(stairs-2);
	*/
	static auto _Ladder_Ways_Recursion(in06 stairs = 6, in06 steps = 2) -> in06 {
		if (false == (1 <= stairs && 1 <= steps)) {
			return 0;
		}

		auto __Ladder_Ways_Recursion = function<in06(in06)>();
		__Ladder_Ways_Recursion = [&__Ladder_Ways_Recursion, steps](in06 stair) -> in06 {
			if (stair < 0) {
				return 0;
			}
			else if (stair == 0) {
				return 1;
			}

			auto ways = (in06)0;
			for (in06 step = 1; step <= steps; step += 1) {
				ways += __Ladder_Ways_Recursion(stair - step);
			}
			return ways;
		};

		return __Ladder_Ways_Recursion(stairs);
	}

	static auto _Ladder_Ways_Recursion_Cache(in06 stairs = 6, in06 steps = 2) -> in06 {
		if (false == (1 <= stairs && 1 <= steps)) {
			return 0;
		}
	
		auto cache = vector<in06>(1 + stairs, 0); 
		cache[0] = 1;
		auto __Ladder_Ways_Recursion_Cache = function<void(in06)>();
		__Ladder_Ways_Recursion_Cache = [&__Ladder_Ways_Recursion_Cache, &cache, steps](in06 stair) -> void {
			if (0 < cache[stair]) {
				return;
			}
			for (auto step = (in06)1; step <= steps; step += 1) {
				if (0 <= stair - step) {
					__Ladder_Ways_Recursion_Cache(stair - step);
					cache[stair] += cache[stair - step];
				}
			}
		};

		__Ladder_Ways_Recursion_Cache(stairs);
		return cache[stairs];
	}

	static auto _Ladder_Ways_Circulation(in06 stairs = 6, in06 steps = 2) -> in06 {
		if (false == (1 <= stairs && 1 <= steps)) {
			return 0;
		}

		auto ways = vector<in06>(1 + stairs, 0);
		ways[0] = 1;
		for (auto stair = (in06)1; stair <= stairs; stair += 1) {
			for (auto step = (in06)1; step <= steps; step += 1) {
				if (0 <= stair - step) {
					ways[stair] += ways[stair - step];
				}
			}
		}
		return ways[stairs];
	}

public:
	/*
	问题：假设有stairs个台阶，每跨一步可以上1阶或者2阶直到n阶。假设第一步迈左脚（奇数），则则走完stairs个台阶正好迈左脚（奇数）或者迈右脚（偶数），总共有多少种走法？
	分析：
		ways_even(stairs) = ways_odd (stairs-1) + ways_odd (stairs-2);
		ways_odd (stairs) = ways_even(stairs-1) + ways_even(stairs-2);
	*/
	static auto _Ladder_Ways_Stagger_Recursion(in06 stairs = 6, in06 steps = 2) -> vector<in06> {
		if (false == (1 <= stairs && 1 <= steps)) {
			return vector<in06>{ 0, 0 };
		}

		auto ways_even_odd = vector<in06>(2, 0);
		auto __Ladder_Ways_Stagger_Recursion = function<void(in06, in06)>();
		__Ladder_Ways_Stagger_Recursion = [&__Ladder_Ways_Stagger_Recursion, &ways_even_odd, steps](in06 stairs, in06 step_odd_even) -> void {
			if (stairs < 0) {
				return;
			}
			else if (stairs == 0) {
				ways_even_odd[step_odd_even % 2] += 1;
				return;
			}

			step_odd_even += 1;
			for (auto step = (in06)1; step <= steps; step += 1) {
				__Ladder_Ways_Stagger_Recursion(stairs - step, step_odd_even);
			}
		};

		__Ladder_Ways_Stagger_Recursion(stairs, 0);
		return ways_even_odd;
	}

	static auto _Ladder_Ways_Stagger_Recursion_Odd_Even(in06 stairs = 6, in06 steps = 2) -> vector<in06> {
		if (false == (1 <= stairs && 1 <= steps)) {
			return vector<in06>{ 0, 0 };
		}

		auto __Ladder_Ways_Stagger_Recursion_Odd  = function<in06(in06)>();
		auto __Ladder_Ways_Stagger_Recursion_Even = function<in06(in06)>();
		__Ladder_Ways_Stagger_Recursion_Odd  = [&__Ladder_Ways_Stagger_Recursion_Even, steps](in06 stairs) -> in06 {
			if (stairs < 0) {
				return 0;
			}
			else if (stairs == 0) {
				return 0;
			}
			
			auto ways = (in06)0;
			for (auto step = (in06)1; step <= steps; step += 1) {
				ways += __Ladder_Ways_Stagger_Recursion_Even(stairs - step);
			}
			return ways;
		};
		__Ladder_Ways_Stagger_Recursion_Even = [&__Ladder_Ways_Stagger_Recursion_Odd, steps](in06 stairs) -> in06 {
			if (stairs < 0) {
				return 0;
			}
			else if (stairs == 0) {
				return 1;
			}

			auto ways = (in06)0;
			for (auto step = (in06)1; step <= steps; step += 1) {
				ways += __Ladder_Ways_Stagger_Recursion_Odd(stairs - step);
			}
			return ways;
		};

		auto ways_odd  = __Ladder_Ways_Stagger_Recursion_Odd(stairs);
		auto ways_even = __Ladder_Ways_Stagger_Recursion_Even(stairs);
		return vector<in06> { ways_even, ways_odd };
	}

	static auto _Ladder_Ways_Stagger_Recursion_Cache(in06 stairs = 6, in06 steps = 2) -> vector<in06> {
		if (false == (1 <= stairs && 1 <= steps)) {
			return vector<in06> { 0, 0 };
		}

		auto cache_even = vector<in06>(1 + stairs, 0);
		auto cache_odd  = vector<in06>(1 + stairs, 0);
		cache_even[0] = 1;
		cache_odd[0]  = 0;
		auto __Ladder_Ways_Stagger_Recursion_Cache = function<void(in06)>();
		__Ladder_Ways_Stagger_Recursion_Cache = [&__Ladder_Ways_Stagger_Recursion_Cache, &cache_even, &cache_odd, steps](in06 stairs) -> void {
			if (0 < cache_even[stairs] && 0 < cache_odd[stairs]) {
				return;
			}

			for (auto step = (in06)1; step <= steps; step += 1) {
				if (0 <= stairs - step) {
					__Ladder_Ways_Stagger_Recursion_Cache(stairs - step);
					cache_even[stairs] += cache_odd [stairs - step];
					cache_odd [stairs] += cache_even[stairs - step];
				}
			}
		};

		__Ladder_Ways_Stagger_Recursion_Cache(stairs);
		return vector<in06> { cache_even[stairs], cache_odd[stairs] };
	}

	static auto _Ladder_Ways_Stagger_Circulation(in06 stairs = 6, in06 steps = 2) -> vector<in06> {
		if (false == (1 <= stairs && 1 <= steps)) {
			return vector<in06> { 0, 0 };
		}

		auto ways_even = vector<in06>(1 + stairs, 0);
		auto ways_odd  = vector<in06>(1 + stairs, 0);
		ways_even[0] = 1;
		ways_odd[0]  = 0;
		for (auto stair = 1; stair <= stairs; stair += 1) {
			for (auto step = 1; step < steps; step += 1) {
				if (0 <= stair - step) {
					ways_even[stair] += ways_odd[stair - step];
					ways_odd[stair] += ways_even[stair - step];
				}
			}
		}
		return vector<in06> { ways_even[stairs], ways_odd[stairs] };
	}

public:
	static auto _Test_Ladder_Ways_Recursion() -> void {
		auto ways = _Ladder_Ways_Recursion();
		fwprintf(stdout, L"ways = %lld\n", ways);
	}

	static auto _Test_Ladder_Ways_Recursion_Cache() -> void {
		auto ways = _Ladder_Ways_Recursion_Cache();
		fwprintf(stdout, L"ways = %lld\n", ways);
	}

	static auto _Test_Ladder_Ways_Circulation() -> void {
		auto ways = _Ladder_Ways_Circulation();
		fwprintf(stdout, L"ways = %lld\n", ways);
	}

	static auto _Test_Ladder_Ways_Stagger_Recursion() -> void {
		auto ways = _Ladder_Ways_Stagger_Recursion();
		fwprintf(stdout, L"ways of even step = %lld, ways of odd step = %lld\n", ways[0], ways[1]);
	}

	static auto _Test_Ladder_Ways_Stagger_Recursion_Odd_Even() -> void {
		auto ways = _Ladder_Ways_Stagger_Recursion_Odd_Even();
		fwprintf(stdout, L"ways of even step = %lld, ways of odd step = %lld\n", ways[0], ways[1]);
	}

	static auto _Test_Ladder_Ways_Stagger_Recursion_Cache() -> void {
		auto ways = _Ladder_Ways_Stagger_Recursion();
		fwprintf(stdout, L"ways of even step = %lld, ways of odd step = %lld\n", ways[0], ways[1]);
	}

	static auto _Test_Ladder_Ways_Stagger_Circulation() -> void {
		auto ways = _Ladder_Ways_Stagger_Recursion();
		fwprintf(stdout, L"ways of even step = %lld, ways of odd step = %lld\n", ways[0], ways[1]);
	}
};

int main(int argc, char* argv[]) {
	// Ladder_Ways::_Test_Ladder_Ways_Recursion();
	// Ladder_Ways::_Test_Ladder_Ways_Recursion_Cache();
	// Ladder_Ways::_Test_Ladder_Ways_Circulation();
	// Ladder_Ways::_Test_Ladder_Ways_Stagger_Recursion();
	Ladder_Ways::_Test_Ladder_Ways_Stagger_Recursion_Odd_Even();
	Ladder_Ways::_Test_Ladder_Ways_Stagger_Recursion_Cache();
	// Ladder_Ways::_Test_Ladder_Ways_Stagger_Circulation();

	return 0;
}
