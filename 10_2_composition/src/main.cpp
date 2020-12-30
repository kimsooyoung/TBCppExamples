#include <iostream>

#include "Monster.h"

int main(){

    Monster mon1("Groot", 1, 2);
    mon1.moveTo(10,10);

    Monster mon2("Dracula");

    std::cout << mon1 << std::endl;
    std::cout << mon2 << std::endl;

    return 0;
}