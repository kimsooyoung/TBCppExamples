cmake_minimum_required(VERSION 3.0.0)

project(boost_accumulators)
find_package(Boost REQUIRED)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER g++)
message("build type: " ${CMAKE_BUILD_TYPE})

add_executable(main src/main.cpp)
