#include <iostream>

using namespace std;

class Mother{
private:
    int m_i;
public:
    Mother(const int &i_in): m_i(i_in){
        cout << "Mother Constructor Called" << endl;
    }
};

class Child : public Mother {
private:
    double m_d;
    float m_f;
public:
    Child(const int &i_in, const double &d_in): Mother(i_in), m_d(d_in){
        cout << "Child Constructor Called" << endl;
    }
};

class A {
public:
    A(){
        cout << "A Const" << endl;
    }
    ~A(){
        cout << "A Dest" << endl;
    }
};

class B : public A {
public:
    B(){
        cout << "B Const" << endl;
    }
    ~B(){
        cout << "B Dest" << endl;
    }
};

class C : public B {
public:
    C(){
        cout << "C Const" << endl;
    }
    ~C(){
        cout << "C Dest" << endl;
    }
};

int main(){

    // Watch the sizeof each Classes
    // Child class size = (Mother Class Instance size) + (Child Class Instance size)
    {
        Child c(1, 0.01);
        Mother m(1);

        cout << "sizeof(c) : " << sizeof(c) << endl;
        cout << "sizeof(m) : " << sizeof(m) << endl;
    }


    {
        A a;
        B b;
        C c;
    }

    return 0;
}