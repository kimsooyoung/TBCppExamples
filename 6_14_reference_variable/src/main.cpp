#include <iostream>

void doSomething(int &val){
    val = 23;
    std::cout << "Val Address in Function : " << &val << std::endl;
}

// Array size must be specified 
void printElem(int (&arr)[5]){
    for (int i = 0; i < 5; i++)
    {
        std::cout << i << " " << arr[i] << std::endl;
    }
}

struct Something{
    int i;
    float f;
};

struct Other{
    Something st;
};

int main(){

    using namespace std;

    // Reference - Basic Usage
    {
        int val = 3;
        int *ptr_val = nullptr;
        ptr_val = &val;

        int &ref_val = val;

        cout << "&val : " << &val << endl;
        cout << "&ref_val : " << &ref_val << endl;
        cout << "ptr_val : " << ptr_val << endl;
        cout << "&ptr_val : " << &ptr_val << endl;
    }

    // Caution, Reference Must be initialized
    {
        int val = 5;
        // int &ref_val;
         
    } 

    // Const and Reference
    {
        const int val = 3;
        // Error
        // int &ref_val = val;
        const int &ref_val = val;

    }

    // Reference as a Function parameter
    {
        int val = 1;

        cout << "Main val : " << val << " / Address : " << &val << endl;
        doSomething(val);
        cout << "doSomething val : " << val << endl;
    }

    // Array Reference as a Function Parameter
    {
        const int arr_size = 5;
        int arr[5] = { 1,2,3,4,5 };
        printElem(arr);
    }

    // Struct Hierarchy with reference
    {
        Other oth;
        
        int &ref_f = oth.st.i;
        ref_f = 1;

        cout << "oth.st.i: " << oth.st.i << endl;
    }

    // Reference vs Pointer
    {
        int val = 5;
        int *const ptr_val = &val;
        int &ref_val = val;

        // those are same
        *ptr_val = 12;
        ref_val = 12;
    }

    return 0;
}