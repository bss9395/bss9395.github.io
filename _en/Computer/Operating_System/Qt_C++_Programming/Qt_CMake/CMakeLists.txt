cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

project(Qt_CMake VERSION 0.1 LANGUAGES CXX)

# 可能需要设置环境变量，D:\Qt\Qt5.12.11\5.12.11\msvc2017_64\bin
# 可能需要设置Qt5目录，set(Qt5_DIR "D:/Qt/Qt5.12.11/5.12.11/msvc2017_64/lib/cmake/Qt5")
find_package(Qt5 COMPONENTS
    Widgets
    Sql
    Multimedia
    Quick
REQUIRED)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    qml.qrc
)

add_executable(Qt_CMake
    ${PROJECT_SOURCES}
)

target_link_libraries(Qt_CMake PRIVATE
    Qt5::Widgets
    Qt5::Sql
    Qt5::Multimedia
    Qt5::Quick
)
