#include <iostream>
#include <array>
#include <functional>

using namespace std;

int func(){
    return 4;
}

int printTwo(){
    cout << "Two" << " ";
}

int addOne(int x ){
    return x + 2;
}

bool isEven(const int &n){
    if (n % 2 == 0) return true;
    else return false;
}

bool isOdd(const int &n){
    if (n % 2 == 0) return false;
    else return true;
}

typedef bool(*check_func_t)(const int&);

void checkNum(const std::array<int, 5> &arr, check_func_t func = isEven){
    for (auto &i : arr)
    {
        if( func(i) ) cout << "Pass" << endl;
    }
}

void checkNum(const std::array<int, 5> &arr, std::function<bool(const int&)> func = isEven){
    for (auto &i : arr)
    {
        if( func(i) ) cout << "Pass" << endl;
    }
}


int main(){

    // Address of Fuction
    {
        cout << (uintptr_t)func << endl;
    }

    // Function Pointer
    {
        int (*fcnptr)() = func;

        cout << (uintptr_t)fcnptr << ", " << fcnptr() << endl;
        fcnptr = printTwo;
        cout << (uintptr_t)fcnptr << ", " << fcnptr() << endl;
    
        // output
        // 94899170782106, 4
        // 94899170782117, Two 1870479392 <= what's this?
    }

    // Function Pointer for paramter using function
    {
        int (*fcnptr)(int) = addOne;

        cout << "fcnptr(2) : " << fcnptr(2) << endl;
    }

    // Example, Odd Even Checker
    {
        std::array<int, 5> arr {1,2,3,4,5};
        checkNum(arr, isEven);
        cout << endl;
    }

    // Functional usage - From C++11
    {
        std::array<int, 5> arr {1,2,3,4,5};
        std::function<bool(const int&)> fcnptr = isEven;
        
        checkNum(arr, fcnptr);

        fcnptr = isOdd;
        cout << "Even to Odd changed" << endl;

        checkNum(arr, fcnptr);

    }

    return 0;
}