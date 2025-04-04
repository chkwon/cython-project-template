#ifndef FOO_HPP
#define FOO_HPP

#include <vector>
#include <span>

void multiply_span(std::span<int> v, int factor);
void multiply_vector(std::vector<int>& v, int factor);
void multiply_array(int* arr, int len, int factor);
void multiply_array_via_span(int* arr, int len, int factor);

#endif // FOO_HPP
