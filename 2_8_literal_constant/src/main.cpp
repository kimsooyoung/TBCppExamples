#include <iostream>
#include <limits>

int main()
{
    using namespace std;

    int i = 1234u; // unsigned int will be cast to int type
    
    unsigned int n = 5u;
    long n2 = 5L;
    double d = 6.0e-10;

    int o = 012;
    int u = 0xF;

    // c++ 11 binary literal
    // c++ 14 quaotation ' compiler will ignore this
    int x = 0b1011'1111'1001;

    cout << u << endl;
    cout << x << endl;

    return 0;
}