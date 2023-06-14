/* Drinking_Bottles.cpp
Author: BSS9395
Update: 2023-06-05T22:37:00+08@China-Guangdong-Zhanjiang+08
Design: Drinking Bottles
*/

#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Drinking_Bottles {
public:
	/*
	һԪǮ��һƿ��ˮ��2����ƿ��һƿ��ˮ������20Ԫ������������ƿ��ˮ��
	*/
	static auto _Count_Bottles(double money, double price = 1.0, int exchange_bottles = 2, int drinks = 1) -> int {
		auto total   = (int)(money / price);
		auto bottles = total;
		while (exchange_bottles <= bottles) {
			auto count = bottles / exchange_bottles * drinks;
			total     += count;
			bottles    = count + bottles % exchange_bottles;
		}
		fwprintf(stdout, L"total drinks: %d\n", total);
		return total;
	}

	static auto _Total_Bottles(int drinks, int exchange_bottles = 2 / 1, int exchange_caps = 3 / 1) -> int {
		auto total   = drinks;
		auto bottles = total;
		auto caps    = total;
		while (exchange_bottles <= bottles || exchange_caps <= caps) {
			auto count = bottles / exchange_bottles + caps / exchange_caps;
			total     += count;
			bottles    = count + bottles % exchange_bottles;
			caps       = count + caps % exchange_caps;
		}
		fwprintf(stdout, L"total drinks: %d\n", total);
		return total;
	}

public:
	static auto _Test_Count_Bottles() -> void {
		double money = 20.0;
		_Count_Bottles(money);
	}
	static auto _Test_Total_Bottles() -> void {
		double money = 20.0;
		double price = 1.0;
		_Total_Bottles((int)(money / price));
	}
};


int main(int argc, char *argv[]) {
	// Drinking_Bottles::_Test_Count_Bottles();
	Drinking_Bottles::_Test_Total_Bottles();
	
	return 0;
}
