#include <iostream>
#include <vector>

using namespace std;

int foo(int x, int y){
    return x + y;
} // x and y are destroyed in here

int main(){

    int x = 1, y = 2;

    foo(6, 7); // 6 & 7 : arguments (actual parameter)
    foo(x, y + 1); // variable y + 1 => argument 3 => parameter y

    return 0;
}