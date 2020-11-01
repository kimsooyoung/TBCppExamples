#include <iostream>

int main(int argv, char *argc[])
{
    using namespace std;

    // 자동 줄맞춤이 된다는 거

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