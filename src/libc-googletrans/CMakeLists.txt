cmake_minimum_required(VERSION 3.5)

project(libc-googletrans)

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

add_library(googletranslib STATIC
                translator.cpp
)
target_link_libraries(googletranslib ${PYTHON_LIBRARIES})

set(APP_EXE test_lib)

add_executable(${APP_EXE} "main.cpp")

target_link_libraries(${APP_EXE} googletranslib)

set_target_properties(
    test_lib PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)
