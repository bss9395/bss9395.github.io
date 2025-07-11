TEMPLATE = app
TARGET = Qt_qmake
CONFIG += c++11 console
VERSION = 1.2.3
DEFINES += VERSION=\\\"$$VERSION\\\"
DEFINES += _version_major=1
DEFINES += _version_minor=2
DEFINES += _version_patch=3
DEFINES += _feature_x

SOURCES += \
    Main.cpp
