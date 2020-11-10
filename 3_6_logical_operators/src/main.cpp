#include <iostream>
#include <cmath>

int main()
{
    {
        bool x = true;
        bool y = false;
        
        // logical NOT
        std::cout << "!x : " << !x << std::endl;

        // logical AND
        std::cout << "(x && y) : " << (x && y) << std::endl;

        // logical OR
        std::cout << "(x || y) : " << (x || y) << std::endl;
    }

    {
        bool hit = true;
        int health = 10;
        
        if(hit == true && health < 20 )
            std::cout << "Die " << std::endl;
        else
            health -= 20;
    }

    {
        // short circuit evaluation
        int x = 2;
        int y = 2;

        if( x == 1 && y++ == 2 )
        {
            // do something
        }

        std::cout <<  "y : " << y << std::endl;
    }

    {
        bool x = true;
        bool y = true;

        // De Morgan's Law
        if ( (!(x || y)) == (!x && !y) )
            std::cout << "This is De Morgan's Law!" << std::endl;
    }

    {
        // C++ Doesn't have XOR operator
        // XOR
        // false false false
        // false true false
        // true false true
        // true true false
    }

    {
        // exercise
        std::cout << "Exercise 1: " << ( ( true && true ) || false ) << std::endl;
        std::cout << "Exercise 2: " << ( ( false && true ) || true ) << std::endl;
        std::cout << "Exercise 3: " << ( ( false && true ) || false || true ) << std::endl;
        std::cout << "Exercise 4: " << ( ( 14 > 13 || 2 > 1 ) && ( 9 > 1 ) ) << std::endl;
        std::cout << "Exercise 5: " << ( !(2314123 > 2 || 123123 > 2387 )  ) << std::endl;
    }

    {
        bool v1 = true;
        bool v2 = true;
        bool v3 = false;

        bool r1 = v1 || v2 && v3;
        bool r2 = (v1 || v2) && v3;
        bool r3 = v1 || (v2 && v3);

        // && higher priority than ||
        std::cout << "v1 || v2 && v3 => " << r1 << std::endl;
        std::cout << "(v1 || v2) && v3 => " << r2 << std::endl;
        std::cout << "v1 || (v2 && v3) => " << r3 << std::endl;
    }

    return 0;
}