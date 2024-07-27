cmake_minimum_required(VERSION 3.15)
project(vgc-zero-sdk)

find_package(raylib REQUIRED)

set(CMAKE_CXX_STANDARD 11)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} raylib m drm EGL GL gbm)
