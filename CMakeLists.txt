cmake_minimum_required(VERSION 3.10)
project(CrowApp)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_TOOLCHAIN_FILE "C:/Users/LENOVO/vcpkg/scripts/buildsystems/vcpkg.cmake")

add_definitions(-D_WIN32_WINNT=0x0A00)

add_executable(
    approot
    server.cpp
)