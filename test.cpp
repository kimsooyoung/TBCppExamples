#include <array>
#include <cassert>
#include <iostream>
#include <string>

class Base {
private:
  int private_int = 0;

protected:
  int protected_int = 0;

public:
  int public_int = 0;
};

class Derived : private Base {
  void printInstance() {
    // std::cout << private_int << std::endl;
    std::cout << protected_int << std::endl;
    std::cout << public_int << std::endl;
  }
};

int main(int argv, char **argc) {

  Derived dev;

  // std::cout << dev.public_int << std::endl;
  // std::cout << dev.protected_int << std::endl;
  // std::cout << dev.private_int << std::endl;

  return 0;
}