#include <iostream>

using namespace std;

class Mother {
private:
    int m_i;
public:
    Mother(const int &i_in=0): m_i(i_in) {
        cout << "Mother Constructor Called" << endl;
    }
    
    ~Mother(){
        cout << "Mother Destructor Called" << endl;
    }
};

class Child : public Mother {
private:
    double m_d;
public:
    Child(const int& i_in=0, const double& d_in=0.0): Mother(i_in), m_d(d_in){
        cout << "Child Constructor Called" << endl;
    }

    ~Child(){
        cout << "Child Destructor Called" << endl;
    }
};

// Triple inheritance 
class A{
public:
    A(){
        cout << "A Constructor Called" << endl;
    }
    ~A() {
        cout << "A Destructor Called" << endl;
    }
};

class B : public A {
public:
    B(){
        cout << "B Constructor Called" << endl;
    }
    ~B() {
        cout << "B Destructor Called" << endl;
    }
};

class C : public B {
public:
    C(){
        cout << "C Constructor Called" << endl;
    }
    ~C() {
        cout << "C Destructor Called" << endl;
    }
};

int main(){

    // Pay attention to the sequence 
    // in which the constructor and the destructor 
    // are called.
    {
        Child c(1.2);
        Mother m;
    }

    cout << "=========================" << endl;
    
    // Triple Inheritance Example
    {
        C c;
        B b;
        A a;
    }

    return 0;
}