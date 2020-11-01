#include <iostream>

int main(int argv, char *argc[])
{
    using namespace std;

    int x = 1;
    x = x + 2;
    cout << x << endl;

    int y = x;
    cout << y << endl;

    // x + y 는 L value? R value?
    cout << x + y << endl;

    int z;
    cout << z << endl;
    return 0;
}