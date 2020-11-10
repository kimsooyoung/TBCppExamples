#include <iostream>
#include <cmath>

int main()
{
    {
        int x, y;
        std::cin >> x >> y;
        std::cout << "Your input values are : " << x << " " << y << std::endl;

        if(x == y ) 
            std::cout << "equal" << std::endl;
        if(x != y ) 
            std::cout << "not equal" << std::endl;
        if(x > y ) 
            std::cout << "x is greater than y" << std::endl;
        if(x < y ) 
            std::cout << "x is less than y" << std::endl;
        if(x >= y ) 
            std::cout << "x is greater than y or equal to y" << std::endl;
        if(x <= y ) 
            std::cout << "x is less than y or equal to y" << std::endl;
    }

    {
        double d1(100 - 99.99);
        double d2(10 - 9.99);

        std::cout << d1 << " , " << d2 << std::endl;

        const double epsilon = 1e-10;

        if(d1 == d2)
            std::cout << "equal" << std::endl;
        else
        {
            std::cout << "Difference : " << std::abs(d1 - d2) << std::endl;

            if(std::abs(d1 - d2) < epsilon)
                std::cout << "Approximately Equal" << std::endl;

            std::cout << "Not equal" << std::endl;

            if(d1 > d2)
                std::cout << "d1 > d2" << std::endl;
            else
                std::cout << "d1 < d2" << std::endl;
        }
    }

    return 0;
}