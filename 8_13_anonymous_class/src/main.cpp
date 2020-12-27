#include <iostream>

using namespace std;

class A {
    int m_num = 1;
public:
    A(const int &num_in):m_num(num_in){
        cout << "Constructor" << endl;
    }
    ~A(){
        cout << "Destructor" << endl;
    }
    void print(){
        cout << "Hello my value is : " << m_num << endl; 
    }
};

class Cents {
private:
    int m_val;
public:
    Cents(const int &val_in): m_val(val_in){}
    ~Cents(){}
    
    int getCents() const{
        return m_val;
    }
};

Cents add(const Cents &c1, const Cents &c2){
    return Cents( c1.getCents() + c2.getCents() );
}

int main(){
    
    // Anonymous Class Basic Usage
    {
        A(11).print();
    }

    // Anonymous Class more Complex Usage
    {
        Cents c1(1);
        Cents c2(1);

        cout << add( Cents(1), Cents(2) ).getCents() << endl;
        cout << int(1) + int(2) << endl;
    }
    return 0;
}