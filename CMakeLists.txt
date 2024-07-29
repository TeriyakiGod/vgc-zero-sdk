cmake_minimum_required(VERSION 3.15)
project(vgc-zero-sdk)

find_package(raylib REQUIRED)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SOURCES "src/main.cpp" "src/engine/*.cpp" "src/game/*.cpp")
include_directories("src/engine" "src/game" "include")

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} raylib m drm EGL GL gbm)