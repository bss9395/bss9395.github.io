/* Main.cpp
Author: BSS9395
Update: 2022-07-27T12:16:00+08@China-Shanghai+08
Design: Multi_Language
Encode: UTF-8
System: Qt 5.14.2
*/

#include "Common.h"

int main(int argc, char *argv[]) {
    System::Logging(__FUNCTION__);
    QApplication application(argc, argv);

//    QTranslator *translator = new QTranslator();
//    translator->load("E:/Downloads/QtProjects/Multi_Language_en.qm");
//    application.installTranslator(translator);

    Multi_Language multi_language;
    multi_language.show();

    return application.exec();
    return 0;
}
