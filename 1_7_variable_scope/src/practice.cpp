#include <iostream>

using namespace std;

void doSomething(int x)
{
    x = 123;
    cout << x << endl;
}

int main(int argv, char *argc[])
{
    int x = 0;

    cout << x << endl;
    doSomething(x);
    cout << x << endl;

    return 0;
}