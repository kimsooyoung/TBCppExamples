#include <iostream> 
#include <typeinfo>

using namespace std;

enum Type{
    INT,
    FLOAT,
    CHAR,
};

int main(){

    {
        int     i = 5;
        float   f = 1.2;
        char    c = 'c';

        void *ptr_void = nullptr;

        // void ptr can point any type
        ptr_void = &i;
        ptr_void = &c;
        ptr_void = &f;

        // but... cannot do de-refencing
        // cout << *ptr_void << endl;

        // also cannot do pointer arithmetic
        // cout << *(ptr_void + 1) << endl;

        // Force Cast when you have to use them
        cout << &f << " " << ptr_void << endl;
        cout << f << " " << *static_cast<float*>(ptr_void) << endl;
    }

    // Force Casing Example
    {
        int     i = 5;
        float   f = 112.3;
        char    c = 'c';

        void *ptr_void = &f;
        Type type = FLOAT;

        if(type == FLOAT)
            cout << *static_cast<float*>(ptr_void) << endl;
        else if (type == INT)
            cout << *static_cast<int*>(ptr_void) << endl;
        else if (type == CHAR)
            cout << *static_cast<char*>(ptr_void) << endl;
        else
            cout << "Something Wrong" << endl;
    }

    return 0;
}