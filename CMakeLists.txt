cmake_minimum_required(VERSION 3.5)

project(QuickTranslate VERSION 0.0.1)

include_directories(
    "${CMAKE_SOURCE_DIR}/src/app"
    "${CMAKE_SOURCE_DIR}/src/libc-googletrans"
    "${CMAKE_SOURCE_DIR}/tests"
    )

link_directories(
    "${CMAKE_SOURCE_DIR}/src/app"
    "${CMAKE_SOURCE_DIR}/src/libc-googletrans"
)

add_subdirectory(src/app)
add_subdirectory(src/libc-googletrans)
add_subdirectory(lib/googletest)
#add_subdirectory(tests)

#target_link_libraries(${APP_EXE} ${PYTHON_LIBRARIES})
