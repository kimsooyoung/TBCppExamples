#include <iostream>

int addTwoNumbers(int num_a, int num_b){
     int sum = num_a + num_b;
     return sum;
}

void functionInFunction(){
     // void innerFunction(){
     //      // this is invalid
     // }
}

int mulTwoNumbers(int num_a, int num_b){
     int sum = num_a + num_b;
     return sum;
}

void printHelloWorld(){
     std::cout << "Hello World" << std::endl;
}

int main(){
     std::cout << addTwoNumbers(1,2) << std::endl;
     std::cout << addTwoNumbers(3,4) << std::endl;

     printHelloWorld();

     return 0;
}