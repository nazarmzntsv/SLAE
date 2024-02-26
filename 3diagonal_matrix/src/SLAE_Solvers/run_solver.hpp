#pragma once

#include "../Matrixes/tridiagonal_matrix.hpp"

namespace SLAE::Solver{

std::vector<double> solver_method_run(const Tri_matrix::Tridiagonal_matrix &matrix, const std::vector<double> &free_coef);
}

