#include <iostream>
#include <limits>

int main(void)
{
    char c;

    // std::cin >> c;
    // std::cout << c << std::endl;

    // std::cin >> c;
    // std::cout << c << std::endl;

    // std::cin >> c;
    // std::cout << c << std::endl;

    // std::cin >> c;
    // std::cout << c << std::endl;

    std::cout << int(std::numeric_limits<char>::max()) << std::endl;
    std::cout << int(std::numeric_limits<char>::min()) << std::endl;
    std::cout << int(std::numeric_limits<char>::lowest()) << std::endl;

    std::cout << "This is sound test \a" << std::endl;

    return 0;
}