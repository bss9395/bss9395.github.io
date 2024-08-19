QT       += core gui network widgets

CONFIG += c++17

SOURCES += \
    Main.cpp

HEADERS += \
    Qt_TCP_Client.h \
    Qt_TCP_Server.h

FORMS += \
    Qt_TCP_Client.ui \
    Qt_TCP_Server.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
