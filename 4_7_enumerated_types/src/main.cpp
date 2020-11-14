#include <iostream>

enum Color{
    COLOR_BLACK,
    COLOR_RED,
    COLOR_BLUE,
    COLOR_GREEN,
    // BLUE, // ERROR
};

enum Feeling{
    HAPPY,
    JOY,
    TIRED = -3,
    BLUE = -1,
};

int computeDamage(int weapon_id){
    if (weapon_id == 0)
        return 1;
    if (weapon_id == 1)
        return 2;
    // many many weapons
}

int main()
{
    Color paint = COLOR_BLACK;
    Color house(COLOR_BLUE);
    Color apple{COLOR_RED};

    std::cout << "paint : " << paint << std::endl;
    
    // Color paint = 3; // Error
    Color my_color = static_cast<Color>(3); // OK

    int new_color;
    std::cin >> new_color;
    std::cout << COLOR_BLUE << std::endl;

    if (new_color == COLOR_BLUE)
        paint = COLOR_BLUE;

    std::cout << "paint : " << paint << std::endl;

    return 0;
}
