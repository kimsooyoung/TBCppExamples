#include <iostream>

using namespace std;

class Accumulator {
private:
  int m_counter = 0;

public:
  Accumulator() {}
  int operator()(int i) {
    m_counter += i;
    return m_counter;
  }
};

class Deccel {
private:
  int number_;

public:
  Deccel(const int &number = 0) : number_(number) {}

  int operator()(int i) {
    number_ = number_ - i;
    return number_;
  }
};

int main() {

  // () operator overloaded
  // it is used like function
  // So it's also referred to Functor.
  Accumulator acc;

  cout << acc(10) << endl;
  cout << acc(20) << endl;

  Deccel dec;
  cout << dec(10) << endl;

  return 0;
}