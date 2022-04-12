#include <iostream>

using namespace std;

class Cents
{
private:
    int m_cents;

public:
    Cents(const int &cent_in = 0) : m_cents(cent_in) {}
    int getCents() const { return m_cents; }

    friend Cents operator+(const Cents &c1, const Cents &c2);

    Cents operator+(const Cents &c)
    {
        // return Cents( this->getCents() + c.m_cents );
        return Cents(this->m_cents + c.m_cents);
    }
};

Cents addCents(const Cents &c1, const Cents &c2)
{
    return Cents(c1.getCents() + c2.getCents());
}

// operator overloading
Cents operator+(const Cents &c1, const Cents &c2)
{
    // return Cents( c1.getCents() + c2.getCents() );
    return Cents(c1.m_cents + c2.m_cents);
}

int main()
{

    // Add Cents - without operator
    {
        cout << addCents(Cents(1), Cents(2)).getCents() << endl;
    }

    // Add Cents - with operator
    {
        cout << (Cents(1) + Cents(2)).getCents() << endl;
    }

    // Add Cents - In class overloading
    {
        cout << (Cents(1) + Cents(2)).getCents() << endl;
    }

    // additional caution
    // =, [], (), ->    : overloading allow in Class
    // ? :: sizeof . .* : cannot overloaded
    // ^                : do not overload
    // precedence       : my operator > basic operator

    return 0;
}