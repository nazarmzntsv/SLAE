cmake_minimum_required(VERSION 3.20)
project(tridiagonal)

add_subdirectory(src)

if (WITH_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif ()