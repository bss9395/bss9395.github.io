/* Television.cpp
Design: Singleton
Author: BSS9395
Update: 2019-08-17T15:30
*/

#ifndef Television_h
#define Television_h

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Television {
	enum Power {
		Off = 0,
		Suspend = 1,
		On = 2
	};
	string POWER[3] = { "Power Off", "Suspend", "Power On" };

	enum Volumn {
		minVolumn = 0,
		maxVolumn = 100
	};

	enum Channel {
		minChannel = 1,
		maxChannel = 256
	};

	friend class Controller;

private:
	Television() {
		cerr << "Television();" << endl;
		_power = Off;
		_volumn = minVolumn;
		_channel = minChannel;
	}

	~Television() {
		cerr << "~Television();" << endl;
	}

	Television(const Television &) {
		cerr << "Television(const Television &);" << endl;
	}

	Television &operator=(const Television &) {
		cerr << "Television &operator=(const Television &);" << endl;
	}

public:
	static Television &getTelevision() {
		static Television television;
		return television;
	}

public:
	void PowerOn() {
		_power = On;
	}

	void PowerOff() {
		_power = Off;
	}

	void VolumnUp() {
		if (_volumn < maxVolumn) {
			_volumn = Volumn(_volumn + 1);
		}
	}

	void VolumnDown() {
		if (minVolumn < _volumn) {
			_volumn = Volumn(_volumn - 1);
		}
	}

	void ChannelUp() {
		_channel = Channel((_channel - minChannel + 1 + maxChannel) % maxChannel + minChannel);
	}

	void ChannelDown() {
		_channel = Channel((_channel - minChannel - 1 + maxChannel) % maxChannel + minChannel);
	}

	void showStatus(ostream &os) {
		stringstream ss;

		ss << "Power Status: ";
		ss << POWER[_power];
		ss << endl;

		ss << "Current Volumn: ";
		ss << _volumn;
		ss << endl;

		ss << "Current Channel: ";
		ss << _channel;
		ss << endl;

		os << ss.str() << endl;
	}

protected:
	Power _power;
	Volumn _volumn;
	Channel _channel;
};

#endif // Television_h
