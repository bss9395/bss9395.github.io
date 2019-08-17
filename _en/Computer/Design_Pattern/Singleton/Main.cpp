/* Main.cpp
Design: Singleton
Author: BSS9395
Update: 2019-08-17T15:30
*/

#include "Television.h"
#include "Controller.h"

int main(int argc, char *argv[]) {
	Television &television = Television::getTelevision();
	Controller &controller = Controller::getController();

	television.showStatus(cout);
	television.PowerOn();
	television.VolumnUp();
	television.VolumnUp();
	television.ChannelDown();
	television.ChannelDown();
	television.showStatus(cout);

	controller.setTelevision(&television);
	controller.VolumnUp();
	controller.VolumnUp();
	controller.ChannelUp();
	controller.ChannelUp();
	controller.PowerOff();
	controller.showTelevisionStatus(cout);

	controller.setTelevision(nullptr);
	controller.showTelevisionStatus(cout);

	Television &television2 = Television::getTelevision();
	Controller &controller2 = Controller::getController();

	cout << endl;
	cout << "The same Television: " << &television << " == " << &television2 << endl;
	cout << "The same Controller: " << &controller << " == " << &controller2 << endl;


	return 0;
}