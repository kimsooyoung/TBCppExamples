#include <iostream>
#include <cmath>

int main()
{
    int x = 3 * 4 / 2;

    double result = std::pow(2, 3);
    std::cout << result << std::endl;

    {
        int r = 1 + 2 + 3 * 4;
        int a, b, c;
        
        a = 18;
        a = b = c;
        std::cout << "a : " << a << " b : " << b << 
                " c : " << c << std::endl;

        int t = 10;
        int w = -1;
        t /= --w + 5;
        std::cout << "t : " << t << std::endl;

        {
            bool a = true;
            bool b = false;
            bool c = true;
            bool d = false;

            std::cout << (a || b && c || d) << std::endl;
        }
    }

    return 0;
}