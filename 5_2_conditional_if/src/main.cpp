#include <iostream>

int min (int x, int y){
    if (x > y) return y;
    else        return x;

    // return (x > y) ? y : x; 
}

int main()
{
    {
        int x;
        std::cout << "type x : ";
        std::cin >> x;

        if (x > 10)
            std::cout << x << " is greater than 10" << std::endl;
    }

    {
        int x;
        std::cout << "type x : ";
        std::cin >> x;
        
        if(1)
            int x = 5;
        else 
            int x = 6;

        std::cout << x << std::endl;
    }

    {
        int x;
        std::cout << "type x : ";
        std::cin >> x;

        if (x > 10 )
            std::cout << " x is greater than 10" << std::endl;
        else if (x < 10)
            std::cout << " x is less than 10" << std::endl;
        else 
            std::cout << " x is exactly 10" << std::endl;
    
        if( x >= 10){
            if( x < 20 )
                std::cout << " x is between 10 and 20" << std::endl;
            else
                std::cout << "..." << std::endl;
        }
    }

    {
        int x;

        // null statement
        if (x > 10);
        {
            x = 1;
        }

        std::cout << "x is : " << x << std::endl;
    }

    return 0;
}