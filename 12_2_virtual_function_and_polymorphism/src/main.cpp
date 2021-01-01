#include <iostream>

#include "VirtualClass.h"
#include "Class.h"


int main() {

    // Without Virual function 
    {
        B b;
        C c;
        D d;   

        A &ref_a = b;
        // this will print A
        ref_a.print();
    }

    std::cout << "========================" << std::endl;

    // now use virtual
    {
        VirtualB b;
        VirtualC c;
        VirtualD d;   

        VirtualA &ref_a = b;
        // this will print VirtualB
        ref_a.print();
    }

    return 0;
}