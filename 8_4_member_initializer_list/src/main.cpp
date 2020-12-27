#include <iostream>

using namespace std;

class Something{
    int m_i;
    double m_d;
    char m_c;
    int m_arr[5];
public:
    // member initializer list
    // array only can be initialzied by {} unifrom initializer
    Something(): m_i(1), m_d(3.14), m_c('c'), m_arr{1,2,3,4,5}{
        // m_i = 1;
        // m_d = 3.14;
        // m_c = 'c';
        
        // what happen if do like this?
        m_i *= 10;
        m_d *= 10;
        m_c += 10;
    }

    void print(){
        cout << m_i << " " << m_d << " " << m_c << " " << endl;
        for (auto &&i : m_arr)
            cout << i << endl;        
    }
};

class B{ 
    int m_x;
public:
    B(const int &x_in) : m_x(x_in){};
    void print(){
        cout << "m_x : " << m_x << endl;
    }
};

int main(){

    // Basic Usage
    {
        Something sth;
        sth.print();
    }

    // initialization with params 
    {
        B b(12);
        b.print();
    }

    return 0;
}