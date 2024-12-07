#ifndef UTIL_HPP
#define UTIL_HPP

#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>

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
    void save_time(std::string time, std::string save_path, double analytical_x, double analytical_y, double grid_distance_x, double grid_distance_y);
    ~util();
};




#endif