#include <iostream>
#include <cmath>

int main()
{
    int x = 7;
    int y = 4;

    std::cout << "x / y : " << x / y << std::endl;
    std::cout << "(float)x / y : " << (float)x / y << std::endl;
    std::cout << "x / (float)y : " << x / (float)y << std::endl;
    std::cout << "(float)x / (float)y : " << (float)x / (float)y << std::endl; 
    
    std::cout << "-5 / 2 : " << -5 / 2 << std::endl;
    std::cout << "-5 % 2 : " << -5 % 2 << std::endl;

    int z = 3;
    z += 2;

    return 0;
}