#pragma once
#include "../dense_and_csr/CSR.hpp"
#include "../dense_and_csr/vector_operation.hpp"
#include <cmath>

template<typename T>
std::vector<T> gauss_seidel(const CSR<T>& A, const std::vector<T>& b, const std::vector<T>& x_0, T tolerance, int N_max) {
    T e = tolerance + 1;
    auto x = x_0;
    for (int n = 0; !(e < tolerance) && (n < N_max); n++) {
        auto new_x = x;
        for (int i = 0; i < A.get_m(); i++) {
            T s = 0;
            for (int j = i + 1; j < A.get_n(); j++) {
            s+= A(i, j) * x[j]
            }
            for (int j = 0; j < i; j++) {
                s+= A(i, j) * x[j];
            }
            x[i] = (b[i] - s)/A(i, i);
        }
        e = std::sqrt((x - new_x)*(x - new_x));
        x = new_x;
    }
    return x;
}
