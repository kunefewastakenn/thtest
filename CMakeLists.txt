cmake_minimum_required(VERSION 3.20)

project(thtest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(thtest
    src/main.cpp
        include/supertext.h
)

set(RAYLIB_ROOT "C:/raylib/w64devkit" CACHE PATH "Path to the raylib w64devkit installation")
set(RAYLIB_LIBRARY "${RAYLIB_ROOT}/lib/libraylib.a" CACHE FILEPATH "Path to libraylib.a")
set(RAYLIB_INCLUDE_DIR "${RAYLIB_ROOT}/include" CACHE PATH "Path to raylib headers")

add_library(raylib STATIC IMPORTED
        include/supertext.h)
set_target_properties(raylib PROPERTIES
    IMPORTED_LOCATION "${RAYLIB_LIBRARY}"
    INTERFACE_INCLUDE_DIRECTORIES "${RAYLIB_INCLUDE_DIR}"
)

target_link_libraries(thtest PRIVATE raylib opengl32 gdi32 winmm)
