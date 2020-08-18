cmake_minimum_required(VERSION 3.5)

project(LibC-GoogleTranslate VERSION 0.0.1)

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

set(LIB_NAME libgoogletrans)

add_library(${LIB_NAME} STATIC translator.cpp translator.h)

set_target_properties(
    ${LIB_NAME} PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)

target_link_libraries(${LIB_NAME} ${PYTHON_LIBRARIES})

