#pragma once

#include <iostream>

// Resource Class
class Resource {
private:
    int m_arr[100];
public:
    Resource(){
        std::cout << "Resource Constructor" << std::endl;
    }
    
    ~Resource(){
        std::cout << "Resource Destructor" << std::endl;
    }

    void print(){
        std::cout << "Resource Print()" << std::endl;
    }
};