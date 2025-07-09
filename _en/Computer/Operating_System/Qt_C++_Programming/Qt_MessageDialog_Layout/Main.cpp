#include <QApplication>
#include <QMainWindow>
#include "MessageDialog.h"

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);

    QMainWindow mainWindow;
    mainWindow.show();
    MessageDialog::_Test_MessageDialog(&mainWindow);
    // MessageDialog::_Test_InformationDialog(&mainWindow);
    // MessageDialog::_Test_OptionCheckDialog(&mainWindow);
    // MessageDialog::_Test_OptionRadioDialog(&mainWindow);

    return application.exec();
}
