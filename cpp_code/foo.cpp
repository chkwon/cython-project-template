#include <iostream>
#include "foo.hpp"

void display_vector(const std::vector<int> &v){
    for (auto i : v){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

// This function can receive vector. 
// To pass a vector to this function, we better not use &.
// std::span is a lightweight, non-owning view over a contiguous sequence of objects.
void multiply_span(std::span<int> v, int factor){
    for (auto &i : v){
        i *= factor;
    }
}

// This function does not make a copy of the array
void multiply_array_via_span(int* arr, int len, int factor){
    std::span<int> span(arr, len);
    multiply_span(span, factor);
}

// This function does not make a copy of the vector
void multiply_vector(std::vector<int>& v, int factor){
    for (auto &i : v){
        i *= factor;
    }
}

// This function does not make a copy of the array
void multiply_array(int* arr, int len, int factor){
    for (int i = 0; i < len; i++){
        arr[i] *= factor;
    }
}

int main() {
    std::vector<int> myvector = {1, 2, 3, 4, 5};


    std::cout << "myvector before multiply_array:\t";
    display_vector(myvector);
    
    multiply_array(myvector.data(), myvector.size(), 2);
    
    std::cout << "myvector after multiply_array:\t";
    display_vector(myvector);

    multiply_vector(myvector, 2);

    std::cout << "myvector after multiply_vector:\t";
    display_vector(myvector);

    multiply_span(myvector, 2);

    std::cout << "myvector after multiply_span:\t";
    display_vector(myvector);

    multiply_array_via_span(myvector.data(), myvector.size(), 2);
    
    std::cout << "myvector after multiply_array_via_span:\t";
    display_vector(myvector);


    return 0;
}