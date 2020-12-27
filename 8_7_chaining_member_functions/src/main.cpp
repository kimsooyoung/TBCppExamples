#include <iostream>

using namespace std; 

// Simple Class, has one member variable 
// with getter and setter
class Simple{
    int m_id;
public:
    Simple(const int &id_in){
        setID(id_in);
        cout << "this in setID : " << this << endl;
    }
    void setID(const int &id_in){
        m_id = id_in;
    }
    const int& getID(){
        return m_id;
    }
};

// chaining member function
class Calc {
    int m_num;
public:
    Calc(const int& num_in): m_num(num_in){}
    Calc& add(const int& val){ m_num += val; return *this; }
    Calc& sub(const int& val){ m_num -= val; return *this; }
    Calc& mul(const int& val){ m_num *= val; return *this; }
    Calc& div(const int& val){ m_num /= val; return *this; }
    
    const int& getNum() const {
        return m_num;
    }
    void printNum() const {
        cout << "m_num : " << m_num << endl;
    }
};

int main(){
    
    // class Address
    {
        Simple s1(1), s2(2);
        s1.setID(2);
        s1.setID(4);

        cout << "&s1 : " << &s1 << endl; 
        cout << "&s2 : " << &s2 << endl;

        // how this works??
        // Simple::setID(&s2, 4); == s2.setID(4);
    }

    // Chaining Member Function
    {
        Calc cal(10);
        cal.add(2).div(3).mul(10).sub(4).printNum();

        // or use like this
        Calc(10).add(2).div(3).mul(10).sub(4).printNum();
    }

    return 0;
}