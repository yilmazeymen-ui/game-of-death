cmake_minimum_required(VERSION 3.10)

project(program VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

find_package(SDL3 REQUIRED)

add_executable("program" "src/main.cpp")

target_link_libraries("program" PRIVATE SDL3::SDL3)
