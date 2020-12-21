#include <iostream>

using namespace std;

void doSomething( const int &ref ){
    cout << ref << " ";
}

int main(){

    // Literal Reference is Invalid
    // But const Reference is Valid
    {
        // int &ref = 2 + 3;
        const int &ref = 2 + 3;

        // This can be used as this
        doSomething(1 + 3);
        int temp = 1;
        doSomething(temp + 4);
        doSomething(3 * 4);
    }

    return 0;
}