#include "Storage.h"

template <typename T>
T getMax(T x, T y){
    return (x > y) ? x : y;
}

template <>
char getMax(char x, char y){
    std::cout << "Warning, Char argument";
    return ( x > y ) ? x : y;
}

int main(){

    using namespace std;

    // Give Specialization for char getMax
    {
        // in fact <> is hidden in case of function template
        cout << getMax<int>(1,2) << endl;
        cout << getMax(1.1,2.2) << endl;

        cout << getMax('c', 'd') << endl;
    }

    // Specialization to Class Method
    {
        Storage<int> str(12);
        str.print();

        Storage<double> str_d(3.1415926534);
        str_d.print();
    }

    return 0;
}