project(darkwin)
cmake_minimum_required(VERSION 3.5.0)

find_package(
    Qt5
    REQUIRED
        Widgets
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(MOCUIC_DIR ${CMAKE_CURRENT_BINARY_DIR}/.mocuic)
set(DARKWIN_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})

add_executable(
    darkwin
        darkwin.cpp
)

set_target_properties(
    darkwin
    PROPERTIES
        AUTOGEN_BUILD_DIR
            ${MOCUIC_DIR}
        RUNTIME_OUTPUT_DIRECTORY
            ${DARKWIN_BINARY_DIR}
)

target_link_libraries(
    darkwin
        Qt5::Widgets
)

install(
    TARGETS
        darkwin
    DESTINATION
        bin
)
