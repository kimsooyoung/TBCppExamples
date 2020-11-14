#include <iostream>

auto add(int x, int y) -> int;

int main()
{
    {
        auto a = 123;
        auto b = 123.0;
        auto c = 1 + 2.0;

        std::cout << "sizeof a : " << sizeof a << std::endl;
        std::cout << "sizeof b : " << sizeof b << std::endl;
        std::cout << "sizeof c : " << sizeof c << std::endl;
    
        auto result = add(1, 2);
    }

    return 0;
}

int add(int x, int y){
    return x + y;
}