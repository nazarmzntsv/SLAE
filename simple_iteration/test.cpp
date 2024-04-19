#include <iostream>
#include "Jacobi.hpp"
#include "Simple.hpp"
//#include "../dense_and_csr/dense.hpp"

int main() {
    dense_matrix<double> B = {3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 10}};
    CSR<double> A(B);
    std::vector<double> b = {1, 2, 3};
    // std::vector<double> x = jacobi(A, b, {0, 0, 0}, 0.001, 100);
    // for (int i = 0; i < 3; i++) {
    //     std::cout << x[i] << " ";
    // }
    // std::cout << std::endl;
    std::vector<double> x = simple(A, b, {0,0,0}, 0.001, 100, 0.12657);
    for (int i = 0; i < 3; i++) {
       std::cout << x[i] << " ";
    }
    std::cout << std::endl;
}