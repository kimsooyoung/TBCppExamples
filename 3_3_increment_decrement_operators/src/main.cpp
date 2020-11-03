#include <iostream>
#include <cmath>

int add(int a, int b){
    return a + b; 
}

int main()
{
    int x = 6, y = 6;

    std::cout << x << " " << y << std::endl;
    std::cout << ++x << " " << --y << std::endl;
    std::cout << x << " " << y << std::endl;
    std::cout << x++ << " " << y-- << std::endl;
    std::cout << x << " " << y << std::endl;    

    int v = add(x, ++y); // do not use 
    std::cout << v << std::endl;

    return 0;
}