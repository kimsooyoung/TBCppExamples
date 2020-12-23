#include <iostream>

using namespace std;

// inline doesn't always guaranteed the best.
inline int min(int x, int y){
    return x > y ? y:x;
}

int main(){

    cout << min(3,4) << endl;;
    cout << min(1,6) << endl;;

    cout << (3>4 ? 4:3) << endl;;
    cout << (1>6 ? 6:1) << endl;;

    return 0;
}