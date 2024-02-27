#pragma once
#include <vector>

namespace SLAE::Tri_matrix {

class Tridiagonal_matrix {

    private:
        int size_matrix = 0;
        std::vector<double> matrix;

    public:
        Tridiagonal_matrix(int size) : size_matrix(size), matrix(std::vector<double>(3 * size, 0.0)) {};
         
        int size() const {
            return size_matrix;
        }

        double &operator()(int i, int j);
};

std::vector<double> solver_method_run(const Tri_matrix::Tridiagonal_matrix &matrix, const std::vector<double> &free_coef);

}