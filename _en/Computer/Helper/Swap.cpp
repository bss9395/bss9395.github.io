#include <iostream>
using std::cout;
using std::endl;

#define SWAP(x, y) \
    x = x + y;     \
    y = x - y;     \
    x = x - y;

template<typename Type>
void swap(Type &x, Type &y) {
	x = x + y;
	y = x - y;
	x = x - y;
}

void swap(int &x, int &y) {
	x = x ^ y;
	y = x ^ y;
	x = x ^ y;
}

int main(int argc, char *argv[]) {
	int a = 3;
	int b = 4;

	SWAP(a, b);
	swap(a, b);

	cout << "  a = " << a;
	cout << ", b = " << b << endl;
	return 0;
}