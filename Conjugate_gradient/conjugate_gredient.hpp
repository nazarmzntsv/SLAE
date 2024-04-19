
#pragma once
#include "../dense_and_csr/CSR.hpp"
#include "../dense_and_csr/vector_operation.hpp"
#include <cmath>

template<typename T>
std::vector<T> conjgrad(const CSR<T>& A, const std::vector<T>& b, const std::vector<T>& x_0, T tolerance, int N_max, T tau) {
    T e = tolerance + 1;
    auto x = x_0;
    std::vector<T> r = A*x - b;
    for (int n = 0; !(e < tolerance) && (n < N_max); n++) {
        T tau = (r*r)/(r*(A*r));
        auto new_x = x;
        new_x = new_x - tau*(A*new_x - b);
        e = std::sqrt((x - new_x)*(x - new_x));
        x = new_x;
    }
    return x;
}

template<typename T>
    std::vector<T> Symgauss_seidel(const CSR<T>& A, const std::vector<T>& b, const std::vector<T>& x0, T tolerance, int N_max) {
        std::vector<T> x = x0;
        T e = tolerance + 1;
        auto new_x = x;
        for (int n = 0; !(e <= tolerance) && (n < N_max); n++) {
            for (int i = 0; i < A.get_m(); i++) {
                T s = 0;
                for (int j = 0; j < A.get_n(); j++) {
                    if (i != j) {
                        s += A(i, j)*x[j];
                    }
                }
                x[i] = (b[i] - s)/A(i,i);
            }
            for (int i = A.get_m()-1; i >= 0; i--) {
                T s = 0;
                for (int j = 0; j < A.get_n(); j++) {
                    if (i != j) {
                        s += A(i, j)*x[j];
                    }
                }
                x[i] = (b[i] - s)/A(i,i);
            }
            e = std::sqrt((x - new_x)*(x - new_x));
        }
        return x;
    }
