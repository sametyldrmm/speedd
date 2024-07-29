cmake_minimum_required(VERSION 3.22)

project(program VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_compile_options(-Wall )

file(GLOB SOURCES "src/*.cpp")

add_executable(program ${SOURCES})