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
                double phi_new = ((phi.at(i+1).at(j) + phi.at(i-1).at(j)) * (dL_y*dL_y) + (phi.at(i).at(j+1) + phi.at(i).at(j-1)) * (dL_x*dL_x)) / (2*(dL_x*dL_x + dL_y*dL_y));
                phi.at(i).at(j) = phi_old.at(i).at(j) + omega * (phi_new - phi_old.at(i).at(j));
            }           
            
        }

        // Apply boundary condition //
        for (int i = 0; i < phi.size() - 1; i++)
        {
            for (int j = 0; j < phi.at(i).size() - 1; j++)
            {
                if (flags.at(i).at(j) == 1)
                {
                    phi.at(i).at(j) = phi_old.at(i).at(j);
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
        
        write_solution(phi, "result/results.txt");

    } while (max_error > tolerance);

    // Calculate Electric field //
    std::vector<std::vector<double>> Efield_x(phi.size(), std::vector<double>(phi.at(0).size(), 0.0));
    std::vector<std::vector<double>> Efield_y(phi.size(), std::vector<double>(phi.at(0).size(), 0.0));

    for (int i = 0; i < phi.size() - 1; i++)
    {
        for (int j = 0; j < phi.at(i).size() - 1; j++)
        {
            Efield_x.at(i).at(j) = - (phi.at(i).at(j + 1) - phi.at(i).at(j)) / dL_x;
            Efield_y.at(i).at(j) =  (phi.at(i + 1).at(j) - phi.at(i).at(j)) / dL_y;
        }
        
    }
    write_solution(Efield_x, "result/Efield_x_result.txt");
    write_solution(Efield_y, "result/Efield_y_result.txt");
    
}

SolverSOR::~SolverSOR()
{
}