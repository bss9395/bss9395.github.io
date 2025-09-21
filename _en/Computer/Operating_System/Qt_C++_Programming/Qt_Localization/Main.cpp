
#include <QTimer>
#include <QApplication>
#include "WindowMain.h"

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);

    WindowMain windowMain;
    windowMain.show();

    QTimer::singleShot(3000, &windowMain, []() -> void {
        Localization* localization = Localization::_Instance();
        localization->_Update_Localization(localization->_locale_en_US);
    });

    return application.exec();
}
