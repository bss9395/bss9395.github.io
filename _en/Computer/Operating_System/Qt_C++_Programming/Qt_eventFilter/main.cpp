#include <QApplication>
#include "Label.h"

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);

    Main window;
    window.show();

    return application.exec();
}
