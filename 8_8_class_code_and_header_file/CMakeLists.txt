cmake_minimum_required(VERSION 3.0)

project(class_code_and_header_file)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER g++)
set(SOURCES src/main.cpp src/Calc.cpp src/Date.cpp )
#set(CMAKE_BUILD_TYPE Release)
message("build type: " ${CMAKE_BUILD_TYPE})
add_executable(${PROJECT_NAME} ${SOURCES})