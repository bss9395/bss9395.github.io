
#include "Qt6_QChart.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);

    Qt6_QChart widget;
    widget.show();

    return application.exec();
}
