#include <iostream>
#include <limits>
#include <cmath>

int main()
{
    using namespace std;
    // overflow example

    short val;

    cout << pow(2, sizeof(val) * 8 - 1) - 1 << endl;
    cout << numeric_limits<short>::max() << endl;
    cout << numeric_limits<short>::min() << endl;
    cout << numeric_limits<short>::lowest() << endl;

    short s = 32768;

    cout << s + 1 << endl;

    return 0;
}