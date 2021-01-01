#include <iostream>

class Base {
protected:
    int m_i;
public:
    Base(const int &i_in=0): m_i(i_in){}
    void print(){
        std::cout << "m_i : " << m_i << std::endl;
    }
};

class Child : public Base{
private:
    double m_d;
public:
    Child(const int &i_in=0, const double &d_in=0.1): Base(i_in), m_d(d_in) {}
    // this line allows to approach to m_i in main funciton
    using Base::m_i;
private:
    using Base::print; // do not add ()
    // or use delete
    void print() = delete; 
};

int main(){

    Child c;
    std::cout << c.m_i << std::endl;

    // cannot call print 
    // c.print();

    return 0;
}