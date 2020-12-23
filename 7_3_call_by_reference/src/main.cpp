#include <iostream> 
#include <cmath> // sin(), cos()
#include <array>
#include <vector>

using namespace std;

void addOne(int &x){
    cout << "x : " << x << " &x : " << &x << endl;
    x++;
}

// trick, multiple return values 
void getSinCos(const double &degrees, double &sin_out, double &cos_out){
    static const double pi = 3.141592 / 180;
    const double radian = degrees * pi;
    sin_out = std::sin(degrees);
    cos_out = std::cos(degrees);
}

void foo(const int &x){
    cout << "foo val : " << x << endl;
}

typedef int* pint;

// void ptrFoo(int *&ptr){
void ptrFoo(pint &ptr){
    cout << "Foo ptr_val : " << ptr << " &ptr_val : " << &ptr << endl;
}

// Call by reference - array
void arrFoo(const int (&arr)[5]){
    cout << "arr in Foo : " << arr << endl;
}

// Use more comfortable method - std::array && std::vector
void stdArrFoo(const array<int, 5> &arr){
    cout << "arr.at(0) in Foo : " << arr.at(0) << endl;
}

// Vector
void stdVectorFoo(const vector<int> &vec) {
    cout << "vec.at(0) in Foo : " << vec.at(0) << endl;
}

int main(){
    
    // Basic Example
    {
        int x = 6;

        cout << "x : " << x << " &x : " << &x << endl;
        addOne(x);
        cout << "x : " << x << " &x : " << &x << endl;
    }

    // multiple return values 
    {
        double degree = 30.0;
        double sin = 0.0;
        double cos = 0.0;

        getSinCos(degree, sin, cos);

        cout << "degree : " << degree << 
            ", sin : " << sin <<
            ", cos : " << cos << endl;
    }

    // Cons of reference
    {
        foo(6);
    }

    // Pointer reference
    {
        int val = 3;
        int *ptr_val = &val;

        cout << "Main ptr_val : " << ptr_val << " &ptr_val : " << &ptr_val << endl;
        ptrFoo(ptr_val);
    }

    // array to parameter
    {
        int arr[5] {1,2,3,4,5};

        cout << "arr in Main : " << arr << endl;
        arrFoo(arr);

    }

    // vector to parameter
    {
        vector<int> vec {1,2,3,4,5};

        cout << "vec.at(0) in Foo : " << vec.at(0) << endl;
        stdVectorFoo(vec);
    }

    return 0;
}