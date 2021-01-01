#include "OverrideFinalExample.h"
#include "CovariantExample.h"

int main(){
     
    // virtual function with override keyword
    {
        B b;
        b.print();
    }

    // Covariant Return Type Example
    {
        CovB b;
        
        CovA &ref_a = b;
        // this will return CovB
        b.getThis()->print();
        // this will return CovA?!!! 
        // Covariant Return type
        ref_a.getThis()->print();

        std::cout << typeid(b.getThis()).name() << std::endl;
        std::cout << typeid(ref_a.getThis()).name() << std::endl;
    }

    return 0;
}