/* Instance.cpp
Design: Singleton
Author: BSS9395
Update: 2019-08-16T19:32
*/

#include <iostream>
#include <string>
using namespace std;

class Printer {
private:
	Printer()
		:_os(&cout), _count(0), _times(0) {
		cerr << "Printer();" << endl;
	};

	~Printer() {
		cerr << "~Printer();" << endl;
	};

	Printer(const Printer &printer) {
		cerr << "Printer(const Printer &);" << endl;
	}
	Printer &operator=(const Printer &) {
		cerr << "Printer &operator=(const Printer &);" << endl;
	}

public:
	static Printer &getPrinter() {
		static Printer printer;
		printer._count++;
		return printer;
	}

public:
	void printText(const string &txt, ostream &os = cout) {
		_os = &os;

		_times++;
		(*_os) << "[count: " << _count << ", times: " << _times << "] ";
		(*_os) << txt;
	}

protected:
	ostream *_os;
	long _count;
	long _times;
};

int main() {
	Printer &printer1 = Printer::getPrinter();
	Printer &printer2 = Printer::getPrinter();
	Printer &printer3 = printer1;
	Printer &printer4(printer2);

	string txt = "Hello, world!\n";
	printer1.printText(txt);
	printer2.printText(txt);
	printer3.printText(txt);
	printer4.printText(txt);

	return 0;
}