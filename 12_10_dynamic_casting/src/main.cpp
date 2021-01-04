#include <iostream>
#include <string>

using namespace std;

class Base {
private:
    int m_i;
public:
    virtual void print() {
        cout << "Base" << endl;
    }
};

class Derived1 : public Base {
private:
    double m_d;
public:
    virtual void print() override {
        cout << "Derived1" << endl;
    }
};

class Derived2 : public Base {
private:
    double m_d;
public:
    virtual void print() override {
        cout << "Derived2" << endl;
    }
};

int main(){

    //  dynamic casting example
    {
        Derived1 d_1;
        Base *b = &d_1;

        auto d_to_b = dynamic_cast<Derived1*>(b);

        d_to_b->print();
        // Derived1
    }

    cout << "======================" << endl;

    // Dynamic Cast return nullptr if cating fails
    {
        Derived2 d_1;
        Base *b = &d_1;

        auto d_to_b = dynamic_cast<Derived1*>(b);

        // So handle exception like this
        if (d_to_b != nullptr)
            d_to_b->print();
        else
            cout << "Dynamic Cast Failed" << endl;

        // d_to_b->print();
        // Segmentation fault (core dumped)
    }

    cout << "======================" << endl;

    // Then, How about static cast?
    {
        Derived2 d_1;
        Base *b = &d_1;

        auto d_to_b = static_cast<Derived1*>(b);

        // So handle exception like this
        if (d_to_b != nullptr)
            d_to_b->print();
        else
            cout << "Dynamic Cast Failed" << endl;

        // Derived2
        // static cast tries to cast to nearest type.
    }

    return 0;
}