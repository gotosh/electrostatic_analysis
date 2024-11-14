#ifndef SOLVER_SOR_HPP
#define SOLVER_SOR_HPP

#include <iostream>
#include <vector>

class SolverSOR
{
private:
    std::vector<std::vector<double>> phi_init;
    std::vector<std::vector<double>> phi_temp;

public:
    SolverSOR();
    void Solve(std::vector<std::vector<double>> &phi, std::vector<std::vector<int>> &flags, double dL_x, double dL_y);
    ~SolverSOR();
};


#endif




