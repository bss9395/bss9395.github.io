/* Cpp_Multimap.cpp
Author: BSS9395
Update: 2023-08-28
Design: C++ Multimap
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
using namespace std;


struct Datum {
	string _name   = "";
	double _credit = 0.0;
};

static auto _Cpp_Multimap() -> void {
	multimap<int, Datum> map;
	Datum datum;
	datum._name = "C";
	datum._credit = 90.0;
	map.insert(pair<int, Datum>(1, datum));
	datum._name = "C++";
	datum._credit = 80.0;
	map.insert(pair<int, Datum>(1, datum));
	datum._name = "C#";
	datum._credit = 60.0;
	map.insert(pair<int, Datum>(2, datum));
	datum._name = "Java";
	datum._credit = 70.0;
	map.insert(pair<int, Datum>(1, datum));
	datum._name = "Python";
	datum._credit = 70.0;
	map.insert(pair<int, Datum>(1, datum));
	datum._name = "Java";
	datum._credit = 75.0;
	map.insert(pair<int, Datum>(1, datum));

	fprintf(stdout, "########################################\n");
	for (auto beg = map.begin(); beg != map.end(); ++beg) {
		fprintf(stdout, "[%d, %s, %lf]\n", beg->first, beg->second._name.c_str(), beg->second._credit);
	}

	for (auto beg = map.begin(); beg != map.end(); ) {
		if (beg->second._name == "Java") {
			beg = map.erase(beg);
			continue;
		}
		++beg;
	}

	fprintf(stdout, "########################################\n");
	for (auto beg = map.begin(); beg != map.end(); ++beg) {
		fprintf(stdout, "[%d, %s, %lf]\n", beg->first, beg->second._name.c_str(), beg->second._credit);
	}
}


int main(int argc, char* argv[]) {
	_Cpp_Multimap();

	return 0;
}