#include <iostream>

int main()
{
    {
        int x;
        std::cin >> x;

        if (x > 10)
            std::cout << x << " is greater than 10" << std::endl;
    }

    return 0;
}