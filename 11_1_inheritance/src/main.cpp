#include <iostream>

using namespace std;

class Mother {
private:
  int m_i;

public:
  Mother(const int &i_in = 0) : m_i(i_in) {}

  void setVal(const int &i_in) { m_i = i_in; }

  int getVal() const { return m_i; }
};

class Child : public Mother {
private:
  double m_d;

public:
  Child(const int &i_in = 0, const double &d_in = 0.0)
      : m_d(d_in), Mother(i_in) {}

  void setVal(const int &i_in, const double &d_in) {
    Mother::setVal(i_in);
    m_d = d_in;
  }

  double getVal() const { return m_d; }
};

int main() {
  // Child can use any methods in Mother
  {
    Child c;
    c.setVal(113, 1.5707);
    std::cout << c.getVal() << std::endl;
  }

  // setVal in Child has more high priority
  {
    Child c;
    c.setVal(113, 1.5707);
    std::cout << c.getVal() << std::endl;
  }

  return 0;
}