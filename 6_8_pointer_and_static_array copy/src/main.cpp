#include <iostream>

using namespace std;

struct MyStruct{
    int arr[10] {0};
    char ch;
};

void pointerArray(int *arr){
    cout << sizeof(arr) << endl; // 8
    *arr = 1000;
}

void structArray(MyStruct *ms){
    cout << "sizeof(ms->arr) : " << sizeof(ms->arr) << endl;
    (ms->arr)[0] = 321;
}

int main(){
    
    // Eventually, Pointer is Array!!
    {
        int arr[] {1,2,3,4,5};
        char name[] = "Jack Jack";
        
        cout << arr << endl;
        cout << &(arr[0]) << endl;

        cout << arr[0] << " " << arr[1] << endl; 
        cout << *arr << " " << *(arr + 1) << endl;

        cout << *name << endl;
        cout << "========================================" << endl;
    }

    // Difference between pointer and Array
    {
        int arr[] {1,2,3,4,5};
        int *ptr_arr = nullptr;

        ptr_arr = arr;
        cout << *ptr_arr << endl;

        // ptr_arr is very similar like arr
        // but has different size
        cout << "sizeof(ptr_arr) : " << sizeof(ptr_arr) << endl;
        cout << "sizeof(arr) : " << sizeof(arr) << endl;

        // when array moves to function parameter
        // it copied to pointer
        pointerArray(arr);
        cout << "*arr : " << *arr << endl;
        cout << "========================================" << endl;
    }

    // Array in Struct
    {
        MyStruct name;
        
        name.arr[0] = 123;
        cout << "sizeof(name.arr) : " << sizeof(name.arr) << endl;

        cout << "(name.arr)[0] : " << (name.arr)[0] << endl;
        // if array is located in Struct
        // its size doesn't changes
        structArray(&name);
        cout << "(name.arr)[0] : " << (name.arr)[0] << endl;
    }

    return 0;
}