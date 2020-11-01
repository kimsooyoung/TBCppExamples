#include <iostream>
#include "something.h"

using namespace std;

int main()
{
    int x = 1;

    cout << "value x : " << x << " , %x: " << &x << endl;
    doSth(x);
    cout << "value x : " << x << " , %x: " << &x << endl;

    return 0;
}