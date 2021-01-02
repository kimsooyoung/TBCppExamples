#pragma once
#include <iostream>

class Cents {
private:
    int m_i;
public:
    Cents(const int &i_in=0): m_i(i_in){}
    
    friend bool operator>(const Cents &c1, const Cents &c2){
        return (c1.m_i > c2.m_i);
    }

    friend std::ostream& operator<<(std::ostream& out, const Cents &c_in){
        out << c_in.m_i;
        return out;
    } 
};