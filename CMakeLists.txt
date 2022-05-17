cmake_minimum_required(VERSION 3.22)
project(Lab2_2)

set(CMAKE_CXX_STANDARD 17)

find_library(LIB_TO_INCLUDE structs /home/kristofer/2_sem_prog/Lab2_2/structs_lib/cmake-build-debug)
find_path (LIB_INCLUDES structs_lib.h /home/kristofer/2_sem_prog/Lab2_2/structs_lib/)
include_directories(${LIB_INCLUDES})

add_executable(Lab2_2 Lab2_2.cpp print_func.cpp print_func.h definitions.h draw_func.h draw_func.cpp table_func.h
        table_func.cpp classes.cpp classes.h)

target_link_libraries(Lab2_2 ${LIB_TO_INCLUDE})