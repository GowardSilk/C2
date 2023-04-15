#GENERAL INFO
cmake_minimum_required(VERSION 3.25)
project(C2 C)

#VARIABLES
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)
set(HEADER_DIR ${CMAKE_CURRENT_BINARY_DIR}/../headers)
set(HEADER_FILES
        ${HEADER_DIR}/DeepMain.h
        ${HEADER_DIR}/Terminal_prcl.h
        ${HEADER_DIR}/Reactor_prcl.h
        ${HEADER_DIR}/ReadIO.h
        ${HEADER_DIR}/WriteIO.h
        ${HEADER_DIR}/Generator.h
        ${HEADER_DIR}/Image.h
        )

#SUBDIRECTORY PROJECTS
add_subdirectory(test_cases)
add_subdirectory(algos)

#LIBRARY
add_library(
        HEADER STATIC
        ${HEADER_FILES}
)
#target_link_libraries(${HEADER} -lpthread)
set_target_properties(HEADER PROPERTIES LINKER_LANGUAGE C)

#EXECUTION
add_executable(
        C2 main.c
        ${HEADER_FILES}
)

target_include_directories(C2 PRIVATE ${HEADER_DIR})
target_include_directories(C2_TEST PRIVATE  ${HEADER_DIR})
target_include_directories(C2_ALGOS PRIVATE  ${HEADER_DIR})
