#include <iostream>

class Base {
private:
    int m_i;
public:
    Base(const int &i_in=0): m_i(i_in) {}
    void print(){
        std::cout << "m_i : " << m_i ;
    }
    friend std::ostream& operator<<(std::ostream& out, const Base &b_in){
        out <<  b_in.m_i;
        return out;
    }
};

class Child : public Base {
private:
    double m_d;
public:
    Child(const int &i_in=0, const double &d_in=0.1): Base(i_in), m_d(d_in) {}
    void print(){
        // print(); => 무한 반복
        Base::print();
        std::cout << " / m_d : " << m_d << std::endl;
    }

    // Functoin overriding, add additional feature 
    // based on Base Class method  
    friend std::ostream& operator<<(std::ostream& out, const Child &c_in){
        std::cout << static_cast<Base>(c_in);
        out << " " << c_in.m_d;
    }
};

int main(){

    Child c;

    c.print();
    std::cout << c << std::endl;

    return 0;
}