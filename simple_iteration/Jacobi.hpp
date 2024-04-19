#pragma once
#include "../dense_and_csr/CSR.hpp"
#include "../dense_and_csr/vector_operation.hpp"
#include <cmath>

template<typename T>
std::vector<T> jacobi(const CSR<T>& A, const std::vector<T>& b, const std::vector<T>& x_0, T tolerance, int N_max) {
    T e = tolerance;
    auto x = x_0;
    for (int n = 0; !(e < tolerance) && (n < N_max); n++) {
        auto new_x = x;
        for (int i = 0; i < A.get_m(); i++) {
            T s = 0;
            for (int j = 0; j < A.get_m(); j++) {
                if (i != j) {
                    s+=A(i, j)*x[j];
                }
                new_x[i] = s;
            }
        }
        new_x = b - new_x;
        for (int i = 0; i < A.get_m(); i++) {
            new_x[i] = new_x[i]/A(i, i);
        }
        e = std::sqrt((x - new_x)*(x - new_x));
        x = new_x;
    }
    return x;
}
