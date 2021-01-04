#pragma once 

#include <initializer_list>
#include <iostream>
#include <cassert>

template <typename T>
class Storage { 
private:
    T m_val;
public:
    Storage(const T &val_in): m_val(val_in){}

    ~Storage(){}

    void print() { 
        std::cout << m_val << std::endl;
    }
};
