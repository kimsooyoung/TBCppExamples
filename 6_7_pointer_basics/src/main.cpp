#include <iostream>

using namespace std;

int main(){
    {
        int x = 5;
        double d = 123;

        int *ptr_x = &x;
        double *ptr_d = &d;

        cout << (size_t)&x << endl;
        cout << (size_t)ptr_x <<endl;

        cout << (size_t)&d << endl;
        cout << (size_t)ptr_d <<endl;
    }

    // typeid
    {
        int x = 4;
        int *ptr_x = &x;

        cout << typeid(ptr_x).name() << endl;
    }

    // sizeof pointer
    {
        int x = 4;
        double d = 123;

        int *ptr_x = &x;
        double *ptr_d = &d;

        cout << "sizeof(x) : " << sizeof(x) << endl;
        cout << "sizeof(d) : " << sizeof(d) << endl;
        
        cout << "sizeof(&x) : " << sizeof(&x) << endl;
        cout << "sizeof(&d) : " << sizeof(&d) << endl;
        
        cout << "sizeof(ptr_x) : " << sizeof(ptr_x) << endl;
        cout << "sizeof(ptr_d) : " << sizeof(ptr_d) << endl;
        
        cout << "sizeof(&ptr_x) : " << sizeof(&ptr_x) << endl;
        cout << "sizeof(&ptr_x) : " << sizeof(&ptr_x) << endl;
    }

    // ERROR Case
    {
        int x = 4;
        double d = 234;
        
        int *ptr_x;
        double *ptr_d;

        // Garbage output
        cout << *ptr_x << endl;
        cout << *ptr_d << endl;
    }

    return 0;
}