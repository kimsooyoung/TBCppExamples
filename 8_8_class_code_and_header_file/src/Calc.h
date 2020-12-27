#pragma once

#include <iostream>

// chaining member function
class Calc {
private:
    int m_num;
public:
    Calc(const int& num_in);

    Calc& add(int val);
    Calc& sub(int val);
    Calc& mul(int val);
    Calc& div(int val);
    
    const int& getNum() const;
    void printNum() const;
};