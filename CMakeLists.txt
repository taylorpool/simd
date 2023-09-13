cmake_minimum_required(VERSION 3.25)

project(SIMD
    VERSION 0.1.0
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(main
    src/main.cpp
)
target_compile_options(main
    PUBLIC
    -mavx2
)