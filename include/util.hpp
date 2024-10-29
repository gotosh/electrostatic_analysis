#ifndef UTIL_HPP
#define UTIL_HPP

#include <iostream>
#include <cmath>
#include <vector>

class util
{
private:
    std::vector<std::vector<int>> zero_array;
public:
    // util() = delete;
    int cast_mesh(double num);
    template <typename T>
    std::vector<std::vector<int>> zeros_like(std::vector<std::vector<T>> &vec);
    double Index_to_coordinate(int Number, double dL);
    ~util();
};




#endif