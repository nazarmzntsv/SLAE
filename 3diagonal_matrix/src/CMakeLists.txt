cmake_minimum_required(VERSION 3.17)

project(SLAE_lib)

file(GLOB_RECURSE FILES *.cpp *.hpp)

add_library(SLAE_lib ${FILES} ../tests/test_test.cpp SLAE_Solvers/Jacobi.hpp Tools/Norm.hpp SLAE_Solvers/Simple_iteration.hpp Tools/Overloads.hpp SLAE_Solvers/Gauss_Seidel.hpp SLAE_Solvers/SOR.hpp Tools/Chebyshev_polynomial.hpp SLAE_Solvers/Gradient_descent.hpp SLAE_Solvers/Conjugate_gradients.hpp SLAE_Solvers/BiCG.hpp SLAE_Solvers/GMRES.hpp Matrixes/Triplet.hpp Matrixes/Dense.cpp)