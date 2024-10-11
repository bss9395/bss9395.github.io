/* Main.cpp
Author: bss9395
Update: 2024-09-26T01:04:00+08@China-Beijing+08
*/

#include <QApplication>
#include "Transfer.h"

static void _Test_Server_Listening() {
	Transfer* transfer_server_listening = Transfer::_Server_Listening("E:/QtProjects/TransferServer/folder/");

	QThread::sleep(10);
	delete transfer_server_listening, transfer_server_listening = nullptr;
}

static void _Test_Client_PushFile() {
	Transfer *transfer_client_pushfile = Transfer::_Client_PushFile("192.168.194.62", "E:/QtProjects/TransferClient/folder/Main.cpp");
	QObject::connect(transfer_client_pushfile, &Transfer::_Signal_Client_PushFile, [](const QVector<QPair<quint32, QString>>& codes) -> void {
		qDebug().noquote() << "QObject::connect(transfer_client_pushfile, &Transfer::_Signal_Client_PushFile, [](const QVector<QPair<quint32, QString>>& codes) -> void {";
		qDebug().noquote() << "codes = " << codes;
	});

	QThread::sleep(10);
	delete transfer_client_pushfile, transfer_client_pushfile = nullptr;
}

static void _Test_Client_SyncFolder() {
	Transfer *transfer_client_syncfolder = Transfer::_Client_SyncFolder("192.168.194.62", "E:/QtProjects/TransferClient/folder/");
	QObject::connect(transfer_client_syncfolder, &Transfer::_Signal_Client_SyncFolder, [](const QVector<QPair<quint32, QString>>& codes) -> void {
		qDebug().noquote() << "QObject::connect(transfer_client_syncfolder, &Transfer::_Signal_Client_SyncFolder, [](const QVector<QPair<quint32, QString>>& codes) -> void {";
		qDebug().noquote() << "codes = " << codes;
	});

	QThread::sleep(10);
	delete transfer_client_syncfolder, transfer_client_syncfolder = nullptr;
}

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);

	_Test_Server_Listening();
    // _Test_Client_PushFile();
    // _Test_Client_SyncFolder();

    return application.exec();
}
