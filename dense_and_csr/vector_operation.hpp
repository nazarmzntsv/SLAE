#pragma once
#include <vector>

template<typename Tip>
    
    //sum
    std::vector<Tip> operator+(const std::vector<T> &a, const std::vector<T> &b){
    std::vector<Tip> sum(a.size());
    for (i = 0; i < n; i++) {
        sum[i] = a[i] + b[i];
    }
    return sum;
    }

    //mult
    std::vector<Tip> operator*(const Tip& C, const std::vector<T>& a){
    std::vector<Tip> mult(a.size());
    for (i = 0; i < n; i++) {
        mult[i] = a[i]*C
    }
    return mult;
    }

    //scalar
    Tip operator()(const std::vector<T> &a, const std::vector<T> &b){
       if (a.size() != b.size()) {
           std::cout << "Idi v zhopy! A.size " << a.size() << "! B.size " << b.size() << "!" << std::endl;
       }
    else{
       Tip scalar = 0;
       for (int i = 0; i < a.size(); ++i) {
           scalar += a[i] * b[i];
       }
       return scalar;
    }
    }






