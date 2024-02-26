cmake_minimum_required(VERSION 3.17)
set(GOOGLETEST_VERSION 1.13.0)

project(SLAE_lib)
enable_testing()
find_package(GTest REQUIRED)
#file(GLOB_RECURSE TEST_SOURCES *_test.cpp)
add_executable(test test_test.cpp Simple_iter_test.cpp CSR_test.cpp Jacobi_test.cpp Gauss_Seidel_test.cpp SOR_test.cpp Chebyshev_test.cpp Gradient_descent_test.cpp Conjugate_grad_test.cpp BiCG_test.cpp GMRES.cpp)
target_include_directories(test PUBLIC ${gtest_SOURCE_DIR} ${gtest_SOURCE_DIR}/include)
include_directories(../../SLAE_lib)
target_link_libraries(test SLAE_lib GTest::gtest GTest::gtest_main)
add_test(NAME test COMMAND test)
#add_executable(test test_test.cpp Simple_iter_test.cpp CSR_test.cpp Jacobi_test.cpp Gauss_Seidel_test.cpp SOR_test.cpp Chebyshev_test.cpp Gradient_descent_test.cpp Conjugate_grad_test.cpp)
#target_include_directories(test PUBLIC ${gtest_SOURCE_DIR} ${gtest_SOURCE_DIR}/include)
#include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
#include_directories(../../SLAE_lib)
#target_link_libraries(test SLAE_lib GTest::gtest GTest::gtest_main)
#add_test(NAME test COMMAND test)
#TODO write globe recurse

#foreach(TEST_FILE IN LISTS TEST_SOURCES)
#    get_filename_component(TEST_FILE_NAME ${TEST_FILE} NAME_WE)
#    set(EXECUTABLE_NAME run_${TEST_FILE_NAME})
#    add_executable(${EXECUTABLE_NAME} ${TEST_FILE})
#    target_link_libraries(
#            ${EXECUTABLE_NAME}
#            SLAE_lib
#            gtest
#            gtest_main
#    )
#    message("TEST_FILE: ${TEST_FILE}")
#    add_test(NAME ${EXECUTABLE_NAME}  COMMAND ${EXECUTABLE_NAME})
#endforeach()