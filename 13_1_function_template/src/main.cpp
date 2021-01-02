#include "Cents.h"

template<typename T>
T getMax(T x, T y){
    return (x > y) ? x : y;
}

int main(){

    using namespace std;
    
    // function template example
    {
        cout << getMax(1,2) << endl;
        cout << getMax(1.2,1.3) << endl;
        cout << getMax('c','d') << endl;
        cout << getMax(-21.0,-21.3) << endl;

        // function template with User Defined types
        // But operator << and > must be implemented
        cout << getMax(Cents(1), Cents(2)) << endl;
    }

    return 0;
}