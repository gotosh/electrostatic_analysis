#include <iostream>
#include <vector>

#include <solver_sor.hpp>
#include <util.hpp>
#include "boundary.hpp"
#include <solver_sor.hpp>
#include <thread>
#include <chrono>
#include <filesystem>


int main(){
    /* Count time duration */
    std::chrono::system_clock::time_point start, end;
    start = std::chrono::system_clock::now(); // start clock

    /* Analytical region */
    double L_x = 200.0;   // Vertical width of analytical region is 200 mm
    double L_y = 100.0;   // Horizontal width of analytical region is 200 mm
    /* Mesh grid distance */
    double dL_x = 0.2;     // Grid distance is 1 mm
    double dL_y = 0.2;     // Grid distance is 1 mm
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
    boundary.boundary_condition_2(phi, dL_x, dL_y);
    std::vector<std::vector<int>> flag;
    flag = boundary.flags(phi);

    /* Check wether result folder does exists or not */
    std::filesystem::path dir = "result"; // directory for creating
    if (!std::filesystem::exists(dir))
    {
        std::filesystem::create_directory(dir);
        std::cout << "result directory does not exists so be created" << std::endl;
    } else {
        std::cout << "result directory does already exists" << std::endl;
    }
    

    /* Solve lapalacian equation */
    SolverSOR solve;
    solve.Solve(phi, flag, dL_x, dL_y, omega, conv_cr);

    end = std::chrono::system_clock::now();
    double elapsed = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
    ut.save_time(std::to_string(elapsed), "./result/time.txt", L_x, L_y, dL_x, dL_y);

}