cmake_minimum_required(VERSION "3.19")

project(main)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(main "main.cpp")
target_link_libraries(main ${CURSES_LIBRARIES})
