#include <cassert>
#include <iostream>

using namespace std;

class Fraction {
private:
  int m_numerator;
  int m_denumerator;

public:
  Fraction(const int &num_in = 0, const int &denum_in = 1)
      : m_numerator(num_in), m_denumerator(denum_in) {
    assert(denum_in != 0);
  }
  Fraction(const Fraction &frac)
      : m_numerator(frac.m_numerator), m_denumerator(frac.m_denumerator) {
    cout << "Copy Constructor Called" << endl;
  }
  friend std::ostream &operator<<(std::ostream &out, const Fraction &frac) {
    out << frac.m_numerator << " , " << frac.m_denumerator;
    return out;
  }
};

Fraction doSomething() {
  Fraction temp(1, 2);
  cout << &temp << endl;
  return temp;
}

int main() {

  {
    Fraction frac(1, 3);
    cout << frac << endl;

    Fraction copy = frac;
  }

  // Compiler will reject useless assignment
  { Fraction copy(Fraction(1, 3)); }

  // Return Value Optimization
  // Copy Constructor won't called
  {
    Fraction result = doSomething();
    cout << &result << endl;
    cout << result << endl;
  }

  return 0;
}