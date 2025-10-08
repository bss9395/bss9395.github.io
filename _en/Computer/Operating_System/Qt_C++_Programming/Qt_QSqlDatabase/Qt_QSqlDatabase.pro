### Qt_QSqlDatabase
### Author: bss9395
### Update: 2025/10/08T18:35:00+08@China-GuangDong-ZhanJiang+08
### Keepin: bss9395@yeah.net


QT       += core gui widgets sql
CONFIG += c++17
msvc {
    QMAKE_CXXFLAGS += /std:c++17
}
g++ {
    QMAKE_CXXFLAGS += -std=c++17
}

HEADERS += \
    Viewer.h

SOURCES += \
    Qt_QSqlDatabase.cpp
