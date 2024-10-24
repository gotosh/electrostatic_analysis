#include <util.hpp>

util::util()
{
    
}

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

util::~util()
{
}