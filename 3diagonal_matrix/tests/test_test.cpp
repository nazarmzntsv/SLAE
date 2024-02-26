//
// Created by lonertutu on 01.03.23.
//
#include "../src/Matrixes/tridiagonal_matrix.hpp"
#include "../src/SLAE_Solvers/run_solver.hpp"
#include "gtest/gtest.h"

//TEST(A, B) {
//    std::cout << "test";
//}
//ASSERT_EQ(x, y) //проверка на сравнение двух величин
// _NE, _LT - less than, _LE, _GT, _GE - greater than or equal

TEST(Matrix, Create_zero_matrix)
{
    //Arrange
    int size = 10;
    //ACT
    SLAE::Tri_matrix::Tridiagonal_matrix Matrix_of_zeroes = SLAE::Tri_matrix::Tridiagonal_matrix::zero_field(size);

    // ASSERT
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < 3; j++) {
            ASSERT_EQ(Matrix_of_zeroes(i, j), 0.0);
        }
    }
}

//TEST(Matrix, first_solve)
//{
    //SLAE::Tri_matrix::Tridiagonal_matrix Matrix_example = SLAE::Tri_matrix::Tridiagonal_matrix::zero_field(3);

    //Matrix_example(0, 0) = 1.0;
    //Matrix_example(1, 0) = 3.0;
    //Matrix_example(0, 1) = 2.0;
    //Matrix_example(1, 1) = 5.0;
    //Matrix_example(0,2) = 3.0;
    //Matrix_example(2, 0) = 1.0;
    //Matrix_example(2, 1) = 3.0;
    //Matrix_example(1, 2) = 7.0;
    //Matrix_example(2, 2) = 4.0;

    //std::vector<double> free_coef(3);
    //free_coef[0] = 3;
    //free_coef[1] = 0;
    //free_coef[2] = 1;

    //std::vector<double> solution;
    //solution = SLAE::Solver::solver_method_run(Matrix_example, free_coef);

    //ASSERT_NEAR(solution[0], -4, 1e-15);
    //ASSERT_NEAR(solution[0], -13, 1e-15);
    //ASSERT_NEAR(solution[0], 11, 1e-15);
//}