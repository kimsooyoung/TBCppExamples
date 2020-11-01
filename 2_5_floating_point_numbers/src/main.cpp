#include <iostream>
#include <iomanip>
#include <assert.h>
#include <limits>
#include <cmath>

int main()
{
    // float f(3.14f);
    // double d;
    // long double lg;

    // std::cout << 3.14e-1 << std::endl;
    // std::cout << 3.14e+2 << std::endl;

    // std::cout << std::numeric_limits<float>::lowest() << std::endl;
    // std::cout << std::numeric_limits<double>::lowest() << std::endl;
    // std::cout << std::numeric_limits<long double>::lowest() << std::endl;

    // std::cout << std::numeric_limits<float>::max() << std::endl;
    // std::cout << std::numeric_limits<double>::max() << std::endl;
    // std::cout << std::numeric_limits<long double>::max() << std::endl;

    // std::cout << std::numeric_limits<float>::min() << std::endl;
    // std::cout << std::numeric_limits<double>::min() << std::endl;
    // std::cout << std::numeric_limits<long double>::min() << std::endl;

    std::cout << std::setprecision(5) << std::endl;
    std::cout << 1.0 / 0.3 << std::endl;

    double zero = 0.0;
    double posinf = 5.0 / zero;
    double neginf = -5.0 / zero;
    double nan = zero / zero;

    std::cout << posinf << " " << std::isinf(posinf) << std::endl;
    std::cout << neginf << " " << std::isinf(neginf) << std::endl;
    std::cout << nan << " " << std::isnan(nan) << std::endl;

    return 0;
}