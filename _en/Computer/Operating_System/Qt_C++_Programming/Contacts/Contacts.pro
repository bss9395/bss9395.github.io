
# 本项目使用Visual Studio 2017运行会报错
QT       += core gui sql multimedia widgets

CONFIG += c++17

SOURCES += \
    Main.cpp

HEADERS += \
    Common.h \
    Contacts.h \
    Custom.h \
    Settings.h \
    System.h

FORMS += \
    Contacts.ui

RESOURCES += \
    images.qrc


### CMAKE配置示例
#cmake_minimum_required(VERSION 3.10)
#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(CMAKE_AUTOUIC ON)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)
#
#project(Contacts VERSION 0.1 LANGUAGES CXX)
#
#set(PROJECT_SOURCES
#        main.cpp
#        Common.h
#        Contacts.h
#        Settings.h
#        System.h
#        Contacts.ui
#        images.qrc
#)
#
#add_executable(Contacts
#    ${PROJECT_SOURCES}
#)
#
## 需要手动设置环境变量D:\Qt\Qt5.12.11\5.12.11\msvc2017_64\bin
#set(Qt5_DIR "D:/Qt/Qt5.12.11/5.12.11/msvc2017_64/lib/cmake/Qt5")
#find_package(Qt5 COMPONENTS Core Widgets Sql Gui Multimedia REQUIRED)
#target_link_libraries(Contacts PRIVATE
#    Qt5::Widgets
#    Qt5::Sql
#    Qt5::Multimedia
#)
