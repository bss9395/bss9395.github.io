QT       += core gui widgets quick

CONFIG += c++11 enable_encoder_qr_code

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp

HEADERS += \
    QRCodeEncode.h

FORMS +=

include(QZXing_src/QZXing-components.pri)

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/release/ -lQZXing3
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/release/ -lQZXingd3
#INCLUDEPATH += $$PWD/src
#DEPENDPATH += $$PWD/src
#DEFINES += ENABLE_ENCODER_GENERIC
