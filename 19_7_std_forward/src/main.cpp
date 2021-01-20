#include <iostream>
#include <string>
#include <utility>

#include "CustomVector.h"

using namespace std;

class MyStruct {
private:
    string m_name;
public:
    MyStruct(const string &name_in): m_name(name_in){}
};

void func(const MyStruct &ms_in){
    cout <<  "L value Param" << endl;
}

void func(const MyStruct &&ms_in){
    cout <<  "R value Param" << endl;
}

template <typename T>
void funcWrapper(T my_t){
    func(my_t);
}

template <typename T>
void funcForwardWrapper(T&& my_t){
    func(std::forward<T>(my_t));
}

void vectorFunc(const CustomVector &c_v){
    cout << "L value Param" << endl;
    CustomVector new_c_v(c_v);
}

// const in here will prevent move constructor
void vectorFunc(CustomVector &&c_v){
    cout << "R value Param" << endl;
    CustomVector new_c_v(std::move(c_v));
}

template <typename T>
void vectorFuncWrapper(T &&t){
    vectorFunc(std::forward<T>(t));
}

int main(){

    // Function overloading with R/L value
    {
        MyStruct me("Kim");
        func(me); // L value Param
        func(MyStruct("Mrs. Puff")); // R value Param
    }

    // What happends if functions with tmeplate wrapper??
    {
        MyStruct me("Kim");
        funcWrapper(me); // L value Param
        funcWrapper(MyStruct("Mrs. Puff")); // L value Param
    }

    // how can fix this? => std::forward
    {
        MyStruct me("Kim");
        funcForwardWrapper(me); // L value Param
        funcForwardWrapper(MyStruct("Mrs. Puff")); // R value Param  
    }

    // Do same things with Custom Class
    {
        CustomVector c_v(10, 1); 

        CustomVector l_val_c_v = c_v;
        CustomVector r_val_c_v(std::move(c_v)); // c_v loses its ownership

        cout << l_val_c_v.m_data[0] << " " << c_v.m_size << endl;
        cout << endl;
    }

    //  R/L value parameter function 
    {
        CustomVector c_v(10, 1);
        vectorFunc(c_v);
        vectorFunc(std::move(c_v));
        cout << endl;
    }

    // template with Function Wrapper and std::forward
    {
        CustomVector c_v(10, 1);
        vectorFuncWrapper(c_v);
        vectorFuncWrapper(std::move(c_v));
    }

    return 0;
}