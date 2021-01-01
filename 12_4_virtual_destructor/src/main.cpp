#include <iostream>

class Base {
public:
    virtual ~Base() {
        std::cout << "Base Destructor" << std::endl;
    }
};

class Child : public Base {
private:
    int *m_arr;
public:
    Child(const int &size_in=0){
        m_arr = new int [size_in];
    }
    virtual ~Child() override{
        std::cout << "Child Destructor" << std::endl;
        delete[] m_arr;
    }
};

int main(){

    
    // Destructor Example with polymorphism
    // See virtual keyword in Base Class
    {
        Child *ptr_c = new Child(5);
        Base  *ptr_b = ptr_c;
        delete ptr_b;
    }

    return 0;
}