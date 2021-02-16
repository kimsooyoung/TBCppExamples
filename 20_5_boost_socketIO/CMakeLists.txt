cmake_minimum_required(VERSION 3.0.0)
project(boost_socketIO VERSION 0.1.0)

include(CTest)
enable_testing()

# For Client
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

find_package(Boost 1.65.1 REQUIRED system )

add_executable(server server.cpp)
target_link_libraries(server Boost::system)

add_executable(client client.cpp)
target_link_libraries(client Boost::system)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
