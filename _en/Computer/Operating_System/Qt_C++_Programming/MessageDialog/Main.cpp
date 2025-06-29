#include <QApplication>
#include "MessageDialog.h"
#include <QMainWindow>

int main(int argc, char *argv[]) {
	QApplication application(argc, argv);

    // MessageDialog::_Test_MessageDialog();
	// MessageDialog::_Test_InformationDialog();
	// MessageDialog::_Test_OptionCheckDialog();
	// MessageDialog::_Test_OptionRadioDialog();

    QMainWindow mainWindow;
    mainWindow.show();
    MessageDialog::_Test_MessageDialog(&mainWindow);

	return application.exec();
}
