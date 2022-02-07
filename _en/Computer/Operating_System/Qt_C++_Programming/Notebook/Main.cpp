/* Main.cpp
Author: BSS9395
Update: 2022-02-08T00:24:00+08@China-Guangdong-Zhanjiang+08
Design: Notebook
Encode: UTF-8
System: Qt 5.14.2
*/

#include "Common.h"

int main(int argc, char *argv[]) {
    System::Logging(__FUNCTION__);

//    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
//    QTextCodec::setCodecForLocale(codec);

    char *locale = (char *)setlocale(LC_ALL, ".936");   // ".936" for windows, "zh_CN.GBK" for linux.
    if (locale == NULL) {
        fprintf(stderr, "[%td] %s""\n", (iptr)__LINE__, "invalid locale");
        fflush(stderr);
    }

    ////////////////////////////////////

    QApplication application(argc, argv);
    Notebook notebook;
    notebook.show();

    return application.exec();
}
