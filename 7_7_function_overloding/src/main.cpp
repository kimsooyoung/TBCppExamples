#include <iostream>

using namespace std;


int addInt(int x, int y){
    return x + y;
}

double addDouble(double x, double y){
    return x + y;
}

// same with
int addVal(int x, int y){
    return x + y;
}

double addVal(double x, double y){
    return x + y;
}

// How to overload with different outputs
int getRandomVal(int &x){}
double getRandomVal(double &x){}

// Why don't you try this trick?
typedef double fake_double;
void fakeVal(double x){}
// void fakeVal(fake_double x){}
// Nope, Cannot deceive compiler :/ 

// Caution, Ambiguous Cases
void printVal(char val){
    cout << "Char *Value is " << val << endl; 
} 
void printVal(const char *val){
    cout << "Const Char Value is " << val << endl; 
} 
void printVal(int val){
    cout << "Int Value is " << val << endl;
}

// More Ambiguous Cases
void printVal(unsigned int val){
    cout << "Unsigned Int Value is " << val << endl;
}
void printVal(float val){
    cout << "Float Value is " << val << endl;
}

int main(){

    // Basic Usage
    // parameters must be decided during compile time
    {
        cout << "addVal(3,4) : " << addVal(3,4) << endl;
        cout << "addVal(3.14, 0.01) : " << addVal(3.14, 0.01) << endl;
        
        int input;
        cout << "Get input : ";
        cin >> input; cin.ignore(32767, '\n');
        cout << "input : " << addVal(input, input) << endl;
    }

    // Caution, Ambiguous Cases
    {
        printVal(0); // => int 
        printVal('c'); // => int
        printVal("C"); // => char *

        printVal(0u); // 0 can be treated as int or unsigned int
        printVal(3.14f); // 3.14 will be treated as double
    }

    return 0;
}