#include <iostream>
#include <iomanip>
#include "constants.h"

int main()
{
    double radius;
    
    std::cout << "type radius : ";
    std::cin >> radius;

    double circumference = 2.0 * constants::pi * radius;

    // std::cout << std::setprecision(5);
    std::cout << "circumference is " << circumference << std::endl;

    return 0;
}