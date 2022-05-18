#include <iostream>

class Base {
private:
  int x_;

public:
  Base(const int &x_in) : x_(x_in) {
    if (x_in <= 0)
      throw -1;
  }
};

class Child : public Base {

public:
  Child(const int &x_in) try : Base(x_in) {
    // Do sth
  } catch (...) {
    std::cerr << "Catch in Child" << std::endl;
    // throw;
  }
};

int main() {

  try {
    Child child(-1);

  } catch (const int &x) {
    std::cerr << "Catch in main" << std::endl;
  }

  return 0;
}