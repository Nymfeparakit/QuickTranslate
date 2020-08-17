cmake_minimum_required(VERSION 3.5)

project(LibC-GoogleTranslate VERSION 0.0.1)

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

add_library(lib STATIC translator.cpp)

set_target_properties(
    lib PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)

target_link_libraries(lib ${PYTHON_LIBRARIES})

