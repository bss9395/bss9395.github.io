#include <QApplication>
#include "ergb.h"

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);

    ERGB ergb;
    ergb.show();

    return application.exec();
}
