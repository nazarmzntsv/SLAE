#pragma once
#include <vector>
#include "dense.hpp"

template<typename T>
class CSR{
    private:
    std::vector<T> v;
    std::vector<T> c;
    std::vector<T> r;
    unsigned int n;
    unsigned int m;

    public:
    CSR(unsigned int m, unsigned int n, const std::vector<T>& v, const std::vector<T>& c, const std::vector<T>& r) : m(m), n(n), v(v), c(c), r(r) {}
    CSR(const dense_matrix<T>& A){
        m = A.get_m();
        n = A.get_n();
        v.reserve(m*n);
        c.reserve(m*n);
        r.reserve(m+1);
        r.push_back(0);
        int k = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++){
                if (A(i, j)!=0){
                    v.push_back(A(i, j));
                    c.push_back(j);
                    k = k + 1;
                }
            }
            r.push_back(k);
        }
        v.shrink_to_fit();
        c.shrink_to_fit();
    }
    const T operator()( int const i, int const j) const {
        for (int p = r[i]; p < r[i+1];  ++p) {
            if (c[p] == j) return v[p];
        }
        return 0;
    }

    std::vector<T> operator*(const std::vector<T>& b) const {
        std::vector<T> result(b.size(), 0.0);
         for (int i = 0; i < m; ++i) {
            for (int j = r[i]; j < r[i+1]; ++j) {
                result[i] += v[j] * b[c[j]];
            }
        }
        return result;
    }
};   