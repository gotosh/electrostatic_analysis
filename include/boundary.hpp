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
    void boundary_condition(std::vector<std::vector<double>> &phi, double dL_x, double dL_y);
    void boundary_condition_2(std::vector<std::vector<double>> &phi, double dL_x, double dL_y);
    std::vector<std::vector<int>> flags(std::vector<std::vector<double>> &boundary);


    ~boundary();
};


#endif