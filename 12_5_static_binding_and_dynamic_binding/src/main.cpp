#include <iostream> 

using namespace std;

namespace Calc {
    float add(const int &x_in, const int &y_in){
        return x_in + y_in;
    }

    float sub(const int &x_in, const int &y_in){
        return x_in - y_in;
    }

    float mul(const int &x_in, const int &y_in){
        return x_in * y_in;
    }

    float div(const int &x_in, const int &y_in){
        return x_in / y_in;
    }
}


int main(){

    int op;
    
    std::cout << "0 add 1 sub 2 mul 3 div : ";
    
    std::cin >> op; 
    std::cin.ignore(32767, '\n');
    std::cin.clear();

    int x, y;
    std::cout << "type x and y (operand) : " ;
    std::cin >> x >> y;

    float result;
    

    // static binding 
    // all parameter and functions decided in compile time
    // {
    //     switch (op)
    //     {
    //     case 0: result = Calc::add(x,y); break;
    //     case 1: result = Calc::sub(x,y); break;
    //     case 2: result = Calc::mul(x,y); break;
    //     case 3: result = Calc::div(x,y); break;
    //     default: break;
    //     }

    //     std::cout << "result : " << result << std::endl;
    // }

    // dynamic binding
    {

        float (*ptr_func)(const int&, const int&) = nullptr;

        switch (op)
        {
        case 0: ptr_func = Calc::add; break;
        case 1: ptr_func = Calc::sub; break;
        case 2: ptr_func = Calc::mul; break;
        case 3: ptr_func = Calc::div; break;
        default: break;
        }

        std::cout << "result : " << ptr_func(x, y) << std::endl;
    }


    return 0;
}