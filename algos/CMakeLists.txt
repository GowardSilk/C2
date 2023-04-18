cmake_minimum_required(VERSION 3.25)
project(C2_ALGOS C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/algos_out)

add_executable(
        C2_ALGOS
        Reactor1.c)