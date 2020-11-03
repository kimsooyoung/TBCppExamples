#include <iostream>

bool isEven(int num)
{
    if (num % 2 == 0)
        return true;
    else
        return false;
}

bool isEqual(int a, int b){
    return (a == b);
}

int main()
{
    int user_val;

    {
        bool b1(true);
        bool b2(0);
        bool b3(false); // copy initialization

        std::cout << std::boolalpha;

        std::cout << b1 << std::endl;
        std::cout << !b1 << std::endl;

        std::cout << "(true || true) : " << (true || true) << std::endl; 
        std::cout << "(true && false) : " << (true && false) << std::endl; 
        std::cout << "(true || false) : " << (true || false) << std::endl;
        std::cout << "(false && false) : " << (false && false) << std::endl;
    }

    {
        if (true)
            std::cout << "This is true" << std::endl;
        else
            std::cout << "This is false" << std::endl;        
    }

    {
        std::cout <<  "isEqual : " << isEqual(1, 2) << std::endl;
    }

    {
        bool user_input;

        std::cout << "type your boolean value : ";
        std::cin >> user_input;
        std::cout << "user_input : " << user_input << std::endl;
    }

    {
        std::cout << "Type any Number : ";
        std::cin >> user_val;

        if (isEven(user_val))
            std::cout << "This number is Even" << std::endl;
        else
            std::cout << "This number is Odd" << std::endl;
    }

    
    return 0;
}