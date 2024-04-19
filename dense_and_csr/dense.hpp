#pragma once
#include <vector>

template<typename Tip>
class dense_matrix {
    public:
    dense_matrix(unsigned int m, unsigned int n, const std::vector<Tip>& data) : m(m), n(n), data(data) {}
    Tip operator()(unsigned int i, unsigned int j) const {
        return data[i*n+j];
    }
    std::vector<Tip> operator*(const std::vector<Tip>& b) const {
        std::vector<Tip> result(b.size(), 0.0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result[i] += (*this)(i, j)*b[j];
            }
        }
        return result;
    }
    Tip get_m() const {
        return m;
    }
    Tip get_n() const {
        return n;
    }
    private:
    std::vector<Tip> data;
    unsigned int m;
    unsigned int n;
};