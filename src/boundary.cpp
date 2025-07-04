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
            if ((25.0 <= ut.Index_to_coordinate(i, dL_y) && ut.Index_to_coordinate(i, dL_y) <= 30.0) && (60.0 <= ut.Index_to_coordinate(j, dL_x) && ut.Index_to_coordinate(j, dL_x) <= 140.0))
            {
                phi.at(i).at(j) = 10.0;
            }
            // Contact flame parts //
            if ((30.0 <= ut.Index_to_coordinate(i, dL_y) && ut.Index_to_coordinate(i, dL_y) <= 35.0) && (70.0 <= ut.Index_to_coordinate(j, dL_x) && ut.Index_to_coordinate(j, dL_x) <= 130.0))
            {
                phi.at(i).at(j) = 10.0;   
            }
            // Outlet of burner //
            if (ut.Index_to_coordinate(i, dL_y) == 55.0 && (70 <= ut.Index_to_coordinate(j, dL_x) && ut.Index_to_coordinate(j, dL_x) <= 130.0))
            {
                phi.at(i).at(j) = 0.01;
            }
            // Burner body //
            if (55.0 < ut.Index_to_coordinate(i, dL_y) && ((70.0 <= ut.Index_to_coordinate(j, dL_x) && ut.Index_to_coordinate(j, dL_x) <= 85.0) || (115.0 <= ut.Index_to_coordinate(j, dL_x) && ut.Index_to_coordinate(j, dL_x) <= 130.0)))
            {
                phi.at(i).at(j) = 0.01;
            }
        }
        
    }
    
}

void boundary::boundary_condition_2(std::vector<std::vector<double>> &phi, double dL_x, double dL_y){
    util ut;
    for (int i = 0; i < phi.size(); i++)
    {
        for (int j = 0; j < phi.at(i).size(); j++)
        {
            // At the top of electrode //
            if ((22.0 <= ut.Index_to_coordinate(i, dL_y) && ut.Index_to_coordinate(i, dL_y) <= 30.0) && ((70.0 <= ut.Index_to_coordinate(j, dL_x) && ut.Index_to_coordinate(j, dL_x) <= 85.0) || (115.0 <= ut.Index_to_coordinate(j, dL_x) && ut.Index_to_coordinate(j, dL_x) <= 130.0)))
            {
                phi.at(i).at(j) = 10.0;
            }

            
            // Outlet of burner //
            if (ut.Index_to_coordinate(i, dL_y) == 55.0 && ((70.0 <= ut.Index_to_coordinate(j, dL_x) && ut.Index_to_coordinate(j, dL_x) <= 85.0) || (115.0 <= ut.Index_to_coordinate(j, dL_x) && ut.Index_to_coordinate(j, dL_x) <= 130.0)))
            {
                phi.at(i).at(j) = 0.01;
            }
            // if (ut.Index_to_coordinate(i, dL_y) == 55.0 && (ut.Index_to_coordinate(j, dL_x) == 100.0))
            // {
            //     phi.at(i).at(j) = 0.01;
            // }

            // if (ut.Index_to_coordinate(i, dL_y == 55.0) && ((70.0 <= ut.Index_to_coordinate(j, dL_x) && ut.Index_to_coordinate(j, dL_x) <= 85.0) || (115.0 <= ut.Index_to_coordinate(j, dL_x) && ut.Index_to_coordinate(j, dL_x) <= 130.0)))
            // {
            //     phi.at(i).at(j) = 0.01;
            // }

            // if (ut.Index_to_coordinate(i, dL_y) == 55.0 && (70.0 <= ut.Index_to_coordinate(j, dL_x) && ut.Index_to_coordinate(j, dL_x) <= 130.0))
            // {
            //     phi.at(i).at(j) = 0.01;
            // }
            

            // Burner body //
            if (55.0 < ut.Index_to_coordinate(i, dL_y) && ((70.0 <= ut.Index_to_coordinate(j, dL_x) && ut.Index_to_coordinate(j, dL_x) <= 85.0) || (115.0 <= ut.Index_to_coordinate(j, dL_x) && ut.Index_to_coordinate(j, dL_x) <= 130.0)))
            {
                phi.at(i).at(j) = 0.01;
            }
        }
        
    }
    
}

/* Confirm whether string is consists of white spaces */
bool isWhitespace(const std::string& str) {
    return std::all_of(str.begin(), str.end(), [](unsigned char c) {
        return std::isspace(c);
    });
}

/* Parse inequality or quality */
bool boundary::parseExpression(const std::string& expr, double& minValue, double& maxValue) {
    // initial value //
    minValue = NEG_INF;
    maxValue = POS_INF;

    /* One sided inequality (ex. a < y) */ 
    if (expr.find('<') != std::string::npos && expr.find('>') == std::string::npos)
    {
        double value;
        if (sscanf(expr.c_str(), " %lf < %*s", &value) == 1)
        {
            minValue = value;
            return true;
        }
        if (sscanf(expr.c_str(), " %*s < %lf", &value) == 1)
        {
            maxValue = value;
            return true;
        }
        
    }
    /* Bi-sided equation */
    if (expr.find('<') != std::string::npos)
    {
        if (sscanf(expr.c_str(), " %lf < %*s < %lf", &minValue, &maxValue) == 2)
        {
            return true;
        }
                
    }
    
    /* Equation (ex. "y = 80.0") */
    if (expr.find('=') != std::string::npos)
    {
        double value;
        if (scanf(expr.c_str(), " %*s = %lf", &value) == 1)
        {
            minValue = maxValue = value;
            return true;
        }
                
    }
    return false;

}
std::vector<std::vector<int>> boundary::flags(std::vector<std::vector<double>> &boundary){
    std::vector<std::vector<int>> flag(boundary.size(), std::vector<int>(boundary[0].size(), 0));
    
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
    return flag;
}

boundary::~boundary()
{
}