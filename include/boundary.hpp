#ifndef BOUNDARY_HPP
#define BOUNDARY_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <istream>
#include <string>
#include <tuple>
#include <algorithm>
#include <cctype>

class boundary
{
private:
    int count;

public:
    const double NEG_INF = -1e9;
    const double POS_INF = 1e9;
    boundary(int N_x, int N_y);
    void initialize(std::vector<std::vector<double>> &phi);
    void boundary_condition(std::vector<std::vector<double>> &phi, double dL_x, double dL_y);
    void boundary_condition_2(std::vector<std::vector<double>> &phi, double dL_x, double dL_y);
    bool isWhitespace(const std::string& str);
    bool parseExpression(const std::string& expr, double& minValue, double& maxValue);
    
    std::vector<std::vector<int>> flags(std::vector<std::vector<double>> &boundary);

    struct Condition
    {
        double y_min, y_max;
        double x_min, x_max;
        double boundary;
    };
    


    ~boundary();
};


#endif