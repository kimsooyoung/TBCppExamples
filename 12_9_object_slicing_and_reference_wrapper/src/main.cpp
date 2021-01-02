#include <functional>
#include <iostream>
#include <vector>

using namespace std;

class Base {
private:
    int m_i;
public:
    virtual void print(){
        cout << "Base" << endl;
    }
};

class Derived : public Base {
private:
    double m_d;
public:
    virtual void print() override {
        cout << "Derived" << endl;
    }
}; 

void doSomething(Base &b_in){
    cout << "doSomething Called" << endl;
    b_in.print();
}

int main(){

    // Normal Usage
    {
        Derived d;
        Base &b = d;

        b.print();
        // Derived
    }

    cout << "==========================" << endl;

    // Polymorphism broken
    {   
        Derived d;
        Base b = d;

        b.print();
    }

    cout << "==========================" << endl;

    // Polymorphism with function 
    {   
        Derived d;
        Base b;
        doSomething(d);
        doSomething(b);
    }

    cout << "==========================" << endl;

    // Caution, Polymorphism with vector  
    {
        vector<Base> b_vec;

        b_vec.push_back(Derived());
        b_vec.push_back(Base());
        b_vec.push_back(Derived());

        for (auto &elem : b_vec)
            elem.print();
    }

    cout << "==========================" << endl;

    // How to resolve it?
    // Pointer vector
    {
        vector<Base*> b_vec;

        Derived d;
        Base    b;
        Derived d2;

        b_vec.push_back(&d);
        b_vec.push_back(&b);
        b_vec.push_back(&d2);

        for (auto &elem : b_vec)
            elem->print();
    }

    cout << "==========================" << endl;

    // vector cannot contain reference
    {
        // Error
        // vector<Base&> b_vec;
    }

    cout << "==========================" << endl;

    // Another Method => reference_wrapper
    {   
        vector<reference_wrapper<Base>> b_vec; 

        Derived d;
        Base    b;
        Derived d2;

        b_vec.push_back(d);
        b_vec.push_back(b);
        b_vec.push_back(d2);

        for (auto &elem : b_vec)
            elem.get().print();
    }

    return 0;
}