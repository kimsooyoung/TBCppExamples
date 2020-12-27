#include "Calc.h"

using namespace std;

Calc::Calc(const int& num_in) : m_num(num_in) {}

Calc& Calc::add(int val){ m_num += val; return *this; }
Calc& Calc::sub(int val){ m_num -= val; return *this; }
Calc& Calc::mul(int val){ m_num *= val; return *this; }
Calc& Calc::div(int val){ m_num /= val; return *this; }

const int& Calc::getNum() const {
    return m_num;
}
void Calc::printNum() const {
    cout << "m_num : " << m_num << endl;
}