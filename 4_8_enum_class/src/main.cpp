#include <iostream>

int main()
{
    enum class Color {
        RED, 
        BLUE,
    };

    enum class Fruit {
        BANANA,
        APPLE,
    };

    Color color1 = Color::RED;
    Color color2 = Color::RED;
    Fruit fruit = Fruit::BANANA;

    if(color1 == color2)
        std::cout << "Same Color" << std::endl;

    return 0;
}
