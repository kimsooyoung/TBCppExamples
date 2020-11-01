#include <iostream>

int main(int argv, char *argc[])
{
    using namespace std;
    int x = 0;
    cout << "out of scope : " << &x << endl;

    {
        // toggle between those two lines

        int x = 1;
        // x = 1;
        cout << "in the scope : " << &x << endl;
    }

    cout << "out of scope : " << &x << endl;

    return 0;
}