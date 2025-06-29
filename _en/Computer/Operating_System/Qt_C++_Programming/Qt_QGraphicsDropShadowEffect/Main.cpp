
#include <QApplication>
#include "Dialog.h"

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);

    Dialog dialog(nullptr);
    dialog.show();

    return application.exec();
}
