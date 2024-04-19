#pragma once
#include <vector>

template<typename T>
    
    //sum
    std::vector<T> operator+(const std::vector<T> &a, const std::vector<T> &b){
    std::vector<T> sum(a.size());
    for (int i = 0; i < a.size(); i++) {
        sum[i] = a[i] + b[i];
    }
    return sum;
    }
template<typename T>
    //mult
    std::vector<T> operator*(const T& C, const std::vector<T>& a){
    std::vector<T> mult(a.size());
    for (int i = 0; i < a.size(); i++) {
        mult[i] = a[i]*C;
    }
    return mult;
    }
template<typename T>
    std::vector<T> operator-(const std::vector<T> &a, const std::vector<T> &b) {
        return a + (-1.0)*b;
    }
template<typename T>
    //scalar
    T operator*(const std::vector<T> &a, const std::vector<T> &b){
       if (a.size() != b.size()) {
           std::cout << "Idi v zhopy! A.size " << a.size() << "! B.size " << b.size() << "!" << std::endl;
           return 0;
       }
    else{
       T scalar = 0;
       for (int i = 0; i < a.size(); ++i) {
           scalar += a[i] * b[i];
       }
       return scalar;
    }
    }






