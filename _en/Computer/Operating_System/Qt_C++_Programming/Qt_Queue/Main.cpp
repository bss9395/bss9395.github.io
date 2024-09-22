/* Main.cpp
Author: bss9395
Update: 2024-09-18T18:31:00+08@China-Beijing+08
*/

#include <QApplication>
#include <QQueue>
#include <QDebug>
#include <iostream>
#include <queue>
#include <string>
#include "QueueNonBlocking.h"
#include "QueueBlocking.h"

void _std_queue() {
	std::queue<std::string> queue;
	queue.push("1");
	queue.push("2");
	queue.push("3");

	while (queue.empty() == false) {
		std::string element = queue.front();
		queue.pop();
		std::cout << "element = " << element << std::endl;
	}
}

void _Qt_QQueue() {
	QQueue<QString> queue;
	queue.push_back("1");
	queue.push_back("2");
	queue.push_back("3");

	while (queue.empty() == false) {
		QString element = queue.takeFirst();
		qDebug().noquote() << QString("element = %1").arg(element);
	}
}

int main(int argc, char *argv[]) {
	QApplication application(argc, argv);

	// _std_queue();
	// _Qt_QQueue();

    // _Test_QueueNonBlocking();
    _Test_QueueBlocking();

	return application.exec();
}
