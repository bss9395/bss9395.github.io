CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(plugin_battery)
TEMPLATE    = lib

HEADERS     = Plugin_Battery.h
RESOURCES   = images.qrc
LIBS        += -L. 

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(Widget_Battery.pri)

DISTFILES += \
    ReadMe.md
