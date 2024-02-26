#include "tridiagonal_matrix.hpp"

namespace SLAE::Tri_matrix{
    
double &Tridiagonal_matrix::operator()(int i, int j) {
        return matrix[i*3 + j];
        }

Tridiagonal_matrix Tridiagonal_matrix::zero_field(int size) {
    
    Tridiagonal_matrix zero_matrix(size);
    zero_matrix.matrix = std::vector<double>(3 * size, 0.0);
    return zero_matrix;
}
}