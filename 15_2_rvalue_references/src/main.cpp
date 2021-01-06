#include <iostream>

// return from function is r value
int getResult(){
    return 1; 
}

void doSomething(int &ref_in){
    std::cout << "L-value Referenece Income" << std::endl;
}

void doSomething(int &&ref_in){
    std::cout << "R-value Reference Income" << std::endl;
}

int main () {

    int x = 5;
    int y = getResult();
    const int cx = 6;
    const int cy = getResult();


    // l value reference
    {
        int &lr1 = x; // Modifiable l-values
        // int &lr2 = cx; // Non-modifiable l-values
        // int &lr3 = 5; // R-values

        // const int & can be used like symbolic constants
        const int &lr4 = x; // Modifiable l-values
        const int &lr5 = cx; // Non-modifiable l-values
        const int &lr6 = 5; // R-values
    }

    // r-value reference
    {
        // int &&rr1 = x; // Modifiable l-values
        // int &&rr2 = cx; // Non-modifiable l-values
        int &&rr3 = 5; // R-values

        std::cout << rr3 << std::endl;
        rr3 = 10;
        std::cout << rr3 << std::endl;
    }

    // L/R value reference parameters
    {
        doSomething(x);
        // doSomething(cx);
        doSomething(5);
        doSomething(getResult());
    }

    return 0;
}