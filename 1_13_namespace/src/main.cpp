#include <iostream>

namespace MySpace{
    namespace InnerSpace {
        int printSomething(){
            std::cout << "I am Something" << std::endl;
        }
    }
    int doSomething(int a, int b){
        return a + b;
    }
}

int doSomething(int a, int b){
    return a * b;
}

int main(){

    using namespace MySpace::InnerSpace;
    
    printSomething();

    std::cout << doSomething(1, 2) << std::endl;
    std::cout << MySpace::doSomething(1, 2) << std::endl;

    return 0;
}