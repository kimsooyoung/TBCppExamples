#include <iostream>
#include <limits>
#define EXAMPLE_NUMBER 5


int main(void)
{
    char c;

#if EXAMPLE_NUMBER == 1
    {
        char c1('A');
        char c2(65);

        std::cout << c1 << " " << c2 << " " << 
                int(c1) << " " << int(c2) << std::endl;
    }

#elif EXAMPLE_NUMBER == 2
    {
        std::cout << "c style casting" << std::endl;
        std::cout << (char)65 << std::endl;
        std::cout << (int)'A' << std::endl;

        std::cout << "cpp style casting" << std::endl;
        std::cout << char(65) << std::endl;
        std::cout << int('A') << std::endl;

        std::cout << "static casting" << std::endl;
        std::cout << static_cast<char>(65) << std::endl;
        std::cout << static_cast<int>('A') << std::endl;
    }

#elif EXAMPLE_NUMBER == 3
    {
        char input;
        
        std::cout << "type input : ";
        std::cin >> input;
        std::cout << "casting result : " <<
                 static_cast<int>(input) << std::endl;
    }

#elif EXAMPLE_NUMBER == 4
    {
        std::cout << sizeof(char) << std::endl;
        std::cout << int(std::numeric_limits<char>::max()) << std::endl;
        std::cout << int(std::numeric_limits<char>::min()) << std::endl;
        std::cout << int(std::numeric_limits<char>::lowest()) << std::endl;
    }

#elif EXAMPLE_NUMBER == 5 
    {
        // escape sequence
        std::cout << int('\n') << std::endl;
        std::cout << std::endl;
        std::cout << std::flush;
        std::cout << int('\t') << std::endl;
        std::cout << '\a' << std::endl;
    }

#endif
    std::cout << "This is sound test \a" << std::endl;

    return 0;
}