cmake_minimum_required(VERSION 3.16)
project(thtest)

set(CMAKE_CXX_STANDARD 17)

set(RAYLIB_ROOT "C:/raylib/w64devkit" CACHE PATH "raylib w64devkit install path")

find_path(RAYLIB_INCLUDE_DIR raylib.h
        PATHS "${RAYLIB_ROOT}/include"
        REQUIRED)

find_library(RAYLIB_LIBRARY raylib
        PATHS "${RAYLIB_ROOT}/lib"
        REQUIRED)

add_executable(thtest src/main.cpp
        include/supertext.h)
target_include_directories(thtest PRIVATE "${RAYLIB_INCLUDE_DIR}" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(thtest PRIVATE "${RAYLIB_LIBRARY}" opengl32 gdi32 winmm)
target_link_options(thtest PRIVATE $<$<CONFIG:Release>:-mwindows>)

add_custom_command(TARGET thtest POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/resources"
        "$<TARGET_FILE_DIR:thtest>/resources")
