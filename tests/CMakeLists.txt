cmake_minimum_required(VERSION 3.5)

project(AppTests)

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

set(HEADERS
    tst_translatorstests.h
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/libc-googletrans/translator.h"
    #"${CMAKE_CURRENT_SOURCE_DIR}/../src/app/googletranslator.h"
)
set(SOURCES
    main.cpp
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/libc-googletrans/translator.cpp"
    #"${CMAKE_CURRENT_SOURCE_DIR}/../src/app/googletranslator.cpp"
)
set(EXE_NAME app_tests)

add_executable(${EXE_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(
    ${EXE_NAME} PRIVATE
    ${PYTHON_LIBRARIES}
    #libgoogletrans
    gtest gtest_main
    )

#target_link_libraries(${EXE_NAME} libgoogletrans)
