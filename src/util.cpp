#include <util.hpp>

util::util()
{
    
}

/* To cast double type to int for assign mesh number */
int util::cast_mesh(double num){
    int num_int = static_cast<int>(num);
    std::cout << num << std::endl;
    if (std::fabs(num_int - num) > 0.0)
    {
        std::cerr << "Mesh number does not be converted to int. Please rewrite the distance of mesh grid" << std::endl;
        std::abort();
        return -1;
    }

    return num_int;
    
}

/* Create zero 2D vector */
template <typename T>
std::vector<std::vector<int>> util::zeros_like(std::vector<std::vector<T>> &vec){
    std::vector<std::vector<int>> zero_array(vec.size(), std::vector<int>(vec.at(0).size(), 0));
    return zero_array;
};

double util::Index_to_coordinate(int Number, double dL){
    return Number * dL;
}

util::~util()
{
}