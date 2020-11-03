#include <iostream>
#include <iomanip>
#include <assert.h>
#include <limits>
#include <cmath>

int main()
{
    {
        float f(3.14f); // 31.4 * 0.1
        double d;
        long double ld;

        std::cout << 3.14 << std::endl;
        std::cout << 31.4e-1 << std::endl;
        std::cout << 314e-2 << std::endl;
        std::cout << 31.4e1 << std::endl;
        std::cout << 31.4e3 << std::endl;


        std::cout << sizeof(f) << std::endl;
        std::cout << sizeof(d) << std::endl;
        std::cout << sizeof(ld) << std::endl;

        std::cout << "max number of float type : " <<  std::numeric_limits<float>::max() << std::endl;
        std::cout << "max number of double type : " <<  std::numeric_limits<double>::max() << std::endl;
        std::cout << "max number of long double type : " <<  std::numeric_limits<long double>::max() << std::endl;
        
        std::cout << "lowest number of float type : " << std::numeric_limits<float>::lowest() << std::endl;
        std::cout << "lowest number of double type : " << std::numeric_limits<double>::lowest() << std::endl;
        std::cout << "lowest number of float type : " << std::numeric_limits<long double>::lowest() << std::endl;

        // std::cout << std::numeric_limits<float>::min() << std::endl;
        // std::cout << std::numeric_limits<double>::min() << std::endl;
        // std::cout << std::numeric_limits<long double>::min() << std::endl;
    }

    {
        std::cout << std::setprecision(16) << std::endl;
        std::cout <<  "1.0 / 0.3 : " << 1.0 / 0.3 << std::endl;

        float f(123456789.0f);

        std::cout << std::setprecision(9);
        std::cout << f << std::endl; // 123456792

        double d(0.1);

        std::cout << std::setprecision(17);
        std::cout << d << std::endl; // 0.10000000000000001

        double d2(0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1);
        std::cout << std::setprecision(17);

        std::cout << d2 << std::endl; // 0.99999999999999989
    }

    {
        double zero = 0.0;
        double posinf = 5.0 / zero;
        double neginf = -5.0 / zero;
        double nan = zero / zero;

        std::cout << posinf << " " << std::isinf(posinf) << std::endl;
        std::cout << neginf << " " << std::isnan(neginf) << std::endl;
        std::cout << nan << " " << std::isnan(nan) << std::endl;
        std::cout << 1.0 << " " << std::isnan(1.0) << std::endl;

    }


    return 0;
}