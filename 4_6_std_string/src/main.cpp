#include <iostream>
#include <string>
#include <limits>

int main()
{

    {
        const char my_str[] = "Hello, World";
        const std::string my_hello = "Hello, World";

        std::cout << my_hello << std::endl;
    }

    {
        std::cout << "======== Example 1 ========" << std::endl;
        std::cout << "Your Name ? : ";
        std::string name;
        std::cin >> name;

        std::cout << "Your age ? : ";
        std::string age;
        std::cin >> age;

        std::cout << "name : " << name << " " << "age : " << age << std::endl;
    }

    {
        // need to consider space and enter
        std::cout << "======== Example 2 ========" << std::endl;
        
        std::cout << "Your Name ? : ";
        std::string name;
        std::getline(std::cin, name);

        std::cout << "Your age ? : ";
        std::string age;
        std::getline(std::cin, age);

        std::cout << "name : " << name << " " << "age : " << age << std::endl;
    }

    {
        // make buffer empty 
        std::cout << "======== Example 3 ========" << std::endl;

        std::cout << "Your age ? : ";
        std::string age;
        std::cin >> age;

        // ignore until \n appears
        // std::cin.ignore(32767, '\n');
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Your Name ? : ";
        std::string name;
        std::getline(std::cin, age);

        std::cout << "name : " << name << " " << "age : " << age << std::endl;
    }
    
    {
        std::string a("Hello, ");
        std::string b("World ");
        std::string hw = a + b;

        hw += "I'm good";

        std::cout << hw << std::endl;
    }

    return 0;
}
