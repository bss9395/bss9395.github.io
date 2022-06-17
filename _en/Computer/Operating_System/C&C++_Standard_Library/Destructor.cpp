/* Destructor.cpp
Author: BSS9395
Update: 2022-06-15T22:14:00+08@China-Shanghai+08
Design: C++ Language Feature: Destructor
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Nested {
public:
	Nested() {
		fprintf(stderr, "%s\n", __FUNCTION__);
	}
	~Nested() {
		fprintf(stderr, "%s\n", __FUNCTION__);
	}
};

class Destructor {
public:
	Nested _nested;

public:
	Destructor() {
		fprintf(stderr, "%s\n", __FUNCTION__);
	}

	~Destructor() {
		fprintf(stderr, "%s\n", __FUNCTION__);
	}

public:
	void _Clear() {
		fprintf(stderr, "%s\n", __FUNCTION__);
		this->~Destructor();                   
	}
};

void Test_Destructor() {
	Destructor destructor = Destructor();
	destructor._Clear();
}

void Test_delete() {
	Destructor* destructor = (Destructor *)malloc(sizeof(Destructor));
	delete destructor;

	destructor = new Destructor();
	free(destructor);
}

int main(int argc, char* argv[]) {
	//Test_Destructor();
	Test_delete();
}
