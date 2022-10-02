/* Number_Identification.cpp
Author: bss9395
Update: 2022-10-01T10:01:00+08@China-Guangdong-Zhanjiang+08
Design: Number Identification.cpp
*/

/*
Input : Jkdi234klowe90a3
Output: Jkdi*234*klowe*90*a*3*
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]) {
	string str = "Jkdi234klowe90a3";
	string trans = "";

	int i = 0;
	int leng = str.length();
	while (i < leng) {
		if ('0' <= str[i] && str[i] <= '9') {
			trans += '*';
			while (i < leng && '0' <= str[i] && str[i] <= '9') {
				trans += str[i];
				i += 1;
			}
			trans += '*';
		}
		trans += str[i];
		i += 1;
	}
	fprintf(stdout, "%s\n", trans.c_str());
	return 0;
}