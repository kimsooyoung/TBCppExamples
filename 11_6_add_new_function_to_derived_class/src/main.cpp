#include <iostream>

class Base {
protected:
    int m_i;
public:
    Base(const int &i_in=0): m_i(i_in) {}
};

class Child : public Base{
public:
    void newFunction(){
        Base::m_i = 12;
    }
};

int main(){

    Child ch;

    ch.newFunction();

    return 0;
}