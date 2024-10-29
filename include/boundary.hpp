#ifndef BOUNDARY_HPP
#define BOUNDARY_HPP

#include <iostream>
#include <vector>
#include <fstream>


class boundary
{
private:
    int count;
public:
    boundary(int N_x, int N_y);
    void initialize(std::vector<std::vector<double>> &phi);
    void boundary_condition(std::vector<std::vector<double>> &phi);
    std::vector<std::vector<int>> flags(std::vector<std::vector<double>> &boundary);


    ~boundary();
};


#endif