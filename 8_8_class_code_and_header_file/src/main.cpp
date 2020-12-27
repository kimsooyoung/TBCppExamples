#include "Calc.h"

int main(){
    
    // Chaining Member Function
    {
        Calc cal(10);
        cal.add(2).div(3).mul(10).sub(4).printNum();

        // or use like this
        Calc(10).add(2).div(3).mul(10).sub(4).printNum();
    }

    return 0;
}