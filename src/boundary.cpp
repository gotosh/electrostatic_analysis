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

void boundary::boundary_condition(std::vector<std::vector<double>> &phi, double dL_x, double dL_y){
    util ut;
    for (int i = 0; i < phi.size(); i++)
    {
        for (int j = 0; j < phi.at(i).size(); j++)
        {
            // At the top of electrode //
            if ((30.0 <= ut.Index_to_coordinate(i, dL_y) && ut.Index_to_coordinate(i, dL_y) <= 32.5) && (60.0 <= ut.Index_to_coordinate(j, dL_x) && ut.Index_to_coordinate(j, dL_x) <= 140.0))
            {
                phi.at(i).at(j) = 10.0;
            }
            // Contact flame parts //
            if ((32.5 <= ut.Index_to_coordinate(i, dL_y) && ut.Index_to_coordinate(i, dL_y) <= 35.0) && (70.0 <= ut.Index_to_coordinate(j, dL_x) && ut.Index_to_coordinate(j, dL_x) <= 130.0))
            {
                phi.at(i).at(j) = 10.0;   
            }
            // Outlet of burner //
            if (ut.Index_to_coordinate(i, dL_y) == 55.0 && (70 <= ut.Index_to_coordinate(j, dL_x) && ut.Index_to_coordinate(j, dL_x) <= 130.0))
            {
                phi.at(i).at(j) = 0.01;
            }
            // Burner body //
            if (55.0 < ut.Index_to_coordinate(i, dL_y) && ((70.0 <= ut.Index_to_coordinate(j, dL_x) && ut.Index_to_coordinate(j, dL_x) <= 85.0) || (105.0 <= ut.Index_to_coordinate(j, dL_x) && ut.Index_to_coordinate(j, dL_x) <= 130.0)))
            {
                phi.at(i).at(j) = 0.01;
            }
            
            
            

            
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