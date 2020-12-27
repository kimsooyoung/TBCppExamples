#include <iostream>

using namespace std;

// class A doesn't know that B exists
// forward declaration needed
class B;
// class C doesn't know that A exists
// forward declaration needed
class A;

class C{
    int m_val = 3;
public:
    void doSomething(A &a, B &b);
};

class A{
    int m_val = 1;
    friend void doSomething(A &a, B &b);
    friend void C::doSomething(A &a, B &b);
};

class B{
    int m_val = 2;
    friend void doSomething(A &a, B &b);
    friend void C::doSomething(A &a, B &b);
};

void doSomething(A &a, B &b){
    cout << a.m_val << " " << b.m_val << endl;
}

// class C doesn't know it was friended from other class
// so swap the order of doSomething function
void C::doSomething(A &a, B &b){
    cout << a.m_val << " " << b.m_val << endl;
}


int main(){
    
    // friend example1
    {
        B b;
        A a;
        doSomething(a, b);
    }

    // friend example2
    {
        B b;
        A a;
        C c;
        c.doSomething(a, b);
    }
    
    return 0;
}