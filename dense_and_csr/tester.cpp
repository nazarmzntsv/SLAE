#include "dense.hpp"
#include <iostream>
#include "CSR.hpp"



int main() {
    std::vector<double> data{3, 0, 1, 0, 0, 0, 1, 0, 0, 7, 2, 9, 2, 9, 8, 0};
    dense_matrix <double> A(4, 4, data);
    std::cout << A(1, 0) << std::endl;
    std::vector<double> b{1, 3, 8};
    std::vector<double> res(3);
    res = A*b;
    for(int i=0;i<3;i++){
        std::cout<<res[i]<<std::endl;
    }
    /////////////////////////////

    
    std::vector<double> v{1, 2, 1, 6, 3, 5, 1}; 
    std::vector<double> c{0, 1, 3, 2, 3, 0, 3}; 
    std::vector<double> r{0, 3, 5, 7};
    CSR B(3,4,v,c,r);
    std::vector<double> h{1,2,3,4};
    for(int i=0;i<4;i++){
        std::cout<<(B*h)[i]<<std::endl;
    }

}