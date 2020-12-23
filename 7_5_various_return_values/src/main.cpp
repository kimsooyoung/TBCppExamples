#include <iostream>
#include <array>
#include <tuple>

using namespace std;

// return by value
int retVal(int x){
    return x;
}

// return by Address
int* retAdd(int x){
    return &x;
}

// return by Address with Mem alloc
int* retMalloc(int size){
    int *arr = new int[size];
    return arr;
}

// return by reference
int& retRef(int x){
    int val = x + 2;
    return val;
}

// return by reference - Use like this
int& getElem(std::array<int, 5> &arr, const int loc){
    return arr[loc];
}

// return more than one 
struct S{
    int a,b,c,d;
};

S getStruct(){
    S my_s{ 1,2,3,4 };
    return my_s;
}

std::tuple<int, double> getTuple(){
    // std::tuple<int, double> tup {1, 12.3};
    // or
    int i = 3;
    double d = 0.141592;
    return std::make_tuple(i, d);
}

int main(){
    
    // return by value
    {
        int x = 3;
        retVal(x);
        retVal(4);
    }

    // return by Address
    {
        int x = 3;
        
        // // Do not use this
        // int *ptr = retAdd(x);
        // // or
        // int val = *retAdd(x);

        // Why? See this
        // cout << *ptr << endl;
        // cout << val << endl;

        // result => Segmentation fault (core dumped)
    }

    // return by Address with Mem alloc
    {
        int *arr = nullptr;

        arr = retMalloc(100);
        delete[] arr;
    }

    // return by reference - Do not Use this
    {
        int x = 3;
        // int val = retRef(x);

        // // Segmentation fault (core dumped)
        // cout << "retRef(x) : " << val << endl;

        // // Error case
        // // Get reference by reference

        // int &ref = retRef(x);
        // cout << "ref : " << ref << endl;
        // cout << "ref : " << ref << endl;
    }

    // return by reference - Use Like this
    {
        int loc = 0;
        std::array<int, 5> arr = {1,2,3,4,5};
        
        // array is already allocated in stack
        cout << "elem : " << getElem(arr, loc) << endl;
    }

    // return more than one 
    {
        S my_s = getStruct();
        cout << "my_s.a : " << my_s.a << endl;
    }

    // Tuple 
    {
        std::tuple<int, double> tup = getTuple();
        cout << std::get<0>(tup) << endl;
        cout << std::get<1>(tup) << endl;

        //or

        // From C++17
        auto[i, d] = getTuple();
        cout << i << endl;
        cout << d << endl;
    
    }

    return 0;
}