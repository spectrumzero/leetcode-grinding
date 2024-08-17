cmake_minimum_required(VERSION 3.25.0)
project(leetcode-grinding VERSION 1.0)

# specify the C standard
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)

# the directories where head files in
include_directories("./utils/")

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

add_executable(leetcode-grinding "./unsolved/0217.c")
