cmake_minimum_required(VERSION 3.25)
project(C2_TEST C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/test_case_out)
set(ACTIVE_EXEC Terminal2.c) #SPECIFY EXECUTABLE

add_executable(
        C2_TEST
        ${ACTIVE_EXEC})