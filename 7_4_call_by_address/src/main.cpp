#include <iostream>
#include <cmath>

using namespace std;

void ptrFunc(int *ptr){
    cout << "ptr : " << ptr << ", " <<  "&ptr : " << &ptr << endl;
}

typedef int* pint;
// Eventually call by address is same with call by value
void pintFunc(pint ptr){
    cout << "ptr : " << ptr << ", " <<  "&ptr : " << &ptr << endl;
}

void printArr(int *arr, const int size){
    // for (auto i = 0; i < size; i++)
    //     cout << arr[i] << ",";
    // cout << endl;
    arr[0] = 100;
}

// Re-write previous Example with pointer
void getSinCos(double const *degrees, double *sin_out, double *cos_out){
    static const double pi = 3.141592 / 180.0;
    const double radian = pi * (*degrees);
    *sin_out = std::sin(radian);
    *cos_out = std::cos(radian);
}

int main(){
    
    // call by pointer address is eventually 
    // same with call by value
    {
        int val = 5;
        int *ptr = nullptr;
        
        // practice
        ptr = &val;

        cout << "&val : " << &val << endl;
        ptrFunc(&val);
        cout << "ptr : " << ptr << ", " <<  "&ptr : " << &ptr << endl;
        ptrFunc(ptr); // different address

    }

    // getSinCos with pointers
    {
        double degree = 30.0;
        double sin, cos;

        getSinCos(&degree, &sin, &cos);
        cout << "degree : " << degree << ", sin : " << 
            sin << ", cos : " << cos << endl;
    }

    // C-style array
    {
        const int len = 5;
        int arr[len] = {1,2,3,4,5};

        for (auto i = 0; i < 5; i++)
            cout << arr[i] << ",";
        cout << endl;
        printArr(arr, len);
        for (auto i = 0; i < 5; i++)
            cout << arr[i] << ",";
        cout << endl;
    }

    return 0;
}