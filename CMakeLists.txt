cmake_minimum_required(VERSION 3.16)
project(myproject)

set(CMAKE_CXX_STANDARD 17)

find_package(raylib REQUIRED)

add_executable(myproject src/main.cpp)
target_link_libraries(myproject raylib)