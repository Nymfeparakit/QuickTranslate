cmake_minimum_required(VERSION 3.5)

project(AppTests)

set(HEADERS
    tst_translatorstests.cpp
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/app/googletranslator.h"    
)
set(SOURCES
    #main.cpp
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/app/googletranslator.cpp"    
)
set(EXE_NAME app_tests)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}) # set directory for executable

add_executable(${EXE_NAME} ${SOURCES} ${HEADERS})

# target_include_directories(
#     ${EXE_NAME} PRIVATE
#     "${CMAKE_CURRENT_SOURCE_DIR}/../src/app"
# )

target_link_libraries(
    ${EXE_NAME} PRIVATE
    gtest gtest_main
    )

#target_link_libraries(${EXE_NAME} ${APP_EXE})
target_link_libraries(${APP_EXE} libgoogletrans)
