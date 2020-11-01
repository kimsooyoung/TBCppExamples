#include "something.h"

void doSth(int x)
{
    x = 1234;
    std::cout << "value x : " << x << " , %x: " << &x << std::endl;
    return;
}