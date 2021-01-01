#pragma once

#include <iostream>

class A {
public:
    virtual void print() const {
        std::cout << "A" << std::endl;
    }
};

class B : public A {
public:
    // override keyword usage
    // prevent virtual function mistakes
    //
    // final keyword usage
    // further inherited classes cannot access 
    // to this function
    virtual void print() const override final {
        std::cout << "B" << std::endl;
    }
};

class C : public B {
public:
    // cannot override "final" function
    // virtual void print() const {
    //     std::cout << "C" << std::endl;
    // }
};