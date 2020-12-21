cmake_minimum_required(VERSION 3.0)

project(member_approach_with_reference_and_pointer)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER g++)
set(SOURCES src/main.cpp )
#set(CMAKE_BUILD_TYPE Release)
message("build type: " ${CMAKE_BUILD_TYPE})
add_executable(${PROJECT_NAME} ${SOURCES})