#include <iostream>

bool isEven(int num)
{
    if (num % 2 == 0)
        return true;
    else
        return false;
}

int main()
{
    int user_val;

    std::cout << "Type any Number : ";
    std::cin >>
        user_val;

    if (isEven(user_val))
        std::cout << "This number is Even" << std::endl;
    else
        std::cout << "This number is Odd" << std::endl;

    return 0;
}