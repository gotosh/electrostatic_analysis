#include <iostream>
#include <vector>

#include <solver_sor.hpp>
#include <util.hpp>
#include "boundary.hpp"
#include <solver_sor.hpp>
#include <eigen3/Eigen/Dense>
#include <thread>


int main(){
    /* Analytical region */
    double L_x = 200.0;   // Vertical width of analytical region is 200 mm
    double L_y = 100.0;   // Horizontal width of analytical region is 200 mm
    /* Mesh grid distance */
    double dL_x = 0.1;     // Grid distance is 1 mm
    double dL_y = 0.1;     // Grid distance is 1 mm
    /* Number of grid */
    util ut;
    int N_x = ut.cast_mesh(L_x / dL_x);
    int N_y = ut.cast_mesh(L_y / dL_y);

    /* convergence criterion */
    const double conv_cr = 1e-5;
    /* Relaxation coefficient of SOR method */
    const double omega = 1.7;
    
    /* Initalize */
    std::vector<std::vector<double>> phi(N_y, std::vector<double>(N_x, 0.0));
    boundary boundary(N_x, N_y);
    boundary.initialize(phi);
    boundary.boundary_condition(phi, dL_x, dL_y);
    std::vector<std::vector<int>> flag;
    flag = boundary.flags(phi);

    /* Solve lapalacian equation */
    SolverSOR solve;
    solve.Solve(phi, flag, dL_x, dL_y, omega, conv_cr);


}