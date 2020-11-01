cmake_minimum_required(VERSION 3.0)

project(first_functions)
set(CMAKE_CXX_COMPILER g++)
set(SOURCES src/first_functions.cpp )
#set(CMAKE_BUILD_TYPE Release)
message("build type: " ${CMAKE_BUILD_TYPE})
add_executable(${PROJECT_NAME} ${SOURCES})

