#include <iostream>
#include <limits>
#include <cmath>

int main()
{
    using namespace std;

    {
        short s = 1; // 2 bytes = 2 * bits = 16 bits
        int i = 1;
        long l = 1;
        long long ll = 1;

        std::cout << "sizeof : short" << sizeof(short) << std::endl;
        std::cout << "sizeof : int" << sizeof(int) << std::endl;
        std::cout << "sizeof : long" << sizeof(long) << std::endl;
        std::cout << "sizeof : long long" << sizeof(long long) << std::endl;
    }

    // overflow example
    {
        short val;

        cout << pow(2, sizeof(val) * 8 - 1) - 1 << endl;
        cout << numeric_limits<short>::max() << endl;
        cout << numeric_limits<short>::min() << endl;
        // min and lowest will same for integer types
        cout << numeric_limits<short>::lowest() << endl;

        short s = numeric_limits<short>::max(); // 32768;
        s += 1;

        cout << s << endl;
    }

    {
        unsigned int i = -1;
        std::cout << i << std::endl;
    }

    {
        int i = 22 / 4;
        std::cout << "devide in integer " << i << std::endl;
        std::cout << "devide in float " << (float) 22 / 4 << std::endl;
    }

    return 0;
}