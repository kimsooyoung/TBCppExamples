#include <iostream>

int main(int argv, char *argc[])
{
    using namespace std;

    // auto lining by /t
    // this will be usefull for multiple line print

    cout << "qwerty"
         << "\t"
         << "asdfg" << endl;

    cout << "qwer"
         << "\t"
         << "tyasdfg" << endl;

    int input;
    cin >> input;
    cout << input << endl;

    return 0;
}