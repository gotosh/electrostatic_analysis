#include <iostream>
#include <vector>

#include <solver_sor.hpp>
#include <util.hpp>
#include <eigen3/Eigen/Dense>
#include <thread>


int main(){
    /* test */
    std::cout << "start" << std::endl;
    std::vector<double> vec = {1, 3, 5};
    std::cout << vec.at(1) << std::endl;

    /* Analytical region */
    double L_x = 200.0;   // Vertical width of analytical region is 200 mm
    double L_y = 100.0;   // Horizontal width of analytical region is 200 mm
    /* Mesh grid distance */
    double dL_x = 0.01;     // Grid distance is 0.01 mm
    double dL_y = 0.01;     // Grid distance is 0.01 mm
    /* Number of grid */
    util ut;
    int N_x = ut.cast_mesh(L_x / dL_x);
    int N_y = ut.cast_mesh(L_y / dL_y);

    /* convergence criterion */
    double conv_cr = 1e-5;

    /* Boundary condition */
    std::vector<std::vector<double>> phi(N_y, std::vector<double>(N_x, 0.0));
    std::cout << "size: " << phi.at(0).size() << std::endl;
    Eigen::Vector3i v(1, 3, 4);
    std::cout << v << std::endl;
    for (size_t i = 0; i < 100; i++)
    {
        for (size_t j = 0; j < 100; j++)
        {
            // std::cout << phi[i][j] << " ";
        }
        if (i % 10 == 0)
        {
            
        }
        
        
    }
}