#ifndef SOLVER_SOR_HPP
#define SOLVER_SOR_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class SolverSOR
{
private:
    std::vector<std::vector<double>> phi_init;
    std::vector<std::vector<double>> phi_temp;

public:
    SolverSOR();
    void write_solution(const std::vector<std::vector<double>> &phi, std::string save_file);
    double calculate_error(const std::vector<std::vector<double>>& phi, const std::vector<std::vector<double>> &phi_old);
    void Solve(std::vector<std::vector<double>> &phi, std::vector<std::vector<int>> &flags, double dL_x, double dL_y, double omega, double tolerance);

    ~SolverSOR();
};


#endif




