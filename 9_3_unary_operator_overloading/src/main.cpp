#include <iostream>

using namespace std;

class Cents {
private:
  int m_val = 0;

public:
  Cents(const int &val_in = 0) : m_val(val_in) {}
  int getCents() const { return m_val; }
  Cents operator-() const { return Cents(-m_val); }
  bool operator!() const { return (m_val == 0) ? true : false; }
  friend std::ostream &operator<<(std::ostream &out, const Cents &c_in) {
    out << "(" << c_in.m_val << ")";
    return out;
  }
};

int main() {

  {
    Cents c1(120);

    cout << !c1 << endl;
    cout << -c1 << endl;
  }
  return 0;
}