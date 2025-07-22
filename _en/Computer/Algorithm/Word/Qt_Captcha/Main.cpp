#include <QApplication>
#include "Captcha.h"


int main(int argc, char *argv[]) {
    QApplication application(argc, argv);

    Captcha captcha;
    captcha.show();

    return application.exec();
}
