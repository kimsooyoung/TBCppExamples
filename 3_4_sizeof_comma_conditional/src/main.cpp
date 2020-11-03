#include <iostream>
#include <cmath>

int getSale(bool isSale){
    if (isSale)
        return 10;
    else
        return 100;
}

int main()
{
    {
        float a;

        std::cout << sizeof(a) << std::endl;
        // sizeof is operator, not a function
        std::cout << sizeof a << std::endl; 
        // cannot use sizeof for type without ()
        // std::cout << sizeof float << std::endl;
    }

    {
        int x = 3;
        int y = 10;

        int z = (++x, ++y);
        
        // Upper expressoin is same with this
        // ++x;
        // ++y;
        // int z = y;

        std::cout << z << std::endl;

        int a = 1, b = 10;

        z = a, b;
        std::cout << z << std::endl;
    }


    {
        bool isSale = true;
        // const int price;
        // if (isSale)
        //     price = 10;
        // else
        //     price = 100;


        // instead..
        const int price = (isSale) ? 10: 100;
        // Or if you wanna use function...
        const int price_2 = getSale(isSale);
        
        int x = 10;
        std::cout << ((x % 2 == 0) ? "even" : "odd") << std::endl;
    }

    return 0;
}