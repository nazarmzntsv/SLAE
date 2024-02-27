#include "../src/Matrixes/tridiagonal_matrix.hpp"
#include <gtest/gtest.h>

TEST(Matrix, Create_zero_matrix)
{
    int size = 10;
    SLAE::Tri_matrix::Tridiagonal_matrix Matrix_of_zeroes(size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 3; j++) {
            ASSERT_EQ(Matrix_of_zeroes(i, j), 0.0);
        }
    }
}