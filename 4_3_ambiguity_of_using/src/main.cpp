#include <iostream>

namespace a
{
    int my_var(10);
    int count(21121212);

} // namespace a

namespace b
{
    int my_var(20);

} // namespace a

int main()
{
    {
        using namespace a;
        std::cout << my_var << std::endl;
    }

    {
        using namespace b;
        std::cout << my_var << std::endl;
    }

    {
        using namespace a;
        
        std::cout << a::count << std::endl;    
        // error! count is already defined in std
        std::cout << count << std::endl;
    }
    return 0;
}