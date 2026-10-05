
#include <QApplication>
#include "Widget1.h"
#include "Widget2.h"

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);
    Widget widget;
    widget.show();
    return application.exec();
}
