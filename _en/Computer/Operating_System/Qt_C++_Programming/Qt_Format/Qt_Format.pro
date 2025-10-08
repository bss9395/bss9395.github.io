### Qt_Format
### Author: bss9395
### Update: 2025/10/07T18:14:00+08@China-GuangDong-ZhanJiang+08
### Keepin: bss9395@yeah.net

QT += core gui widgets

CONFIG += c++17
msvc {
    QMAKE_CXXFLAGS += /std:c++17
}
g++ {
    QMAKE_CXXFLAGS += -std=c++17
}

SOURCES += \
    Qt_Format.cpp
