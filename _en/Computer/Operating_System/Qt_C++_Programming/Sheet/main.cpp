#include "Common.h"

int main(int argc, char *argv[]) {
    Logging(__FUNCTION__);

    QApplication application(argc, argv);
    Sheet sheet;
    sheet.show();
    return application.exec();
}
