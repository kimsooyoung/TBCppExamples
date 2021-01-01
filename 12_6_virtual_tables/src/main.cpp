#include <iostream>

using namespace std;

class VirtualBase {
public:
    virtual void func1() {}
    virtual void func2() {}
};

class VirtualChild : public VirtualBase {
public:
    virtual void func1() override {}
};

class Base {
public:
    void func1() {}
    void func2() {}
};

class Child : public Base {
public:
    void func1() {}
};

int main() {

    using namespace std;

    // Classes with virtual fucntion contains
    // virtual table, so its size grows 
    // by the size of the pointer.
    cout << "sizeof(Base) : " << sizeof(Base) << endl;
    cout << "sizeof(Child) : " << sizeof(Child) << endl;
    cout << "sizeof(VirtualBase) : " << sizeof(VirtualBase) << endl;
    cout << "sizeof(VirtualChild) : " << sizeof(VirtualChild) << endl;

    // result
    // sizeof(Base) : 1
    // sizeof(Child) : 1
    // sizeof(VirtualBase) : 8
    // sizeof(VirtualChild) : 8

    return 0;
}