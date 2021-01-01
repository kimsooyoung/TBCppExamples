#pragma once 

#include <iostream>

class CovA {
public:
    void print() { std::cout << "CovA" << std::endl; }
    virtual CovA* getThis(){
        std::cout << "CovA* getThis" << std::endl;
        return this;
    }
};

class CovB : public CovA {
public:
    void print() { std::cout << "CovB" << std::endl; }
    virtual CovB* getThis(){
        std::cout << "CovB* getThis" << std::endl;
        return this;
    }
};