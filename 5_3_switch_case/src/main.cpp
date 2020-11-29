#include <iostream>

enum class Colors{
    BLACK,
    WHITE,
    RED,
    GREEEN,
    BLUE,
};

void printColorName__Bad(Colors color){
    if (color == Colors::BLACK){
        std::cout << "It's Black" << std::endl; 
    } else if ( color == Colors::WHITE ){
        std::cout << "It's White" << std::endl;
    } // ...
    // This stuffs stinks
}

void printColorName(Colors color){
    {
        switch (static_cast<int>(color))
        {
        case 0:
            std::cout << "It's Black" << std::endl;
            break;
        case 1:
            std::cout << "It's White" << std::endl;
            break;
        case 2:
            std::cout << "It's Red" << std::endl;
            break;
        case 3:
            std::cout << "It's GREEEN" << std::endl;
            break;
        case 4:
            std::cout << "It's Blue" << std::endl;
            break;

        default:
            std::cout << "No such Color exists" << std::endl;
            break;
        }
    }
}

int main() {

    int color_input;
    std::cout << "Type number, It'll switched to Colors : ";
    std::cin >> color_input;


    printColorName(static_cast<Colors>(color_input));


    {
        switch (1)
        {
        case 0:
            // declaration in case is treated like declaration out of case block
            int x;
            x = 5;
            break;
        case 1:
            x = 13;
            std::cout << "x is " << x << std::endl;
        default:
            break;
        }
    }

    {
        switch (1)
        {
        case 0:
            int x;
            x = 12;
            break;
        case 1:
            // result will be a garbage value
            std::cout << " x is : " << x << std::endl;
        default:
            // default doens't need a break line
            // break;
        }
    }

    return 0;
}