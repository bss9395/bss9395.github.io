#include <QApplication>
#include "QRCodeEncode.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QRCodeEncode widget;
    widget.show();

    return a.exec();
}
