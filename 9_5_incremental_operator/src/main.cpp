#include <iostream>

using namespace std;

class Digit {
private:
    int m_digit;
public:
    Digit(const int &digit_in = 0): m_digit(digit_in){}
    
    Digit& operator++(){
        m_digit = (m_digit == 9) ? -1:m_digit; 
        ++m_digit;
        return *this;
    }

    Digit& operator--(){
        m_digit = (m_digit == 0) ? 10:m_digit; 
        --m_digit;
        return *this;
    }

    Digit operator++(int){
        m_digit = (m_digit == 9) ? -1:m_digit; 
        Digit temp(m_digit);
        ++m_digit;
        
        return temp;
    }

    Digit operator--(int){
        m_digit = (m_digit == 0) ? 10:m_digit; 
        Digit temp(m_digit);
        --m_digit;
        return temp;
    }

    friend std::ostream& operator<<(ostream& out, const Digit &digit){
        out << digit.m_digit;
        return out;
    }
};

int main(){
    // recap, incremental operator
    {
        int a = 1;
        cout << ++a << endl;
        cout << a++ << endl;
        cout << a << endl;
    }

    {
        cout << "==== increment overloading ====" << endl;
        Digit d(9);
        ++d;
        cout << d << endl;

        d++;
        cout << d << endl;

        d--;
        cout << d << endl;

        for (auto i = 0; i < 20; i++)
            cout << ++d << " ";
        cout << endl;

        for (auto i = 0; i < 20; i++)
            cout << --d << " ";
        cout << endl;
        
    }

    return 0;
}