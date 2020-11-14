#include <iostream>
#include "MyConstants.h"

extern void displayHello();
extern int g_a = 456;

void doSomething(){
    int a = 1;
    ++a;
    std::cout << a << std::endl;
}

void doStaticSomething(){
    static int a = 1;
    ++a;
    std::cout << a << std::endl;
}

int main()
{
    {
        doSomething();
        doSomething();
        std::cout << "Static Something" << std::endl;
        doStaticSomething();
        doStaticSomething();
        doStaticSomething();
        doStaticSomething();
    }

    {
        std::cout << "In main.cpp file : " << Constants::pi << " address : " << &Constants::pi << std::endl;
        displayHello();
    }

    return 0;
}