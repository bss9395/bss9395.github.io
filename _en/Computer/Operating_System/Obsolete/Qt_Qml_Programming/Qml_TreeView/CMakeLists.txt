# 2025-07-14T22:57:00+08@China-ShangHai+08

cmake_minimum_required(VERSION 3.16)

project(Qml_TreeView VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(Qml_TreeView
    main.cpp
)

qt_add_qml_module(Qml_TreeView
    URI untitled
    VERSION 1.0
    QML_FILES
        Main.qml
)

target_link_libraries(Qml_TreeView
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS Qml_TreeView
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
