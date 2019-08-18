/* Controller.cpp
Design: Singleton
Author: BSS9395
Update: 2019-08-17T15:30
*/

#ifndef Controller_h
#define Controller_h

#include "Television.h"

class Controller {
private:
	Controller() {
		cerr << "Controller();" << endl;
		_television = nullptr;
	}

	Controller(Television *television) {
		cerr << "Controller(Television &);" << endl;
		_television = television;
	}

	~Controller() {
		cerr << "~Controller();" << endl;
	}

	Controller(const Controller &) {
		cerr << "Controller(const Controller &);" << endl;
	}

	Controller &operator=(const Controller &) {
		cerr << "Controller &operator=(const Controller &);" << endl;
	}

public:
	static Controller &getController(Television *television = nullptr) {
		static Controller controller(television);
		return controller;
	}

	void setTelevision(Television *television) {
		_television = television;
	}

public:
	void PowerOn() {
		if (_checkTelevision()) {
			_television->PowerOn();
		}
	}

	void PowerOff() {
		if (_checkTelevision()) {
			_television->PowerOff();
		}
	}

	void VolumnUp() {
		if (_checkTelevision()) {
			_television->VolumnUp();
		}
	}

	void VolumnDown() {
		if (_checkTelevision()) {
			_television->VolumnDown();
		}
	}

	void ChannelUp() {
		if (_checkTelevision()) {
			_television->ChannelUp();
		}
	}

	void ChannelDown() {
		if (_checkTelevision()) {
			_television->ChannelDown();
		}
	}

	void showTelevisionStatus(ostream &os) {
		if (_checkTelevision()) {
			_television->showStatus(os);
		}
		else {
			stringstream ss;

			ss << "Unconnected to Television.";
			ss << endl;

			os << ss.str();
		}
	}

protected:
	bool _checkTelevision() {
		if (_television) {
			return true;
		}
		return false;
	}
protected:
	Television *_television;
};

#endif // Controller_h
