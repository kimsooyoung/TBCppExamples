#include <iostream>

int add (int a, int b); // forward declaration
int sub (int a, int b);
int mul (int a, int b);
float divide (int a, int b);

int main () {

    std::cout << add(1,2) << std::endl;
    std::cout << sub(1,2) << std::endl;
    std::cout << mul(1,2) << std::endl;
    std::cout << divide(5,3) << std::endl;

    return 0;
}

int add(int a, int b){ // definition
    return a + b; 
}

int sub (int a, int b){
    return a - b;
}

int mul (int a, int b){
    return a * b;
}

float divide (int a, int b) {
    return a / b;
}

