#include <iostream>


void last() {
    std::cout << "last" << std::endl;

    // who will catch this error? 
    // -1 is int type
    throw 3.14f;
}

void third(){
    std::cout << "third" << std::endl;

    try{
        last();
    }
    catch(char){
        // std::cerr, similar to cout 
        // but it don't put string on buffer 
        std::cerr << "third catch err" << '\n'; 
    }
    
}

void second(){
    std::cout << "second" << std::endl;

    try{
        third();
    }
    catch(double){
        std::cerr << "second catch err" << '\n';
    }
    
}

void first(){
    std::cout << "first" << std::endl;
    
    try{
        second();
    }
    catch(int){
        std::cout << "first catch err" << std::endl;
    }
    catch(...){
        std::cerr << "main caught ellipse exception" << std::endl;
    }
}

// throw(int) means 
// this function may throw an exception
void test() throw(int) {
    // do Sth
    throw 1;
}

// throw() means
// this function won't throw and exception
void test2() throw() {
    // do Sth
}

int main() {

    // -1 is int type
    // who will catch this error?
    {
        first();
        // first catch err
    }

    return 0;
}