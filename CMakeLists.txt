cmake_minimum_required(VERSION 3.13)
project(dice_coeff)

set(CMAKE_CXX_STANDARD 11)

add_library(dice_coeff SHARED dice.cpp dice.h)
#uncomment the line below to generate the test executable
#add_executable(test test.cpp dice.cpp dice.h)