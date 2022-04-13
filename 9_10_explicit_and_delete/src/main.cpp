#include <cassert>
#include <iostream>

using namespace std;

class Fraction {
private:
  int m_numerator;
  int m_denumerator;

public:
  Fraction(char) = delete;

  explicit Fraction(const int &num_in = 0, const int &denum_in = 1)
      : m_numerator(num_in), m_denumerator(denum_in) {
    assert(denum_in != 0);
    cout << "Constructor Called" << endl;
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

void printFrac(const Fraction &frac) { cout << frac << endl; }

int main() {

  // explicit usage
  {
    Fraction frac(12, 1);

    printFrac(frac);
    // converting constructor
    // compiler made new object with 12

    // use explicit to prevent this
    // printFrac(12);
  }

  // delete Usage
  {
    // will be casted into int and become 97
    // Fraction frac('a');
    // cout << frac << endl;

    // To prevent this, use delete in public
  }

  return 0;
}