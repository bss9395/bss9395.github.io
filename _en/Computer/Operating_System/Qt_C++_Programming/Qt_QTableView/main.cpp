#include <QApplication>
#include "MainWidget.h"

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);

    MainWidget mainWidget;
    mainWidget.show();

    return application.exec();
}
