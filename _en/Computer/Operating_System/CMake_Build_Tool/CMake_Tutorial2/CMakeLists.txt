cmake_minimum_required(VERSION 3.10)
project(Tutorial VERSION 1.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)
configure_file(TutorialConfig.h.in TutorialConfig.h)
add_executable(Tutorial Tutorial.cxx)
target_include_directories(Tutorial PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/MathFunctions"
                          )
add_subdirectory(MathFunctions)
target_link_libraries(Tutorial PUBLIC MathFunctions)
