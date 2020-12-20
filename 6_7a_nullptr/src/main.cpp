#include <iostream>
#include <cstddef>

using namespace std;

void doSomething(double *ptr_d){
    cout << "pointer addess in doSomething" << &ptr_d << endl;

    if (ptr_d != nullptr){
        cout << *ptr_d << endl;
    }else {
        cout << "Null ptr, do nothing" << endl;  
    }
}

int main(){
    {
        double *ptr_d = nullptr;

        if (ptr_d != nullptr)
            // do something useful
            cout << "";
        else{
            // do nothing with ptr_d 
            cout << "";
        }
    }

    {
        double d = 223;
        double *ptr_d = nullptr;

        doSomething(&d);
        doSomething(nullptr);

        doSomething(ptr_d);
        ptr_d = &d;
        doSomething(ptr_d);

        cout << "pointer addess in main" << (size_t)&ptr_d << endl;
    }

    // nullptr_t;
    {
        std::nullptr_t nptr;
        nptr = nullptr;


    }

    return 0;
}