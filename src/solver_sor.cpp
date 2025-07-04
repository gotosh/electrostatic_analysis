#include <solver_sor.hpp>


SolverSOR::SolverSOR(/* args */)
{
}

void SolverSOR::write_solution(const std::vector<std::vector<double>> &phi, std::string save_file){
    std::ofstream file(save_file);
    if (!file)
    {
        std::cout << "File results.txt cannot be opened" << std::endl;
        return;
    }
    for (int i = 0; i < phi.size(); i++)
    {
        for (int j = 0; j < phi.at(i).size(); j++)
        {
            file << phi.at(i).at(j) << " ";
        }
        file << std::endl;
    }
    
    
}

double SolverSOR::calculate_error(const std::vector<std::vector<double>>& phi, const std::vector<std::vector<double>> &phi_old){
    double max_error = 0.0;
    for (int i = 1; i < phi.size(); ++i) {
        for (int j = 1; j < phi.at(i).size() - 1; ++j) {
            double error = std::abs(phi[i][j] - phi_old[i][j]);
            if (error > max_error) {
                max_error = error;
            }
        }
    }
    return max_error;
}

void SolverSOR::Solve(std::vector<std::vector<double>> &phi, std::vector<std::vector<int>> &flags, double dL_x, double dL_y, double omega, double tolerance){
    std::cout << "solve" << std::endl;
    std::vector<std::vector<double>> phi_old;
    int iterations = 0;
    double max_error;

    do {
        // Previous step //
        phi_old = phi;

        // Update SOR method //
        for (int i = 1; i < phi.size() - 1; i++)
        {
            for (int j = 1; j < phi.at(i).size() - 1; j++)
            {
                // Apply boundary condition //
                if (flags[i][j] == 1)
                {
                    phi[i][j] = phi_old[i][j];  // if boundary, it will not update
                }
                
                else if (flags[i][j] == 0)
                {
                    double phi_new = 
                                     ((phi[i+1][j] + phi[i-1][j]) * (dL_y*dL_y) 
                                     + (phi[i][j+1] + phi[i][j-1]) * (dL_x*dL_x)) / (2*(dL_x*dL_x + dL_y*dL_y));
                    phi[i][j] = phi_old[i][j] + omega * (phi_new - phi_old[i][j]);                    
                }
                

            }           
            
        }

        // Calculate error //
        max_error = calculate_error(phi, phi_old);
        iterations++;

        if (iterations > 1e7)
        {
            std::cout << "Don't converged" << std::endl;
            break;
        }
        
        // 

    } while (max_error > tolerance);
    
    // Save the result //
    write_solution(phi, "result/results_potential.txt");

    // Calculate Electric field //
    std::vector<std::vector<double>> Efield_x(phi.size(), std::vector<double>(phi.at(0).size(), 0.0));
    std::vector<std::vector<double>> Efield_y(phi.size(), std::vector<double>(phi.at(0).size(), 0.0));

    for (int i = 0; i < phi.size() - 1; i++)
    {
        for (int j = 0; j < phi[0].size() - 1; j++)
        {
            if (j > 0 && j < phi[0].size() - 1)
            {
                Efield_x[i][j] = - (phi[i][j+1] - phi[i][j-1]) / (2*dL_x);
            } else if (j == 0 && j + 1 < phi[0].size())
            {
                Efield_x[i][j] = - (phi[i][j+1] - phi[i][j]) / dL_x;
            } else if (j == phi[0].size() - 1 && j - 1 >= 0)
            {
                Efield_x[i][j] = - (phi[i][j] - phi[i][j-1]) / dL_x;
            }
            
            
            if (i > 0 && i < phi.size() - 1)
            {
                Efield_y[i][j] = (phi[i+1][j] - phi[i-1][j]) / (2*dL_y);
            } else if (i == 0 && i + 1 < phi.size())
            {
                Efield_y[i][j] = (phi[i+1][j] - phi[i][j]) / dL_y;
            } else if (i == phi.size() - 1 && i - 1 >= 0)
            {
                Efield_y[i][j] = (phi[i][j] - phi[i-1][j]) / dL_y;
            }
            
        }
        
    }
    write_solution(Efield_x, "result/Efield_x_result.txt");
    write_solution(Efield_y, "result/Efield_y_result.txt");
    
}

SolverSOR::~SolverSOR()
{
}