cmake_minimum_required(VERSION 3.5)

project(MainApp)

set(APP_EXE main_app)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
#set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}) # set directory for executable

find_package(Qt5 COMPONENTS Core Quick REQUIRED)

set(SOURCES
    googletranslator.cpp
    langslistmodel.cpp
    languageslist.cpp
    main.cpp
    mainpresenter.cpp
    mainview.cpp
    translatorworker.h
)
set(HEADERS
    cursorposprovider.h
    googletranslator.h
    imainview.h
    langslistmodel.h
    languageslist.h
    mainpresenter.h
    mainview.h
    translatorworker.cpp
)

add_executable(${APP_EXE} ${SOURCES} ${HEADERS} "qml.qrc")

set_target_properties(
    ${APP_EXE} PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(
    ${APP_EXE}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../libc-googletrans
)

#target_link_libraries(${APP_EXE} Qt5::Core Qt5::Quick)
target_link_libraries(${APP_EXE} libgoogletrans Qt5::Core Qt5::Quick)
