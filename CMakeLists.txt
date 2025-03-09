cmake_minimum_required(VERSION 3.5.0)
project(darkwin)

find_package(
    Qt6
    COMPONENTS
        Widgets
    REQUIRED
)

set(CMAKE_AUTOMOC ON)
set(MOCUIC_DIR ${CMAKE_CURRENT_BINARY_DIR}/.mocuic)

add_executable(
    darkwin
        src/darkwin.cpp
)

set_target_properties(
    darkwin
    PROPERTIES
        AUTOGEN_BUILD_DIR
            ${MOCUIC_DIR}
)

target_link_libraries(
    darkwin
        Qt6::Widgets
)

install(
    TARGETS
        darkwin
    DESTINATION
        bin
)
