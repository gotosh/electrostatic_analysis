#include <boundary.hpp>
#include <util.hpp>

boundary::boundary(int N_x, int N_y)
{
}

void boundary::initialize(std::vector<std::vector<double>> &phi){
    for (int i = 0; i < phi.size(); i++)
    {
        for (int j = 0; j < phi.at(i).size(); j++)
        {
            phi.at(i).at(j) = 0.0;
        }
        
    }
    
}

void boundary::boundary_condition(std::vector<std::vector<double>> &phi){
    util ut;
    for (int i = 0; i < phi.size(); i++)
    {
        for (int j = 0; j < phi.at(i).size(); j++)
        {
            phi.at(i).at(j) = 0.0;
        }
        
    }
    
}

std::vector<std::vector<int>> boundary::flags(std::vector<std::vector<double>> &boundary){
    std::vector<std::vector<int>> flag;
    
    for (int i = 0; i < boundary.size(); i++)
    {
        for (int j = 0; j < boundary.at(i).size(); j++)
        {
            if (boundary.at(i).at(j) != 0.0)
            {
                flag.at(i).at(j) = 1;
            }
            else if (boundary.at(i).at(j) == 0.0)
            {
                flag.at(i).at(j) = 0;
            }
            
            
        }
        
    }
    
}

boundary::~boundary()
{
}