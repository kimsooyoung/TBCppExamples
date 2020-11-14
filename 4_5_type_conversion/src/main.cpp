#include <iostream>
#include <typeinfo>
#include <iomanip>

int main()
{
    {
        // implicit type conversion (coersion)
        int a = 123;
        int b = 123.0;
        double c = 3.14;

        std::cout << "typeof a : " << typeid(a).name() << std::endl;
        std::cout << "typeof b : " << typeid(b).name() << std::endl;
        std::cout << "typeof c : " << typeid(c).name() << std::endl;
    }

    {
        // explicit type conversion (casting)

        // numeric promotion
        float a = 1.0f;
        double d = a; 

        // numeric conversion
        int i = 300000;
        char c = i;
        std::cout << "int to char casting : " << static_cast<int>(c) << std::endl;

        // numeric conversion
        double e = 0.123456789;
        float f = e;

        std::cout << "double to float casting : " << std::setprecision(12) << f << std::endl;

        // numeric conversion
        std::cout << "5u - 10 : " << 5u - 10 << std::endl;
        std::cout << "5u - 10u : " << 5u - 10u << std::endl;
    }

    {
        // explicit casting
        int a = int(4.0); // c++ style
        int b = (int)4.0; // c style
        int c = static_cast<int>(4.0); // best method
    }
}
