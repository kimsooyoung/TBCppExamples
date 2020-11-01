#include <iostream>
#include <bitset>

int main() { 
    bool bValue = true;
    char chValue = 65;
    float fValue = 3.141592f;
    double dValue = 3.141592;

    std::cout << sizeof(bool) << std::endl;
    std::cout << fValue << sizeof(fValue) << std::endl;
    std::cout << dValue << sizeof(dValue) << std::endl;

    // copy initialization
    int i = 3.14;
    // direct initialization
    int a(3.14); // occurs warning
    // uniform initialization
    // int b{1.57}; // occurs error

    return 0;
}