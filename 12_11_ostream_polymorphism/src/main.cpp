#include <iostream>

using namespace std; 

class Base {
private:
    int m_i;
public:
    friend std::ostream& operator<<(std::ostream& out, const Base &b_in){
        return b_in.print(out);
    }
    virtual std::ostream& print(std::ostream& out) const {
        out << "Base";
        return out;
    }
};

class Derived : public Base {
public:
    virtual std::ostream& print(std::ostream& out) const override {
        out << "Derived";
        return out;
    }
};

int main() {

    {
        Base b;
        Derived d;

        cout << b << endl;
        cout << d << endl;
    }

    return 0;
}