
#pragma once
#include "../dense_and_csr/CSR.hpp"
#include "../dense_and_csr/vector_operation.hpp"
#include <cmath>

template<typename T>
std::vector<T> simple(const CSR<T>& A, const std::vector<T>& b, const std::vector<T>& x_0, T tolerance, int N_max, T tau) {
    T e = tolerance + 1;
    auto x = x_0;
    for (int n = 0; !(e < tolerance) && (n < N_max); n++) {
    for (int n = 0; n < N_max; n++) {
        auto new_x = x;
        new_x = new_x - tau*(A*new_x - b);
        e = std::sqrt((x - new_x)*(x - new_x));
        x = new_x;
    }
    }
    return x;
}
