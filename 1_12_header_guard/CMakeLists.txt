cmake_minimum_required(VERSION 3.0)

project(header_guard_example)
set(CMAKE_CXX_COMPILER g++)
set(SOURCES src/main.cpp src/add_one.cpp src/print_sth.cpp )
#set(CMAKE_BUILD_TYPE Release)
message("build type: " ${CMAKE_BUILD_TYPE})
add_executable(${PROJECT_NAME} ${SOURCES})
