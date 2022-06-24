/* new.cpp
Author: BSS9395
Update: 2022-06-24T11:57:00+08@China-Shanghai+08
Design: C++ Keyword: new
*/

#include <iostream>
using namespace std;

struct Datum {
	Datum() {
		fprintf(stderr, "[%td] %s\n", __LINE__, __FUNCTION__);
	}

	Datum(const Datum& datum) {
		fprintf(stderr, "[%td] %s\n", __LINE__, __FUNCTION__);
	}

	Datum& operator=(const Datum& datum) {
		fprintf(stderr, "[%td] %s\n", __LINE__, __FUNCTION__);
		if (this != &datum) {
			this->~Datum();
			new (this) Datum(datum);
		}
		return (*this);
	}

	virtual ~Datum() {
		fprintf(stderr, "[%td] %s\n", __LINE__, __FUNCTION__);
	}
};

struct Base {
	char* _base_buffer = nullptr;
	double _base_value = 0.0;
	string _base_text = "";
	Datum _base_datum = Datum();

	Base(const Base& base) {
		fprintf(stderr, "[%td] %s\n", __LINE__, __FUNCTION__);
		// _base_buffer = base._base_buffer;
		// _base_value = base._base_value;
		// _base_text = base._base_text;
		// _base_datum = base._base_datum;

		new (&_base_buffer) char* (base._base_buffer);
		new (&_base_value) double(base._base_value);
		new (&_base_text) string(base._base_text);
		new (&_base_datum) Datum(base._base_datum);
	}

	Base& operator=(const Base& base) {
		fprintf(stderr, "[%td] %s\n", __LINE__, __FUNCTION__);
		if (this != &base) {
			fprintf(stderr, "%s\n", "if (this != &base) {");
			this->~Base();
			new (this) Base(base);
		}
		return (*this);
	}

	virtual ~Base() {
		fprintf(stderr, "[%td] %s\n", __LINE__, __FUNCTION__);
	}
};

struct Derived : public Base {
	char* _derived_buffer = nullptr;
	double _derived_value = 0.0;
	string _derived_text = "";
	Datum _derived_datum = Datum();

	Derived(char* buffer, double value, const string& text)
		: Base(*(Base *)this) {
		fprintf(stderr, "[%td] %s\n", __LINE__, __FUNCTION__);

		//_derived_buffer = buffer;
		//_derived_value = value;
		//_derived_text = text;

		new (&_derived_buffer) char* (buffer);
		new (&_derived_value) double(value);
		new (&_derived_text) string(text);
	}

	Derived(const Derived &derived)
		: Base(*(Base *)&derived) {
		fprintf(stderr, "[%td] %s\n", __LINE__, __FUNCTION__);

		//_derived_buffer = derived._derived_buffer;
		//_derived_value = derived._derived_value;
		//_derived_text = derived._derived_text;
		//_derived_datum = derived._derived_datum;

		new (&_derived_buffer) char* (derived._derived_buffer);
		new (&_derived_value) double(derived._derived_value);
		new (&_derived_text) string(derived._derived_text);
		new (&_derived_datum) Datum(derived._derived_datum);
	}

	Derived& operator=(const Derived& derived) {
		fprintf(stderr, "[%td] %s\n", __LINE__, __FUNCTION__);
		if (this != &derived) {
			fprintf(stderr, "%s\n", "if (this != &derived) {");
			this->~Derived();             
			new (this) Derived(derived);
		}
		return (*this);
	}

	virtual ~Derived() {
		fprintf(stderr, "[%td] %s\n", __LINE__, __FUNCTION__);
	}
};

int main(int argc, char* argv[]) {
	char buffer[1024];
	double value = 123.456;
	string text = "abcdef";
	Derived derived = Derived(buffer, value, text);
	//Derived another = derived;
	//another = derived;

	return 0;
}
