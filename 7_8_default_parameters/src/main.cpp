#include <iostream>

using namespace std;

void printMultiVal(int x = 10, int y = 20, int z = 30);

void printVal(const int &x= 0){
    cout << x << endl;
}

void printMultiVal(int x, int y, int z){
    cout << "x : " << x << endl; 
    cout << "y : " << y << endl;
    cout << "z : " << z << endl;
    cout << "===================" << endl;
}

// string print function overloading
void printStr(std::string str){
    cout << "std::string is selected : " << str << endl;
}
void printStr(char ch = ' '){
    cout << "char ch is selected : " << ch << endl;
}

// Ambiguous case
void ambigFunc(int x){
    cout << x << endl;
}

void ambigFunc(int x, int y = 10){
    cout << x << endl;
    cout << y << endl;
}

int main(){


    // Basic Usage
    {
        printVal();
        // Multiple default values
        printMultiVal();
        printMultiVal(11);
        printMultiVal(11,22);
        printMultiVal(11,22,33);
    }

    // Function overloading with default parameter
    {
        printStr();
    }

    {
        // Error : call of overloaded ‘ambigFunc(int)’ is ambiguous
        // ambigFunc(10);
    }

    return 0;
}