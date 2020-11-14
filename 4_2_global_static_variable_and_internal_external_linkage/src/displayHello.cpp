#include <iostream>
#include "MyConstants.h"

void displayHello(){

    std::cout << "In displayHello.cpp file : " << Constants::pi << " address : " << &Constants::pi << std::endl;

    std::cout << "Hello" << std::endl;
}