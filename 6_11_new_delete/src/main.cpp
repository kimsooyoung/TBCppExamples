#define MEMORY_LEAK_EXAMPLE 0


#include <iostream>

using namespace std;

int main(){

    // new keyword basic usage
    {
        int *ptr = nullptr;
        
        ptr = new int;
        *ptr = 3;

        // same with this 
        // int *ptr = new int{3};

        cout << "ptr : " << ptr << endl;
        cout << "*ptr : " << *ptr << endl;

        delete ptr;
    }

    // Error case
    {
        int *ptr = new int {3};
        
        cout << ptr << " " << *ptr << endl;

        delete ptr;

        cout << ptr << " " << *ptr << endl;

        // in order to prevent this...
        ptr = nullptr;

        if(ptr != nullptr)
            cout << ptr << " " << *ptr << endl;
    }

    // nothrow
    // sometimes, new fail when memory fulls
    {
        int *ptr = new (std::nothrow) int{7};

        if(ptr){
            cout << ptr << endl;
            cout << *ptr << endl;
        }
        else{
            cout << "Could not allocate memory" << endl;
        }
    }

    // memory leak
#if MEMORY_LEAK_EXAMPLE == 1
    {
        while(1){
            int *ptr = new int;
            cout << ptr <<endl;

            // delete ptr;
        }
    }
#endif

    return 0;
}