cmake_minimum_required(VERSION 3.17)

project(SLAE_lib)

file(GLOB_RECURSE FILES *.cpp *.hpp)

add_library(SLAE_lib ${FILES} ../tests/test_test.cpp)